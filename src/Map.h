#pragma once

#include "Unit.h"

/**
 * @brief Each segment of the map where troops can be stationed 
 * 
 */
struct City{
public:
    //! For graphics
    int HEIGHT; /**< The height of the city when rendered*/
    int WIDTH; /**< The width of the city when rendered*/
    int x; /**< The x origin of the city shape*/
    int y; /**< The y origin of the city shape*/

    int res_x; /**< The x origin of the cities resources*/
    int res_y; /**< The y origin of the cities resources*/

    int skip_troop[3]   = {0, 0, 0};  /**< When cities are shown the troop to start showing is at the index of the players nationality*/
    Uint32 last_skip[3] = {0, 0, 0,}; /**< Every 10 seconds update the skip units count */

    bool full_display[3] = {false, false, false}; /**< Array to hold if the city has been selected by the player (player id doubles as index) to display all units*/
public:
    //#ID Name            Type    Status  Pop     Muster  Resource    ResourceType
    size_t ID=0; /**< The ID of the city*/

    string name =""; /**< The name of the city*/

    string country=""; /**< Which larger country it belongs too*/

    CityType city_type; /**< What type of power it starts as (West, Axis, Ussr)*/

    PowerType power_type; /**< Whats the power level of the city (great, home...)*/

    CityType ruler_type; /**< The current ruler of the city (origionally set to the city_type until conquered)*/

    PopulationType population_type; /**< The type of city population (capital, city, town...)*/

    UnitCountry city_nationality; /**< The starting nationality of the city (different from country where non-powers is neutral)*/

    UnitCountry ruler_nationality; /**< The starting nationality of the city (different from country where non-powers is neutral)*/
    
    size_t population; /**< The population (pop) of the city*/

    size_t muster; /**< The muster determines how much troops are gained when influnced or strength of neutral forces when invaded*/

    size_t resource; /**< The amount of resources this city provides (mixed resources are always halfed so can be stored as one)*/

    ResourceType resource_type; /**What type of resource is on this city (only matters for blockades and going around Africa)*/

    bool blockcade=false; /**< If the city is unable to be traced back to the main capital*/

    bool med_blockcade=false; /**< If the city is unable to be traced back to the main capital, BUT the red resource is able to go around africa*/

    bool armed=false;

    bool capital=false;

    bool deep=false;

    bool voilation_of_neutrality[3] = {false, false, false};

    vector<Unit*> occupants[4]; /**< Hold the current units and sperates them by their power 0:West, 1:Axis 2:USSR: 3:Neutral */

    size_t country_counts[7] = {0, 0, 0, 0, 0, 0, 0}; //BRITIAN_U, FRANCE_U, USA_U, GERMANY_U, ITALY_U, USSR_U, NEUTRAL_U

    size_t num_occupants = 0; /**< Total number of occupants in the city between all  */

    //For influence
    uint8_t influence; /**< The amount of influence on this country*/

    CityType influencer; /**< The power who has the current influence over a starting neutral country (neutral if no influence)*/

    CityType aggresor; /**< The Attacker is the Faction provoking Combat in that Player Turn (the Active player). This is not the same as the Aggressor (the Faction trying to wrest control of a Land Area from the Owner)*/

    //For supply lines
    size_t year_supplied=0; /**< The last year checked that this city was supplied */

    Season season_supplied; /**< The last season checked that this city was supplied */

    bool supllied=false; /**< If the city can be connected to a main capital or sub capital and is supplied */

