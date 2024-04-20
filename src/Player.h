#pragma once

#include "Map.h"
/**
 * @brief Represents Great Power and Player Stats
 * 
 */
class Player{
private:
    //&Player attributes
    string name;

    size_t victory_points;

    size_t rival_capitals;

    bool atomic;

    //&Great Power attributes
    CityType nationality;

    size_t population;

    size_t resources;

    size_t industry;

    size_t card_size;

    size_t factory_cost;

    vector<Unit*> units;

    bool ussr_treaty;

    bool west_treaty;

    bool axis_treaty;

    bool axis;

    bool usa_treaty;

    //&Hands
    vector<ActionCard*> action_hand;

    vector<InvestmentCard*> invest_hand;

    //&Stats
    size_t battles_won[3]; /**<Allies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t battles_lost[3]; /**<Allies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t total_units[8]; /**< Each index is a specific unit and how much*/

    size_t cards_spent;

    size_t cities_controlled;
public:
    Player(){
        name = "Default";
    }
    Player (const string name, const CityType nationality): name(name), nationality(nationality){
        switch (nationality){
        case (WEST):
            westInit();
            break;
        case (AXIS):
            axisInit();
            break;
        case (USSR):
            ussrInit();
            break;
        default:
            printf("Unkown nationality %d!\n", (int)nationality);
            exit(1);
            break;
        }
    }

    Player(const string name, const CityType nationality, const size_t population, const size_t resource, const size_t industry, const size_t card_size, const size_t factory_cost, const bool ussr_treaty, bool axis_treaty, bool allies_treaty, const bool usa_treaty)
        : name(name), nationality(nationality), population(population), resources(resource), industry(industry), card_size(card_size), factory_cost(factory_cost), ussr_treaty(ussr_treaty), west_treaty(allies_treaty), axis_treaty(axis_treaty), usa_treaty(usa_treaty){

    }

    /**
     * @brief Setup West player on default values in rules
     * 
     */
    void westInit();
    
    /**
     * @brief Setup Axis player on default values in rules
     * 
     */
    void axisInit();

    /**
     * @brief Setup USSR player on default values in rules
     * 
     */
    void ussrInit();

    /**
     * @brief Goes through the map and fills in the players stats
     * 
     */
    void mapPlayer();

    CityType getNationality() const{
        return nationality;
    }

    size_t getPopulation() const{
        return population;
    }

    size_t getResource() const{
        return resources;
    }

    void setPopulation(const size_t pop){
        population = pop;
    }

    void setResource(const size_t res){
        resources = res;
    }

    size_t getHandSize() const{
        return action_hand.size() + invest_hand.size();
    }

    size_t getMaxCard() const{
        return card_size;
    }

    size_t getMaxProduction() const{

    }

    size_t getVP() const{
        return victory_points;
    }

    void print() const;
};
