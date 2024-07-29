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

#include <math.h>

#include <random>
#include <algorithm>
using std::shuffle;
using std::find;

#include <utility>
using std::pair;

#include "../include/SDL2/SDL.h"

#include "../include/SDL2_image/SDL_image.h"

#include "../include/SDL2/SDL_gamecontroller.h"

typedef Uint32 tick_t;

typedef Uint32 year_t;

#define END_YEAR 1945;

#define START_YEAR 1936;

#define NULL_YEAR 0;

#define INFI SIZE_MAX;

const int JOYSTICK_DEADZONE = 16000;

const int CONVOY_MOVEMENT = 2;

constexpr int CURSOR_SPEED = 5;

#define loopVal(v, i, a) ((v < i)? (a) : ((v>a)? (i) : (v)))

//held tick, tick, wait_time
#define pastWait(h, t, w)(h? (t - h > w) : (false))

#define isLand(b)(COAST_MOUNTAIN <= b && b <= LAND_STRAIT)

#define isNaval(b)((NA < b && b <= COAST_PLAINS) || b == LAND_STRAIT)

#define isAir(b)(b != NA)

#define isCoastal(b)((WATER_STRAIT <= b && b <= COAST_PLAINS) || b == LAND_STRAIT)

#define isStrait(b)(b == WATER_STRAIT || b == LAND_STRAIT || b == DEEP_STRAIT)

/**
 * @enum The Type of City Allegiance
 * @brief Is the cities ruler's allegiance and also doubles as using the player's power (WEST, AXIIS, USSR) as an index
 * 
 */
enum CityType {
    WEST, /**< Enum for the player who controls the West powers (Britian, France, USA) */
    AXIS, /**< Enum for the player who controls the Axis powers (Germany, Italy)*/
    USSR,  /**< Enum for the player who controls the USSR power (USSR)*/
    NEUTRAL,  /**< Enum for the cities who are neutral and not alligned with any powers */
    NEUTRAL_AT_WAR,  /**< Enum for the cities who are neutral but have been violated by a power*/
    WATER  /**< Enum for the water tiles (or empty cities)r*/
};

/**
 * @enum The Power Level of a Country
 * @brief Is the countries power level (i.e Britian:Great France:Major Syria:Colony Neutrals:Minor) and determines game actions like building units and invasion
 * 
 */
enum PowerType {
    GREAT, /**< Great Powers are the main players and cities of the WEST (Britian), AXIS (Germany), and USSR(USSR) */
    MAJOR, /**< Major Powers are the major allies of the Great powers West:France/USA, Axis:Italy, USSR:n/a*/
    COLONY, /**< Colonies are the colonies of both Great and Major powers taht start with extra units. when the major powers are defeated they become armed colonies */
    MINOR, /**< Minor powers are for all neutrals that aren't (currently) alligned with a power */
    NONE, /**< None is for water places where none rule them */
};

/**
 * @enum The Type of Population a City has
 * @brief Is the population level of a city that determines how much POP is added and the muster when swayed and goes towards victory goals
 * 
 */
enum PopulationType {
    EMPTY, /**< No population for water areas */
    TOWN, /**< A town gives 0 POP and 1 muster */
    CITY, /**< A city gives 1 POP and 2 muster */
    CAPITAL_CITY, /**< A capital city is only for neutral countries and gives 1 POP and 3 muster */
    SUB_CAPITAL, /**< Sub capitals are the capitals of Major powers and when captured give 2 POP and 0 muster*/
    MAIN_CAPITAL /**< The main capital of powers and when captured will arm colonies and prevent new units from being built and give 3 POP*/
};

/**
 * @enum The Type of Resource a City has
 * @brief Resources attribute to RES but need to reach the main capital of the player. If they go through the atlantic only the Trans atlantic resources (half the total) will be counted  
 * 
 */
enum ResourceType {
    NORMAL, /**< Normal resource that can't go around the atlantic */
    TRANS_ATLANTIC /**< Resources that can go aound the atlantic and half will be counted towards RES */
};

/**
 * @enum The Type of Border Between Two Cities
 * @brief The type of border/terrain between two cities that determines how many units can cross into battles and for trade routes. These are stored in an adjacency map
 * 
 */
