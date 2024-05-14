#pragma once

#include "Unit.h"

/**
 * @brief Each segment of the map where troops are stationed 
 * 
 */
struct City{
public:
    //For graphics
    int HEIGHT;
    int WIDTH;
    int x;
    int y;

    int color[3];
public:
    //#ID Name            Type    Status  Pop     Muster  Resource    ResourceType
    size_t ID;

    string name ="";

    CityType city_type;

    PowerType power_type;

    CityType ruler_type;

    size_t population;

    size_t muster;

    size_t resource;

    ResourceType resource_type;

    vector<Unit*> occupants[4]; /**< Hold the current units and sperates them by their power 0:West, 1:Axis 2:USSR: 3:Neutral */

    //For influence
    size_t influence;

    CityType influencer;

    //? The Attacker is the Faction provoking Combat in that Player Turn (the Active player). This is not the same as the Aggressor (the Faction trying to wrest control of a Land Area from the Owner).
    CityType aggresor; 

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
    City(const size_t ID=0, const string name="City", const CityType city_type=WATER, const PowerType power_type=NONE, const size_t population=0, const size_t muster=0, const size_t resource=0, const ResourceType resource_type=NORMAL):
    ID(ID), name(name), city_type(city_type), power_type(power_type), population(population), muster(muster), resource(resource), resource_type(resource_type){
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
    unordered_map<string, City*> cities; //the total graph where the key is the name

    vector<City*> city_masterlist;

    vector<vector<BorderType>> adjacency;

public:
    void initLists(const size_t size);

    void addCity(City* city){
        cities.insert(std::make_pair(city->getName(), city));
        city_masterlist.insert(city_masterlist.begin()+city->getID(), city);
    }
    
    City* operator[](const string target){
        return cities.at(target);
    }

    City* operator[](const size_t id){
        return city_masterlist[id];
    }

    void connect(const size_t& idx1, const size_t& idx2, const BorderType border);

    size_t findCity(const string name) const;

    City* getCity(const string name) const;

    City* getCity(const size_t id) const;

    bool checkConnection(const string A, const string B){
        return adjacency[findCity(A)][findCity(B)];
    }

    const size_t getNumCity() const{
        return cities.size();
    }

    const unordered_map<string, City*>& getCities() const{
        return cities;
    }

    const vector<vector<BorderType>>& getAdjacency() const{
        return adjacency;
    }

    void print() const; // prints all cities

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