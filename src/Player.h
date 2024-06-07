#pragma once

#include "Map.h"
/**
 * @brief Represents Great Power and Player Stats
 * 
 */
class Player{
private:
    //&Player attributes
    string name; /**< The name of the player*/

    size_t victory_points=0; /**< Current number of VP*/

    size_t rival_capitals=0; /**< Number of enemy capitals the player has captured*/

    bool atomic=false; /**< If the player has all 4 stages of atomics*/

    size_t year_at_peace; /**< Is the last year the player was at peace (used for peace chits)*/

    //&Great Power attributes
    CityType allegiance; /**< Which power the player is controlling (West, Axis, USSR)*/

    size_t population; /**< Total POP of the player*/

    size_t resources; /**< Total number of resources player has*/

    size_t industry=0; /**< Total number of industry the player has*/

    size_t card_size; /**< Hand size of the player they must discard to at the end of government*/

    size_t factory_cost=0; /**< The cost to upgrade the industry*/

    size_t max_production=0;

    size_t current_production=0;

    vector<Unit*> units; /**< Masterlist of all units the player controls*/

    vector<Technology> achieved_tech; /**< List of all technologies that the player has discovered*/

    unordered_map<string, City*> controlled_cities; /**< Masterlist of all cites the player controls*/

    DowState ussr_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState west_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState axis_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState usa_dow=PEACE; /**< Holds the diplomacy state of the DOW with USA (only for the WEST really)*/

    string capital=""; /**< The capital city of the player (either London, Berlin, or Moscow)*/

    //&Hands
    vector<ActionCard*> action_hand; /**< Hand of all action cards (used in command and government)*/

    vector<InvestmentCard*> invest_hand; /**< Hand of all investment cards*/

    vector<PeaceChit> peace_dividends; /**< List of all peace chits earned*/

    //&Stats
    size_t battles_won[3]; /**< Allies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t battles_lost[3]; /**<A llies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t total_units[8]; /**< Each index is a specific unit and how much*/

    size_t cards_spent; /**< Number of cards the player has spent this game*/

    size_t cities_controlled; /**< Number of cities the player controls*/
public:
    //& Graphics things
    int action_card_start=0; /**< Which action card to start displaying on the main home screen*/
    int invest_card_start=0; /**< Which invest card to start displaying on the main home screen*/
    int tech_card_start=0; /**< Which discovered tech card to start displaying on the main home screen*/

    BoardState state = HOME_BOARD; /**< The current board to show the player*/

    int mapX = 0; /**< The x-coord offset of the production map of the player to show*/
    int mapY = 0; /**< The y-coord offset of the production map of the player to show*/

    size_t bought_action = 0;
    size_t bought_invest = 0;

    int current_home_button=0;

    bool board_change=true;

    bool show_action = false;
    bool show_invest = false;
    
    bool flip=0;

    double cursor_x = 1512/2;
    double cursor_y = 982/2;

    City* closest_map_city = nullptr;

    /**
     * @brief Construct a blank default Player object
     * 
     */
    Player(){
        name = "Default"; 
    }

    /**
     * @brief Constructs the player based on the allegiance
     * 
     * @param name Name of player
     * @param allegiance Which power they'll play
     */
    Player (const string name, const CityType allegiance): name(name), allegiance(allegiance){
        switch (allegiance){
        case (WEST):
            westInit();
            break;
        case (AXIS):
            axisInit();
            break;
        case (USSR):
            ussrInit();
            break;
        default:
            printf("Unkown allegiance %d!\n", (int)allegiance);
            exit(1);
            break;
        }

        year_at_peace = START_YEAR;
    }

    /**
     * @brief Constructs a new player
     * 
     * @param name Name of player
     * @param allegiance Which power
     * @param population Starting population (pop)
     * @param resource Starting resources (red)
     * @param industry Starting industry (ind)
     * @param card_size Starting max hand size
     * @param factory_cost Starting cost to upgrade industry
     * @param ussr_dow Inital ties with USSR
     * @param axis_dow Inital ties with AXIS
     * @param allies_dow Inital ties with WEST
     * @param usa_dow Inital USA involvement
     */
    Player(const string name, const CityType allegiance, const size_t population, const size_t resource, const size_t industry, const size_t card_size, const size_t factory_cost, const DowState ussr_treaty, DowState axis_treaty, DowState allies_treaty, const DowState usa_treaty, const string capital)
        : name(name), allegiance(allegiance), population(population), resources(resource), industry(industry), card_size(card_size), factory_cost(factory_cost), ussr_dow(ussr_treaty), west_dow(allies_treaty), axis_dow(axis_treaty), usa_dow(usa_treaty), capital(capital){

    }

    //& Initalizers 
    /**
     * @brief Setup West player on default values in rules
     * 
     */
    void westInit();
    