enum BorderType {
    NA, /**< There is no connection between the two cities*/
    OCEAN, /**< The cities are connected by ocean */
    DEEP_OCEAN, /**< The cities are connected by a depp ocean and costs two movements since they cover so much area*/
    COAST, /**< A coast connection is from a land city to an ocean*/
    WATER_STRAIT, /**< Straits can be passed by water or land connections, this specifies it goes from a water into the strait or out*/
    COAST_MOUNTAIN, /**< Are two citeis connected by a mountain range but are also on the same coast line (used for sea units moving along coasts)*/
    COAST_FOREST, /**< Are two citeis connected by a forest but are also on the same coast line (used for sea units moving along coasts)*/
    COAST_RIVER, /**< Are two citeis connected by a river but are also on the same coast line (used for sea units moving along coasts)*/
    COAST_PLAINS, /**< Are two citeis connected by a plains but are also on the same coast line (used for sea units moving along coasts)*/
    MOUNTAIN, /**< Are two citeis connected by a mountain range*/
    FOREST, /**< Are two citeis connected by a forest */
    RIVER, /**< Are two citeis connected by a river*/
    PLAINS, /**< Are two citeis connected by a plains*/
    LAND_STRAIT /**< Straits can be passed by water or land connections, this specifies it goes from a land into the strait or out*/
};

/**
 * @enum The Class of the Unit
 * @brief The type of unit that determines movement limitations and rebasing/retreating
 */
enum UnitClass {
    CLASS_A, /**< Class Air that doesn't abide by border limtis and can ReBase*/
    CLASS_N, /**< Class Naval that doesn't abide by border limtis and can ReBase*/
    CLASS_G, /**< Class Ground has to abide by border limtis and cannot ReBase*/
    CLASS_S  /**< Class Sub that doesn't abide by border limtis and can escape*/
};

/**
 * @enum The Type of Unit
 * @brief Enums for the different type of units the players can build and fight with, which affects firepower/movement and order in battle
 * 
 */
enum UnitType {
    FORTRESS, /**< Fortress has the best firing capability and go first in battle but cannot move. They can be build in any friendly territory*/
    AIR, /**< Air doesn't abide to border limits and do bombing runs on capitals to lower IND, but without ground support they must rebase */
    CARRIER, 
    SUB, 
    FLEET, 
    TANK, 
    INFANTRY, 
    CONVOY
};

/**
 * @enum The nationality (or block color) of the unit
 * @brief Since they are all units controleld by the players, depending on their block color there is a limit to their amounts and where they can be built
 * 
 */
enum UnitCountry {
    BRITIAN_U, /**< British Units */
    FRANCE_U, /**< French Units */
    USA_U, /**< USA Units */
    GERMANY_U, /**< German Troops */
    ITALY_U, /**< Italian Troops */
    USSR_U, /**< USSR Troops */
    NEUTRAL_U /**< Neutral Troops (Only fortresses) */
};

/**
 * @enum The current season the game is in
 * @brief Acts as a timestamp of the game and which phase the game is in (Seasons are more than just summer ect but also reshuffle and turn order)
 * 
 */
enum Season {
    SPRING, /**< Spring Season of War Actions */
    SUMMER, /**< Summer Season of War Actions */
    FALL,   /**< Fall Season of War Actions */
    WINTER,  /**< Winter Season of War Actions (only USSR can act)*/

    NEW_YEAR, /**< New Year Phase of game loop */
    RESHUFFLE,  /**< Card Shuffling Phase of game loop */
    TURN_ORDER, /**< Deciding Turn Order Phase of game loop */
    PEACE_DIVIDENS, /**< Giving Peace Dividends of game loop */
    NEW_YEAR_RES,   /**< New Year Resolution Phase of game loop */
    PRODUCTION, /**< Production Phase of game loop */
    GOVERNMENT, /**< Government/Diplomacy Phase of game loop */

    SPRING_COMMAND,
    SUMMER_COMMAND,
    FALL_COMMAND,
    WINTER_COMMAND
};

/**
 * @enum Represents the state of A Declaration of War between two players
 * @brief A Declaration of War (DoW) state between two players to show if they are either at peace, the one to declare a DoW, and the one who was declared against
 */
enum DowState {
    PEACE, /**< Is at peace with other player */
    DECLARED, /**< Declared a DoW on another player */
    VICTIM /**< Has a DoW declared agasint them*/
};

/**
 * @enum The type of investment card
 * @brief Investment cards have either multiple possible 'TECHNOLOGY' developments, special `INTELLIGENCE` actions, and `YEAR` cards that can be used as a wild for specific technologies
 * 
 */
enum InvestType {
    TECHNOLOGY, 
    INTELLIGENCE, 
    YEAR
};

enum GovernmentAction{
    INFLUENCE,
    ACHIEVE,
    INDUSTRY,
    INTELLIGENCE_FUCNTION
};

enum ActionType {
    DIPLOMACY, 
    WILD
};

enum InfluenceType { 
    UNALIGNED,
    ASSOCIATES, 
    PROTECTORATES, 
    SATELLITES
};

