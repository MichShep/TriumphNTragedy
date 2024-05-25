#pragma once

#include "Player.h"

static int SDLCALL event_filter(void* userdata, SDL_Event* event) {
    if (event->type == SDL_JOYAXISMOTION) {
        int value = event->jaxis.value;
        // Apply deadzone filtering
        if (value > -JOYSTICK_DEADZONE && value < JOYSTICK_DEADZONE) {
            return false; // Filter out this event
        }
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

    Dice die; /**< Dice used to roll decisions, default a D6*/

    vector<ActionCard*> action_deck; /**< Draw deck of the action cards*/

    vector<ActionCard*> action_discard; /**< Draw deck of the action cards*/

    vector<InvestmentCard*> invest_deck; /**< Draw deck of the invest cards*/

    vector<InvestmentCard*> invest_discard; /**< Discard pile of investment cards*/

    vector<PeaceChit> peace_dividends_bag; /**< Holds all the unpulled peace dividends*/

    Player* start_player; /**Player who will start the turn*/

    Player* current_player;

    Player* turn_order[3];

    const unsigned int seed = time(NULL);
    
    std::mt19937 g;

    App app; /**< The stuct that holds all window and renderer for SDL2 and shows the main board*/

    App powers_app[3];

public:
    /**
     * @brief Construct a new Runner object that intializes the map and players
     * 
     * @param default_mode true if should go off of default or read in through the map
     */
    Runner(bool default_mode = 1){
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
            setXY("/Users/michshep/Desktop/TriumphNTragedy/src/starter4.map");
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
        map_sprite = Spritesheet(path2.c_str(), app.renderer);

        powers_sprite_map[0] = Spritesheet(path.c_str(), powers_app[0].renderer);
        powers_sprite_map[1] = Spritesheet(path.c_str(), powers_app[1].renderer);
        powers_sprite_map[2] = Spritesheet(path.c_str(), powers_app[2].renderer);

        powers_map_sprite[0] = Spritesheet(path2.c_str(), powers_app[0].renderer);
        powers_map_sprite[1] = Spritesheet(path2.c_str(), powers_app[1].renderer);
        powers_map_sprite[2] = Spritesheet(path2.c_str(), powers_app[2].renderer);


        //for handling stick drift
        SDL_SetEventFilter(event_filter, NULL);
    }

    size_t test(){
        map["London"]->occupants[0].push_back(new Unit(1, BRITIAN_U, FLEET));

        map["Paris"]->occupants[0].push_back(new Unit(1, BRITIAN_U, INFANTRY));
        map["Paris"]->occupants[0].push_back(new Unit(2, USA_U, TANK));
        map["Paris"]->occupants[0].push_back(new Unit(3, FRANCE_U, AIR));
        map["Paris"]->occupants[0].push_back(new Unit(1, BRITIAN_U, FLEET));
        map["Paris"]->occupants[0].push_back(new Unit(2, BRITIAN_U, CARRIER));
        map["Paris"]->occupants[0].push_back(new Unit(1, USA_U, SUB));
        map["Paris"]->occupants[0].push_back(new Unit(1, BRITIAN_U, TANK));
        map["Paris"]->occupants[0].push_back(new Unit(4, BRITIAN_U, FORTRESS));
        map["Paris"]->occupants[0].back()->combat_value = 4;

        map["Budapest"]->occupants[0].push_back(new Unit(1, BRITIAN_U, INFANTRY));

        map["Marseille"]->blockcade = true;

        map["Ankara"]->ruler_type = WEST;
        map["Ankara"]->blockcade = true;
        players[0].add(map.getCity("Ankara"));

        map["Iraq"]->blockcade = true;

        map["Gibraltar"]->ruler_type = AXIS;


        return 0;
    }

    void test1(){
        move(map["A"]->occupants[1][0], "A", "H");


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
    bool run();

    //- New Year
    CityType newYear();

    //- Production Phase
    void production();

    //- Government Phase
    void government();

    //- Spring Season
    void spring();

    //- Summer Season
    void summer();

    //- Check Blockades
    void blockade();

    //- Fall Season
    void fall();

    //- Winter Season
    void winter();

    void reshuffle(const bool animation);

    void peaceDividends();

    void newYearRes();

    void handCheck(Player* player);

    bool deal(Player* player, size_t amount, const char state='A');

    void decideTurnOrder();

    //&Checking on map

    /**
     * @brief Goes over the players holdings over the map and sums up their pop, res, CV
     * 
     * @param player 
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
    bool checkTradeRoutes(Player& player, string main_capital);

    //&&&Unit Actions


    //& Movement 
    bool move(Unit* unit, const string start, const string end);

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

    //& Runner Getters and Setters
    const Map& getMap() const{
        return map;
    }

private:
    bool canDisengage(Unit* unit, const string start, const string end);

    void printMemo(size_t memo[][5]) const;

private:  //!!! Graphics things

    Spritesheet sprite_map; /**< A png that holds every sprite in the game and can be indexed into and a clip pulled from in 32 by 32 pixels*/

    Spritesheet map_sprite;

    Spritesheet powers_sprite_map[3];  /**< A png that holds every sprite in the game and can be indexed into and a clip pulled from in 32 by 32 pixels but used for the second renderer*/

    Spritesheet powers_map_sprite[3];

    //& Controller Things
    SDL_GameController *west_controller=nullptr;

    SDL_GameController *axis_controller=nullptr;

    SDL_GameController *ussr_controller=nullptr;

    SDL_GameController* controllers[3]= {nullptr, nullptr, nullptr};



    //- Init Functions
    /**
     * @brief Initalizes SDL2 and the window
     * 
     * @return true Initalized succesfully
     * @return false Failexcd to initalize
     */
    bool InitSDL();

    /**
     * @brief Clears the screen so the screen can 'update'
     * 
     */
    void ClearScreen(SDL_Renderer* renderer);

    /**
     * @brief Deletes the windows and frees memory specifically used by SDL
     * 
     */
    void ShutdownApplication();

    /**
     * @brief Initalizes the 'app', the struct that hlds the renderer and the window
     * 
     * @return true Initalized succesfully
     * @return false Failexcd to initalize
     */
    bool InitApplication();

    //- Game Displaying
    /**
     * @brief Draws the city onto the renderer and the units that are in this city
     * 
     * @param city 
     */
    void drawCity(City* city, const bool resources=true);

    void drawCity(int x, int y, PopulationType population_type);

    void drawInfluence();

    /**
     * @brief Get the City Sprite object
     * 
     * @param city The city being drawn
     * @return int The index of the sprite in the sprite map
     */
    int getCitySprite(City* city);

    /**
     * @brief Draws a unit of the units nationality located at the given coords
     * 
     * @param renderer The screen that the unit will be drawn too
     * @param unit The target unit
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawUnit(SDL_Renderer* renderer, Unit* unit, const int x, const int y, const float scale);
    
    /**
     * @brief Draws all the connections between the cities and colors them based on the border 
     * 
     */
    void DrawConnections();

    /**
     * @brief Draws the current year and end year; shows the American flag and the level from 1941 to 1944
     * 
     */
    void DrawTimeTrack();

    /**
     * @brief Draws the players pop, res, ind, and DoW's onto the screen
     * 
     * @param player The player who is being drawn
     */
    void drawPlayerStats(Player& player);

    /**
     * @brief Takes any length number and draws it as a 7-segment at the x,y as the top left. Origional scale is 7*13 for one digit. Defaul color is black
     * 
     * @param num Number to render
     * @param x X coord of number origin
     * @param y Y coord of number origin
     * @param scale Scales draw size of the number
     * @param r The red value of the color (0, 255)
     * @param g The green value of the color (0, 255)
     * @param b The blue value of the color (0, 255) 
     */
    void drawNumber(SDL_Renderer* renderer, const int num, const int x, const int y, const float scale, const uint8_t r=255, const uint8_t g=255, const uint8_t b=255) const;

    /**
     * @brief Animation of the cards from the discard pile being added back
     * 
     * @param action_size Number of action cards to add back
     * @param invest_size Number of invest cards to add back
     */
    void reshuffleAnimation(const size_t& action_size, const size_t& invest_size);

    /**
     * @brief Draws the private view of the player including cards and VP and production levels and acheived tech
     * 
     * @param player The player whose card is being drawn
     * @param renderer The player's renderer
     */
    void drawPlayerBoard(const Player& player, SDL_Renderer* renderer, const int bought_action=0, const int bought_invest=0);

    void drawHomeBoard(const Player& player, SDL_Renderer* renderer);

    void drawProductionBoard(const Player& player, SDL_Renderer* renderer, const int bought_action, const int bought_invest);

    /**
     * @brief Takes the memo of the Dijkstra's knock-off II for finding trade routes and highlighting the route it takes
     * 
     * @param memo The completed memo
     * @param unblocked The list of cities who were unblockaded and there path will be shown
     */
    void drawMemoResolution(const size_t memo[][6], vector<City*> unblocked);
    
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
    bool inBox(int x, int y, int width, int height, int target_x, int target_y){
        return (target_x >= x && target_x <= x+width) && (target_y >= y && target_y <= y+height);
    }

    void drawTurnRoll(const int& result);

    void drawPeaceDividends(const bool west, const bool axis, const bool ussr);

    void drawMap(const bool cities, const bool influence, const bool resources, const bool connections, const bool render=true, const int& fps=-1);

    void setXY(const string& path){
        string path2 = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Artboard 1.png";
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

                map_sprite.drawSprite(app.renderer, &tar, 0, 0, 1512, 982);

                if (SDL_PollEvent(&event)){
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:{
                            int mouseX,mouseY;
                            SDL_GetMouseState(&mouseX, &mouseY);
                            out_file << mouseX << " " << mouseY << "\n";
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
};