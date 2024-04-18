#pragma once

#include "Player.h"
/**
 * @brief The main controller of the game and controls sequence of play
 * 
 */
class Runner{
private:
    int num_players; /**< Number of player in game (2 || 3 but hopefully can make a 1)*/

    Map map; /**< Map of the game and nations/waters*/

    size_t year; /**<Current year the player is in (goes from 1936 to 1945)*/

    Dice die;

public:
    /**
     * @brief Construct a new Runner object that intializes the map and players
     * 
     */
    Runner(){
        srand(100);

        die = Dice(1, 6);

        year = START_YEAR;

        initMap("/Users/michshep/Desktop/TriumphNTragedy/src/starter.map");
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
};