enum ProductionAction {
    BUY_AC, 
    BUY_IC, 
    UNIT_UP, 
    CADRE
};

enum Widget {
    ACTION_HAND, /**< Player's hand of Action Cards */
    INVEST_HAND, /**< Player's hand of Investment Cards */
    TECH_HAND, /**< Player's list of achieved technology */
    STAT_WIDGET, 
    MAP, /**< The map with units and cities */

    //Used for Intelligence Cards
    SELECT_RIVAL,
    SELECT_CITY,
    SELECT_UNIT,
};

enum ProductionError{
    ABLE= 0,

    OUTSIDE_HOME = 1,
    PRE_FORTRESS,
    UNIT_MAXED,
    ENEMY_FORTRESS,
    NAVAL_INLAND,

    AT_SEA = 10,
    ENGAGED,
    UNSUPPLIED,
    MAX_CV
};

enum MovementMessage{
    EMPTY_MEMO = -12,
    EMERGENCY_ENGAGE,
    BORDER_LIMIT,
    TIRED,
    TOO_FARR,
    ENGAGE_NOT_LAST,
    NOT_CONNECTED,
    WILL_BE_NEUT,
    NO_COMMAND,
    PAST_COAST,
    AIR_OVER_WATER,
    CONVOY_ENGAGE_AT_SEA,
    // ^ Error 
    // v Effects
    NO_EFFECT = 0,
    DOWED,
    VONED,
    LANDFALL,
    INVASION
};

/**
 * @enum Technological Achievements 
 * @brief The wartime technological advancements the player can achieve to boost their efforts (also doubles as sprite offset)
 * 
 */
enum Tech{
    LSTs, /**< Can Sea Invade two Ground units/border */
    MOTORIZED_INFANTRY, /**< Infantry moves 3*/
    NAVAL_RADAR, /**< Fleets have FirstFire */
    ROCKET_ARTILLERY, /**< Infantry has FirstFire */
    HEAVY_TANKS, /**< Tanks have FirstFire */
    HEAVY_BOMBERS, /**< Air Force move 3 */
    PERCISION_BOMBERS, /**< AFs can bomb industry at I1 */
    JETs, /**< Air Forces have FirstFire */
    SONAR, /**< Fleets Fire S3 */
    AIRDEFENCE_RADAR, /**< AFs in Friendly Territory Fire 2A3 */
    ATOMIC_ONE, /**< ATOMIC PILE. */
    ATOMIC_TWO, /**< Breeder Reactors. */
    ATOMIC_THREE, /**< Plutonium. */
    ATOMIC_FOUR, /**< Implosion Trigger. */
    Y_1938, /**< Pair with: SONAR, NAVAL_RADAR, HEAVY_TANKS, AIRDEFENCE_RADAR, MOTORIZED_INFANTRY, ATOMIC_ONE. */
    Y_1940, /**< Pair with: SONAR, NAVAL_RADAR, HEAVY_BOMBERS, ROCKET_ARTILLERY, PERCISION_BOMBERS, ATOMIC_TWO. */
    Y_1942, /**< Pair with: LSTs, HEAVY_TANKS, ROCKET_ARTILLERY, AIRDEFENCE_RADAR, PERCISION_BOMBERS, ATOMIC_THREE. */
    Y_1944, /**< Pair with: LSTs, JETs, HEAVY_BOMBERS, PERCISION_BOMBERS, ATOMIC_THREE, ATOMIC_FOUR. */
    INDUSTRIAL_ESPIONAGE, /**< Pair with any Revealed Tech */
    // offsets for intel cards
    COUP, /**< Remove all Rival Influence from one Minor Nation. */
    CODE_BREAKER, /**< Inspect a Rival's Hand. */
    AGENT, /**< Insepct a Rival's blocks in any one area. */
    MOLE, /**< Inspect a Rival's Secret Vault. Pair this card with any Tech in your hand that matches a Tech found there to Achieve that Tech (show Rival). If not, discard */
    SABOTAGE, /**< Reduce a Rival's Industry by one. */
    SPY_RING, /**< Blindly take one card from a Rival's Hand. */
    DOUBLE_AGENT, /**< Reverse the effects of an Intel card just played against you back on the Rival the played it [immediate reaction]*/
    //Not techs just used for offsets
    FACT_ONE, /**< Contribute one (1) factory towards raising industry*/
    FACT_TWO, /**< Contribute two (2) factory towards raising industry*/
    FACT_THREE, /**< Contribute three (3) factory towards raising industry*/
    FACT_FOUR, /**< Contribute four (4) factory towards raising industry*/
    FACT_BLANK, /**< Blank tile for one sided cards */
    SECRET_OUTLINE, /**< Outline to show the player their tech is in the archive */
    SECRET_FULL, /**< Full hidden sprite to show other players there are vaulted tech */
};

