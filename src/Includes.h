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

#include <stack>
using std::stack;

#include <cmath>
using std::pow;

#include <random>
#include <algorithm>
using std::shuffle;

#include "../include/SDL2/SDL.h"

#include "../include/SDL2_image/SDL_image.h"

#include "../include/SDL2/SDL_gamecontroller.h"

#define END_YEAR 1945;

#define START_YEAR 1936;

#define INFI SIZE_MAX;

const int JOYSTICK_DEADZONE = 14000;


enum CityType {WEST, AXIS, USSR, NEUTRAL, NEUTRAL_AT_WAR, WATER};

enum PowerType {GREAT, MAJOR, COLONY, MINOR, NONE, SEA};

enum PopulationType {EMPTY, TOWN, CITY, CAPITAL_CITY, SUB_CAPITAL, MAIN_CAPITAL};

enum ResourceType {NORMAL, TRANS_ATLANTIC};

enum BorderType {NA, OCEAN, DEEP_OCEAN, COAST, WATER_STRAIT, COAST_MOUNTAIN, COAST_FOREST, COAST_RIVER, COAST_PLAINS, MOUNTAIN, FOREST, RIVER, PLAINS, LAND_STRAIT}; //NA means not connected

enum UnitClass {CLASS_A, CLASS_N, CLASS_G, CLASS_S};

enum UnitType {FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY};

enum UnitCountry {BRITIAN_U, FRANCE_U, USA_U, GERMANY_U, ITALY_U, USSR_U, NEUTRAL_U};

enum Season {SUMMER, FALL, SPRING, WINTER};

enum DowState {PEACE, DECLARED, VICTIM};

enum InvestType {TECHNOLOGY, INTELLIGENCE, YEAR};

enum ActionType {DIPLOMACY, WILD};

enum InfluenceType {UNALIGNED, ASSOCIATES, PROTECTORATES, SATELLITES};

enum BoardState {HOME_BOARD, PRODUCTION_BOARD, GOVERNMENT_BOARD};

enum ButtonMovements {NORTH_D, WEST_D, SOUTH_D, EAST_D};

enum Tech   {LSTs, MOTORIZED_INFANTRY, NAVAL_RADAR, ROCKET_ARTILLERY, HEAVY_TANKS, HEAVY_BOMBERS, PERCISION_BOMBERS, JETs, SONAR, AIRDEFENCE_RADAR, 
            COUP, CODE_BREAKER, AGENT, MOLE, SABOTAGE, SPY_RING, DOUBLE_AGENT,
            ATOMIC_ONE, ATOMIC_TWO, ATOMIC_THREE, ATOMIC_FOUR, Y_1938, Y_1940, Y_1942, Y_1944};

//enum State {ADVANCE_YEAR, VICTORY_CHECK, RESHUFFLE, PEACE_DIVIDENDS, TURN_ORDER, NEW_YEAR_RES, PRODUCTION, GOVERNMENT, HAND_CHECK};

const string NATIONALITY_STRING[7] = {"BRITISH", "FRANCE", "USA", "GERMAN", "ITALY", "USSR", "NEUTRAL"};

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

const int MAX_CV_TABLE[8][7] = { //BRITIAN, FRANCE, USA, GERMANY, ITALY, USSR, neautral
    {4, 3, 4, 4, 3, 3, 3}, //Fort
    {4, 3, 4, 4, 3, 3, 0}, //Air
    {4, 3, 4, 4, 3, 3, 0}, //Carrir
    {4, 3, 4, 4, 3, 3, 0}, //Sub
    {4, 3, 4, 4, 3, 3, 0}, //Fleet
    {4, 3, 4, 4, 3, 3, 0}, //Tank
    {4, 3, 4, 4, 3, 3, 0}, //Infantry
    {0, 0, 0, 0, 0, 3, 0}  //Convoy
};

const Uint8 COLOR_TABLE[6][3] = {
    {16, 28, 238}, //WEST - blue
    {142, 143, 158}, //AXIS - grey
    {210, 13, 13}, //USSR - red
    {251, 160, 6}, //NEUTRAL - orange
    {233, 99, 6}, //NEUTRAL_AT_WAR - blood-oragen
    {131, 236, 232}  //WATER - light blue
};

const int BORDER_COLOR[14][3]{ // NA, OCEAN, DEEP_OCEAN, STRAIT, COAST, COAST_MOUNTAIN, COAST_FOREST, COAST_RIVER, COAST_PLAINS, MOUNTAIN, FOREST, RIVER, PLAINS
    {0,0,0},            //NA
    {0, 59, 255},        //OCEAN
    {4, 35, 137},        //DEEP_OCEAN
    {4, 136, 137},         //COAST
    {245, 255, 78},     //WATER_STRAIT
    {51, 189, 190},        //COAST_MOUNTAIN
    {60, 165, 98},    //COAST_FOREST
    {92, 193, 176},    //COAST_RIVER
    {82, 90, 111},    //COAST_PLAINS
    {79, 79, 79},    //MOUNTAIN
    {37, 224, 75},    //FOREST
    {54, 236, 237},    //RIVER
    {155, 255, 174},    //PLAINS
    {196, 237, 49}    //LAND_STRAIT
};

