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

    size_t action_card_start=0;

    size_t invest_card_start=0;

    //&Great Power attributes
    CityType allegiance; /**< Which power the player is controlling (West, Axis, USSR)*/

    size_t population; /**< Total POP of the player*/

    size_t resources; /**< Total number of resources player has*/

    size_t industry=0; /**< Total number of industry the player has*/

    size_t card_size; /**< Hand size of the player they must discard to at the end of government*/

    size_t factory_cost=0; /**< The cost to upgrade the industry*/

    vector<Unit*> units; /**< Masterlist of all units the player controls*/

    unordered_map<string, City*> controlled_cities; /**< Masterlist of all cites the player controls*/

    DowState ussr_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState west_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState axis_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState usa_dow; /**< Holds the diplomacy state of the DOW with USSR*/

    //&Hands
    vector<ActionCard*> action_hand; /**< Hand of all action cards (used in command and government)*/

    vector<InvestmentCard*> invest_hand; /**< Hand of all investment cards*/

    vector<PeaceChit> peace_dividends;

    //&Stats
    size_t battles_won[3]; /**< Allies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t battles_lost[3]; /**<A llies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t total_units[8]; /**< Each index is a specific unit and how much*/

    size_t cards_spent; /**< Number of cards the player has spent this game*/

    size_t cities_controlled; /**< Number of cities the player controls*/
public:
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
    Player(const string name, const CityType allegiance, const size_t population, const size_t resource, const size_t industry, const size_t card_size, const size_t factory_cost, const DowState ussr_treaty, DowState axis_treaty, DowState allies_treaty, const DowState usa_treaty)
        : name(name), allegiance(allegiance), population(population), resources(resource), industry(industry), card_size(card_size), factory_cost(factory_cost), ussr_dow(ussr_treaty), west_dow(allies_treaty), axis_dow(axis_treaty), usa_dow(usa_treaty){

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
    void add(City* city){
        if (controlled_cities.find(city->name) ==  controlled_cities.end()){ //not found
            controlled_cities[city->name] = city;
        }
    }

    size_t getNumBlockaded(){
        size_t sum = 0;
        for (auto& city : controlled_cities){
            sum += city.second->blockcade;
        }

        return sum;
    }

    bool isEnemy(CityType& allegiance){
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
    void deal(ActionCard* aC){
        action_hand.push_back(aC);
    }

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

    size_t getActionSize() const{
        return action_hand.size();
    }

    size_t getInvestSize() const{
        return invest_hand.size();
    }

    /**
     * @brief Get the number of resources owned
     * 
     * @return size_t Number of resources
     */
    size_t getResource() const{
        return resources;
    }

    size_t getIndustry() const{
        return industry;
    }

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
        return action_hand.size() + invest_hand.size();
    }

    DowState getUssrDow() const{
        return ussr_dow;
    }

    DowState getWestDow() const{
        return west_dow;
    }

    DowState getAxisDow() const{
        return axis_dow;
    }

    DowState getUsaDow() const{
        return usa_dow;
    }

    size_t getYearAtPeace() const{
        return year_at_peace;
    }


    void setUssrDow(const DowState ds) {
        ussr_dow = ds;
    }

    void setWestDow(const DowState ds) {
        west_dow = ds;
    }

    void setAxisDow(const DowState ds) {
        axis_dow = ds;
    }

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

    ActionCard* getActionCard(const size_t indx) const{
        return action_hand[indx];
    }

    InvestmentCard* getInvestCard(const size_t indx) const{
        return invest_hand[indx];
    }



    /**
     * @brief Get the min production of the player min(pop, res, ind). If not at war then dont look at res
     * 
     * @return size_t The production of the player for the phase
     */
    size_t getProduction() const{
        return (atWar()? std::min(population, std::min(resources, industry)):  std::min(population, industry)); //At war : not at war 
    }


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

    void givePeaceDividend(const PeaceChit chit){
        peace_dividends.push_back(chit);
    }

    PeaceChit& getPeaceDividend(const size_t i){
        return peace_dividends[i];
    }

    size_t getPeaceDividendSize() const{
        return peace_dividends.size();
    }

    /**
     * @brief Prints out all stats of the player
     * 
     */
    void print() const;
};