    /**
     * @brief Free the memory of the city by deleting the units
     * 
     */
    void freeMemory(){
        if (name != ""){
            for (auto& occ : occupants){
                for(auto& un : occ)
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
    City(const size_t ID=0, const string name="City", const CityType city_type=WATER, const PowerType power_type=NONE, const PopulationType population_type=EMPTY, const UnitCountry nationality=NEUTRAL_U, const size_t population=0, const size_t muster=0, const size_t resource=0, const ResourceType resource_type=NORMAL):
    ID(ID), name(name), city_type(city_type), power_type(power_type), population_type(population_type), city_nationality(nationality), population(population), muster(muster), resource(resource), resource_type(resource_type){
        ruler_type = city_type; //set it be ruled by who starts with it
        ruler_nationality = city_nationality;
        influence = 0;
        WIDTH = 32;
        HEIGHT = 32;

    }

    City(const int height, const int width, const int x, const int y, const size_t ID=0, const string name="City"): 
    HEIGHT(height), WIDTH(width), x(x), y(y), ID(ID), name(name){
    }

    /**
     * @brief Set the ruler of the city to the new ruler and update the allegiance
     * 
     * @param new_ruler The nationality of the new ruler
     */
    void setRuler(const UnitCountry new_ruler){
        constexpr CityType ca[6] = {WEST, WEST, WEST, AXIS, AXIS, USSR};
        ruler_nationality = new_ruler;
        ruler_type = ca[new_ruler];
    }

    /**
     * @brief If there currently a battle going on (more than one allegiance of troops) 
     * 
     * @return true There is a battle
     * @return false There is no battle (friendly troops or empty)
     */
    bool isConflict() const {
        return ((bool)occupants[0].size() + (bool)occupants[1].size() + (bool)occupants[2].size() + (bool)occupants[3].size()) > 1;
    }

    /**
     * @brief Returns if the opposing troops are together
     * 
     * @param allegiance The allegiance of the troop entering
     * @return true There is enemies
     * @return false No enemies
     */
    bool hasRival(const CityType allegiance) const{
        switch (allegiance){
        case WEST:
            return occupants[USSR].size() || occupants[AXIS].size();
        case AXIS:
            return occupants[USSR].size() || occupants[WEST].size();
        case USSR:
            return occupants[WEST].size() || occupants[AXIS].size();
        default:
            return false;
        }
    }

    bool hasOther(const CityType allegiance) const{
        switch (allegiance){
        case WEST:
            return occupants[USSR].size() || occupants[AXIS].size() || occupants[NEUTRAL].size();
        case AXIS:
            return occupants[USSR].size() || occupants[WEST].size() || occupants[NEUTRAL].size();
        case USSR:
            return occupants[WEST].size() || occupants[AXIS].size() || occupants[NEUTRAL].size();
        default:
            return false;
        }
    }

    inline bool hasEnemy(const DowState& west_dow, const DowState& axis_dow, const DowState& ussr_dow) const{
        return (west_dow != PEACE && occupants[WEST].size()) || (axis_dow != PEACE && occupants[AXIS].size()) || (ussr_dow != PEACE && occupants[USSR].size());
    }

    bool isFighting(const CityType allegiance) const{
        return isConflict() && occupants[allegiance].size();
    }
    
    /**
     * @brief Gives the number of enemies (not the number of units) in the current city
     * 
     * @param allegiance The allegiance of the unit
     * @return size_t how many enemeis in the city depending on the unit's allegiance
     */
    size_t numEnemies(const CityType allegiance) const{
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

    /**
     * @brief Get the name of the city
     * 
     * @return string The cities name
     */
    string getName() const{
        return name;
    }

    /**
     * @brief Get the ID of the city
     * 
     * @return size_t The ID of the city
     */
    size_t getID() const{
        return ID;
    }

    /**
     * @brief Debugg method to print the ID's of the current occupants of the city
     * 
     */
    void printOccupants() const;

    /**
     * @brief Prints out all attributes of the city
     * 
     */
    void print() const;
};

struct Country{
public:
    size_t id; /**< The ID of the country */

    string name=""; /**< The name of the country */

    City* capital= nullptr; /**< The capital city of the country wher influenced is placed */

    CityType allegiance=NEUTRAL; /**< The allegiance (West, Axis, USSR) of the country*/

    InfluenceType influence_level=UNALIGNED; /**< The current influence level of the country that decides what benefits the influencer gets and any changes in invatsion from rivals */
    
    int influence=0; /**< The current number of influence the country has (0,1,2,3+) */

    int added_influence=0; /**< The number of influence added by the `top_card` power in a government phase */

    bool armed_minor = false; /**< If the country is an armed minor and in battle */

    CityType invader; /**< The power who invaded the country first and armed it */

    CityType top_card=NEUTRAL; /**< The power who has played the most cards for this country (neutral if none or tied) */

    vector<City*> cities; /**< Vector of cities who are in the country */

public:
    /**
     * @brief Construct a new Country
     * 
     * @param name Name of the country
     * @param influence_level The satelite state of this country (UNALIGNED, ASSOCIATES, PROTECTORATES, SATELLITES)
     * @param influence The current influnce level of the country [0...3]
     */
    Country(const size_t id, const string name, City* capital, const InfluenceType influence_level=UNALIGNED, const int influence=0):
    id(id), name(name), capital(capital), influence_level(influence_level), influence(influence){
    }

    /**
     * @brief Add a city to the vector of cities who makeup the country
     * 
     * @param city The city thats in the country
     */
    void pushback(City* city){
        if (allegiance == WATER) //since the 
            allegiance = city->city_type;

        cities.push_back(city);
    }

    /**
     * @brief Resolve the effects of a power playing a card on the country
     * 
     * @param influencer The power who is playing a diplomacy on the country
     */
    void addCard(const CityType& influencer){
        if (top_card == NEUTRAL){ //neutral means its empty
            top_card = influencer;
            added_influence = 1;
        }
        else if (top_card != influencer){ //if its not the influencer then cancel one card
            if (added_influence == 1){
                top_card = NEUTRAL;
            }
            added_influence--;
        }
        else if (top_card == influencer){ //if its the influencer then add onto the influence being added
            added_influence++;
        }
    }

    /**
     * @brief At the end of the government phase resolve the cards added and change the number of influence and who the top influencer is
     * 
     */
    void resolveCards(){
        if (added_influence == 0 && top_card == NEUTRAL) //no cards currently on
            return;

        if (allegiance == NEUTRAL && added_influence > 0){
            allegiance = top_card;
            influence = added_influence;
        }
        else if (allegiance == top_card){
            influence += added_influence;
        }
        else if (allegiance != top_card){
            if (added_influence > influence){ //if the added influence is from a rival and greater than the difference is for the new allegiance
                allegiance = top_card;
                influence = added_influence-influence;
            }
            else if (added_influence == influence){ //if its equal then they all cancel out and goes back to neutal
                allegiance = NEUTRAL;
                influence = 0;
            }
            else{ //if it wasn't more than the current it just decreases it
                influence -= added_influence;
            }
        }
        added_influence = 0;
        resolveDiplomacy();
    }

    /**
     * @brief Change the influence level and the effects after cards have been resolved
     * 
     * @see resolveCards
     * 
     */
    //TODO add full functionality
    void resolveDiplomacy(){
        // now that the influence level has been set change the influence level
        influence_level = (InfluenceType)std::min(influence, 3);

        switch (influence_level){
            case UNALIGNED:{
                allegiance = NEUTRAL;
                break;
            }
            case ASSOCIATES:{
                allegiance = top_card;
                /* code */
                break;
            }
            case PROTECTORATES:{
                allegiance = top_card;
                /* code */
                break;
            }
            case SATELLITES:{
                allegiance = top_card;
                /* code */
                break;
            }
            
            default:
                break;
        }
        top_card=NEUTRAL;
    }

    /**
     * @brief Go through all cities in the country and update them to the new influencer
     * 
     */
    void setCities(){
        for (auto& city : cities){
            city->ruler_type = top_card;
        }
    }

    /**
     * @brief Get the name of the country
     * 
     * @return string Name of country
     */
    string getName()const{
        return name;
    }
};

class Map{
private:
    size_t list_size; /**< The size or amount of cities in the game*/

    unordered_map<string, Country*> countries; /**< Hash table of all countrues where the country is a collection of cities that share the same influence*/

    unordered_map<string, City*> cities; /**< Hash table of all cities where the city pointer is the value of the City key name*/

    vector<City*> city_masterlist; /**< Masterlist of all cities*/

    vector<vector<BorderType>> adjacency; /**< Is an adjacency matrix of the cities where the connection of cities is reresented by as nonzero value (0 is an offset city)*/

    vector<vector<vector<int8_t>>> border_limit;

    vector<City*> sortedX; /**< Sorts all cities by their x value (left...right)*/

    vector<City*> sortedY; /**< Sorts all cities by their y value (bottom...top)*/

public:
    /**
     * @brief Initalizes the adjacency list 
     * 
     * @param size The amount of cities and ultimate the side length of it
     */
    void initLists(const size_t size);

    /**
     * @brief Adds a country pointer to the map
     * 
     * @param country The country being added
     */
    void addCountry(Country* country){
        countries.insert(std::make_pair(country->getName(), country));
    }

    /**
     * @brief Adds a city pointer to the map and master list
     * 
     * @param city The new city
     */
    void addCity(City* city){
        //- Add to hashmap
        cities.insert(std::make_pair(city->getName(), city));

        //- Add to sorted x
        size_t i = 0;
        for (; i < list_size; i++){
            if (sortedX[i] == NULL || sortedX[i]->x > city->x)
                break;
        }
        sortedX[i] = city;

        //- Add to sorted y
        i = 0;
        for (; i < list_size; i++){
            if (sortedY[i] == NULL || sortedY[i]->y > city->y)
                break;
        }
        sortedY[i]= city;

        //- Add to masterlist
        city_masterlist[+city->getID()] = city;
    }
    
    /**
     * @brief overloads [] such that the hash map can be accessed from outside the scope
     * 
     * @param target The name of the city that acts as the key
     * @return City* The city with the given name
     */
    City* operator[](const string target){
        try{
            return cities.at(target);
        }
        catch (std::out_of_range){
            std::cerr << "Country key '" << target << "' was not found as a key" << endl;
            exit(1);
        }
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
     * @brief Gets the country of that name
     * 
     * @param name Name of the country
     * @return Country* The country of that name
     */
    Country* getCountry(const string& name) const{
        try{
            return countries.at(name);
        }
        catch (std::out_of_range){
            std::cerr << "Country key '" << name << "' was not found as a key" << endl;
            exit(1);
        }
    }

    /**
     * @brief Gets the capital of that country
     * 
     * @param country Name of the country with the desired capital
     * @return City* The capital of the city (where influence is places)
     */
    City* getCapital(const string country) const{
        try{
            return countries.at(country)->capital;
        }
        catch (std::out_of_range){
            std::cerr << "Country name '" << country << "' was not found as a key" << endl;
            exit(1);
            return nullptr;
        }
    }

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
     * @brief Gets the city closest to the x,y coords from the mouse position
     * 
     * @param x The x coord of the anchor
     * @param y The y coord of the anchor
     * @param zoom The zoom scale to apply when looking at distance
     * @return City* The city closest to the (x,y)
     */
    City* getClosestCity(const int x, const int y, const double zoom_x, const double zoom_y) const;

    /**
     * @brief Get the total number of cities
     * 
     * @return const size_t The total number of cities (shouldn't change after initalization)
     */
    const size_t getNumCity() const{
        return cities.size();
    }

    const BorderType getBorder(const City* lhs, const City* rhs) const{
        return adjacency[lhs->getID()][rhs->getID()];
    }

    const int8_t getBorderLimit(const City* lhs, const City* rhs, const CityType& mover) const{
        return border_limit[lhs->getID()][rhs->getID()][mover];
    }

    void increaseBorderLimit(const City* lhs, const City* rhs, const CityType& mover) {
        border_limit[lhs->getID()][rhs->getID()][mover]++;
    }

    void resetBorderLimits(){
        for (auto& row : border_limit){
            for (auto& col : row){
                for (auto& mover : col)
                    mover = 0;
            }
        }
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
     * @brief Get reference to hash map of countries to reduce calls 
     * 
     * @return const unordered_map<string, Country*>& The city hashmap reference
     */
    const unordered_map<string, Country*>& getCountries() const{
        return countries;
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
        for (auto& city : city_masterlist){
            if (city == nullptr)
                continue;
            city->freeMemory();
            delete city;
        }
        city_masterlist.clear();
        cities.clear();
        sortedX.clear();
        sortedY.clear();

        countries.clear();
    }

};