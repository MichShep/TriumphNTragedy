#pragma once

#include "Player.h"

/**
 * @brief Since controllers can have stick drift, it will flood the SDL_PollEvent Queue with joystick moves and delay user inputs. 
 * The filter will only allow significant movements to be placed in queue
 * 
 * @param userdata ???
 * @param event The event picked up
 * @return int 1: if the event should be recorded 0: if to be ignored
 */
static int SDLCALL event_filter(void* userdata, SDL_Event* event) {
    if (event->type == SDL_JOYAXISMOTION) {
        /*int value = event->jaxis.value;
        // Apply deadzone filtering
        if (value > -JOYSTICK_DEADZONE && value < JOYSTICK_DEADZONE) {
            return false; // Filter out this event
        }*/
       return false;
    }

    // Allow other events to pass through
    return true;
}

/**
 * @brief The main controller of the game and controls sequence of play
 * 
 */
class Runner{
private:
    int num_players; /**< Number of player in game (3 but hopefully can make a 1)*/

    Player players[3]; /**Holds each playe object with allegiance as index 0: West 1: Axis 2: USSR*/ 

    Map map; /**< Map of the game and nations/waters*/

    size_t year; /**< Current year the player is in (goes from 1936 to 1945)*/

    size_t end_year; /**< Year the game will end (usually 1945)*/

    Season season=NEW_YEAR; /**< The current season being playes */

    Dice die; /**< Dice used to roll decisions, default a D6*/

    vector<ActionCard*> action_deck; /**< Draw deck of the action cards*/

    vector<ActionCard*> action_discard; /**< Draw deck of the action cards*/

    vector<InvestmentCard*> invest_deck; /**< Draw deck of the invest cards*/

    vector<InvestmentCard*> invest_discard; /**< Discard pile of investment cards*/

    vector<PeaceChit> peace_dividends_bag; /**< Holds all the unpulled peace dividends*/

    Player* start_player; /**< Player who will start the turn*/

    Player* current_player; /**< The player's who current turn it is*/

    Player* turn_order[3]; /**< Array with the first player at 0 and the last player in the loop at 2*/

    const unsigned int seed = 100; /**< The set (or time set seed) for all randomness*/
    
    std::mt19937 g; /**< The random generator for shuffling*/

    App app; /**< The stuct that holds all window and renderer for SDL2 and shows the main board*/

