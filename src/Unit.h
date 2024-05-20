#pragma once

#include "Includes.h"

struct PeaceChit{
    uint8_t value;

    int x; 
    int y;
};

struct Technology{
    string name;

    Tech tech;

    bool secret;

    Technology(){
        name=""; tech=LSTs; secret=false;
    }

    Technology(const string name, const Tech tech, bool secret=false): name(name), tech(tech), secret(secret){
    }
};

struct Dice{
    vector<int> stats; /**< Vector to hold how often each side was rolled*/

    int min; /**< Min value of the die*/

    int max; /**< Max value of the die*/

    /**
     * @brief Construct a default dice where the only possible value is 0
     * 
     */
    Dice(){
        min = 0; max = 0;
    }

    /**
     * @brief Construct a new dice with a given min and max value
     * 
     * @param min The mininum value the dice can roll
     * @param max The maximum value the dice can roll
     */
    Dice(int min, int max): min(min), max(max){
        if (min >= max){
            printf("Min value is greater than the max!");
            exit(EXIT_FAILURE);
        }
        stats.resize(max); 
    }

    /**
     * @brief Returns a value between the min and max value (inclusive, inclusive)
     * 
     * @return int The value of the die
     */
    int roll(){
        int result = rand() % (max - min + 1) + min;
        stats[result-1]++;
        return result;
    }

    /**
     * @brief Prints out the frequency of each possible dice roll
     * 
     */
    void print() const{
        printf("Dice:");
        for (int i = min; i <= max; i++){
            printf("[%d : %d] ", i, stats[i-1]);
        }
        printf("\n");
    }
};

struct ActionCard{
public:
    ActionType type;

    string countryA;
    string countryB;

    Season season;

    //For Priority
    char letter;
    int number;

    size_t sprite_offset_left;
    size_t sprite_offset_right;

    ActionCard(const ActionType type, const string countryA, const string countryB, const Season season, const char letter, const size_t number, const size_t sprite_offset_left, const size_t sprite_offset_right):
    type(type), countryA(countryA), countryB(countryB), season(season), letter(letter), number(number), sprite_offset_left(sprite_offset_left*2), sprite_offset_right(sprite_offset_right*2+1){

    }
};

struct InvestmentCard{
public:
    InvestType type;

    Technology tech1;

    Technology tech2;

    size_t amount;

    //for science cards
    size_t year;

    size_t sprite_offset_left;
    size_t sprite_offset_right;

    InvestmentCard(const InvestType type, const string tech1_name, const string tech2_name, const int amount, const size_t year, const size_t sprite_offset_left, const size_t sprite_offset_right): 
    type(type), amount(amount), year(year), sprite_offset_left(sprite_offset_left), sprite_offset_right(sprite_offset_right) {
        tech1 = Technology(tech1_name, (Tech)sprite_offset_left, false);
        tech2 = Technology(tech2_name, (Tech)sprite_offset_right, false);
    }
};

class Unit{
public:
    size_t id; /**< ID of the unit */

    CityType allegiance; /**< Which power the unit belongs to (West, Axis, USSR, Neutral)*/

    UnitCountry nationality; /**< Which country the unit comes from (West:British, USA, France; Axis: Germany, Italy; USSR: USSR)*/

    UnitClass class_type; /**< Which class the unit is in that is mostly just for movement and ReBase*/

    UnitType unit_type; /**< Which type of unit that decied attack and movement (Fortress, Infantry, Air...)*/

    size_t birth_year;

    uint8_t combat_value; /**< Functions as how many forces are in the one unit and how many it fires in battle*/

    uint8_t max_combat_value; /**< Limits the max amount of forces can be in the unit*/

    size_t movement; /**< The max amount of cities it can move in one turn*/

    bool rebase; /**< If this unit can ReBase (move freely to ground force)*/

    size_t landing; /**< The year the unit landed from water this turn (therefore it can't attack)*/

    bool convoy; /**< If the ground unit is a convoy its an infantry in the water and can't attack*/

    bool escaped=false; /**< Used for subs and if they have 'escaped' and can block trade routes */

    Unit(const size_t id, UnitCountry nationality, UnitType unit_type): id(id), nationality(nationality), unit_type(unit_type){ //for making cadres

        combat_value = 1; //1 for all cadres

        switch (nationality){ //BRITIAN_U, FRANCE_U, USA_U, GERMANY_U, ITALY_U, USSR_U, NEUTRAL_U
            case (BRITIAN_U):
                allegiance = WEST;
                break;

            case (FRANCE_U):
                allegiance = WEST;
                break;
            
            case (USA_U):
                allegiance = WEST;
                break;

            case (GERMANY_U):
                allegiance = AXIS;
                break;

            case (ITALY_U):
                allegiance = AXIS;
                break;

            case (USSR_U):
                allegiance = USSR;
                break;

            case (NEUTRAL_U):
                allegiance = NEUTRAL;
                break;
            
            default:
                break;
        }

        switch (unit_type){  //AIR, CARRIER, FLEETS, SUBS, FORTRESS, TANKS, INFANTRY, CONVOYS
            case (FORTRESS):{
                class_type = CLASS_G;

                movement = 0;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (AIR):{
                class_type = CLASS_A;

                movement = 2;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = true;

                landing = false;

                break;
            }
            case (CARRIER):{
                class_type = CLASS_N;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = true;

                landing = true;
                break;
            }
            case (SUB):{
                class_type = CLASS_S;

                movement = 2;
                
                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = true;

                landing = true;
                break;
            }
            case (FLEET):{
                class_type = CLASS_N;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = true;

                landing = true;

                break;
            }
            case (TANK):{
                class_type = CLASS_G;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (INFANTRY):{
                class_type = CLASS_G;
                
                movement = 2;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (CONVOY):{
                class_type = CLASS_N;
                
                movement = 2;

                max_combat_value = MAX_CV_TABLE[unit_type][nationality];

                rebase = false;

                landing = true;

                break;
            }
            
            default:
                break;
        }

    }

    Unit(const UnitCountry nationality, const CityType allegiance, const UnitClass class_type, const UnitType unit_type, const size_t combat_value, const size_t movement, const  bool rebase, const bool landing=false): 
    allegiance(allegiance), nationality(nationality), class_type(class_type), unit_type(unit_type), combat_value(combat_value), movement(movement), rebase(rebase), landing(landing){ //for making custom units or US delivery

    }

    void setMovement(const size_t mov){ //just for testing
        movement = mov;
    }   

    void print() const;
};