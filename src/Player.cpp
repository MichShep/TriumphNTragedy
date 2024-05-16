#include "Player.h"

void Player::westInit(){
    //- Place cadres in Britain

    //- Place cadres in France

    factory_cost = 6;

    card_size = 8;

    industry = 7;
}

void Player::axisInit(){
    factory_cost = 5;

    card_size = 7;

    industry = 12;
}

void Player::ussrInit(){
    //- Place cadres in USSR

    //- Draw 6 cards
    factory_cost = 7;

    card_size = 6;

    industry = 9;
}

void Player::print() const{
    printf("Player %d has %d industry that costs %d, %d population, and %d resources\n", (int)allegiance, (int)industry, (int)factory_cost, (int)population, (int)resources);
}