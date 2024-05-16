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

#include <cmath>
using std::pow;

#include <random>
#include <algorithm>
using std::shuffle;

#include "../include/SDL2/SDL.h"

#include "../include/SDL2_image/SDL_image.h"

#define END_YEAR 1945;

#define START_YEAR 1936;

#define INFI SIZE_MAX;

enum CityType {WEST, AXIS, USSR, NEUTRAL, NEUTRAL_AT_WAR, WATER};

enum PowerType {GREAT, MAJOR, COLONY, MINOR, NONE, SEA};

enum PopulationType {EMPTY, TOWN, CITY, CAPITAL_CITY, SUB_CAPITAL, MAIN_CAPITAL};

enum ResourceType {NORMAL, TRANS_ATLANTIC};

enum BorderType {NA, COAST, STRAIT, MOUNTAIN, FOREST, RIVER, PLAINS, OCEAN}; //NA means not connected

enum UnitClass {CLASS_A, CLASS_N, CLASS_G, CLASS_S};

enum UnitType {FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY};

enum UnitCountry {BRITIAN_U, FRANCE_U, USA_U, GERMANY_U, ITALY_U, USSR_U, NEUTRAL_U};

enum Season {SPRING, SUMMER, FALL, WINTER};

enum DowState {PEACE, DECLARED, VICTIM};

enum InvestType {TECHNOLOGY, INTELLIGENCE, YEAR};

enum ActionType {DIPLOMACY, WILD};

enum InfluenceType {UNALIGNED, ASSOCIATES, PROTECTORATES, SATELLITES};

enum Tech {AIR_DEFENSE, FIRST_FIRE, INDUSTRIAL_ESPIONAGE, SCIENCE};

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

const int UNIT_SPRITE_OFFSET[7]{ //"BRITISH", "FRANCE", "USA", "GERMAN", "ITALY", "USSR", "NEUTRAL"
    0, 5, 9, 14, 19, 23, 27
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
        const int HEIGHT = 912;

        const int center_x = WIDTH /2;
        const int center_y = HEIGHT /2;
    };
};

class Spritesheet{
private:
    SDL_Rect clip;
    SDL_Texture* spritesheet_image;

public:
    Spritesheet(){
    }

    Spritesheet(char const *path, SDL_Renderer* renderer, int width=32, int height=32){
        auto spritesheet_surface = IMG_Load(path);
        spritesheet_image = SDL_CreateTextureFromSurface(renderer, spritesheet_surface);

        clip.w = width;
        clip.h = height;
    }

    ~Spritesheet(){
    }

    void selectSprite(int x, int y=0){
        clip.x = x * clip.w;
        clip.y = y * clip.h;
    }
    void drawSelectedSprite(SDL_Renderer* renderer, SDL_Rect* position){
        SDL_RenderCopy(renderer, spritesheet_image, &clip, position);
    }
};

// Application
struct App{
    SDL_Window* window;
    SDL_Renderer* renderer;

    Graphics::Screen screen;

};