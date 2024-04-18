#pragma once

#include "Player.h"
/**
 * @brief The main controller of the game and controls sequence of play
 * 
 */
class Runner{
private:
    int num_players; /**< Number of player in game (2 || 3 but hopefully can make a 1)*/

    Player players[3]; 

    Map map; /**< Map of the game and nations/waters*/

    size_t year; /**<Current year the player is in (goes from 1936 to 1945)*/

    Dice die;

    queue<ActionCard*> action_deck;

    vector<ActionCard*> action_discard;

    queue<InvestmentCard*> invest_hand;

    vector<InvestmentCard*> invest_discard;

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

        //- Create Map
        initMap("/Users/michshep/Desktop/TriumphNTragedy/src/starter.map");
        
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
        Unit* test = new Unit(1, WEST, INFANTRY);
        map.getCity("London")->addUnit(test);
        size_t result = canMove(test, "London", "Paris");

        printf("%zu\n", result);

        printf("%zu\n", canMove(test, "London", "Ruhr"));

        return 0;
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
    void newNear();

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

    //&Checking on map

    /**
     * @brief Goes over the players holdings over the map and sums up their pop, res, CV
     * 
     * @param player 
     * @return true No changes were made from the stored attributes
     * @return false Changes were made from stale attributes
     */
    bool mapPlayer(Player& player);

    //&Unit Actions

    //- Movement 
    void landMovement(Unit* unit, const string name);

    /**
     * @brief Checks if that unit is able to move into that city
     * 
     * @param unit The unit moving
     * @param name The target City
     * @return size_t How much movement would be left (returns INFI if it can't)
     */
    size_t canMove(Unit* unit,  const string start, const string name);

    size_t getNumPlayers() const{
        return num_players;
    }

    void freeMemory(){
        map.freeMemory();
    }

private:
    void printMemo(size_t memo[][5]) const;

};