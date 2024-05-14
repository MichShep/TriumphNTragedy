#pragma once

#include "Unit.h"

/**
 * @brief Each segment of the map where troops can be stationed 
 * 
 */
struct City{
public:
    //? For graphics
    int HEIGHT; /**< The height of the city when rendered*/
    int WIDTH; /**< The width of the city when rendered*/
    int x; /**< The x origin of the city shape*/
    int y; /**< The y origin of the city shape*/

    int color[3];
public:
    //#ID Name            Type    Status  Pop     Muster  Resource    ResourceType
    size_t ID; /**< The ID of the city*/

    string name =""; /**< The name of the city*/

    string country=""; /**< Which larger country it belongs too*/

    CityType city_type; /**< What type of power it starts as (West, Axis, Ussr)*/

    PowerType power_type; /**< Whats the power level of the city (great, home...)*/

    CityType ruler_type; /**< The current ruler of the city (origionally set to the city_type until conquered)*/

    PopulationType population_type; /**< The type of city */
    
    size_t population; /**< The population (pop) of the city*/

    size_t muster; /**< The muster determines how much troops are gained when influnced or strength of neutral forces when invaded*/

    size_t resource; /**< The amount of resources this city provides (mixed resources are always halfed so can be stored as one)*/

    ResourceType resource_type; /**What type of resource is on this city (only matters for blockades and going around Africa)*/

    vector<Unit*> occupants[4]; /**< Hold the current units and sperates them by their power 0:West, 1:Axis 2:USSR: 3:Neutral */

    //For influence
    uint8_t influence; /**< The amount of influence on this country*/

    CityType influencer; /**< The power who has the current influence over a starting neutral country (neutral if no influence)*/

    CityType aggresor; /**< The Attacker is the Faction provoking Combat in that Player Turn (the Active player). This is not the same as the Aggressor (the Faction trying to wrest control of a Land Area from the Owner)*/

    void freeMemory(){
        if (name != ""){
            for (auto occ : occupants){
                for(auto un : occ)
                    delete un;
                occ.clear();
            } 
        }
    }
public:
    /**
     * @brief Construct a new City object
     * 
     * @param ID id of the city
     * @param name Name of the city
     * @param city_type The starting allegiance of the city
     * @param power_type The power of the city (GREAT, HOME, MINOR, NONE)
     * @param population The pop value 
     * @param muster How many troops are added when taken over
     * @param resource How many resources given
     * @param resource_type The type of resource (N is none as well)
     */
    City(const size_t ID=0, const string name="City", const CityType city_type=WATER, const PowerType power_type=NONE, const PopulationType population_type=EMPTY, const size_t population=0, const size_t muster=0, const size_t resource=0, const ResourceType resource_type=NORMAL):
    ID(ID), name(name), city_type(city_type), power_type(power_type), population_type(population_type), population(population), muster(muster), resource(resource), resource_type(resource_type){
        ruler_type=city_type; //set it be ruled by who starts with it
        influence = 0;
        WIDTH = 32;
        HEIGHT = 32;

    }

    City(const int height, const int width, const int x, const int y, const int r=255, const int g=255, const int b=255, const size_t ID=0, const string name="City"): 
    HEIGHT(height), WIDTH(width), x(x), y(y), ID(ID), name(name){
        color[0] = r; color[1] = g; color[2] = b;
    }

    /**
     * @brief If there currently a battle going on (more than one allegiance of troops) (Doesn't check neutrality)
     * 
     * @return true There is a battle
     * @return false There is no battle (friendly troops or empty)
     */
    bool isConflict(){
        return ((bool)occupants[0].size() + (bool)occupants[1].size() + (bool)occupants[2].size()) > 1;
    }

    /**
     * @brief Returns if the opposing troops are together
     * 
     * @param allegiance The allegiance of the troop entering
     * @return true There is enemies
     * @return false No enemies
     */
    bool isEnemy(CityType allegiance){
        switch (allegiance){
        case WEST:
            return occupants[(size_t)USSR].size() || occupants[(size_t)AXIS].size() || occupants[(size_t)NEUTRAL].size();
        case AXIS:
            return occupants[(size_t)USSR].size() || occupants[(size_t)WEST].size() || occupants[(size_t)NEUTRAL].size();
        case USSR:
            return occupants[(size_t)WEST].size() || occupants[(size_t)AXIS].size() || occupants[(size_t)NEUTRAL].size();
        default:
            return false;
        }
    }

    /**
     * @brief Gives the number of enemies (not the number of units) in the current city
     * 
     * @param allegiance The allegiance of the unit
     * @return size_t how many enemeis in the city depending on the unit's allegiance
     */
    size_t numEnemies(CityType allegiance){
        switch (allegiance){
        case WEST:
            return occupants[(size_t)USSR].size()!=0 + occupants[(size_t)AXIS].size()!=0 + occupants[(size_t)NEUTRAL].size()!=0;
        case AXIS:
            return occupants[(size_t)USSR].size()!=0 + occupants[(size_t)WEST].size()!=0 + occupants[(size_t)NEUTRAL].size()!=0;
        case USSR:
            return occupants[(size_t)WEST].size()!=0 + occupants[(size_t)AXIS].size()!=0 + occupants[(size_t)NEUTRAL].size()!=0;
        default:
            return 0;
        }
    }