enum MovementType{
    LAND_MOVEMENT,
    SEA_MOVEMENT,
    AIR_MOVEMENT
};

enum ActionPhase{
    MOVEMENT,
    COMBAT,
    OBSERVING
};

enum Message{
    WEST_PASSED=0,
    AXIS_PASSED,
    USSR_PASSED,

    PRODUCTION_START=3,

    GOVERNMENT_START=4,

    RESHUFFLE_START=5,

    WEST_TECH_REVEALED = 6,
    AXIS_TECH_REVEALED,
    USSR_TECH_REVEALED,

    WEST_CARD_PEAKING = 9,
    AXIS_CARD_PEAKING,
    USSR_CARD_PEAKING,

    WEST_UNIT_PEAKING = 12,
    AXIS_UNIT_PEAKING,
    USSR_UNIT_PEAKING,

    WEST_SABOTAGE = 18,
    AXIS_SABOTAGE,
    USSR_SABOTAGE
};

//enum State {ADVANCE_YEAR, VICTORY_CHECK, RESHUFFLE, PEACE_DIVIDENDS, TURN_ORDER, NEW_YEAR_RES, PRODUCTION, GOVERNMENT, HAND_CHECK};

const string NATIONALITY_STRING[7] = {"BRITISH", "FRANCE", "USA", "GERMAN", "ITALY", "USSR", "NEUTRAL"};

const Tech YEAR_TECHS[4][6] = {
    {SONAR, NAVAL_RADAR, HEAVY_TANKS, AIRDEFENCE_RADAR, MOTORIZED_INFANTRY, ATOMIC_ONE}, //1938
    {SONAR, NAVAL_RADAR, HEAVY_BOMBERS, ROCKET_ARTILLERY, PERCISION_BOMBERS, ATOMIC_TWO}, //1940
    {LSTs, HEAVY_TANKS, ROCKET_ARTILLERY, AIRDEFENCE_RADAR, PERCISION_BOMBERS, ATOMIC_THREE}, //1942
    {LSTs, JETs, HEAVY_BOMBERS, PERCISION_BOMBERS, ATOMIC_THREE, ATOMIC_FOUR}  //1944
};

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

const int MAX_CV_TABLE[7] = { //BRITIAN, FRANCE, USA, GERMANY, ITALY, USSR, NEUTRAL
    4, 3, 4, 4, 3, 3, 3
};

const int UNIT_COUNTS[8][7] = {
    //BRITIAN,  FRANCE,     USA,    GERMANY, ITALY, USSR, NEUTRAL
    {6,         3,          2,      8,       2,     6,    8}, //Fort
    {4,         3,          4,      8,       3,     6,    0}, //Air
    {2,         1,          1,      2,       1,     2,    0}, //Carrir
    {3,         1,          1,      8,       2,     2,    0}, //Sub
    {6,         4,          4,      6,       4,     4,    0}, //Fleet
    {3,         2,          4,      8,       2,     8,    0}, //Tank
    {6,         6,          4,      16,      6,     16,   0}, //Infantry
    {30,        20,         20,     56,     20,     44,   8} //TOTAL
};
                                //NA, OCEAN, DEEP_OCEAN, COAST, WATER_STRAIT, COAST_MOUNTAIN, COAST_FOREST, COAST_RIVER, COAST_PLAINS, MOUNTAIN, FOREST, RIVER, PLAINS,  LAND_STRAIT
const int BORDER_LIMITS[15] = {0,     100,   100,        1,     100,          1,              2,            2,           3,            1,        2,      2,     3,       1};

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

const int ZOOM_DIMENSIONS[3][2] = {
    {20, 20}, //Zoom 1 (broadest)
    {40, 40}, //Zoom 2 
    {64, 64}  //Zoom 3 (Closest)
};

//[button][direction]
const Widget WIDGET_ADJACENCY[5][4] = {
    //up down               left            right
    {MAP, ACTION_HAND,      ACTION_HAND,    STAT_WIDGET}, //ACTION_HAND
    {MAP, INVEST_HAND,      TECH_HAND,      INVEST_HAND}, //INVEST_HAND
    {MAP, TECH_HAND,        MAP,            INVEST_HAND}, //TECH_HAND
    {MAP, MAP,              ACTION_HAND,    MAP}, //STAT_WIDGET
    {MAP, MAP,              STAT_WIDGET,    TECH_HAND}  //MAP
};

