#include "Player.h"

void Player::westInit(){
    factory_cost = 6;

    card_size = 8;

    industry = 7;

    emergency_command = 2;

    capital = "London";

    units.resize(UNIT_COUNTS[7][BRITIAN_U]+UNIT_COUNTS[7][FRANCE_U]+UNIT_COUNTS[7][USA_U]);
}

void Player::axisInit(){
    factory_cost = 5;

    card_size = 7;

    industry = 12;

    emergency_command = 4;

    capital = "Berlin";

    units.resize(UNIT_COUNTS[7][GERMANY_U]+UNIT_COUNTS[7][ITALY_U]);
}

void Player::ussrInit(){
    factory_cost = 7;

    card_size = 6;

    industry = 9;

    emergency_command = 2;

    capital = "Moscow";

    units.resize(UNIT_COUNTS[7][USSR]);
}

void Player::print() const{
    printf("Player %d has %d industry that costs %d, %d population, and %d resources. Stats: %d %d %d %d %d %d\n", (int)allegiance, (int)industry, (int)factory_cost, (int)population, (int)resources,
    (int)rival_capitals, (int)atomic, (int)battles_won[0], (int)battles_lost[0], (int)cards_spent, (int)cities_controlled);
}