#pragma once

#include "Player.h"
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

    queue<ActionCard*> action_deck; /**< Draw deck of the action cards*/

    vector<ActionCard*> action_discard; /**< Draw deck of the action cards*/

    queue<InvestmentCard*> invest_hand; /**< Draw deck of the invest cards*/

    vector<InvestmentCard*> invest_discard; /**< Discard pile of investment cards*/

    vector<PeaceChit> peace_dividends_bag; /**< Holds all the unpulled peace dividends*/

    Player* start_player; /**Player who will start the turn*/

    Player* active_player; /**< Player whose turn it is currently*/

    App app;

public:
    /**
     * @brief Construct a new Runner object that intializes the map and players
     * 
     * @param default_mode true if should go off of default or read in through the map
     */
    Runner(bool default_mode = 1){
        //- Set random seed

        srand(100);

        //- Init Dice
        die = Dice(1, 6);

        //- Set starting year
        year = START_YEAR;
        end_year = END_YEAR;
        year--;

        //- Create Map
        initMap("/Users/michshep/Desktop/TriumphNTragedy/src/starter2.map");

        start_player = &players[1]; //AXIS start
        
        //- Init Players
        players[0] = Player("Michael", WEST);
        players[1] = Player("Taiga", AXIS);
        players[2] = Player("Luke", USSR);
        
        if (!default_mode){
            mapPlayer(players[0]);
            mapPlayer(players[1]);
            mapPlayer(players[2]);
        }

        players[0].print();
        players[1].print();
        players[2].print();

        if (InitApplication() == false){
            ShutdownApplication();
            exit(1);
        }

        const unsigned int seed = 42;
        std::mt19937 g(seed);

        peace_dividends_bag = {{2,0,0}, {2,0,0}, {2,0,0}, {2,0,0},
                               {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, 
                               {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};
        shuffle(peace_dividends_bag.begin(), peace_dividends_bag.end(), g);
    }

    size_t test(){
        active_player = &players[0];

        //For B
        Unit* wInfa0 = new Unit(1, BRITIAN_U, INFANTRY);
        Unit* wAir0 = new Unit(2, BRITIAN_U, AIR);

        Unit* uInfa0 = new Unit(3, USSR_U, INFANTRY);
        Unit* uInfa1 = new Unit(4, USSR_U, INFANTRY);

        map["B"]->addUnit(wInfa0);
        map["B"]->addUnit(wAir0);
        map["B"]->addUnit(uInfa0);
        map["B"]->addUnit(uInfa1);

        //For A
        Unit* aTank0 = new Unit(5, GERMANY_U, TANK);
        Unit* aTank1 = new Unit(11, ITALY_U, TANK);

        map["A"]->addUnit(aTank0);
        map["A"]->addUnit(aTank1);

        //For J
        Unit* uInfa2 = new Unit(6, USSR_U, INFANTRY);
        Unit* uAir0 = new Unit(7, USSR_U, AIR);
        Unit* uAir1 = new Unit(8, USSR_U, AIR);

        map["K"]->addUnit(uInfa2);
        map["K"]->addUnit(uAir0);
        map["K"]->addUnit(uAir1);

        //For I
        Unit* wTank1 = new Unit(9, FRANCE_U, TANK);

        map["C"]->addUnit(wTank1);

        //For H 
        Unit* nFort = new Unit(10, NEUTRAL_U, FORTRESS);
        map["H"]->addUnit(nFort);

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

    //& Sequence of Play
    //- round handler
    bool run();

    //- New Year
    CityType newNear();

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

    void reshuffle();

    void peaceDividends();

    void newYearRes();

    void handCheck(Player* player);

    //&Checking on map

    /**
     * @brief Goes over the players holdings over the map and sums up their pop, res, CV
     * 
     * @param player 
     * @return true No changes were made from the stored attributes
     * @return false Changes were made from stale attributes
     */
    bool mapPlayer(Player& player);

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
    }

    //& Runner Getters and Setters
    const Map& getMap() const{
        return map;
    }

private:
    bool canDisengage(Unit* unit, const string start, const string end);

    void printMemo(size_t memo[][5]) const;

private:
    //!!! Graphics things
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
    void ClearScreen();

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
     * @brief An array that holds the pointers to functions that draw the units, use4s the unit's type as an index
     * 
     */
    void (Runner::* draw [8])(Unit*, int, int, float) const = {&Runner::drawFortress, &Runner::drawAir, &Runner::drawCarrier, &Runner::drawSub, &Runner::drawFleet, &Runner::drawTank, &Runner::drawInfantry, &Runner::drawConvoy};

    /**
     * @brief Draws the city onto the renderer and the units that are in this city
     * 
     * @param city 
     */
    void drawCity(City* city);

    /**
     * @brief Get the City Sprite object
     * 
     * @param city The city being drawn
     * @return int The index of the sprite in the sprite map
     */
    int getCitySprite(City* city);

    /**
     * @brief Draws a fortress of the units nationality located at the given coords
     * 
     * @param unit The unit thats a fortress
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawFortress(Unit* unit, const int x, const int y, const float scale) const;

    /**
     * @brief Draws a air unit of the units nationality located at the given coords
     * 
     * @param unit The unit thats a air unit
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawAir(Unit* unit, const int x, const int y, const float scale) const;

    /**
     * @brief Draws a carrier of the units nationality located at the given coords
     * 
     * @param unit The unit thats a carrier
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawCarrier(Unit* unit, const int x, const int y, const float scale) const;

    /**
     * @brief Draws a submarine unit of the units nationality located at the given coords
     * 
     * @param unit The unit thats a sub
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawSub(Unit* unit, const int x, const int y, const float scale) const;

    /**
     * @brief Draws a fleet of the units nationality located at the given coords
     * 
     * @param unit The unit thats a fleet
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawFleet(Unit* unit, const int x, const int y, const float scale) const;
    /**
     * @brief Draws a tank of the units nationality located at the given coords
     * 
     * @param unit The unit thats a tank
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawTank(Unit* unit, const int x, const int y, const float scale) const;

     /**
     * @brief Draws a infantry of the units nationality located at the given coords
     * 
     * @param unit The unit thats a infantry
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawInfantry(Unit* unit, const int x, const int y, const float scale) const;

     /**
     * @brief Draws a conoy of the units nationality located at the given coords
     * 
     * @param unit The unit thats a convoy
     * @param x The x coord of the unit (upper left corner is the origin)
     * @param y The x coord of the unit (upper left corner is the origin)
     * @param scale The scale to draw the unit (origin is still x,y); scale of 1 is 5x5
     */
    void drawConvoy(Unit* unit, const int x, const int y, const float scale) const;
    
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
    void drawNumber(const int num, const int x, const int y, const float scale, const uint8_t r=255, const uint8_t g=255, const uint8_t b=255) const;

};