    /**
     * @brief In the case where there is only one enemy return the one there
     * 
     * @param allegiance The allegiance of the attacker
     * @return CityType The defender
     */
    CityType getEnemy(CityType allegiance){
        switch (allegiance){
        case WEST:
            return (occupants[USSR].size() ==0 )? AXIS: USSR;
        case AXIS:
            return (occupants[WEST].size() ==0 )? USSR: WEST;;
        case USSR:
            return (occupants[AXIS].size() ==0 )? WEST: AXIS;;
        default:
            return WATER;
        }
    }

    /**
     * @brief Removes a unit form this city
     * 
     * @param unit The unit to remove
     */
    void removeUnit(Unit* unit);

    /**
     * @brief Adds a unit to this city
     * 
     * @param unit The unit to add
     */
    void addUnit(Unit* unit);

    void printOccupants() const;

    string getName() const{
        return name;
    }

    size_t getID() const{
        return ID;
    }

    /**
     * @brief Prints out all attributes of the city
     * 
     */
    void print() const;
};

class Map{
private:
    unordered_map<string, City*> cities; /**< Hash table of all cities where the city pointer is the value of the City key name*/

    vector<City*> city_masterlist; /**< Masterlist of all cities*/

    vector<vector<BorderType>> adjacency /**< Is an adjacency matrix of the cities where the connection of cities is reresented by as nonzero value (0 is an offset city)*/;

public:
    /**
     * @brief Initalizes the adjacency list 
     * 
     * @param size The amount of cities and ultimate the side length of it
     */
    void initLists(const size_t size);

    /**
     * @brief Adds a city pointer to the map and master list
     * 
     * @param city The new city
     */
    void addCity(City* city){
        cities.insert(std::make_pair(city->getName(), city));
        city_masterlist.insert(city_masterlist.begin()+city->getID(), city);
    }
    
    /**
     * @brief overloads [] such that the hash map can be accessed from outside the scope
     * 
     * @param target The name of the city that acts as the key
     * @return City* The city with the given name
     */
    City* operator[](const string target){
        return cities.at(target);
    }

    /**
     * @brief Returns the city form the ML at the index (id)
     * 
     * @param id The id of the target city
     * @return City* The city with the given id
     */
    City* operator[](const size_t id){
        return city_masterlist[id];
    }

    /**
     * @brief Connects two cities with the given border and updates adjacncy list
     * 
     * @param idx1 
     * @param idx2 
     * @param border 
     */
    void connect(const size_t& idx1, const size_t& idx2, const BorderType border);

    /**
     * @brief Works as the [] overload for out of scope but gives the ID of the found city
     * @see City* operator[](const string target)
     * 
     * @param name name of the desired city
     * @return size_t the Id of the city with 'name'
     */
    size_t findCity(const string name) const;

    /**
     * @brief Works as the [] overload for out of scope
     * @see City* operator[](const string target)
     * 
     * @param name name of the desired city
     * @return City* The desired city obj
     */
    City* getCity(const string name) const;

    /**
     * @brief Get the desiured city by id (works like [] overload)
     * @see City* operator[](const size_t id)
     * 
     * @param id 
     * @return City* 
     */
    City* getCity(const size_t id) const;

    /**
     * @brief Checks to see if there is a connection between the two named cities
     * 
     * @param A Starting City
     * @param B Ending City
     * @return true The cities share a connection
     * @return false The cities don't share a connection
     */
    bool checkConnection(const string A, const string B){
        return adjacency[findCity(A)][findCity(B)];
    }

    /**
     * @brief Get the total number of cities
     * 
     * @return const size_t The total number of cities (shouldn't change after initalization)
     */
    const size_t getNumCity() const{
        return cities.size();
    }

    /**
     * @brief Get reference to hash map of cities to reduce calls 
     * 
     * @return const unordered_map<string, City*>& The city hashmap reference
     */
    const unordered_map<string, City*>& getCities() const{
        return cities;
    }

    /**
     * @brief Get the adjacency matrix of cities to reduce calls 
     * 
     * @return const vector<vector<BorderType>>& The adjacency matrix reference
     */
    const vector<vector<BorderType>>& getAdjacency() const{
        return adjacency;
    }

    /**
     * @brief Prints all the cities and stats (not connections)
     * 
     */
    void print() const; // prints all cities

    /**
     * @brief Evokes each city to free memory before clearing the hasmap and masterlist
     * 
     */
    void freeMemory(){
        for (auto city : city_masterlist){
            if (city == nullptr)
                continue;
            city->freeMemory();
            delete city;
        }
        city_masterlist.clear();
        cities.clear();
    }

};