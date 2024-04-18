#pragma once

#include "Includes.h"

struct Dice{
    vector<int> stats; /**< Vector to hold how often each side was rolled*/

    int min; /**< Min calue of the die*/

    int max; /**< Max value of the die*/

    Dice(){
        min = 0; max = 0;
    }

    Dice(int min, int max): min(min), max(max){
        if (min >= max){
            printf("Min value is greater than the max!");
            exit(EXIT_FAILURE);
        }
        stats.resize(max); 
    }

    int roll(){
        int result = rand() % (max - min + 1) + min;
        stats[result-1]++;
        return result;
    }

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
    string countryA;
    string countryB;

    Season season;

    //For Priority
    char letter;
    int number;

    ActionCard(const string countryA, const string countryB, const Season season, const char letter, const int number):
    countryA(countryA), countryB(countryB), season(season), letter(letter), number(number){

    }
};

struct InvestmentCard{
public:
    string name;

    Tech tech;

    size_t amount;

    //for science cards
    size_t year;

    InvestmentCard(const string name, const Tech tech, const int amount, const size_t year): name(name), tech(tech), amount(amount), year(year){

    }
};

class Unit{
public:
    size_t id;

    CityType nationality;

    UnitClass class_type;

    UnitType unit_type;

    size_t combat_value;

    size_t movement;

    bool rebase;

    bool landing;

    Unit(const size_t id, CityType nationality, UnitType unit_type): id(id), nationality(nationality), unit_type(unit_type){ //for making cadres
        //AIR, CARRIER, FLEETS, SUBS, FORTRESS, TANKS, INFANTRY, CONVOYS

        combat_value = 1; //1 for all cadres

        switch (unit_type){
            case (FORTRESS):{
                class_type = CLASS_G;

                movement = 0;

                rebase = false;

                landing = false;

                break;
            }
            case (AIR):{
                class_type = CLASS_A;

                movement = 2;

                rebase = true;

                landing = false;

                break;
            }
            case (CARRIER):{
                class_type = CLASS_N;
                
                movement = 3;

                rebase = true;

                landing = true;
                break;
            }
            case (SUB):{
                class_type = CLASS_S;

                movement = 2;

                rebase = true;

                landing = true;
                break;
            }
            case (FLEET):{
                class_type = CLASS_N;
                
                movement = 3;

                rebase = true;

                landing = true;

                break;
            }
            case (TANK):{
                class_type = CLASS_G;
                
                movement = 3;

                rebase = false;

                landing = false;

                break;
            }
            case (INFANTRY):{
                class_type = CLASS_G;
                
                movement = 2;

                rebase = false;

                landing = false;

                break;
            }
            case (CONVOY):{
                class_type = CLASS_N;
                
                movement = 2;

                rebase = false;

                landing = true;

                break;
            }
            
            default:
                break;
        }
    }

    Unit(const CityType nationality, const UnitClass class_type, const UnitType unit_type, const size_t combat_value, const size_t movement, const  bool rebase, const bool landing): nationality(nationality), class_type(class_type), unit_type(unit_type), combat_value(combat_value),
    movement(movement), rebase(rebase), landing(landing){ //for making custom units

    }

    void print() const;
};