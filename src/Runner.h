#pragma once

#include "Map.h"
/**
 * @brief The main controller of the game and controls sequence of play
 * 
 */
class Runner{
private:
    int num_players;

    Map map; /**< Map of the game and nations/waters*/

public:
    /**
     * @brief Creates the game map including nations and cities and connections
     * 
     * @return true  Was able to succesfully make the map
     * @return false Encountered an error while making
     */
    bool initMap(string map_file);
};