const int UNIT_SPRITE_OFFSET[7]{ //"BRITISH", "FRANCE", "USA", "GERMAN", "ITALY", "USSR", "NEUTRAL"
    0, 5, 9, 14, 19, 23, 27
};

const double UNIT_CIRCLE_RADIANS[8][3]{
    {-90,  0,  -1.4}, //n 0
    {-45,  1,  -1}, //n e 1
    {0,    1.4,   0}, //e 2
    {45,   1,   1}, //s e 3
    {90,   0,   1.4}, //s 4
    {135, -1,   1}, //s w 5
    {180, -1.4,   0}, //w 6 
    {-135,-1,    -1} //n w 7
};

//Colors
namespace Colors{
    const SDL_Color BLACK = {0, 0, 0, 255};
    const SDL_Color GREEN = {0, 255, 0, 255};
}

//Graphics
namespace Graphics{
    struct Screen{
        int WIDTH = 1512;
        int HEIGHT = 946;

        double zoom_factor = 1.0;

        int zoom_x = 0;
        int zoom_y = 0;

        inline int getCenterX() const {
            return WIDTH/2;
        }
        inline int getCenterY() const {
            return HEIGHT/2;
        }

        inline int getScaledCenterX() const {
            return (WIDTH/zoom_factor) /2;
        }
        inline int getScaledCenterY() const {
            return (HEIGHT/zoom_factor) /2;
        }

        inline double getXScale() const{
            return zoom_factor*WIDTH/1512.0;
        }

        inline double getYScale() const{
            return zoom_factor*HEIGHT/982.0;
        }

        inline int getX(const int x) const{
            return (x-zoom_x)*getXScale();
        }

        inline int getY(const int y) const{
            return (y-zoom_y)*getYScale();
        }
    };

   
};

struct PublicMessage{
    Message message;
    Uint32 start_tick;
    Uint32 life_time=-1;
    Uint32 tpf;

    int width;
    int height;

    unsigned int frames;

    int offset;

    bool flicker;

    bool beside_action;


    PublicMessage(const Message message, const Uint32 start_tick, const Uint32 tpf, const int width, const int height, const unsigned int frames, const int offset = 0, const bool flicker=false, const bool beside_action=false): 
    message(message), start_tick(start_tick), tpf(tpf), width(width), height(height), frames(frames), offset(offset), flicker(flicker), beside_action(beside_action){
    }

    PublicMessage(const Message message, const Uint32 start_tick, const Uint32 tpf, const Uint32 life_time, const int width, const int height, const int offset, const bool beside_action):
    message(message), start_tick(start_tick), life_time(life_time), tpf(tpf), width(width), height(height), offset(offset), beside_action(beside_action){
        flicker = true;
    }

    bool operator==(const PublicMessage& lhs){ 
    return this->message == lhs.message && this->start_tick == lhs.start_tick;
    }
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
        SDL_SetTextureBlendMode(spritesheet_image, SDL_BLENDMODE_BLEND);

        SDL_FreeSurface(spritesheet_surface);

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

    void drawSprite(SDL_Rect* position, const int row, const int pos, const int size_x=32, const int size_y=32, const int offset=0, const int unscaledX=0, const int unscaledY=0){
        position->x += offset;
        clip.x = pos * size_x + unscaledX;
        clip.y = row * size_y + unscaledY;
        clip.w = size_x;
        clip.h = size_y;

        
        if (SDL_RenderCopy(renderer, spritesheet_image, &clip, position) < 0){ //was an error
            cout << "Drawing sprite failed with error: " << SDL_GetError() << endl;
        }
    }

    void drawArea(SDL_Rect* position, const int x, const int y, const int w, const int h){
        clip = {x, y, w, h};

        if (SDL_RenderCopy(renderer, spritesheet_image, &clip, position) < 0){ //was an error
            cout << "Drawing transparent area failed with error: " << SDL_GetError() << endl;
        }
    }

    void drawArea(SDL_Rect* position, const int x, const int y, const int w, const int h,  const Uint8 alpha){
        clip = {x, y, w, h};

        SDL_SetTextureAlphaMod(spritesheet_image, alpha);
        if (SDL_RenderCopy(renderer, spritesheet_image, &clip, position) < 0){ //was an error
            cout << "Drawing transparent area failed with error: " << SDL_GetError() << endl;
        }

        //- Reset transparency
        SDL_SetTextureAlphaMod(spritesheet_image, 255);
    }
};

// Application
struct App{
    SDL_Window* window;
    SDL_Renderer* renderer;

    Graphics::Screen screen;
};

constexpr int offset=0;
