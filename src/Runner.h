#pragma once

#include "Player.h"
/**
 * @brief The main controller of the game and controls sequence of play
 * 
 */
class Runner{
private:
    int num_players; /**< Number of player in game (3 but hopefully can make a 1)*/

    Player players[3]; /**Holds each playe object with nationality as index 0: West 1: Axis 2: USSR*/ 

    Map map; /**< Map of the game and nations/waters*/

    size_t year; /**< Current year the player is in (goes from 1936 to 1945)*/

    Dice die; /**< Dice used to roll decisions, default a D6*/

    queue<ActionCard*> action_deck; /**< Draw deck of the action cards*/

    vector<ActionCard*> action_discard; /**< Draw deck of the action cards*/

    queue<InvestmentCard*> invest_hand; /**< Draw deck of the invest cards*/

    vector<InvestmentCard*> invest_discard; /**< Discard pile of investment cards*/

    Player* start_player; /**Player who will start the turn*/

    Player* active_player; /**< Player whose turn it is currently*/

    App& app;

public:
    /**
     * @brief Construct a new Runner object that intializes the map and players
     * 
     * @param default_mode true if should go off of default or read in through the map
     */
    Runner(App& app, bool default_mode = 1):app(app){
        //- Set random seed
        srand(100);

        //- Init Dice
        die = Dice(1, 6);

        //- Set starting year
        year = START_YEAR;
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
    }

    size_t test(){
        active_player = &players[0];

        //For B
        Unit* wInfa0 = new Unit(1, WEST, INFANTRY);
        Unit* wAir0 = new Unit(2, WEST, AIR);

        Unit* uInfa0 = new Unit(3, USSR, INFANTRY);
        Unit* uInfa1 = new Unit(4, USSR, INFANTRY);

        map["B"]->addUnit(wInfa0);
        map["B"]->addUnit(wAir0);
        map["B"]->addUnit(uInfa0);
        map["B"]->addUnit(uInfa1);

        //For A
        Unit* aTank0 = new Unit(5, AXIS, TANK);

        map["A"]->addUnit(aTank0);

        //For J
        Unit* uInfa2 = new Unit(6, USSR, INFANTRY);
        Unit* uAir0 = new Unit(7, USSR, AIR);
        Unit* uAir1 = new Unit(8, USSR, AIR);

        map["K"]->addUnit(uInfa2);
        map["K"]->addUnit(uAir0);
        map["K"]->addUnit(uAir1);

        //For I
        Unit* wTank1 = new Unit(9, WEST, TANK);

        map["C"]->addUnit(wTank1);
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
     * @param nationality The nationality of the current player 
     * @return vector<City*> Vector of all cities the player is batteling for
     */
    vector<City*> getBattles(const CityType nationality); 

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

};