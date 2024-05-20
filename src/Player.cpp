#include "Player.h"

void Player::westInit(){
    //- Place cadres in Britain

    //- Place cadres in France

    factory_cost = 6;

    card_size = 8;

    industry = 7;

    capital = "London";

}

void Player::axisInit(){
    factory_cost = 5;

    card_size = 7;

    industry = 12;

    capital = "Berlin";
}

void Player::ussrInit(){
    //- Place cadres in USSR

    //- Draw 6 cards
    factory_cost = 7;

    card_size = 6;

    industry = 9;

    capital = "Moscow";
}

void Player::print() const{
    printf("Player %d has %d industry that costs %d, %d population, and %d resources. Stats: %d %d %d %d %d %d %d\n", (int)allegiance, (int)industry, (int)factory_cost, (int)population, (int)resources,
    (int)rival_capitals, (int)atomic, (int)battles_won[0], (int)battles_lost[0], (int)total_units[0], (int)cards_spent, (int)cities_controlled);
}