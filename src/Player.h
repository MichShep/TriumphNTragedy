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

    bool at_war=false;

    size_t card_size; /**< Hand size of the player they must discard to at the end of government*/

    size_t factory_cost=0; /**< The cost to upgrade the industry*/

    size_t max_production=0; /**< Max production level of the player for the current production phase*/

    int current_production=0; /**< The current production left for the pleyer for the production phase */

    int industry_raised=0; /**< The number of times the player has raised their industry for the government phase */

    int units_upgraded=0; /**< Count for the number of units upgraded in the current production phase */

    int units_built=0; /**< Count for the number of units built (cadres added) in the current production phase*/

    size_t total_units=0; /**< Current number of units the player has on the board (number in play) */

    vector<Unit*> units; /**< Masterlist of all units the player controls*/

    AchievedTechnology* achieved_tech[25]; /**< List of all technologies that the player has discovered*/

    int technology_count = 0;

    int secret_count = 0;

    unordered_map<string, City*> controlled_cities; /**< Masterlist of all cites the player controls*/

    DowState ussr_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState west_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState axis_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState usa_dow=PEACE; /**< Holds the diplomacy state of the DOW with USA (only for the WEST really)*/

    string capital=""; /**< The capital city of the player (either London, Berlin, or Moscow)*/

    //&Command
    Season command_season;

    char command_priority;

    int command_value=-1;

    int emergency_command;

    bool used_emergency = false;

    //&Hands
    vector<ActionCard*> action_hand; /**< Hand of all action cards (used in command and government)*/

    vector<InvestmentCard*> invest_hand; /**< Hand of all investment cards*/

    vector<PeaceChit> peace_dividends; /**< List of all peace chits earned*/

    //&Stats
    size_t battles_won[3]; /**< Allies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t battles_lost[3]; /**<A llies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t cards_spent; /**< Number of cards the player has spent this game*/

    size_t cities_controlled; /**< Number of cities the player controls*/
