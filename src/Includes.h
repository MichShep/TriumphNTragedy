#pragma once

#include <iostream>
using std::cout;
using std::endl;
using std::cout;
using std::string;
using std::cin;

#include <fstream>
using std::fstream;

#include <vector>
using std::vector;
using std::find;

#include <unordered_map> 
using std::unordered_map;

#include <cstdio>
using std::printf;

#include <sstream>

#include <queue>
using std::queue;
using std::priority_queue;

#include "/opt/homebrew/Cellar/sdl2/2.30.2/include/SDL2/SDL.h"

#include "/opt/homebrew/Cellar/sdl2_ttf/2.22.0/include/SDL2/SDL_ttf.h"

#define END_YEAR 1946;

#define START_YEAR 1936;

#define INFI SIZE_MAX;
enum CityType {WEST, AXIS, USSR, NEUTRAL, NEUTRAL_AT_WAR, WATER};

enum PowerType {GREAT, HOME, MINOR, NONE, SEA};

enum ResourceType {NORMAL, TRANS_ATLANTIC};

enum BorderType {NA, COAST, STRAIT, MOUNTAIN, FOREST, RIVER, PLAINS, OCEAN}; //NA means not connected

enum UnitClass {CLASS_A, CLASS_N, CLASS_G, CLASS_S};

enum UnitType {FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY};

enum Season {SPRING, SUMMER, FALL, WINTER};

enum Tech {AIR_DEFENSE, FIRST_FIRE, INDUSTRIAL_ESPIONAGE, SCIENCE};

const int FIREPOWER_TABLE[8][4] = { // Damage against {A N G S}
    {2, 3, 4, 3}, //Fort
    {3, 1, 1, 1}, //Air
    {2, 2, 1, 2}, //Carrir
    {2, 2, 1, 2}, //Sub
    {1, 3, 1, 2}, //Fleet
    {0, 0, 2, 0}, //Tank
    {1, 1, 3, 0}, //Infantry
    {0, 0, 0, 0}  //Convoy
};

const int COLOR_TABLE[6][3] = {
    {16, 28, 238}, //WEST - blue
    {142, 143, 158}, //AXIS - grey
    {210, 13, 13}, //USSR - red
    {251, 160, 6}, //NEUTRAL - orange
    {233, 99, 6}, //NEUTRAL_AT_WAR - blood-oragen
    {131, 236, 232}  //WATER - light blue
};

const int BORDER_COLOR[8][3]{
    {0,0,0}, //NA
    {0,198,226}, //Coast
    {9,132,149}, //Strait
    {61,63,63}, //Mountain
    {25,198,27}, //Forest
    {159, 244, 255}, //River
    {221, 239, 198}, //Plains
    {131, 236, 232} //Ocean
};

const int UNIT_COLOR[8][3]{ //FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY
    {170, 118, 63}, //Fortress 
    {169, 99, 176}, //Air
    {172, 131, 226}, //Carrier
    {138, 191, 27}, //Sub
    {18, 100, 98}, //Fleet
    {158, 0, 26}, //Tank
    {3, 122, 9}, //Infantry
    {254, 255, 141} //Convoy
};

//Colors
namespace Colors{
    const SDL_Color BLACK = {0, 0, 0, 255};
    const SDL_Color GREEN = {0, 255, 0, 255};
}

//Graphics
namespace Graphics{
    struct Screen{
        const int WIDTH = 1512;
        const int HEIGHT = 1964/2;

        const int center_x = WIDTH /2;
        const int center_y = HEIGHT /2;
    };
};

// Application
struct App{
    SDL_Window* window;
    SDL_Renderer* renderer;

    Graphics::Screen screen;

};