const int UNIT_COLOR[7][3]{ //BRITIAN, FRANCE, USA, GERMANY, ITALY, USSR, neautral
    {11, 56, 208}, //britian 
    {36, 226, 208}, //france
    {42, 171, 85}, //usa
    {178, 191, 196}, //germany
    {210, 200, 128}, //italy
    {213, 19, 19}, //ussr_u
    {255, 191, 58} //neutral_u
};

const bool SEVEN_SEGMENT_DISPLAY[10][7] = { 
    { 1,1,1,1,1,1,0 }, // display '0'
    { 0,1,1,0,0,0,0 }, // display '1'
    { 1,1,0,1,1,0,1 }, // display '2'
    { 1,1,1,1,0,0,1 }, // display '3'
    { 0,1,1,0,0,1,1 }, // display '4'
    { 1,0,1,1,0,1,1 }, // display '5'
    { 1,0,1,1,1,1,1 }, // display '6'
    { 1,1,1,0,0,0,0 }, // display '7'
    { 1,1,1,1,1,1,1 }, // display '8'
    { 1,1,1,0,0,1,1 }  // display '9'
};

const int HOME_BOARD_BUTTONS[9][8] = { //id is the index n, w, s, e, x, y, w, h
    {3, 4, 1, 6, 192, 111, 579, 102}, //0
    {0, 4, 2, 7, 192, 231, 579, 102}, //1 
    {1, 5, 3, 8, 240, 360, 483, 96}, //2
    {2, 5, 0, 8, 429, 465, 102, 102}, //3
    {5, 6, 5, 0, 12, 177, 102, 102}, //4
    {4, 7, 4, 1, 12, 294, 102, 102}, //5
    {8, 0, 7, 4, 852, 45, 102, 102}, //6
    {6, 1, 8, 5, 852, 207, 105, 102}, //7
    {7, 3, 6, 5, 852, 366, 102, 102}, //8
};

const int UNIT_SPRITE_OFFSET[7]{ //"BRITISH", "FRANCE", "USA", "GERMAN", "ITALY", "USSR", "NEUTRAL"
    0, 5, 9, 14, 19, 23, 27
};

struct Button{
    int x;
    int y;

    int width;
    int height;

    string name;
    int id;

    Button* north;
    Button* west;
    Button* south;
    Button* east;
    Button* north_east;
    Button* north_west;
    Button* south_east;
    Button* south_west;

    Button(){
        name = "default";
        id = -1;
    }

    Button(const int x, const int y, const int width, const int height, const string name, const int id, Button* north, Button* west, Button* south ,Button* east, Button* north_east ,Button* north_west , Button* south_east, Button* south_west)
    : x(x), y(y), width(width), height(height), name(name), id(id), north(north), west(west), south(south), east(east), north_east(north_east), north_west(north_west), south_east(south_east), south_west(south_west){

    }
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
        const int HEIGHT = 982;

        const int center_x = WIDTH /2;
        const int center_y = HEIGHT /2;
    };

   
};

class Spritesheet{
private:
    SDL_Rect clip;
    SDL_Texture* spritesheet_image;
    SDL_Renderer* renderer;

public:
    Spritesheet(){
    }

    Spritesheet(char const *path, SDL_Renderer* renderer, int width=32, int height=32){
        this->renderer = renderer;

        auto spritesheet_surface = IMG_Load(path);
        if (!(spritesheet_image = SDL_CreateTextureFromSurface(renderer, spritesheet_surface))){
            cout << "Creating spritesheet failed with error: " << SDL_GetError() << endl;
        }

        clip.w = width;
        clip.h = height;
    }

    void freeMemory(){
        SDL_DestroyTexture(spritesheet_image);
        spritesheet_image = nullptr;
    }

    void selectSprite(int x, int y=0, int clip_x=-1, int clip_y=-1){
        clip.x = x * ((clip_x == -1)? clip.w : clip_x);
        clip.y = y * ((clip_y == -1)? clip.h : clip_y);

        if (clip_y !=-1){
            clip.w = clip_x;
            clip.h = clip_y;
        }
      
    }
    void drawSelectedSprite(SDL_Rect* position){
        if (SDL_RenderCopy(renderer, spritesheet_image, &clip, position) < 0){ //was an error
            cout << "Drawing selected sprite failed with error: " << SDL_GetError() << endl;
        }
    }

    void drawSprite(SDL_Rect* position, int row, int pos, int size_x=32, int size_y=32, int offset=0, int unscaledX=0, int unscaledY=0){
        position->x += offset;
        clip.x = pos * size_x + unscaledX;
        clip.y = row * size_y + unscaledY;
        clip.w = size_x;
        clip.h = size_y;

        if (SDL_RenderCopy(renderer, spritesheet_image, &clip, position) < 0){ //was an error
            cout << "Drawing sprite failed with error: " << SDL_GetError() << endl;
        }
    }
};

// Application
struct App{
    SDL_Window* window;
    SDL_Renderer* renderer;

    Graphics::Screen screen;
};