public:
    int unit_counts[7][7] = {{0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}}; /**< An array of the count of how many units on the board this player has made*/
    
    bool passed = false; /**< Flag for if the player has passed int he current phase and forfits any future turns in the phase */

    ActionPhase current_phase = OBSERVING;
    pair<City*, Unit*> moving_unit = {nullptr, nullptr};

    //& Movement
    vector<City*> movement_memo;

    //& Graphics things
    App* app; /**< Container for the attributes of the player's window/screen and renderer*/

    Spritesheet* sprite_sheet; /**< The general spritesheet for the player's renderer */

    Spritesheet* map_sprite; /**< The spirte of the map for the player's renderer */

    Spritesheet* message_animation_sheets; /**< The spirte of the map for the player's renderer */

    Spritesheet* units_sprite_z1; /**< The sprite sheet for units at zoom 1 (the broadest) */

    Spritesheet* units_sprite_z3; /**< The sprite sheet for the units at zoom 3 (the closest) */

    Spritesheet* controller_button_sprites; /**< The sprite sheet for the units at zoom 3 (the closest) */

    int action_card_start=0; /**< Which action card to start displaying on the main home screen*/
    int invest_card_start=0; /**< Which invest card to start displaying on the main home screen*/
    int tech_card_start=0; /**< Which discovered tech card to start displaying on the main home screen*/

    int zoom = 1; /**< The current zoom level (1,2,3) of the player's screen*/

    int bought_action = 0; /**< The current number of action cards the player intends to buy*/
    int bought_invest = 0; /**< The current number of invest cards the player intends to buy*/

    bool board_change=true; /**< Boolen to track wether the player's board/view has changed and needs to be redrawn*/

    //TODO change to false
    bool show_action = false; /**< Flag to track if the action hand should be expanded to show all cards*/
    bool show_invest = false; /**< Flag to track if the invest hand should be expanded to show all cards*/
    bool show_tech = false;
    bool show_stat = false;

    bool show_west = false; /**< Flag to track if the information of the West Player should be shown */
    bool show_axis = false; /**< Flag to track if the information of the Axis Player should be shown */
    bool show_ussr = false; /**< Flag to track if the information of the USSR Player should be shown */

    int start_tech = 0;
    int tech_view = 0;
    int action_view = 0;
    int invest_view = 0;
    int stat_view = 0;
    
    double cursor_x = 0;  /**< The current x coord of the player's cursor on the screen*/
    double cursor_y = 0;  /**< The current y coord of the player's cursor on the screen*/

    double wheel_x = 0; /**< The x-coord of a unit circle for the selection wheel */
    double wheel_y = 0; /**< The y-coord of a unit circle for the selection wheel */
    double popped_option[3] = {-2, -2, -2};

    CityType allegiance_viewing = NEUTRAL;  /**< The allegiance of the unit being view or in focus*/
    pair<City*, Unit*> selected_unit = {nullptr, nullptr}; /**< The unit thats under focus and all actions pertaining to*/

    City* closest_map_city = nullptr; /**< The city that is closest to the player's cursor (updated when cursor stops moving) */

    City* selecting_city = nullptr; /**< Pointer to the city that has been selected to add a unit */
    bool unit_available[7]= {false, false, false, false, false, false, false}; /**< Array that corresponds to the units to hold flags if the unit is buildable in the current `building_city`*/

    Widget widget = MAP; /**< Holds which current widget the player is on */

    bool d_up_held = false; /**< Flag to indicate if the D-PAD Up button is being held by the player */
    bool d_down_held = false; /**< Flag to indicate if the D-PAD Down button is being held by the player */
    bool d_left_held = false; /**< Flag to indicate if the D-PAD Left button is being held by the player */
    bool d_right_held = false; /**< Flag to indicate if the D-PAD Right button is being held by the player */
    tick_t last_widget = 0; /**< Time to indicate when the player last changed widgets to pace UI change */

    InvestmentCard* command_fake = nullptr;
    ActionCard* command_card = nullptr;


    int popped_action_card_index = -1; /**< The index into the action hand of the action card the player has currently selected */
    ActionCard* popped_action_card = nullptr; /**< Pointer to the action card the player has currently selected in their action hand (nullptr if none selected) */
    City* popped_left_country = nullptr; /**< Pointer to the capital of the country on the left hand side of the card (used for drawing) */
    bool show_left_country = false; /**< Flag to indicate if the capital of the left side country should be drawn */
    City* popped_right_country = nullptr; /**< Pointer to the capital of the country on the right hand side of the card (used for drawing) */
    bool show_right_country = false; /**< Flag to indicate if the capital of the left side country should be drawn */
    Country* selected_country = nullptr; /**< Pointer to the country the player has currently selected for card actions (nullptr if none selected) */

    int popped_invest_card_index = -1; /**< The index into the investment hand of the investment card the player has currently selected */
    InvestmentCard* popped_invest_card = nullptr;
    vector<InvestmentCard*> selected_invest_cards;
    Tech* selected_tech1 = nullptr;
    InvestmentCard* selected_tech1_card = nullptr;
    Tech* selected_tech2 = nullptr; 
    InvestmentCard* selected_tech2_card = nullptr;
    bool tech_select_flip = true;

    int popped_tech_index = -1;
    Tech* popped_tech = nullptr;

    tick_t peak_ticks[3] = {0, 0, 0};
    pair<City*, Unit*> peaked_unit = {nullptr, nullptr};
    tick_t unit_peak_tick;

    tick_t x_held_tick = 0; /**< Tick of when the player most recently pressed down on the X-Button (0 if not held) */
    tick_t y_held_tick = 0; /**< Tick of when the player most recently pressed down on the Y-Button (0 if not held) */
    tick_t a_held_tick = 0; /**< Tick of when the player most recently pressed down on the A-Button (0 if not held) */
    tick_t b_held_tick = 0; /**< Tick of when the player most recently pressed down on the B-Button (0 if not held) */

    bool y_resolved = true; /**< Flag for if the Y-Button animation has been resolved */
    tick_t right_stick_y_tick = 0; /**< Tick of when the player most moved the right joystick along the y axis */
    tick_t right_stick_x_tick = 0; /**< Tick of when the player most moved the right joystick along the x axis */

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

        tech_view = allegiance;
        invest_view = allegiance;
        action_view = allegiance;
        stat_view = allegiance;

        for (auto& d : achieved_tech)
            d = nullptr;
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
     * @brief Add a unit to the master list of units and update the unit counts of the player
     * 
     * @param unit Pointer to the unit being created 
     */
    void add(Unit* unit){
        units[unit->id] = unit;
        total_units++;
        unit_counts[unit->nationality][unit->unit_type]++;
    }

    /**
     * @brief Removes a unit from the master list and updates the unit count of the player
     * 
     * @param unit Pointer to the unit that will be removed
     * @pre The @p unit is in the masterlist
     */
    void remove(Unit* unit){
        units[unit->id] = nullptr;
        total_units--;
        unit_counts[unit->nationality][unit->unit_type]--;
    }

    /**
     * @brief Iterates through the units and if they were marked as upgraded, increases the combat value and resets the upgrade flag
     * 
     */
    void upgradeUnits(){
        for (auto& unit : units){
            if (unit != nullptr && unit->upgrading){
                unit->upgrading = false;
                unit->combat_value++;
            }
        }
    }

    /**
     * @brief Gets the next empty ID in the unit master list to give to a new unit
     * 
     * @return size_t 
     */
    size_t getNextID() const{
        for (size_t i = 0; i < units.size(); i++){
            if (units[i] == nullptr)
                return i;
        }

        return -1;
    }

    bool canIncreaseIND() const{
        int sum = 0;
        for (const auto& card : selected_invest_cards)
            sum += card->amount;

        return sum >= factory_cost && industry_raised < 2;
    }

    inline void raiseIND(){
        industry++;
        industry_raised++;
    }

    inline void lowerIND(){
        industry--;
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
        case NEUTRAL:
            return true;
            break;
        case WATER:
            return true;
            break;
        
        default:
            return false;
            break;
        }
    }

    //& Button Things

    inline bool XHeld(const tick_t& ticks, const tick_t timer){
        return pastWait(x_held_tick, ticks, timer) && !a_held_tick && !y_held_tick && !b_held_tick;
    }

    inline bool YHeld(const tick_t& ticks, const tick_t timer){
        return pastWait(y_held_tick, ticks, timer) && !a_held_tick && !x_held_tick && !b_held_tick;
    }

    inline bool AHeld(const tick_t& ticks, const tick_t timer){
        return pastWait(a_held_tick, ticks, timer) && !x_held_tick && !y_held_tick && !b_held_tick;
    }

    inline bool BHeld(const tick_t& ticks, const tick_t timer){
        return pastWait(b_held_tick, ticks, timer) && !a_held_tick && !y_held_tick && !x_held_tick;
    }

    inline bool XPressed(){
        return x_held_tick;
    }

    inline bool YPressed(){
        return y_held_tick;
    }

    inline bool APressed(){
        return a_held_tick;
    }

    inline bool BPressed(){
        return b_held_tick;
    }

    inline bool multiHeld(const bool x, const bool y, const bool a, const bool b, const tick_t& ticks, const tick_t timer){
        return (x==pastWait(x_held_tick, ticks, timer)) && (y==pastWait(y_held_tick, ticks, timer)) && (a==pastWait(a_held_tick, ticks, timer)) && (b==pastWait(b_held_tick, ticks, timer));
    }

    inline void resetButtons(){
        a_held_tick = 0;
        b_held_tick = 0;
        x_held_tick = 0;
        y_held_tick = 0;
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

    void remove(const ActionCard* action_card){
        action_hand.erase(std::find(action_hand.begin(), action_hand.end(), action_card));
    }

    void remove(const InvestmentCard* invest_card){
        invest_hand.erase(std::find(invest_hand.begin(), invest_hand.end(), invest_card));
    }

    inline const bool hasSelected(const InvestmentCard* card) const{
        return std::find(selected_invest_cards.begin(), selected_invest_cards.end(), card) != selected_invest_cards.end();
    }

    inline void deselect(const InvestmentCard* card){
        selected_invest_cards.erase(std::find(selected_invest_cards.begin(), selected_invest_cards.end(), card));
    }

    inline bool hasTech(const Tech* tech) const{
        return achieved_tech[*tech] != nullptr;
    }

    void setCommand(ActionCard* selected_card, const Season season){
        command_card = selected_card;
        command_season = selected_card->season;
        command_priority = selected_card->command_priority;
        command_value = selected_card->command_value;

        if (season != command_season){
            command_value = emergency_command;
            used_emergency = true;
        }
    }

    void setCommand(InvestmentCard* selected_card){
        command_fake = selected_card;
        command_value = 0;
    }

    void resetCommand(){
        command_value = -1;
        command_card = nullptr;
        command_fake = nullptr;
    }

    void useCommand(){
        command_value--;
    }

    inline void achieveTech(const Tech& tech){
        achieved_tech[tech] = new AchievedTechnology("TODO ADD NAME", tech, false);
        technology_count++;
        setTechSecret(tech);
        if (tech == ATOMIC_FOUR)
            atomic = true;
    }

    void updatePoppedInvestCard(){
        if (getInvestSize() > 0){
            popped_invest_card_index = loopVal(popped_invest_card_index, 0,  getInvestSize()-1);
            popped_invest_card = getInvestCard(popped_invest_card_index);
        }
        else{
            popped_invest_card_index = -1;
            popped_invest_card = nullptr;
        }

        selected_tech1 = nullptr;
        selected_tech1_card = nullptr;
        selected_tech2 = nullptr;
        selected_tech2_card = nullptr;
    }

    void updatePoppedActionCard(const unordered_map<string, Country*> map){
        if (getActionSize() > 0){
            popped_action_card_index = loopVal(popped_action_card_index, 0,  getInvestSize()-1);
            popped_action_card = getActionCard(popped_action_card_index);
            if (popped_action_card->type == DIPLOMACY){
                popped_left_country = map.at(popped_action_card->countryA)->capital;
                popped_right_country = map.at(popped_action_card->countryB)->capital;
            }
        }
        else{
            popped_action_card_index = -1;
            popped_action_card = nullptr;
            popped_left_country = nullptr;
            popped_right_country = nullptr;
        }
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
    int getTechSize() const{
        return technology_count;
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
        return action_hand.size() + invest_hand.size() + secret_count;
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

    DowState getDoW(const CityType rival) const{
        switch (rival){
            case WEST:
                return west_dow;
                break;
            case AXIS:
                return axis_dow;
                break;
            case USSR:
                return ussr_dow;
                break;
            default:
                break;
        }

        std::cerr << "Unkown rival DoW requested" << endl;
        exit(1);

        return PEACE;
    }

    void setDoW(const CityType& rival, const DowState rival_state){
        switch (rival){
            case WEST:
                west_dow = rival_state;
                break;
            case AXIS:
                axis_dow = rival_state;
                break;
            case USSR:
                ussr_dow = rival_state;
                break;
            default:
                break;
        }


    }

    /**
     * @brief Get the last year the player was peaceful
     * 
     * @return size_t the year at peace
     */
    size_t getYearAtPeace() const{
        return year_at_peace;
    }

    bool usedEmergency() const{
        return used_emergency;
    }

    void setEmergency(){
        used_emergency = true;
    }

    /**
     * @brief Get the capital of the player that the traderoutes need to be traced to
     * 
     * @return string Name of the capital
     */
    string getCapital() const{
        return capital;
    }

    int getCommandNumber() const{
        return command_value;
    }

    void setCommandNumber(const int& new_num){
        command_value = new_num;
    }

    char getCommandLetter() const{
        return command_priority;
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
     * @param ds The new state of the WEST DoW
     */
    void setWestDow(const DowState ds) {
        west_dow = ds;
    }

    /**
     * @brief Set the AXIS DoW state
     * 
     * @param ds The new state of the AXIS DoW
     */
    void setAxisDow(const DowState ds) {
        axis_dow = ds;
    }

    /**
     * @brief Set the USA DoW state
     * 
     * @param ds The new state of the USA DoW
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
     * @return Technology& The tech at the index
     */
    AchievedTechnology* getTech(const size_t indx) const{
        return achieved_tech[indx];
    }

    const int getSecretCount() const{
        return secret_count;
    }

    void setTechSecret(const Tech indx){
        achieved_tech[indx]->secret = true;
        secret_count++;
    }

    bool setTechPublic(const Tech indx){
        if (achieved_tech[indx]->secret){
            achieved_tech[indx]->secret = false;
            secret_count--;
            return true;
        }
        return false;
    }

    void setMovingUnit(){
        moving_unit = selected_unit;
    }

    void resetMovingUnit(){
        moving_unit = {nullptr, nullptr};
    }

    inline void makeAtomic(){
        atomic = true;
    }

    inline bool canPeakAction(){
        return popped_invest_card != nullptr && selected_tech1 != nullptr && *selected_tech1 == CODE_BREAKER && action_view != allegiance;
    }

    void peakAction(const tick_t& tick){
        peak_ticks[action_view] = tick;
        remove(popped_invest_card);
        updatePoppedInvestCard();
    }

    inline bool canPeakUnit(){
        return selected_unit.first != nullptr && selected_tech1 != nullptr && *selected_tech1 == AGENT && selected_unit.second->allegiance != allegiance;
    }

    void peakUnit(const tick_t& tick){
        unit_peak_tick = tick;
        peaked_unit = selected_unit;
        remove(popped_invest_card);
        updatePoppedInvestCard();
    }

    void resetUnits(){
        for (auto& unit : units){
            unit->moved = false;
        }
    }

    

    //& Production
    /**
     * @brief Get the min production of the player min(pop, res, ind). If not at war then ignore res
     * 
     * @return size_t The production of the player for the phase
     */
    size_t calculateProduction() {
        max_production = (atWar()? std::min(population, std::min(resources, industry)):  std::min(population, industry));

        return current_production=max_production; //At war : not at war 
    }

    /**
     * @brief Gets the Current production of the player for this production phase
     * 
     * @return const size_t The current production (or how much they have left to spend)
     */
    const int getCurrentProduction() const{
        return current_production-units_built-units_upgraded-bought_action-bought_invest;
    }

    /**
     * @brief Get the max production of the player for this production phase (is calculated in )
     * @see calculateProduction
     * 
     * @return const size_t The max production of the player for this production phase
     */
    const size_t getMaxProduction() const{
        return max_production;
    }

    void spendProduction(const ProductionAction p_act, const bool undo=false){ //BUY_AC, BUY_IC, UNIT_UP, CADRE}
        int* target = nullptr;

        switch (p_act) {
            case BUY_AC:
                target = &bought_action;
                break;
            case BUY_IC:
                target = &bought_invest;
                break;
            case UNIT_UP:
                target = &units_upgraded;
                break;
            case CADRE:
                target = &units_built;
                break;
            default:
                return;
        }

        *target += (undo) ? -1 : 1;
    }   

    /**
     * @brief Gets if the player is at war with any other player
     * 
     * @return true Is at war with another player
     * @return false Is not at war (not neccisarily peaceful if the VoN)
     */
    bool atWar() const{
        return at_war;
    }

    void setWartime(){
        at_war = true;
    }

    bool atWar(const CityType rival) const{
        switch (rival){
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
                break;
        }

        return false;    
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
     * @brief Returns the name of the player
     * 
     * @return const string& Name of the Player
     */
    const string& getName() const{
        return name;
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
        /*for (Unit* unit: units){
            if (unit != nullptr) delete unit;
        }*/
        units.clear();
        controlled_cities.clear();

        name = "DELETED";
    }

    bool operator==(const int& city_type) const{
        return allegiance == city_type;
    }

    bool operator!=(const int& city_type) const{
        return allegiance != city_type;
    }

    bool operator==(const CityType& city_type) const{
        return allegiance == city_type;
    }

    bool operator!=(const CityType& city_type) const{
        return allegiance != city_type;
    }

    bool operator==(const Player* player) const{
        return this == player;
    }

    bool operator==(const Player& player) const{
        return this == &player;
    }

    bool operator!=(const Player* player) const{
        return this != player;
    }

    bool operator!=(const Player& player) const{
        return this != &player;
    }

    operator int() const{
        return allegiance;
    }

    operator CityType() const{
        return allegiance;
    }
};
