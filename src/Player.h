#pragma once

#include "Map.h"
/**
 * @brief Represents Great Power and Player Stats
 * 
 */
class Player{
private:
    //&Player attributes
    string name; /**< The name of the player*/

    size_t victory_points; /**< Current number of VP*/

    size_t rival_capitals; /**< Number of enemy capitals the player has captured*/

    bool atomic; /**< If the player has all 4 stages of atomics*/

    //&Great Power attributes
    CityType allegiance; /**< Which power the player is controlling (West, Axis, USSR)*/

    size_t population; /**< Total POP of the player*/

    size_t resources; /**< Total number of resources player has*/

    size_t industry; /**< Total number of industry the player has*/

    size_t card_size; /**< Hand size of the player they must discard to at the end of government*/

    size_t factory_cost; /**< The cost to upgrade the industry*/

    vector<Unit*> units; /**< Masterlist of all units the player controls*/

    bool ussr_treaty; /**< If the player is peaceful with USSR will be true*/

    bool west_treaty; /**< If the player is peacful with the West will be true*/

    bool axis_treaty; /**< If the player is peacful witht the Axis will be true*/

    bool usa_treaty; /**< If the USA has joined the West*/

    //&Hands
    vector<ActionCard*> action_hand; /**< Hand of all action cards (used in command and government)*/

    vector<InvestmentCard*> invest_hand; /**< Hand of all investment cards*/

    //&Stats
    size_t battles_won[3]; /**< Allies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t battles_lost[3]; /**<A llies:0 Axis:1 USSR:2 where each index specifies against who*/

    size_t total_units[8]; /**< Each index is a specific unit and how much*/

    size_t cards_spent; /**< Number of cards the player has spent this game*/

    size_t cities_controlled; /**< Number of cities the player controls*/
public:
    Player(){
        name = "Default";
    }
    /**
     * @brief Constructs the player based on the allegiance
     * 
     * @param name Name of player
     * @param allegiance Which power they'll play
     */
    Player (const string name, const CityType allegiance): name(name), allegiance(allegiance){
        switch (allegiance){
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
            printf("Unkown allegiance %d!\n", (int)allegiance);
            exit(1);
            break;
        }
    }

    /**
     * @brief Constructs a new player
     * 
     * @param name Name of player
     * @param allegiance Which power
     * @param population Starting population (pop)
     * @param resource Starting resources (red)
     * @param industry Starting industry (ind)
     * @param card_size Starting max hand size
     * @param factory_cost Starting cost to upgrade industry
     * @param ussr_treaty Inital ties with USSR
     * @param axis_treaty Inital ties with AXIS
     * @param allies_treaty Inital ties with WEST
     * @param usa_treaty Inital USA involvement
     */
    Player(const string name, const CityType allegiance, const size_t population, const size_t resource, const size_t industry, const size_t card_size, const size_t factory_cost, const bool ussr_treaty, bool axis_treaty, bool allies_treaty, const bool usa_treaty)
        : name(name), allegiance(allegiance), population(population), resources(resource), industry(industry), card_size(card_size), factory_cost(factory_cost), ussr_treaty(ussr_treaty), west_treaty(allies_treaty), axis_treaty(axis_treaty), usa_treaty(usa_treaty){

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

    /**
     * @brief Gets which power the player is
     * 
     * @return CityType The Power the player is
     */
    CityType getAllegiance() const{
        return allegiance;
    }

    /**
     * @brief Get how much population the player controls
     * 
     * @return size_t The player's population
     */
    size_t getPopulation() const{
        return population;
    }

    /**
     * @brief Get the number of resources owned
     * 
     * @return size_t Number of resources
     */
    size_t getResource() const{
        return resources;
    }

    /**
     * @brief Set the players population
     * 
     * @param pop The new population
     */
    void setPopulation(const size_t pop){
        population = pop;
    }

    /**
     * @brief Set the number of resources
     * 
     * @param res The new resource count
     */
    void setResource(const size_t res){
        resources = res;
    }

    /**
     * @brief Gets the combined hand size of action and investment cards
     * 
     * @return size_t 
     */
    size_t getHandSize() const{
        return action_hand.size() + invest_hand.size();
    }

    /**
     * @brief gets the player's card limit
     * 
     * @return size_t The card limit
     */
    size_t getMaxCard() const{
        return card_size;
    }

    /**
     * @brief Get the max production of the player max(pop, res, ind)
     * 
     * @return size_t The production of the player for the phase
     */
    size_t getMaxProduction() const{
        return std::max(population, std::max(resources, industry));
    }

    /**
     * @brief Get the current VP of player
     * 
     * @return size_t The victory points of the player
     */
    size_t getVP() const{
        return victory_points;
    }

    /**
     * @brief Prints out all stats of the player
     * 
     */
    void print() const;
};
