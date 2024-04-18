#include "Player.h"

void Player::westInit(){
    //- Place cadres in Britain

    //- Place cadres in France

    //- Draw 8 cards

    industry = 7;

    factory_cost = 6;

    population = 12;

    resources = 11;
}

void Player::axisInit(){
    //- Place cadres in Germany

    //- Place cadres in Italy

    //-Draw 14 cards

    industry = 12;

    factory_cost = 5;

    population = 11;

    resources = 6;
}

void Player::ussrInit(){
    //- Place cadres in USSR

    //- Draw 6 cards

    industry = 9;

    factory_cost = 7;

    population = 12;

    resources = 11;
}

void Player::print() const{
    printf("Player %d has %d industry that costs %d, %d population, and %d resources\n", (int)nationality, (int)industry, (int)factory_cost, (int)population, (int)resources);
}