    /**
     * @brief Setup Axis player on default values in rules
     * 
     */
    void axisInit();

    /**
     * @brief Setup USSR player on default values in rules
     * 
     */
    void ussrInit();

    //& Control things
    /**
     * @brief Adds a city to the current control list of the player
     * 
     * @param city The city to be controlled by the player
     */
    void add(City* city){
        if (controlled_cities.find(city->name) ==  controlled_cities.end()){ //not found
            controlled_cities[city->name] = city;
        }
    }

    /**
     * @brief Get the begin iterator of the controlled cities hashmap to iteratre through
     * 
     * @return unordered_map<string,City*>::const_iterator 
     */
    unordered_map<string,City*>::const_iterator getControlledCitiesBegin() const{
        return controlled_cities.begin();
    };

    /**
     * @brief Get the end iterator of the controlled cities hashmap to iteratre through
     * 
     * @return unordered_map<string,City*>::const_iterator 
     */
    unordered_map<string,City*>::const_iterator getControlledCitiesEnd() const{
        return controlled_cities.end();
    };

    /**
     * @brief Get the number of controlled cities 
     * 
     * @return size_t Number of controlled cities
     */
    size_t getControlledSize() const{
        return controlled_cities.size();
    }

    /**
     * @brief Get the number of cities controlled that are blockaded 
     * 
     * @return size_t Number of blockaded cities
     */
    size_t getNumBlockaded(){
        size_t sum = 0;
        for (auto& city : controlled_cities){
            sum += (city.second->blockcade || city.second->med_blockcade);
        }

        return sum;
    }

    /**
     * @brief See if the player allegiance provided is an enemy of the player (has a DOW)
     * 
     * @param allegiance The allegiance to check if an enemy
     * @return true Is an enemy
     * @return false Is not an enemy (at peace)
     */
    bool isEnemy(const CityType& allegiance) const{
        switch (allegiance){
        case WEST:
            return west_dow != PEACE;
            break;
        case AXIS:
            return axis_dow != PEACE;
            break;
        case USSR:
            return ussr_dow != PEACE;
            break;
        
        default:
            return false;
            break;
        }
    }
    
    //& Card Things
    /**
     * @brief Gives the player the provided card into the corresponding hand
     * 
     * @param aC The action card to add into the action hand
     */
    void deal(ActionCard* aC){
        action_hand.push_back(aC);
    }

    /**
     * @brief Gives the player the provided card into the corresponding hand
     * 
     * @param iC The invest card to add into the action hand
     */
    void deal(InvestmentCard* iC){
        invest_hand.push_back(iC);
    }

    //& Getters and Setters
    /**
     * @brief Gets which power the player is
     * 
     * @return CityType The Power the player is
     */
    CityType getAllegiance() const{
        return allegiance;
    }

    /**
     * @brief Get how much population the player controls
     * 
     * @return size_t The player's population
     */
    size_t getPopulation() const{
        return population;
    }

    /**
     * @brief Get the number of action cards the player has
     * 
     * @return size_t number of action cards
     */
    size_t getActionSize() const{
        return action_hand.size();
    }

    /**
     * @brief Get the number of invest cards the player has
     * 
     * @return size_t number of invest cards
     */
    size_t getInvestSize() const{
        return invest_hand.size();
    }

    /**
     * @brief Get the number of achieved tech the player has
     * 
     * @return size_t number of achieved tech
     */
    size_t getTechSize() const{
        return achieved_tech.size();
    }

    /**
     * @brief Get the number of resources owned
     * 
     * @return size_t Number of resources
     */
    size_t getResource() const{
        return resources;
    }

    /**
     * @brief Get the current industry (ind) of the player
     * 
     * @return size_t The current industry of player
     */
    size_t getIndustry() const{
        return industry;
    }

    /**
     * @brief Get the cost to add 1 to the current industry 
     * 
     * @return size_t the cost of upgrading industry
     */
    size_t getIndustryCost() const{
        return factory_cost;
    }

    /**
     * @brief Set the players population
     * 
     * @param pop The new population
     */
    void setPopulation(const size_t pop){
        population = pop;
    }

    /**
     * @brief Set the number of resources
     * 
     * @param res The new resource count
     */
    void setResource(const size_t res){
        resources = res;
    }

    /**
     * @brief Gets the combined hand size of action and investment cards
     * 
     * @return size_t 
     */
    size_t getHandSize() const{
        int num_secret=0;
        for(const auto& t : achieved_tech)
            num_secret += t.secret;
        return action_hand.size() + invest_hand.size() + num_secret;
    }

    /**
     * @brief Get the USSR Declaration of War 
     * 
     * @return DowState The state of the DOW (peacful, victim, or declarer)
     */
    DowState getUssrDow() const{
        return ussr_dow;
    }