    App powers_app[3]; /**< The app (window, rendered, ect) of each player and their board*/

public:
    /**
     * @brief Construct a new Runner object that intializes the map and players
     * 
     * @param default_mode true if should go off of default or read in through the map
     */
    Runner(bool default_mode = true){
        if (InitApplication() == false){
            ShutdownApplication();
            exit(1);
        }
        
        //- Set random seed
        srand(seed);

        //- Init Dice
        die = Dice(1, 6);

        //- Set starting year
        year = START_YEAR;
        end_year = END_YEAR;
        year--;

        

        if (!default_mode){
            //setXY("/Users/michshep/Desktop/TriumphNTragedy/src/starter4.map");
            setResXY();
            exit(EXIT_SUCCESS);
        }

        //- Create Map
        initMap("/Users/michshep/Desktop/TriumphNTragedy/src/starter4.map");

        //- Create Cards
        initCards("/Users/michshep/Desktop/TriumphNTragedy/src/invest.card", "/Users/michshep/Desktop/TriumphNTragedy/src/action.card");

        start_player = &players[1]; //AXIS start
        
        //- Init Players
        players[0] = Player("Michael", WEST); //give 8 cards
        deal(&players[0], 8);
        players[1] = Player("Taiga", AXIS); //give 14 cards
        deal(&players[1], 14);
        players[2] = Player("Luke", USSR); //give 7 cards
        deal(&players[2], 7);

        
        mapPlayer(players[0]);
        mapPlayer(players[1]);
        mapPlayer(players[2]);
        
        std::mt19937 g(seed);

        peace_dividends_bag = {{2,0,0}, {2,0,0}, {2,0,0}, {2,0,0},
                               {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, 
                               {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};
        shuffle(peace_dividends_bag.begin(), peace_dividends_bag.end(), g);

        string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/SpriteMap0.png";

        sprite_map = Spritesheet(path.c_str(), app.renderer);

        string path2 = "/Users/michshep/Desktop/TriumphNTragedy/sprites/MapSprite4.png";
        string path3 = "/Users/michshep/Desktop/TriumphNTragedy/sprites/UnitSpritesZ1.png";
        string path4 = "/Users/michshep/Desktop/TriumphNTragedy/sprites/UnitSpritesZ3.png";
        map_sprite = Spritesheet(path2.c_str(), app.renderer);

        powers_sprite_map[0] = Spritesheet(path.c_str(), powers_app[0].renderer);
        players[WEST].sprite_sheet = &powers_sprite_map[0];
        powers_sprite_map[1] = Spritesheet(path.c_str(), powers_app[1].renderer);
        players[AXIS].sprite_sheet = &powers_sprite_map[1];
        powers_sprite_map[2] = Spritesheet(path.c_str(), powers_app[2].renderer);
        players[USSR].sprite_sheet = &powers_sprite_map[2];

        powers_map_sprite[0] = Spritesheet(path2.c_str(), powers_app[0].renderer);
        players[WEST].map_sprite = &powers_map_sprite[0];
        powers_map_sprite[1] = Spritesheet(path2.c_str(), powers_app[1].renderer);
        players[AXIS].map_sprite = &powers_map_sprite[1];
        powers_map_sprite[2] = Spritesheet(path2.c_str(), powers_app[2].renderer);
        players[USSR].map_sprite = &powers_map_sprite[2];

        powers_units_sprite_z1[0] = Spritesheet(path3.c_str(), powers_app[0].renderer);
        players[WEST].units_sprite_z1 = &powers_units_sprite_z1[0];

        powers_units_sprite_z1[1] = Spritesheet(path3.c_str(), powers_app[1].renderer);
        players[AXIS].units_sprite_z1 = &powers_units_sprite_z1[1];

        powers_units_sprite_z1[2] = Spritesheet(path3.c_str(), powers_app[2].renderer);
        players[USSR].units_sprite_z1 = &powers_units_sprite_z1[2];

        powers_units_sprite_z3[0] = Spritesheet(path4.c_str(), powers_app[0].renderer);
        players[WEST].units_sprite_z3 = &powers_units_sprite_z3[0];

        powers_units_sprite_z3[1] = Spritesheet(path4.c_str(), powers_app[1].renderer);
        players[AXIS].units_sprite_z3 = &powers_units_sprite_z3[1];

        powers_units_sprite_z3[2] = Spritesheet(path4.c_str(), powers_app[2].renderer);
        players[USSR].units_sprite_z3 = &powers_units_sprite_z3[2];

        players[WEST].app = &powers_app[0];
        players[AXIS].app = &powers_app[1];
        players[USSR].app = &powers_app[2];


        test();

        //for handling stick drift
        SDL_SetEventFilter(event_filter, NULL);

        last_tick = SDL_GetTicks();

        players[0].cursor_x = map.getCapital("Britian")->x;
        players[0].cursor_y = map.getCapital("Britian")->y;
        players[0].closest_map_city = map.getCapital("Britian");

        players[2].cursor_x = map.getCapital("USSR")->x;
        players[2].cursor_y = map.getCapital("USSR")->y;
        players[2].closest_map_city = map.getCapital("USSR");

        players[1].cursor_x = map.getCapital("Germany")->x;
        players[1].cursor_y = map.getCapital("Germany")->y;
        players[1].closest_map_city = map.getCapital("Germany");

        players[0].calculateProduction();
        players[1].calculateProduction();
        players[2].calculateProduction();
    }

    size_t test(){
    
        map["London"]->occupants[0].push_back(new Unit(1, BRITIAN_U, FLEET));
        map["London"]->occupants[0].push_back(new Unit(2, BRITIAN_U, FORTRESS));
        map["London"]->num_occupants = 2;
        
        map["Washington"]->occupants[0].push_back(new Unit(1, USA_U, FLEET));
        map["Washington"]->occupants[0].push_back(new Unit(2, USA_U, FORTRESS));
        map["Washington"]->occupants[0].push_back(new Unit(1, USA_U, SUB));
        map["Washington"]->occupants[0].push_back(new Unit(2, USA_U, CARRIER));
        map["Washington"]->occupants[0].push_back(new Unit(1, USA_U, AIR));
        map["Washington"]->occupants[0].push_back(new Unit(2, USA_U, TANK));
        map["Washington"]->occupants[0].push_back(new Unit(1, USA_U, INFANTRY));
        map["Washington"]->num_occupants = 7;

        map["Ruhr"]->occupants[3].push_back(new Unit(3, USSR_U, TANK));
        map["Ruhr"]->occupants[3].push_back(new Unit(4, USSR_U, TANK));
        map["Ruhr"]->occupants[3].push_back(new Unit(5, USSR_U, TANK));
        map["Ruhr"]->occupants[1].push_back(new Unit(6, GERMANY_U, AIR));
        map["Ruhr"]->occupants[1].push_back(new Unit(7, GERMANY_U, AIR));
        map["Ruhr"]->occupants[1].push_back(new Unit(8, GERMANY_U, INFANTRY));
        map["Ruhr"]->num_occupants = 6;

        map["Moscow"]->occupants[2].push_back(new Unit(3, USSR_U, TANK));
        map["Moscow"]->occupants[2].push_back(new Unit(4, USSR_U, INFANTRY));
        map["Moscow"]->occupants[2].push_back(new Unit(5, USSR_U, AIR));
        map["Moscow"]->occupants[2].push_back(new Unit(6, USSR_U, AIR));
        map["Moscow"]->occupants[2].push_back(new Unit(7, USSR_U, INFANTRY));
        map["Moscow"]->occupants[2].push_back(new Unit(8, USSR_U, TANK));
        map["Moscow"]->num_occupants = 6;

        map["Warsaw"]->occupants[3].push_back(new Unit(1, NEUTRAL_U, FORTRESS));
        map["Warsaw"]->occupants[3][0]->combat_value = 3;
        map["Warsaw"]->num_occupants = 1;

        map["Budapest"]->occupants[0].push_back(new Unit(1, BRITIAN_U, INFANTRY));
        map["Budapest"]->occupants[1].push_back(new Unit(1, GERMANY_U, AIR));
        map["Budapest"]->num_occupants = 2;

        map["Berlin"]->occupants[1].push_back(new Unit(1, GERMANY_U, INFANTRY));
        map["Berlin"]->occupants[1][0]->combat_value = 3;
        map["Berlin"]->occupants[1].push_back(new Unit(1, GERMANY_U, AIR));
        map["Berlin"]->occupants[1][1]->combat_value = 2;
        map["Berlin"]->num_occupants = 2;

        map["Croatia"]->occupants[0].push_back(new Unit(1, BRITIAN_U, INFANTRY));
        map["Croatia"]->occupants[2].push_back(new Unit(1, USSR_U, AIR));
        map["Croatia"]->num_occupants = 2;

        map["Budapest"]->ruler_type = WEST;
        map.getCountry("Hungary")->influence_level = SATELLITES;
        map.getCountry("Hungary")->allegiance = WEST;
        map["Budapest"]->influencer = WEST;
        map["Budapest"]->country_counts[0] = 2;
        players[0].add(map.getCity("Budapest"));


        map.getCountry("Turkey")->influence_level = SATELLITES;
        map.getCountry("Turkey")->allegiance = WEST;
        map["Ankara"]->ruler_type = WEST;
        map["Ankara"]->blockcade = true;
        players[0].add(map.getCity("Ankara"));

        map["Iraq"]->blockcade = true;
        map["Marseille"]->blockcade = true;

        map["Gibraltar"]->ruler_type = AXIS;

        deal(&players[0], 11, 'I');
        
        return 0;
    }


    /**
     * @brief Creates the game map including nations and cities and connections
     * 
     * @return true  Was able to succesfully make the map
     * @return false Encountered an error while making
     */
    bool initMap(string map_file);

    /**
     * @brief Creates the decks of cards
     * 
     * @return true 
     * @return false 
     */
    bool initCards(const string invest_file, const string action_file);

    //& Sequence of Play
    //- Round handler
    /**
     * @brief The main runner of the game loop
     * 
     * @return true The game is over with a winner
     * @return false The game is still going on 
     */
    bool run();

    //& New Year
    /**
     * @brief The first phase of the game loop where vicotry is checked, cards reshuffled, peace chits are distributed, USA influence, production, govenment phase occur
     * 
     * @see peaceDividends()
     * @see reshuffle()
     * @see newYearRes()
     * @see production()
     * @see government()
     * 
     * @return CityType  The player who won the game (CityType::Water if there is no winner)
     */
    CityType newYear();

    /**
     * @brief New Year phase where Cards in the discard piles will be added to both draw decks and then the whole deck will be reshuffled
     * 
     * @param animation Bool which will play the reshuffle animation if true
     */
    void reshuffle(const bool animation);
    
    /**
     * @brief All players who have been peacful (not DoW's or VoN in the past year) will recieve a random chit of 0, 1, or 2 VP's. This happens in the first year as well
     * 
     */
    void peaceDividends();

    /**
     * @brief New Year phase where the turn order of the players is decided for the following year. A D6 is rolled and depending on the number the strting player, and rotation is decided
     * 
     */
    void decideTurnOrder(const bool animation=false);

    /**
     * @brief In specific years 1 WEST influence will be added to the USA and if the USA is already a satellite then 
     * one of each unit will be automattically added to Washington and New York
     * 
     */
    void newYearRes();

    //- Production Phase
    /**
     * @brief New Year phase where players can spend there production (lowest of pop/res/ind) on buying cards, building cadres, and upgrading units. Runs on the turn order until all have gone through
     * 
     */
    void production();

    /**
     * @brief Handles what to draw during the production phase
     * 
     */
    void drawProductionPhase();

    /**
     * @brief Deal a set amount of cards to the player of action or invest. Hand limit doesn't apply to card drawing. The player will draw up onto the amount or the number of cards remaining in the deck
     * 
     * @param player The player recieveing the cards
     * @param amount The amount of the card the player will recieve
     * @param state The type of card to deal 'A': action, 'I': invest
     * @return true The player was able to draw all cards
     * @return false The player wasn't able to draw all cards 
     */
    bool deal(Player* player, size_t amount, const char state='A');

    //- Government Phase
    /**
     * @brief New Year phase where players play action cards to add influence and play investment cards, goes in turn order until all have passed
     * 
     */
    void government();

    /**
     * @brief Checks the players hand to see if it is over the card limit, and to discard down to the hand limit
     * 
     * @param player The player whose hand will be checked
     */
    void handCheck(Player* player);

    //& Seasons of War
    //- Spring
    /**
     * @brief Spring season of war where players will commence the war. Action cards with spring will have priority
     * 
     */
    void spring();

    //- Summer Season
    /**
     * @brief Summer season of war where players will commence the war and after which blockades will be added. Action cards with SUMMER will have priority
     * 
     */
    void summer();

    //- Checking Blockades
    /**
     * @brief At the end of summer, cities who cannot trace a trade route to the Main Capital of its ruler is blockaded and the pop/res won't be counted in production
     * 
     */
    void blockade();

    //- Fall Season
    /**
     * @brief Fall season of war where players will commence the war. Action cards with FALL will have priority
     * 
     */
    void fall();

    //- Winter Season
    /**
     * @brief The winter season of war where the USSR player can act inside of the bounds of the USSR. Only the USSR player can act during this turn
     * 
     */
    void winter();

    //&Checking on map

    /**
     * @brief Goes over the players holdings over the map and sums up their pop, res, CV
     * 
     * @param player The player whose cities will be checked
     * @return true No changes were made from the stored attributes
     * @return false Changes were made from stale attributes
     */
    bool mapPlayer(Player& player);

    /**
     * @brief During the production phase it needs to verify all cities controlled by the player that are blockaded are still blockaded (route can only include 1 land segment and 1 sea segment)
     * 
     * @param player The player whose trade routes are being checked
     * @param main_capital The capital of the player that the cities must conenct to 
     * @return true Blockades were removed 
     * @return false Blockades weren't removed
     */
    bool checkTradeRoutes(Player& player, const string& main_capital);

    /**
     * @brief A decider for if the city provided is supplied and can have steps built. All the cities on the route are marked as supplied to decrease redundancy
     * 
     * @param player The player who would build the unit
     * @param city The city where the unit wants to be built
     * @param allegiance The allegiance of the current city
     * @return true The city is suplliable
     * @return false The city is not suplliable
     */
    bool isSupllied(const Player& player, City* city, const CityType allegiance);

    //&&&Unit Actions

    /**
     * @brief Decider for if a new unit of the given type is able to be built in the city provided
     * 
     * @param player Player whose troop will be added
     * @param city The city where the unit wants to be added
     * @param nationality The nationality (or color) of the unit that wants to be added (used to track limits)
     * @param unit The type of unit that wants to be added (used to track limits)
     * @return ProductionError The error given as to why it can't be built (0 if no error)
     */
    ProductionError canBuild(const Player& player,  City* city, const UnitCountry nationality, const UnitType unit);

    /**
     * @brief Decider for if an exisiting unit can be upgraded
     * 
     * @param player The player who wants to upgrade the unit
     * @param city The city where the unit is
     * @param nationality The nationality of the unit
     * @param unit The unit who would be upgraded
     * @return ProductionError The error given as to why it can't be upgrade (0 if no error)
     */
    ProductionError canUpgrade(const Player& player, City* city, const UnitCountry nationality, const Unit* unit);

    //& Movement 
    /**
     * @brief Checks what type of movement is allowed and if the player is allowed to move there
     * 
     * @param unit The unit being moved
     * @param start The Starting city being left
     * @param end The destination of the unit
     * @return true The unit was able to move
     * @return false The unit was unable to move
     */
    bool move(Unit* unit, const string start, const string end);

    /**
     * @brief Checks if the player can disengage from the current battle
     * 
     * @param unit Unit disengaging
     * @param start The city with the battle being fled from
     * @param end The potential city to flee to
     * @return true Able to disengage
     * @return false Unable to disengage
     */
    bool canDisengage(Unit* unit, const string start, const string end);

    /**
     * @brief When the unit is leaving a battle it can move to one adjacent friendly city
     * 
     * @param unit The unit disengaging
     * @param start The city with the conflict
     * @param end The city to disengage to
     * @return true Is able to move to end
     * @return false is unable (border limits or out of range or not friendly)
     */
    bool disengage(Unit* unit, const string start, const string end);

    /**
     * @brief Checks if that unit is able to move into that city
     * 
     * @param unit The unit moving
     * @param name The target City
     * @return size_t How much movement would be left (returns INFI if it can't)
     */
    size_t canMove(Unit* unit,  const string start, const string name);

    //& Combat
    /**
     * @brief Executes the current players combat rounds
     * 
     */
    void combatRound();

    /**
     * @brief Executes a land battle at the given city for one combat round
     * 
     * @param battlefield The city with the battle taken place
     */
    void landCombat(City* battlefield);

    /**
     * @brief Executes a sea battle at the given 'city' until concluded
     * 
     * @param battlefield The 'city' with the battle taken place
     * @return true if the combat round needs to repeat
     * @return false if the battle fininshed
     */
    bool seaCombat(City* battlefield);

    
    //-check which cities have battles and have the

    /**
     * @brief Check which cities have a current battle happening
     * 
     * @param allegiance The allegiance of the current player 
     * @return vector<City*> Vector of all cities the player is batteling for
     */
    vector<City*> getBattles(const CityType allegiance); 

    /**
     * @brief Get the number of players
     * 
     * @return size_t The number of playes in the game (2 or 3)
     */
    size_t getNumPlayers() const{
        return num_players;
    }

    //& Runner Getters and Setters
    /**
     * @brief Get the map of the game
     * 
     * @return const Map& A const reference to the game map and cities
     */
    const Map& getMap() const{
        return map;
    }

private:
    /**
     * @brief Free the allocated memory of the whole game
     * 
     */
    void freeMemory(){
        map.freeMemory();
        sprite_map.freeMemory();
        map_sprite.freeMemory();

        powers_sprite_map[0].freeMemory();
        powers_sprite_map[1].freeMemory();
        powers_sprite_map[2].freeMemory();
        powers_map_sprite[0].freeMemory();
        powers_map_sprite[1].freeMemory();
        powers_map_sprite[2].freeMemory();

        for (ActionCard* ac : action_deck){
            if (ac != nullptr) delete ac;
        }
        action_deck.clear();
        for (ActionCard* ac : action_discard){
            if (ac != nullptr) delete ac;
        }
        action_discard.clear();

        for (InvestmentCard* ac : invest_deck){
            if (ac != nullptr) delete ac;
        }
        invest_deck.clear();
        for (InvestmentCard* ac : invest_discard){
            if (ac != nullptr) delete ac;
        }
        invest_discard.clear();

        players[0].freeMemory();
        players[1].freeMemory();
        players[2].freeMemory();

        current_player = nullptr;
        start_player = nullptr;

        ShutdownApplication();
    }

    void printMemo(size_t memo[][5]) const;

private:  //!!! Graphics things
    //& Sprite Maps
    Spritesheet sprite_map; /**< A png that holds every sprite in the game and can be indexed into and a clip pulled from in 32 by 32 pixels*/

    Spritesheet map_sprite;

    Spritesheet powers_sprite_map[3];  /**< A png that holds every sprite in the game and can be indexed into and a clip pulled from in for the player's seperate renderer*/

    Spritesheet powers_map_sprite[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the map */

    Spritesheet powers_units_sprite_z1[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the units at the first zoom level */

    Spritesheet powers_units_sprite_z3[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the units at the third zoom level */

    //& Controller Things
    SDL_GameController *west_controller=nullptr; /**< The controller of the West player */

    SDL_GameController *axis_controller=nullptr;  /**< The controller of the Axis player */

    SDL_GameController *ussr_controller=nullptr;  /**< The controller of the USSR player */

    SDL_GameController* controllers[3]= {nullptr, nullptr, nullptr}; /**< Array of the controllers so that the controller.which can be used to index the controller obj*/

    bool map_changed=true; /**< Boolean that is true when an update has happened on the main screen and the main screen needs to be re-rendered */

    Uint32 last_tick; /**< Used by animations to see how long has elapsed since the last render */

    //& Init Functions
    /**
     * @brief Initalizes SDL2 and the window
     * 
     * @return true Initalized succesfully
     * @return false Failexcd to initalize
     */
    bool InitSDL();

    /**
     * @brief Initalizes the 'app', the struct that hlds the renderer and the window
     * 
     * @return true Initalized succesfully
     * @return false Failexcd to initalize
     */
    bool InitApplication();

    /**
     * @brief Deletes the windows and frees memory specifically used by SDL
     * 
     */
    void ShutdownApplication();

    /**
     * @brief Clears the screen so the screen can 'update'
     * 
     */
    void ClearScreen(SDL_Renderer* renderer);

    //& Map Displaying
    /**
     * @brief Draw's the map to the main rendered with different options to control what is shown
     * 
     * @param cities Draws all cities if true
     * @param influence Draws the influence markers on each applicable city if true
     * @param resources Draw the resources of each city if true
     * @param connections Draw the line connections (colored by type) between connected cities if true
     * @param render Will render the map onto the renderer if true (used for when nothing will be added ontop of the map)
     * @param fps If a fps is provided it will draw it onto the renderer
     */
    void drawMap(const Player& player, const bool cities, const bool influence, const bool resources, const bool connections, const bool render=true, const int& fps=-1);

    /**
     * @brief Draws the private view of the player including cards and VP and production levels and acheived tech
     * 
     * @param player The player whose card is being drawn
     * @param renderer The player's renderer
     */
    void drawPlayerBoard(const Player& player, SDL_Renderer* renderer, const int bought_action=0, const int bought_invest=0);

    /**
     * @brief Get the index of the sprite needed for the city
     * 
     * @param city The city being drawn
     * @return int The index of the sprite in the sprite map
     */
    int getCitySprite(City* city);

    /**
     * @brief Draws a city onto the players renderer and if opted the resources as well
     * 
     * @param player The player whose screen will have the city drawn on
     * @param city The city being drawn
     * @param resources If the resources should be drawn or not
     */
    void drawCity(const Player& player, City* city, const bool resources=true);

    /**
     * @brief Draw a city marker (not tied to any specific city)
     * 
     * @param x The x-coord of the city
     * @param y The y-coord of the city
     * @param population_type The type of city to draw
     */
    void drawCity(int x, int y, PopulationType population_type);

    /**
     * @brief Draws the unit onto the player's screen
     * 
     * @param player The player whose screen will have the unit drawn
     * @param unit The unit that will be drawn
     * @param x The x-coord of the unit to draw 
     * @param y The y-coord of the unit to draw 
     * @param zoom The zoom level of the player's map to determine units level of detail
     * @param secret If true the unit sprite will be a question mark only showing the nationality (for when not in combat and not the player's allegiance)
     * 
     * @pre x and y have already been scaled 
     */
    void drawUnit(const Player& player, const Unit* unit, const int x, const int y, const int zoom, const bool secret=false);

    /**
     * @brief Draws 5 units under the city, rotating to the next 5 every 5 seconds
     * 
     * @param player The player whose screen will have the units drawn (also affects which units are visible)
     * @param city The city whose occupants will be drawn
     */
    void drawCityUnits(const Player& player, City* city);

    /**
     * @brief If the city has full displayed enable, every unit at the city will be displayed in rows of 5 (no rotation)
     * 
     * @param player The player who opted for the city to be fully displayed
     * @param city The city whose units will all be shown
     */
    void drawFullCityUnits(const Player& player, City* city);

    /**
     * @brief Draws the influence tokens onto the map
     * 
     * @param player The player whose screen will have the tokens rendered to
     */
    void drawInfluence(const Player& player);

    /**
     * @brief Draws the players action cards onto their screen starting at the given x and y and decends
     * 
     * @param player The player's cards to draw
     * @param start_x The top right x-coord corner of where cards should be drawn
     * @param start_y The top right y-coord corner of where cards should be drawn
     * @param count  The amount of cards to be drawn (max amount drawn will be XX)
     * @param scale THe scale of the cards to draw
     */
    void drawActionCards(const Player* player, int start_x, int start_y, int count, int scale=1);

    /**
     * @brief Draws the players invest cards onto their screen starting at the given x and y and decends
     * 
     * @param player The player's action cards to draw
     * @param start_x The top right x-coord corner of where cards should be drawn
     * @param start_y The top right y-coord corner of where cards should be drawn
     * @param count  The amount of cards to be drawn (max amount drawn will be XX)
     * @param scale THe scale of the cards to draw
     */
    void drawInvestCards(const Player* player, int start_x, int start_y, int count, int scale=1);

    
    /**
     * @brief Draws all the connections between the cities and colors them based on the type of border 
     * 
     * @param The player whose screen will have connections drawn on
     * 
     */
    void drawConnections(const Player& player);

    /**
     * @brief Takes any length number and draws it as a 7-segment at the x,y as the top left. Origional scale is 7*13 for one digit. Default color is black
     * 
     * @param renderer The rendererer to draw the number onto
     * @param num Number to render
     * @param x X coord of number origin
     * @param y Y coord of number origin
     * @param scale Scales draw size of the number
     * @param r The red value of the color (0, 255)
     * @param g The green value of the color (0, 255)
     * @param b The blue value of the color (0, 255) 
     */
    void drawNumber(SDL_Renderer* renderer, int num, const int x, const int y, const float scale, const uint8_t r=255, const uint8_t g=255, const uint8_t b=255) const;

    //& Animations
    /**
     * @brief Animation of the cards from the discard pile being added back
     * 
     * @param action_size Number of action cards to add back
     * @param invest_size Number of invest cards to add back
     */
    void reshuffleAnimation(const size_t& action_size, const size_t& invest_size);

    /**
     * @brief Takes the memo of the Dijkstra's knock-off II for finding trade routes and highlighting the route it takes
     * 
     * @param memo The completed memo
     * @param unblocked The list of cities who were unblockaded and there path will be shown
     */
    void drawMemoResolution(const vector<std::array<size_t, 6>>& memo, vector<City*> unblocked);

    /**
     * @brief Draws the memo of the Dijkstra's knock-off III for supply routes
     * 
     * @param player The player whose screen it will be drawn too
     * @param memo The completed memo of the algorithm
     */
    void drawMemoResolution(const Player& player, const vector<std::array<size_t, 4>>& memo);

    /**
     * @brief Animation for rolling a D6 and form that the turn order that is decided
     * 
     * @param result The result of the dice roll
     */
    void drawTurnRoll(const int& result);

    /**
     * @brief Animation of the cities who were peacful receiving a peace chit
     * 
     * @param west Bool if the WEST player should be shown receiving a peace chit
     * @param axis Bool if the AXIS player should be shown receiving a peace chit
     * @param ussr Bool if the USSR player should be shown receiving a peace chit
     */
    void drawPeaceDividends(const bool west, const bool axis, const bool ussr);

    /**
     * @brief Used for button presses where a given mouse clip position will see if its in the rectangle provided
     * 
     * @param x The top left x-coord of the rectangle
     * @param y The top left y-coord of the rectangle
     * @param width The width of the button 
     * @param height The height of the button
     * @param target_x The x-coord where the mouse clicked
     * @param target_y The y-coord where the mouse clicked
     * @return true The click is in the button
     * @return false The click is not in the button
     */
    bool inBox(const int x, const int y, const int width, const int height, const int target_x, const int target_y){
        return (target_x >= x && target_x <= x+width) && (target_y >= y && target_y <= y+height);
    }

    //& User Input

    /**
     * @brief Main handler for all possible user input
     * 
     * @param running Reference to the check if the game loop should continue running and can be changed if player inputs it so
     */
    void handleUserInput(bool& running);

    /**
     * @brief Handels the cases where the player pressed down on a button
     * 
     * @param player The player who commenced the event
     * @param event The button down event by the player
     */
    void handleButtonDown(Player& player, const SDL_Event& event);

    /**
     * @brief Handels the players controller joystick movement the dictates cursor movement and is called only every frame to make game smoother
     * 
     * @param player The player whose controller is checked for movement
     */
    void handleJoyStickMovement(Player& player);

    /**
     * @brief Handels the players controller trigger (L2, R2) movement that dictates zoom and is called only every frame to make game smoother
     * 
     * @param player The player whose controller is checked for movement
     */
    void handleTriggerMovement(Player& player);
    
    //& Dev Tools
    /**
     * @brief Dev tool for setup when deciding the X and Y of the city, it'll print which city and then record the clicked X and Y as the location of the city
     * 
     * @param path 
     */
    void setXY(const string& path){
        string path2 = "/Users/michshep/Desktop/TriumphNTragedy/sprites/MapSprite4.png";
        map_sprite = Spritesheet(path2.c_str(), app.renderer);
        SDL_Rect tar = {0,0,1512,982};
        string line;
        

        fstream map_file(path, std::ios_base::in);
        fstream out_file("out.txt");

        if (!map_file.is_open()){
            cout << "failed to open file " << path << endl;
            exit(1);
        }

        if (!out_file.is_open()){
            cout << "failed to open file out.txt" << endl; 
            exit(1);
        }

        int num_cities, num_countries;

        map_file >> num_cities;
        map_file >> num_countries;
        getline(map_file, line); //junk line

        SDL_Event event;
        out_file << num_cities << " " << num_countries << "\n";
        for (int i = 0; i < num_cities; i++){
            bool running = true;
            getline(map_file, line);
            out_file << line << " ";
            cout <<  line << endl;
            while (running){
                ClearScreen(app.renderer);

                map_sprite.drawSprite(&tar, 0, 0, 1512, 982);

                if (SDL_PollEvent(&event)){
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:{
                            int mouseX,mouseY;
                            SDL_GetMouseState(&mouseX, &mouseY);
                            out_file << mouseX-16 << " " << mouseY-16 << "\n";
                            cout << line << " "<< mouseX << " " << mouseY << endl;
                            running = false;
                            break;
                        }
                        case SDL_KEYDOWN:{
                            goto Skip;
                            break;
                        }
                    }
                }
                SDL_RenderPresent(app.renderer);
            }
        }

        Skip:
        for (int i = 0; i < num_cities; i ++){
            getline(map_file, line);
            if (line[0] <= '9'){
                i--;
                continue;
            }
            std::istringstream iss(line);
            string starting_city;
            iss >> starting_city;
            out_file << starting_city << " ";

            string city, border;
            while (!iss.fail()){
                iss >> city;
                iss >> border;
                out_file << "[" << city << " " << border << "] ";
            }
            out_file << "\n";
        }
    }

    /**
     * @brief Dev tool to Set the resource x and y coords for each city that has a resource
     * 
     */
    void setResXY(){
        initMap("/Users/michshep/Desktop/TriumphNTragedy/src/starter4.map");
        string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/SpriteMap0.png";

        sprite_map = Spritesheet(path.c_str(), app.renderer);

        string path2 = "/Users/michshep/Desktop/TriumphNTragedy/sprites/MapSprite4.png";
        map_sprite = Spritesheet(path2.c_str(), app.renderer);

        vector<std::pair<int, int>> coords;
        SDL_Rect tar = {0,0,1512,982};
        SDL_Event event;
        for (int i = 1; i < map.getCities().size(); i++){
            const auto& city = map.getCity(i);
            bool running = true;
            if (city->resource > 0){
                cout << city->name << " has " << city->resource << " resources, place at ";
                while (running){
                    ClearScreen(app.renderer);

                    map_sprite.drawSprite(&tar, 0, 0, 1512, 982);
                    drawCity(city->x, city->y, city->population_type);

                    if (SDL_PollEvent(&event)){
                        switch (event.type) {
                            case SDL_MOUSEBUTTONDOWN:{
                                int mouseX,mouseY;
                                SDL_GetMouseState(&mouseX, &mouseY);
                                coords.push_back(std::make_pair(mouseX, mouseY));
                                cout << mouseX << " " << mouseY << endl;
                                running = false;
                                break;
                            }
                            case SDL_KEYDOWN:{
                                goto Skip;
                                break;
                            }
                        }
                    }
                    SDL_RenderPresent(app.renderer);
                }            
            }
            else{
                coords.push_back(std::make_pair(0, 0));
            }
        }
        for (const auto& a : coords){
            cout << a.first << " " << a.second << endl;
        }

        Skip:
        exit(0);
    }

    /**
     * @brief Checks if the joy stick movement is within the accepted range of movement (fights stick drift)
     * 
     * @param move The degree of the joystick movement 
     * @return true The movement is acceptable 
     * @return false The movement is unacceptable (in the dead zone) 
     */
    bool pastDeadZone(const int& move) const{
        return !(move > -JOYSTICK_DEADZONE && move < JOYSTICK_DEADZONE);
    }

    /**
     * @brief Takes a joy axis movement and scales it to be from [0.0, 1.0] bases on a min movement of -32000 and max movement of 32000
     * 
     * @param x The joy axis movement
     * @return double The scaled joy axis movement
     */
    double scaleAxis(const double& x) const{
        return 2.0 * ((SDL_clamp(x, -32000, 32000) - -32000.f) / (32000 - - 32000.f)) - 1.0;
    
    }

};