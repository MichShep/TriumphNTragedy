#pragma once

#include "Map.h"


/**
 * @brief Represents Great Power and the Players graphical status
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

    bool at_war=false; /**< Flag set to if the player is currently at war with another rival (not including VoN's on neutral minors) */

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

    bool first_fires[CONVOY+1]= {false, false, false, false, false, false, false, false};

    int technology_count = 0; /**< The current number of technologies the player has discovered */

    int secret_count = 0; /**< The current number of  technologies the player has secret (not known to rivals) (contributes to the card limit)*/

    unordered_map<string, City*> controlled_cities; /**< Masterlist of all cites the player controls*/

    DowState ussr_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState west_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState axis_dow=PEACE; /**< Holds the diplomacy state of the DOW with USSR*/

    DowState usa_dow=PEACE; /**< Holds the diplomacy state of the DOW with USA (only for the WEST really)*/

    string capital=""; /**< The capital city of the player (either London, Berlin, or Moscow)*/

    //&Command
    Season command_season; /**< The season of the action card played for the action phase */

    char command_priority; /**< The 'priority' (letter) of the action card played for the action phase*/

    int command_value=-1; /**< The 'value' (number) of the action card played and dictates how many units can be moved in the movement phase (will be overwritten if emergency command is used) (is -1 if no action card was played)*/

    int emergency_command; /**< The number of movements the player can make when they use emergency command */

    bool used_emergency = false; /**< Flag used to indicate if the player used emergency command for the current action season */

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

    //& Action Phase
    ActionPhase combat_phase = OBSERVING; /**< The current phase the player is in for the action phase and dictates what actions they can do*/

    //&^ Movement
    vector<City*> movement_memo; /**< Memo of the player made city route for the unit to travel */
    pair<City*, Unit*> moving_unit = {nullptr, nullptr}; /**< The unit chosen by the player to move along the memo */

    //& Graphic Tools
    App* app; /**< Container for the attributes of the player's window/screen and renderer*/

    Spritesheet* sprite_sheet; /**< The general spritesheet for the player's renderer */

    Spritesheet* map_sprite; /**< The spirte of the map for the player's renderer */

    Spritesheet* message_animation_sheets; /**< The spirte of the map for the player's renderer */

    Spritesheet* units_sprite_z1; /**< The sprite sheet for units at zoom 1 (the broadest) */

    Spritesheet* units_sprite_z3; /**< The sprite sheet for the units at zoom 3 (the closest) */

    Spritesheet* controller_button_sprites; /**< The sprite sheet for the units at zoom 3 (the closest) */

    //& Graphic Status

    //&^ Widget Status
    Widget widget = MAP; /**< Holds which current widget the player is on */
    tick_t last_widget = 0; /**< Time to indicate when the player last changed widgets to pace UI change */

    //&^^ Action Hand Widget
    bool show_action = false; /**< Flag to track if the action hand should be expanded to show the cards*/
    int action_view; /**< Indicates which player to view their action hand */
    int action_card_start=0; /**< Which action card to start displaying on the main home screen*/
    int bought_action = 0; /**< The current number of action cards the player intends to buy*/

    //&^^ Invest Hand Widget
    bool show_invest = false; /**< Flag to track if the invest hand should be expanded to show the cards*/
    int invest_view;/**< Indicates which player to view their invest hand */
    int invest_card_start=0; /**< Which invest card to start displaying on the main home screen*/
    int bought_invest = 0; /**< The current number of invest cards the player intends to buy*/

    //&^^ Tech Widget
    bool show_tech = false;
    int tech_view; /**< Indicates which player to view their achieved tech */
    int tech_card_start=0; /**< Which discovered tech card to start displaying on the main home screen*/
    int start_tech = 0;

    //&^^ Stat Widget
    bool show_stat = false;
    int stat_view; /**< Indicates which player to view their stats */

    //&^^ Combat Widget
    bool show_combat = true;
    int popped_unit_index = 0;

    int zoom = 1; /**< The current zoom level (1,2,3) of the player's screen*/
    bool board_change=true; /**< Boolen to track wether the player's board/view has changed and needs to be redrawn*/

    //&^ Title Screen
    bool in_start=false;
    bool in_house=false;
    bool in_credits=false;
    
    //& Joystick Movements

    //&^ Cursor
    int cursor_speed = CURSOR_SPEED;
    double cursor_x = 0;  /**< The current x coord of the player's cursor on the screen*/
    double cursor_y = 0;  /**< The current y coord of the player's cursor on the screen*/

    //&^ Select Wheel
    double wheel_x = 0; /**< The x-coord of a unit circle for the selection wheel */
    double wheel_y = 0; /**< The y-coord of a unit circle for the selection wheel */
    double wheel_selection[3] = {-2, -2, -2}; /**< The coordinates of the closest selected option from the select wheel; [0] = which option (0...7), [1] = X-Coord, [2] = Y-Coord */

    tick_t right_stick_y_tick = 1; /**< Tick of when the player most moved the right joystick along the y axis */
    tick_t right_stick_x_tick = 1; /**< Tick of when the player most moved the right joystick along the x axis */
    int popped_hit_index = 0;
    Unit* popped_hit_unit = nullptr;

    //& Selected Things
    CityType allegiance_viewing = NEUTRAL;  /**< The allegiance of the unit being view or in focus*/
    pair<City*, Unit*> selected_unit = {nullptr, nullptr}; /**< The unit thats under focus and all actions pertaining to*/


    //&^ City Selecting Status
    City* closest_map_city = nullptr; /**< The city that is closest to the player's cursor (updated when cursor stops moving) */
    City* selecting_city = nullptr; /**< Pointer to the city that has been selected to add a unit */
    bool unit_available[7]= {false, false, false, false, false, false, false}; /**< Array that corresponds to the units to hold flags if the unit is buildable in the current `building_city`*/

    //&^ Card Select
    InvestmentCard* command_fake = nullptr;
    ActionCard* command_card = nullptr;

    //&^^ Selected Aciton Card
    int popped_action_card_index = -1; /**< The index into the action hand of the action card the player has currently selected */
    ActionCard* popped_action_card = nullptr; /**< Pointer to the action card the player has currently selected in their action hand (nullptr if none selected) */
    City* popped_left_country = nullptr; /**< Pointer to the capital of the country on the left hand side of the card (used for drawing) */
    bool show_left_country = false; /**< Flag to indicate if the capital of the left side country should be drawn */
    City* popped_right_country = nullptr; /**< Pointer to the capital of the country on the right hand side of the card (used for drawing) */
    bool show_right_country = false; /**< Flag to indicate if the capital of the left side country should be drawn */
    Country* selected_country = nullptr; /**< Pointer to the country the player has currently selected for card actions (nullptr if none selected) */

    //&^^ Selected Invest Card
    int popped_invest_card_index = -1; /**< The index into the investment hand of the investment card the player has currently selected */
    InvestmentCard* popped_invest_card = nullptr; /**< Pointer to the invest card the player has currently selected in their invest hand (nullptr if none selected) */
    vector<InvestmentCard*> selected_invest_cards; /**< Vector of pointers to all Invest Cards the player has selected to put toward raising Industry */
    Tech* selected_tech1 = nullptr; /**< The first tech of a card selected to be paired*/
    InvestmentCard* selected_tech1_card = nullptr; /**< The card of the first tech selected to be paired*/
    Tech* selected_tech2 = nullptr; /**< The second tech of a card selected to be paired*/
    InvestmentCard* selected_tech2_card = nullptr;  /**< The card of the second tech selected to be paired*/
    bool tech_select_flip = true; /**< Works as a two-state dictator for which tech should be replaces when a new one is selected */

    //&^^ Selected Tech
    int popped_tech_index = -1; /**< The index of the achieved tech the player has currently selected*/
    Tech* popped_tech = nullptr;/**< Pointer to the technology the player has currently selected in their tech widget (nullptr if none selected) */

    //&^^ Rival Unit Showing
    tick_t peak_ticks[3] = {0, 0, 0}; /**< The tick when the player started viewing a rivals hand (the rivals allegiance works as the index for the tick) (0 if not viewing)*/

    tick_t unit_peak_tick = 0; /** The tick when the player started viewing another rivals unit (0 if not veiwing any)*/
    pair<City*, Unit*> peaked_unit = {nullptr, nullptr}; /**< Pair to store which City has pointer to the Unit being viewed and which unit is being viewed */
    
    //& Buttons
    bool d_up_held = false; /**< Flag to indicate if the D-PAD Up button is being held by the player */
    bool d_down_held = false; /**< Flag to indicate if the D-PAD Down button is being held by the player */
    bool d_left_held = false; /**< Flag to indicate if the D-PAD Left button is being held by the player */
    bool d_right_held = false; /**< Flag to indicate if the D-PAD Right button is being held by the player */

    tick_t x_held_tick = 0; /**< Tick of when the player most recently pressed down on the X-Button (0 if not held) */
    tick_t y_held_tick = 0; /**< Tick of when the player most recently pressed down on the Y-Button (0 if not held) */
    tick_t a_held_tick = 0; /**< Tick of when the player most recently pressed down on the A-Button (0 if not held) */
    tick_t b_held_tick = 0; /**< Tick of when the player most recently pressed down on the B-Button (0 if not held) */

    bool y_resolved = true; /**< Flag for if the Y-Button animation has been resolved */

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
        delete unit;
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
     * @return size_t The next free ID to assign to a Unit
     */
    size_t getNextID() const{
        for (size_t i = 0; i < units.size(); i++){
            if (units[i] == nullptr)
                return i;
        }

        return -1;
    }

    /**
     * @brief Decider for if the player can increase their Industry (has enough factory selected and haven't done it twice this year and under 35)
     * 
     * @return true Player can increase their industry once more
     * @return false Player cannot increase their industry once more
     * @pre Assuming the player is in the correct season to do so
     */
    bool canIncreaseIND() const{
        int sum = 0;
        for (const auto& card : selected_invest_cards)
            sum += card->amount;

        return industry < 25 && sum >= factory_cost && industry_raised < 2;
    }

    /**
     * @brief Raise the industry by one and the count of industry raises
     * 
     */
    inline void raiseIND(){
        industry++;
        industry_raised++;
    }

    /**
     * @brief Lower the industry of the player by one
     * 
     * @post Industry is at least 0
     */
    inline void lowerIND(){
        industry = SDL_clamp(industry-1, 0, 100);
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
     * @return true The given allegiance is an enemy
     * @return false The given allegiance is not an enemy (at peace)
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

    /**
     * @brief Decider for if the player has held the X button (only) for the given duration
     * 
     * @param ticks The current tick of the program
     * @param timer The duration of how long the button needs to be held
     * @return true The X-Button has been held long enough given the timer
     * @return false The X-Button hasn't been held long enough given the timer or other buttons are pressed
     */
    inline bool XHeld(const tick_t& ticks, const tick_t& timer) const{
        return pastWait(x_held_tick, ticks, timer) && !a_held_tick && !y_held_tick && !b_held_tick;
    }

    /**
     * @brief Decider for if the player has held the Y button (only) for the given duration
     * 
     * @param ticks The current tick of the program
     * @param timer The duration of how long the button needs to be held
     * @return true The Y-Button has been held long enough given the timer
     * @return false The Y-Button hasn't been held long enough given the timer or other buttons are pressed
     */
    inline bool YHeld(const tick_t& ticks, const tick_t& timer) const{
        return pastWait(y_held_tick, ticks, timer) && !a_held_tick && !x_held_tick && !b_held_tick;
    }

    /**
     * @brief Decider for if the player has held the A button (only) for the given duration
     * 
     * @param ticks The current tick of the program
     * @param timer The duration of how long the button needs to be held
     * @return true The A-Button has been held long enough given the timer
     * @return false The A-Button hasn't been held long enough given the timer or other buttons are pressed
     */
    inline bool AHeld(const tick_t& ticks, const tick_t& timer) const{
        return pastWait(a_held_tick, ticks, timer) && !x_held_tick && !y_held_tick && !b_held_tick;
    }

    /**
     * @brief Decider for if the player has held the B button (only) for the given duration
     * 
     * @param ticks The current tick of the program
     * @param timer The duration of how long the button needs to be held
     * @return true The B-Button has been held long enough given the timer
     * @return false The B-Button hasn't been held long enough given the timer or other buttons are pressed
     */
    inline bool BHeld(const tick_t& ticks, const tick_t& timer) const{
        return pastWait(b_held_tick, ticks, timer) && !a_held_tick && !y_held_tick && !x_held_tick;
    }

    /**
     * @brief Decider for if the X button is currently pressed (if not pressed the tick held is 0)
     * 
     * @return true X button is currently pressed
     * @return false X button isn't currently pressed
     */
    inline bool XPressed() const{
        return x_held_tick;
    }

    /**
     * @brief Decider for if the Y button is currently pressed (if not pressed the tick held is 0)
     * 
     * @return true Y button is currently pressed
     * @return false Y button isn't currently pressed
     */
    inline bool YPressed() const{
        return y_held_tick;
    }

    /**
     * @brief Decider for if the A button is currently pressed (if not pressed the tick held is 0)
     * 
     * @return true A button is currently pressed
     * @return false A button isn't currently pressed
     */
    inline bool APressed() const{
        return a_held_tick;
    }

    /**
     * @brief Decider for if the B button is currently pressed (if not pressed the tick held is 0)
     * 
     * @return true B button is currently pressed
     * @return false B button isn't currently pressed
     */
    inline bool BPressed() const{
        return b_held_tick;
    }

    /**
     * @brief Decider for if a combination of buttons (and only that combination) is held for the duration given based on the timer given
     * 
     * @param x Flag that the X-button should be pressed
     * @param y Flag that the Y-button should be pressed
     * @param a Flag that the A-button should be pressed
     * @param b Flag that the B-button should be pressed
     * @param ticks The current tick of the program
     * @param timer The duration all buttons should be held
     * @return true The button combo has been held past the timer
     * @return false The button combo hasn't been held past the timer or other buttons are pressed
     */
    inline bool multiHeld(const bool x, const bool y, const bool a, const bool b, const tick_t& ticks, const tick_t& timer) const{
        return (x==pastWait(x_held_tick, ticks, timer)) && (y==pastWait(y_held_tick, ticks, timer)) && (a==pastWait(a_held_tick, ticks, timer)) && (b==pastWait(b_held_tick, ticks, timer));
    }

    /**
     * @brief Resets the held ticks of all buttons
     * 
     */
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

    /**
     * @brief Removes the Action Card from the players hand
     * 
     * @param action_card The card to be removed from the player
     * @pre The `action_card` is in the player's hand
     */
    void remove(const ActionCard* action_card){
        action_hand.erase(std::find(action_hand.begin(), action_hand.end(), action_card));
    }

    /**
     * @brief Removes the Invest Card from the players hand
     * 
     * @param invest_card The card to be removed from the player
     * @pre The `invest_card` is in the player's hand
     */
    void remove(const InvestmentCard* invest_card){
        invest_hand.erase(std::find(invest_hand.begin(), invest_hand.end(), invest_card));
    }

    /**
     * @brief Decider if the Investment Card provided is a card the player has selected to up IND
     * 
     * @param card Pointer to the Investment card being checked
     * @return true The card is currently selected for spending
     * @return false The card isn't currently selected for spending
     */
    inline bool hasSelected(const InvestmentCard* card) const{
        return std::find(selected_invest_cards.begin(), selected_invest_cards.end(), card) != selected_invest_cards.end();
    }

    /**
     * @brief Removes the provided card from the player's selected tech cards (for uping IND)
     * 
     * @param card The card being deselected
     * @pre `card` is in the player's selected list
     */
    inline void deselect(const InvestmentCard* card){
        selected_invest_cards.erase(std::find(selected_invest_cards.begin(), selected_invest_cards.end(), card));
    }

    /**
     * @brief Combined function of `hasSelected` and `deselect` to remove the provided card from the vector of selected tech cards
     * if and only if the card is actually selected
     * 
     * @param card The card that would be removed if selected
     * @return true The provided card was able to be removed
     * @return false The provided card wasn't selected and not removed
     */
    bool tryDeselect(const InvestmentCard* card){
        if (std::find(selected_invest_cards.begin(), selected_invest_cards.end(), card) != selected_invest_cards.end()){
            selected_invest_cards.erase(std::find(selected_invest_cards.begin(), selected_invest_cards.end(), card));
            return true;
        }

        return false;
    }

    /**
     * @brief Decider for if the player has achieved (played) the provided tech
     * 
     * @param tech Pointer to the tech that is being checked for achievement
     * @return true The player has achieved the tech
     * @return false The player hasn't achieved the tech
     */
    inline bool hasTech(const Tech* tech) const{
        return achieved_tech[*tech] != nullptr;
    }

    /**
     * @brief Decider for if the player has achieved (played) the provided tech
     * 
     * @param tech The tech that is being checked for achievement
     * @return true The player has achieved the tech
     * @return false The player hasn't achieved the tech
     */
    inline bool hasTech(const Tech& tech) const{
        return achieved_tech[tech] != nullptr;
    }

    /**
     * @brief Set the command values of the player based on the season and card played and handles emergency movement changes
     * 
     * @param selected_card The Card the player has put forth to play command
     * @param season The current season of the game
     */
    void setCommand(ActionCard* selected_card, const Season& season){
        command_card = selected_card;
        command_season = selected_card->season;
        command_priority = selected_card->command_priority;
        command_value = selected_card->command_value;

        // if the season doesn't match the current then use emergency command
        if (season != command_season){
            command_value = emergency_command;
            used_emergency = true;
        }
    }

    /**
     * @brief If the player used a investment card as a ploy then the command is 0 and they get no actions
     * 
     * @param selected_card 
     */
    void setCommand(InvestmentCard* selected_card){
        command_fake = selected_card;
        command_value = 0;
    }

    /**
     * @brief At the end of seasons, all date pertaining to command is reset
     * 
     */
    void resetCommand(){
        command_value = -1;
        command_card = nullptr;
        command_fake = nullptr;
    }

    /**
     * @brief Decreases the current remaining command value
     * 
     * @pre User can use command and won't go below 0
     */
    void useCommand(){
        command_value--;
    }

    /**
     * @brief Acheive (set as true in `achieved_tech`) the tech given and set to secret by default 
     * 
     * @param tech The technology being achieved
     * @pre Player has the cards to achieve the tech and hasn't achieved before
     */
    void achieveTech(const Tech& tech){
        achieved_tech[tech] = new AchievedTechnology("TODO ADD NAME", tech, false);
        technology_count++;
        setTechSecret(tech);

        if (tech == ATOMIC_FOUR)
            atomic = true;
    }

    /**
     * @brief Update the currently viewed investment card based on what the previous viewed index was (for when cards are spent)
     * 
     */
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

    /**
     * @brief Update the currently viewed action card based on what the previous viewed index was (for when cards are spent)
     * 
     * @param map Hashmap of all Countries so the countries being viewed can be updated
     */
    void updatePoppedActionCard(const unordered_map<string, Country*>& map){
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
     * @return size_t The total hand size of the player
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

    /**
     * @brief Get the DoW between the player and the rival provided
     * 
     * @param rival The allegiance of the rival whose DoW is being checked
     * @return DowState The state of the Declaration of War between the player and the rival
     */
    DowState getDoW(const CityType& rival) const{
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

    /**
     * @brief Set the DoW between the player and the rival to be the provided state
     * 
     * @param rival The rival whose DoW is changing
     * @param rival_state The new state of the DoW
     */
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
                exit(1);
                std::cerr << "Unkown Rival" << endl;
                break;
        }
    }

    const bool (&getFirstFire() const)[8] {
        return first_fires;
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
     * @brief Gets the flag for wether the player used emergency command in the current year
     * 
     * @return true 
     * @return false 
     */
    bool usedEmergency() const{
        return used_emergency;
    }

    /**
     * @brief Set the flag to be true for using emergency status
     * 
     */
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

    /**
     * @brief Get the current command value (or the number) for the player's command card
     * 
     * @return int The current amount of command the player has remaining
     */
    int getCommandNumber() const{
        return command_value;
    }

    /**
     * @brief Set the command value of the player to the provided number
     * 
     * @param new_num The new command value for the current year
     */
    void setCommandNumber(const int& new_num){
        command_value = new_num;
    }

    /**
     * @brief Get the command priority (or the letter) for the player's command card
     * 
     * @return char The letter or 'priority' of the command card
     */
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

    /**
     * @brief Get the number of technologies the player has achieved but kept secret since it contributes to the hand limit
     * 
     * @return const int 
     */
    const int getSecretCount() const{
        return secret_count;
    }

    /**
     * @brief Set the provided tech to be secret (achieved but rivals cannot see)
     * 
     * @param indx The tech that the player is setting secret
     * @pre The player has already achieved the tech
     */
    void setTechSecret(const Tech& indx){
        achieved_tech[indx]->secret = true;
        secret_count++;
    }

    /**
     * @brief Set the provided tech to be public (rivals can see)
     * 
     * @param indx The tech that the player is setting secret
     * @return true The tech was secret and is now public
     * @return false The tech wasn't secret and no changes were made
     */
    bool setTechPublic(const Tech& indx){
        if (achieved_tech[indx]->secret){
            achieved_tech[indx]->secret = false;
            secret_count--;
            // Update any flags needed
            switch (indx){
                case ATOMIC_FOUR:
                    atomic = true;
                    break;
                case NAVAL_RADAR:
                    first_fires[FLEET] = true;
                    break;
                case ROCKET_ARTILLERY:
                    first_fires[INFANTRY] = true;
                    break;
                case HEAVY_TANKS:
                    first_fires[TANK] = true;
                    break;
                case JETS:
                    first_fires[AIR] = true;
                    break;

                default:
                    break;
            }
            return true;
        }

        return false;
    }

    /**
     * @brief Set the Unit selected for movement to the current selected unit
     * 
     */
    void setMovingUnit(){
        moving_unit = selected_unit;
    }

    /**
     * @brief Set the Unit selected for movement to nullptr
     * 
     */
    void resetMovingUnit(){
        moving_unit = {nullptr, nullptr};
    }

    /**
     * @brief Set the flag for full atomic (all 4 stages of nuclear developement) to true
     * 
     */
    inline void makeAtomic(){
        atomic = true;
    }

    /**
     * @brief Decider for if the player is able to use their selected invest card to peak at rival's action card hand
     * 
     * @return true Is able to view rivals hand
     * @return false Is unable to view a rivals hand
     */
    inline bool canPeakAction(){
        return popped_invest_card != nullptr && selected_tech1 != nullptr && *selected_tech1 == CODE_BREAKER && action_view != allegiance;
    }

    /**
     * @brief Setup the player to be able to view the rivals hand for a limited time and remove the card used to peak
     * @see canPeakAction
     * 
     * @param tick The tick when the player can begin viewing the rival's hand
     * @pre The player is able to use the current invest card to peak at a rival
     */
    void peakAction(const tick_t& tick){
        peak_ticks[action_view] = tick;
        remove(popped_invest_card);
        updatePoppedInvestCard();
    }

    /**
     * @brief Decider for if the player can use the current selected invest card to peak at the current selcted rival unit
     * 
     * @return true The player is able to peak at the current unit
     * @return false The player is unable to peak at a rival's unit
     */
    inline bool canPeakUnit(){
        return selected_unit.first != nullptr && selected_tech1 != nullptr && *selected_tech1 == AGENT && selected_unit.second->allegiance != allegiance;
    }

    /**
     * @brief Setup the player to be able to view the selected rival unit for a limited time and remove the card used to peak
     * 
     * @param tick The tick when the player can begin viewing the rival's unit
     */
    void peakUnit(const tick_t& tick){
        unit_peak_tick = tick;
        peaked_unit = selected_unit;
        remove(popped_invest_card);
        updatePoppedInvestCard();
    }

    /**
     * @brief Reset all of the player's unit to a base state at the beginning of each season
     * 
     */
    void resetUnits(){
        for (auto& unit : units){
            if (unit)
                unit->acted = false;
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

    /**
     * @brief Handler for the counts of different production actions and if the count should be increased or decreased
     * 
     * @param p_act The production action the player is comiting
     * @param undo Flag for if the player is undoing or adding the action
     */
    void spendProduction(const ProductionAction& p_act, const bool undo=false){ //BUY_AC, BUY_IC, UNIT_UP, CADRE}
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

    /**
     * @brief Set the wartime flag to true
     * 
     */
    void setWartime(){
        at_war = true;
    }

    /**
     * @brief Decides if the player is currently at war with the given rival
     * 
     * @param rival The allegiance of the rival whose DoW is being checked
     * @return true The player is at war with the provided rival
     * @return false The player is not at war with the provided rival
     */
    bool atWar(const CityType& rival) const{
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

        FC_FreeFont(app->font1);
        
        name = "DELETED";
    }

    /**
     * @brief Equivalency Operator Overload for comparing the player to a CityType (allegiance)
     * 
     * @param city_type The underlying int of the allegiance being compared
     * @return true The player has the same allegiance as the provided int
     * @return false The player does NOT have the same allegiance as the provided int
     */
    bool operator==(const int& city_type) const{
        return allegiance == city_type;
    }

    /**
     * @brief Not-Equivalency Operator Overload for comparing the player to a CityType (allegiance)
     * 
     * @param city_type The underlying int of the allegiance being compared
     * @return true The player does NOT has the same allegiance as the provided int
     * @return false The player have the same allegiance as the provided int
     */
    bool operator!=(const int& city_type) const{
        return allegiance != city_type;
    }

    /**
     * @brief Equivalency Operator Overload for comparing the player to a CityType (allegiance)
     * 
     * @param city_type The underlying int of the allegiance being compared
     * @return true The player has the same allegiance as the provided int
     * @return false The player does NOT have the same allegiance as the provided int
     */
    bool operator==(const CityType& city_type) const{
        return allegiance == city_type;
    }

    /**
     * @brief Non-Equivalency Operator Overload for comparing the player to a CityType (allegiance)
     * 
     * @param city_type The underlying int of the allegiance being compared
     * @return true The player does NOT has the same allegiance as the provided int
     * @return false The player have the same allegiance as the provided int
     */
    bool operator!=(const CityType& city_type) const{
        return allegiance != city_type;
    }

    /**
     * @brief Equivalency Operator Overload for comparing the player object to a Player Pointer
     * 
     * @param player The Pointer to Player object thats seeking equivalency
     * @return true 'this' is the same object as the one stored at the pointer
     * @return false 'this' is NOT the same object as the one stored at the pointer
     */
    bool operator==(const Player* player) const{
        return this == player;
    }

    /**
     * @brief Equivalency Operator Overload for comparing `this` to a another Player Object
     * 
     * @param player The Player object reference thats seeking equivalency
     * @return true 'this' is the same object as reference
     * @return false 'this' is NOT the same object as reference
     */
    bool operator==(const Player& player) const{
        return this == &player;
    }

    /**
     * @brief Non-Equivalency Operator Overload for comparing the player object to a Player Pointer
     * 
     * @param player The Pointer to Player object thats seeking non-equivalency
     * @return true 'this' is NOT the same object as the one stored at the pointer
     * @return false 'this' is the same object as the one stored at the pointer
     */
    bool operator!=(const Player* player) const{
        return this != player;
    }

    /**
     * @brief Non-Equivalency Operator Overload for comparing `this` to a another Player Object
     * 
     * @param player The Player object reference thats seeking non-equivalency
     * @return true 'this' is NOT the same object as reference
     * @return false 'this' is the same object as reference
     */
    bool operator!=(const Player& player) const{
        return this != &player;
    }

    /**
     * @brief int Casting Overload by returning the allegiance of the Player object 
     * 
     * @return int The allegiance of the player
     */
    operator int() const{
        return allegiance;
    }

    operator SDL_Renderer*() const{
        return app->renderer;
    }

    /**
     * @brief CityType Casting Overload by returning the allegiance of the Player object 
     * 
     * @return CityType The allegiance of the player
     */
    operator CityType() const{
        return allegiance;
    }
};