    /**
     * @brief Get the WEST Declaration of War 
     * 
     * @return DowState The state of the DOW (peacful, victim, or declarer)
     */
    DowState getWestDow() const{
        return west_dow;
    }

    /**
     * @brief Get the AXIS Declaration of War 
     * 
     * @return DowState The state of the DOW (peacful, victim, or declarer)
     */
    DowState getAxisDow() const{
        return axis_dow;
    }

    /**
     * @brief Get the USA Declaration of War which represents the 
     * 
     * @return DowState The state of the DOW (peacful, victim, or declarer)
     */
    DowState getUsaDow() const{
        return usa_dow;
    }

    /**
     * @brief Get the last year the player was peaceful
     * 
     * @return size_t the year at peace
     */
    size_t getYearAtPeace() const{
        return year_at_peace;
    }

    /**
     * @brief Get the capital of the player that the traderoutes need to be traced to
     * 
     * @return string Name of the capital
     */
    string getCapital() const{
        return capital;
    }

    /**
     * @brief Set the USSR DoW state
     * 
     * @param ds The new state of the USSR DoW
     */
    void setUssrDow(const DowState ds) {
        ussr_dow = ds;
    }

    /**
     * @brief Set the WEST DoW state
     * 
     * @param ds The new state of the USSR DoW
     */
    void setWestDow(const DowState ds) {
        west_dow = ds;
    }

    /**
     * @brief Set the AXIS DoW state
     * 
     * @param ds The new state of the USSR DoW
     */
    void setAxisDow(const DowState ds) {
        axis_dow = ds;
    }

    /**
     * @brief Set the USA DoW state
     * 
     * @param ds The new state of the USSR DoW
     */
    void setUsaDow(const DowState ds) {
        usa_dow = ds;
    }

    /**
     * @brief gets the player's card limit
     * 
     * @return size_t The card limit
     */
    size_t getMaxCard() const{
        return card_size;
    }

    /**
     * @brief Get the Action Card at the specific index
     * 
     * @param indx The index of the wanted card
     * @return ActionCard* The pointer of the desired card
     */
    ActionCard* getActionCard(const size_t indx) const{
        return action_hand[indx];
    }

    /**
     * @brief Get the Invest Card at the specific index
     * 
     * @param indx The index of the wanted card
     * @return InvestmentCard* The pointer of the desired card
     */
    InvestmentCard* getInvestCard(const size_t indx) const{
        return invest_hand[indx];
    }

    /**
     * @brief Get the acheived tech at the specific index
     * 
     * @param indx the desired index of the tech
     * @return const Technology& The tech at the index
     */
    const Technology& getTech(const size_t indx) const{
        return achieved_tech[indx];
    }

    /**
     * @brief Get the min production of the player min(pop, res, ind). If not at war then dont look at res
     * 
     * @return size_t The production of the player for the phase
     */
    size_t calculateProduction() {
        max_production = (atWar()? std::min(population, std::min(resources, industry)):  std::min(population, industry));

        return current_production=max_production; //At war : not at war 
    }

    const size_t getCurrentProduction() const{
        return current_production;
    }

    const size_t getMaxProduction() const{
        return max_production;
    }

    /**
     * @brief Gets if the player is at war with any other player
     * 
     * @return true Is at war with another player
     * @return false Is not at war (not neccisarily peaceful if the VoN)
     */
    bool atWar() const{
        return ussr_dow != PEACE || west_dow != PEACE || axis_dow != PEACE;
    }
    /**
     * @brief Get the current VP of player
     * 
     * @return size_t The victory points of the player
     */
    size_t getVP() const{
        return victory_points;
    }

    /**
     * @brief Gives the player a peace chit 
     * 
     * @param chit The chit to give the player
     */
    void givePeaceDividend(const PeaceChit chit){
        peace_dividends.push_back(chit);
    }

    /**
     * @brief Get the peace chit at the specific index
     * 
     * @param i The index of the peace chit
     * @return PeaceChit& Refrence to the peace chit
     */
    PeaceChit& getPeaceDividend(const size_t i){
        return peace_dividends[i];
    }

    /**
     * @brief Get the number of peace chits owned
     * 
     * @return size_t The number of peace chits
     */
    size_t getPeaceDividendSize() const{
        return peace_dividends.size();
    }

    /**
     * @brief Prints out all stats of the player
     * 
     */
    void print() const;

    /**
     * @brief Frees the memort allocated for the player
     * 
     */
    void freeMemory(){
        for (ActionCard* ac: action_hand){
            if (ac != nullptr) delete ac;
        }
        action_hand.clear();
        for (InvestmentCard* ac: invest_hand){
            if (ac != nullptr) delete ac;
        }
        invest_hand.clear();
        for (Unit* unit: units){
            if (unit != nullptr) delete unit;
        }
        units.clear();
        controlled_cities.clear();

        name = "DELETED";
    }
};
