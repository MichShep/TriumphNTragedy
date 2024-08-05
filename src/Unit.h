#pragma once

#include "Includes.h"

struct PeaceChit{
    uint8_t value;

    int x; 
    int y;
};

struct AchievedTechnology{
    string name; /**< The name of the technology*/

    Tech tech; /** The type of technology corresponding to its name*/

    bool secret; /**< If the technology is secret from other players and the effects aren't appliable*/

    /**
     * @brief Construct a default technology
     * 
     */
    AchievedTechnology(){
        name=""; tech=LSTs; secret=false;
    }

    /**
     * @brief Construct a new Technology 
     * 
     * @param name Name of the tech
     * @param tech The enum for the tech
     * @param secret If the tech is a secret or not
     */
    AchievedTechnology(const string name, const Tech tech, bool secret=false): name(name), tech(tech), secret(secret){
    }

    bool operator==(const AchievedTechnology* rhs) const{
        return this->name == rhs->name && this->tech == rhs->tech;
    }

    bool operator==(const Tech* rhs) const{
        return this->tech == *rhs;
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

struct Card{

};

struct ActionCard : public Card{
public:
    ActionType type; /**< The type of Action Card (DIPLOMACY for specific countries or a WILD)*/

    string countryA; /**< The left country that could be influenced or the name of the wild card*/
    string countryB; /**< The second country that could be influenced (blank for wild)*/

    //For Priority
    Season season; /**< The command season the player has priority for*/
    char command_priority; /**< The command letter for priority (Z<A)*/
    int command_value; /**< The number representing how many actions the player can do in a season*/

    size_t sprite_offset_left; /**< The sprite index of the left country*/
    size_t sprite_offset_right; /**< The sprite index of the right country*/

    /**
     * @brief Construct a new Action Card
     * 
     * @param type The type of card
     * @param countryA The name of the left side (Either a country or type of wild card)
     * @param countryB The name of the right side (Either a country of blank)
     * @param season The season the card commands in with priority
     * @param letter The letter the card commands in with priority
     * @param number The number the card commands in with priority
     * @param sprite_offset_left The uncalculated sprite index of the left sprite
     * @param sprite_offset_right The uncalculated sprite index of the right sprite
     */
    ActionCard(const ActionType type, const string countryA, const string countryB, const Season season, const char letter, const size_t number, const size_t sprite_offset_left, const size_t sprite_offset_right):
    type(type), countryA(countryA), countryB(countryB), season(season), command_priority(letter), command_value(number), sprite_offset_left(sprite_offset_left*2), sprite_offset_right(sprite_offset_right*2+1){
    }

    bool operator==(const ActionCard* card) const{
        return this == card;
    }
};

struct InvestmentCard : public Card{
public:
    InvestType type; /**< The type of invest Card (the basic two sided TECHNOLOGY card, or a wild effect INTELLIGENCE, or a wild YEAR card)*/

    Tech tech1 /**< The name of the left side of the tech (or the year it's usable)*/;

    Tech tech2; /**< The name of the right side of the tech (blank for INTELLIGENCE cards)*/

    size_t amount; /**< The value the card contributes to raising the industry*/

    //for science cards
    size_t year; /**< The year of the YEAR card it applies too*/

    /**
     * @brief Construct a new Investment Card object
     * 
     * @param type 
     * @param tech1_name 
     * @param tech2_name 
     * @param amount 
     * @param year 
     * @param sprite_offset_left 
     * @param sprite_offset_right 
     */
    InvestmentCard(const InvestType type, const string tech1_name, const string tech2_name, const int amount, const size_t year, const size_t sprite_offset_left, const size_t sprite_offset_right): 
    type(type), amount(amount), year(year){
        tech1 = (Tech)sprite_offset_left;
        tech2 = (Tech)sprite_offset_right;
    }

    bool operator==(const InvestmentCard* card) const{
        return card->tech1 == this->tech1 && card->tech2 == this->tech2 && this->amount == card->amount;
    }
};

class Unit{
public:
    size_t id; /**< ID of the unit */

    CityType allegiance; /**< Which power the unit belongs to (West, Axis, USSR, Neutral)*/

    UnitCountry nationality; /**< Which country the unit comes from (West:British, USA, France; Axis: Germany, Italy; USSR: USSR)*/

    UnitClass class_type; /**< Which class the unit is in that is mostly just for movement and ReBase*/

    UnitType unit_type; /**< Which type of unit that decied attack and movement (Fortress, Infantry, Air...)*/

    year_t birth_year=NULL_YEAR; /**< The year that the unit was created in*/

    bool upgrading; /**< The year after the year which the unit was upgraded in*/

    uint8_t combat_value; /**< Functions as how many forces are in the one unit and how many it fires in battle*/

    int8_t max_combat_value; /**< Limits the max amount of forces can be in the unit*/

    uint8_t movement; /**< The max amount of cities it can move in one turn*/

    bool moved=false; /**< Flag for if the Unit has moved in the current year */

    bool rebase=false; /**< If this unit can ReBase (move freely to ground force)*/

    year_t disengage=NULL_YEAR;

    year_t landing=NULL_YEAR; /**< The year the unit landed from water this turn (therefore it can't attack)*/

    bool convoy=false; /**< If the ground unit is a convoy its an infantry in the water and can't attack*/

    bool escaped=false; /**< Used for subs and if they have 'escaped' and can block trade routes */

    Unit(const size_t id, const UnitCountry nationality, const UnitType unit_type, const year_t& curr_year): id(id), nationality(nationality), unit_type(unit_type){ //for making cadres
        combat_value = 0; //1 for all cadres 
        upgrading = true; //since a cadre is basically upgrading nothing to the unit type
        birth_year = curr_year;

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

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (AIR):{
                class_type = CLASS_A;

                movement = 2;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = false;

                break;
            }
            case (CARRIER):{
                class_type = CLASS_N;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[nationality];
                rebase = true;

                landing = true;
                break;
            }
            case (SUB):{
                class_type = CLASS_S;

                movement = 2;
                
                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = true;
                break;
            }
            case (FLEET):{
                class_type = CLASS_N;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = true;

                break;
            }
            case (TANK):{
                class_type = CLASS_G;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (INFANTRY):{
                class_type = CLASS_G;
                
                movement = 2;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (CONVOY):{
                class_type = CLASS_N;
                
                movement = 2;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = true;

                break;
            }
            
            default:
                break;
        }

    }

    Unit(const size_t id, const UnitCountry nationality, const UnitType unit_type, uint8_t combat_value, const year_t& curr_year): id(id), nationality(nationality), unit_type(unit_type), combat_value(combat_value){ //for making cadres
        birth_year = curr_year;
        
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

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (AIR):{
                class_type = CLASS_A;

                movement = 2;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = false;

                break;
            }
            case (CARRIER):{
                class_type = CLASS_N;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = true;
                break;
            }
            case (SUB):{
                class_type = CLASS_S;

                movement = 2;
                
                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = true;
                break;
            }
            case (FLEET):{
                class_type = CLASS_N;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = true;

                landing = true;

                break;
            }
            case (TANK):{
                class_type = CLASS_G;
                
                movement = 3;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (INFANTRY):{
                class_type = CLASS_G;
                
                movement = 2;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = false;

                break;
            }
            case (CONVOY):{
                class_type = CLASS_N;
                
                movement = 2;

                max_combat_value = MAX_CV_TABLE[nationality];

                rebase = false;

                landing = true;

                break;
            }
            
            default:
                break;
        }

    }

    /**
     * @brief Construct a custom unit
     * 
     * @param nationality 
     * @param allegiance 
     * @param class_type 
     * @param unit_type 
     * @param combat_value 
     * @param movement 
     * @param rebase 
     * @param landing 
     */
    Unit(const UnitCountry nationality, const CityType allegiance, const UnitClass class_type, const UnitType unit_type, const size_t combat_value, const size_t movement, const  bool rebase, const bool landing=false): 
    allegiance(allegiance), nationality(nationality), class_type(class_type), unit_type(unit_type), combat_value(combat_value), movement(movement), rebase(rebase), landing(landing){ //for making custom units or US delivery

    }

    /**
     * @brief Set the movement of the unit
     * 
     * @param mov The new unit of the unit
     */
    void setMovement(const size_t mov){ //just for testing
        movement = mov;
    }

    /**
     * @brief Print out the data of the unit
     * 
     */
    void print() const;
};