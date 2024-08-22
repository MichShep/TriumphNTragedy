#pragma once

/*! Importation of librairies*/
#include "Unit.h"

/**
 * @brief Cities represent segments of the map where units will move between, Powers gain resources, and area control
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
    Uint32 last_skip[3] = {1, 1, 1}; /**< Every 10 seconds update the skip units count */

    bool full_display[3] = {false, false, false}; /**< Array to hold if the city has been selected by the player (player id doubles as index) to display all units*/
public:
    //#ID Name            Type    Status  Pop     Muster  Resource    ResourceType
    size_t ID=0; /**< The ID of the city*/

    string name =""; /**< The name of the city*/

    string country=""; /**< Which larger country it belongs too*/

    CityType start_allegiance; /**< The default ruling power of the city at the starts (West, Axis, USSR, Neutrl)*/

    CityType ruler_allegiance; /**< The current ruler of the city (origionally set to the city_type until conquered)*/

    CityType occupier_allegiance; /**< The current occupant of the city but doesn't own the capital and will lose ownership when no units remain in the city (NEUTRAL means no occupier) */

    PowerType power_type; /**< Whats the power level of the city (great, home...)*/

    PopulationType population_type; /**< The type of city population (capital, city, town...)*/

    UnitCountry city_nationality; /**< The starting nationality of the city (different from country where non-powers is neutral)*/

    UnitCountry ruler_nationality; /**< The starting nationality of the city (different from country where non-powers is neutral)*/
    
    size_t population; /**< The population (pop) of the city*/

    size_t muster; /**< The muster determines how much troops are gained when influnced or strength of neutral forces when invaded*/

    size_t resource; /**< The amount of resources this city provides (mixed resources are always halfed so can be stored as one)*/

    ResourceType resource_type; /**What type of resource is on this city (only matters for blockades and going around Africa)*/

    bool blockcade=false; /**< If the city is unable to be traced back to the main capital*/

    bool med_blockcade=false; /**< If the city is unable to be traced back to the main capital, BUT the red resource is able to go around africa*/

    bool armed=false; /**< If the city has had their neutrality violated and has dispensed troops*/

    bool capital=false; /**< Flag to show if this city is the capital for a country (used for VoN) */

    bool deep=false; /**<  Flag to show if this city is a deep ocean and will require an extra movement to move INTO*/

    year_t battling = NULL_YEAR; /**< Flag for if the city has a battle occuring and that all units should be displayed*/

    vector<Unit*> occupants[4]; /**< Hold the current units and sperates them by their power 0:West, 1:Axis 2:USSR: 3:Neutral */

    int occupier_priority[4] = {0, 0, 0, 0};

    int num_occupiers;

    size_t num_occupants = 0; /**< Total number of occupants in the city between all  */

    //For supply lines
    size_t year_supplied=0; /**< The last year checked that this city was supplied */

    Season season_supplied; /**< The last season checked that this city was supplied */

    bool supplied=false; /**< If the city can be connected to a main capital or sub capital and is supplied */

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
     * @param start_allegiance The starting allegiance of the city
     * @param power_type The power of the city (GREAT, HOME, MINOR, NONE)
     * @param population The pop value 
     * @param muster How many troops are added when taken over
     * @param resource How many resources given
     * @param resource_type The type of resource (N is none as well)
     */
    City(const size_t ID=0, const string name="City", const CityType city_type=WATER, const PowerType power_type=NONE, const PopulationType population_type=EMPTY, const UnitCountry nationality=NEUTRAL_U, const size_t population=0, const size_t muster=0, const size_t resource=0, const ResourceType resource_type=NORMAL):
    ID(ID), name(name), start_allegiance(city_type), power_type(power_type), population_type(population_type), city_nationality(nationality), population(population), muster(muster), resource(resource), resource_type(resource_type){
        ruler_allegiance = city_type; //set it be ruled by who starts with it
        ruler_nationality = city_nationality;
        occupier_allegiance = city_type;
        
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
        ruler_allegiance = ca[new_ruler];
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

    /**
     * @brief Returns a bool to show if there are units that are not of the same allegaince in this city
     * 
     * @param allegiance The allegiance that is looking for others
     * @return true There are other units than the provided allegiance in the city
     * @return false There are no other allegiances in the city
     */
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

    /**
     * @brief Returns a bool to show if this city has any enemies dictated by the Declartions of War provided
     * 
     * @param west_dow The state of the DoW between the caller and the WEST
     * @param axis_dow The state of the DoW between the caller and the AXIS
     * @param ussr_dow The state of the DoW between the caller and the USSR
     * @return true There is an enemy in the city
     * @return false There are no enemies in the city (can still have rivals)
     */
    inline bool hasEnemy(const DowState& west_dow, const DowState& axis_dow, const DowState& ussr_dow) const{
        return (west_dow != PEACE && occupants[WEST].size()) || (axis_dow != PEACE && occupants[AXIS].size()) || (ussr_dow != PEACE && occupants[USSR].size());
    }

    /**
     * @brief Returns a bool to show if the allegiance provided is fighting another allegiance within the city
     * 
     * @param allegiance The allegiance being checked for fighting within the city
     * @return true The allegiance is currently in comabat
     * @return false The allegiance is not currently in combat (could also mean not even in city)
     * @see isConflict for how a conflict is decided
     */
    bool isFighting(const CityType& allegiance) const{
        return isConflict() && !occupants[allegiance].empty();
    }

    bool hasANS(const CityType& allegiance) const{
        for (const auto& unit : occupants[allegiance]){
            if (isANS(unit->class_type)){
                return true;
            }
        }
        return false;
    }

    bool hasType(const CityType& allegiance, const UnitClass& type) const{
        for (const auto& unit : occupants[allegiance]){
            if (unit->class_type == type){
                return true;
            }
        }
        return false;
    }
    

    bool mustRebase(const CityType& allegiance) const{
        bool has_ground = false;
        bool has_ans= false;
        for (const auto& unit : occupants[allegiance]){
            has_ans = has_ans || isANS(unit->class_type);
            has_ground = has_ground || unit->class_type == CLASS_G;
        }

        return allegiance != occupier_allegiance && !has_ground && has_ans;
    }
    
    /**
     * @brief Gives the number of rivals (including neutral forts) (not the number of units) in the current city
     * 
     * @param allegiance The rivals of the allegiance being checked
     * @return size_t the number of rivals of the provided allegiance
     */
    size_t numRivals(const CityType& allegiance) const{
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

    size_t getUpgraded(const CityType& allegiance) const{
        size_t count = 0;
        for (const auto& unit: occupants[allegiance]){
            count += unit->upgrading;
        }

        return count;
    }

    
    void removeUnit(Unit* unit);

    void addUnit(Unit* unit);

    void checkRemoved(const CityType& allegiance);

    void updatePriority(const CityType& removed);

    /**
     * @brief Get the name of the city
     * 
     * @return string The cities name
     * @pre Each city has a unique name
     */
    const string& getName() const{
        return name;
    }

    /**
     * @brief Get the ID of the city
     * 
     * @return size_t The ID of the city
     * @pre Each city has a unique ID number
     */
    const size_t& getID() const{
        return ID;
    }

    /**
     * @brief Get a combined vector of every unit in the city
     * 
     * @return const vector<Unit*> The vector or 'master list' of all units currently in the city
     */
    inline const vector<Unit*> getOccupants() const{
        vector<Unit*> unit_ml;

        for (auto& nationality : occupants){
            for (auto& unit : nationality){
                unit_ml.push_back(unit);
            }
        }

        return unit_ml;
    }
    /**
     * @brief Debugg method to print the ID's of the current occupants of the city
     * 
     */
    void printOccupants() const;

    /**
     * @brief Equalality operator overload to check a City pointer to the current instance
     * 
     * @param city The City pointer being compared to 'this'
     * @return true The City* and 'this' has the same ID number
     * @return false The City* and 'this' have different ID numbers
     * @pre Each City object has a unique ID number
     */
    bool operator==(const City* city) const{
        return this->ID == city->ID;
    }

    /**
     * @brief Prints out all attributes of the city
     * 
     */
    void print() const;
};

/**
 * @brief Countries represent a collection of cities that have their own influence, capital cities, and if voilated as a neutral will become armed
 * 
 */
struct Country{
public:
    //& In Game Attributes
    size_t id; /**< The ID of the country */

    string name=""; /**< The name of the country */

    City* capital= nullptr; /**< The capital city of the country where influenced is placed and if captured will gain ownership of whole country*/

    vector<City*> cities; /**< Vector of cities who are in the country */

    CityType starter_allegiance=NULL_ALLEGIANCE;

    CityType allegiance=NULL_ALLEGIANCE; /**< The allegiance (West, Axis, USSR) of the country*/

    InfluenceType influence_level=UNALIGNED; /**< The current influence level of the country that decides what benefits the influencer gets and any changes in invasion from rivals */

    CityType invader; /**< The power who invaded the country first and armed it */

    bool armed_minor = false; /**< If the country has had neutrality violated and is now an armed minor*/

    //&^ Violations of Neutrality
    bool voilation_of_neutrality[3] = {false, false, false}; /**< Array of flags to show who has violated the city (if neutral) and cannot Intervene*/
    CityType first_violator_allegiance=NULL_ALLEGIANCE;

    //&^ Interventions
    bool intervened = false;
    CityType intervenie=NULL_ALLEGIANCE;

    //&^ Records for diplomacy play
    int influence=0; /**< The current number of influence 'tokens' the country has (0,1,2,3+) */

    int added_influence=0; /**< The number of influence added by the `top_card` power in a government phase */

    CityType top_card=NEUTRAL; /**< The power who has played the most cards for this country (neutral if none or tied) */

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
            allegiance = city->start_allegiance;

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
        if (added_influence == 0 && top_card == NEUTRAL){ //no cards currently on but could still have influence tokens changed from wild cards
            resolveDiplomacy();
            return;
        }

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

        top_card = (top_card==NEUTRAL? allegiance : top_card);//for when no card was added but wild influence cards were played

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
                for (auto& city : cities){
                    city->ruler_allegiance = allegiance;
                    city->occupier_allegiance = allegiance;
                }
                /* code */
                break;
            }
            
            default:
                break;
        }
        top_card=NEUTRAL;
    }

    void directAdd(const CityType& adder){
        if (influence == 0){
            allegiance = adder;
            influence = 1;
            influence_level = ASSOCIATES;
        }
        else{
            //if a rival is adding an influencerker then take one away
            influence = influence + (adder == allegiance? 1 : -1);
        }

        if (!influence)
            resetDiplomacy();
    }

    void resetDiplomacy(){
        allegiance = NEUTRAL;
        influence = 0;
        influence_level = UNALIGNED;
    }

    /**
     * @brief Set the ruler of a country and the influnce level (only used for testing)
     * 
     * @param ruler The allegiance of the new owner of the country 
     * @param level The level of influence the new ruler has
     */
    void setTest(const CityType& ruler, const int& level){
        top_card = ruler;
        influence = level;

        resolveDiplomacy();
    }

    void conqueredCapital(const CityType& ruler){
        allegiance = ruler;
        influence_level = SATELLITES;

        for (auto& city : cities){
            city->ruler_allegiance = ruler; //set all of its cities to the new ruler
            if (!city->hasOther(ruler)){ 
                city->occupier_allegiance = ruler;
            }

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

/**
 * @brief Class that holds all the data on the game map, including the cities, countries, and borders
 * 
 */
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
     * @brief Initalizes and resizes all lists the map has to the number of cities
     * 
     * @param size The amount of cities and ultimate the side length of it
     */
    void initLists(const size_t& size);

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
     * @brief Overloads the [] operator such that the hash map can be accessed from outside the scope
     * 
     * @param target The name of the wanted city (acts as the key)
     * @return City* Pointer to the City with the given name
     * @pre There is a City with the name given
     */
    City* operator[](const string& target) const{
        try{
            return cities.at(target);
        }
        catch (std::out_of_range){
            std::cerr << "Country key '" << target << "' was not found as a key" << endl;
            exit(1);
        }
    }

    /**
     * @brief Returns the city form the ML at the index given (ID)
     * 
     * @param id The ID of the target City
     * @return City* The city with the given ID
     * @pre Each City has a unique ID number
     * @pre There is a City with the ID number given
     */
    City* operator[](const size_t id) const{
        return city_masterlist[id];
    }

    /**
     * @brief Connects two cities with the given border and updates the adjacency list
     * 
     * @param idx1 The ID of the first City
     * @param idx2 The ID of the second City
     * @param border The type of connection between the two cities that will dictate movement and engage restrictions
     * @pre The two ID's are not equal
     */
    void connect(const size_t& idx1, const size_t& idx2, const BorderType border);

    /**
     * @brief Works as the [] overload for out of scope but gives the ID of the found city
     * @see City* operator[](const string target)
     * 
     * @param name Name of the desired City
     * @return size_t The ID of the city with 'name'
     * @pre There is a City with the given name
     */
    const size_t& findCity(const string& name) const;

    /**
     * @brief Works as the [] overload for out of scope
     * @see City* operator[](const string target)
     * 
     * @param name Name of the desired City
     * @return City* Pointer to the City with the given name
     */
    City* getCity(const string& name) const;

    /**
     * @brief Get the desired city by ID (works like [] overload)
     * @see City* operator[](const size_t id)
     * 
     * @param id The ID of the wanted city
     * @return City* Pointer to the City with the given ID
     */
    City* getCity(const size_t id) const;

    /**
     * @brief Returns a pointer to the Country with the given name
     * 
     * @param name Name of the Country
     * @return Country* Pointer to the Country of that name
     * @pre Each Country has a unique name
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
     * @brief Returns a pointer to the City that acts as the capital for the given country
     * 
     * @param country Name of the Country with the desired capital
     * @return City* The capital of the city (where influence is places)
     * @pre The name of the country is actually a name of a Country
     */
    City* getCapital(const string& country) const{
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
    bool checkConnection(const string& A, const string& B){
        return adjacency[findCity(A)][findCity(B)];
    }

    /**
     * @brief Returns a pointer to the City closest to the x,y coords from the given coordinated
     * 
     * @param x The x coord of the anchor
     * @param y The y coord of the anchor
     * @param zoom_x The x zoom scale to apply when looking at distance
     * @param zoom_y The y zoom scale to apply when looking at distance
     * @return City* The city closest to the (x,y)
     */
    City* getClosestCity(const int& x, const int& y, const double& zoom_x, const double& zoom_y) const;

    /**
     * @brief Get the total number of cities in the game
     * 
     * @return const size_t The total number of cities (shouldn't change after initalization)
     */
    const size_t getNumCity() const{
        return cities.size();
    }

    /**
     * @brief Returns the border between the two provided cities (Mirrored on both sides to the arguments flipped gives the same border)
     * 
     * @param lhs The left City
     * @param rhs The right City
     * @return const BorderType The type of border joining two cities (NA=0 means no connection)
     */
    const BorderType& getBorder(const City* lhs, const City* rhs) const{
        return adjacency[lhs->getID()][rhs->getID()];
    }

    const BorderType& getBorder(const size_t& lhs, const size_t& rhs) const{
        return adjacency[lhs][rhs];
    }

    /**
     * @brief Get the current border limit of the player for a border that joins each city (used to limit how many units can engage and retreat from a border)
     * 
     * @param lhs The left City
     * @param rhs The right City
     * @param mover The allegiance of the unit moving between the cities
     * @return const int8_t The current number of units that have engaged/retreated across the border in the current year
     */
    const int8_t& getBorderLimit(const City* lhs, const City* rhs, const CityType& mover) const{
        return border_limit[lhs->getID()][rhs->getID()][mover];
    }

    /**
     * @brief Increases the border limit that joins the two provided Cities
     * 
     * @param lhs The left City
     * @param rhs The right City
     * @param mover The allegiance of the unit moving between the cities
     * 
     * @pre There is a border (not NA=0) between the two cities
     */
    void increaseBorderLimit(const City* lhs, const City* rhs, const CityType& mover, const int& amount=1) {
        border_limit[lhs->getID()][rhs->getID()][mover] += amount;
        border_limit[rhs->getID()][lhs->getID()][mover] += amount;
    }

    /**
     * @brief Resets all border limits to 0 at the end of a season
     * 
     */
    void resetBorderLimits(){
        for (auto& row : border_limit){
            for (auto& col : row){
                for (auto& mover : col)
                    mover = 0;
            }
        }
    }

    /**
     * @brief Returns a reference to the hashmap of cities
     * 
     * @return const unordered_map<string, City*>& The city hashmap reference
     */
    const unordered_map<string, City*>& getCities() const{
        return cities;
    }

    /**
     * @brief Returns a reference to the hashmap of countries
     * 
     * @return const unordered_map<string, Country*>& The country hashmap reference
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
    void print() const;

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