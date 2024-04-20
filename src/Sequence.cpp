#include "Runner.h"

//& Sequence of Play
//- New Year
CityType Runner::newNear(){
    //- Advance Year
    year++;

    //- Victroy Check 
    for (Player player : players){
        if (player.getVP() >= 25){
            return player.getNationality();
        }
    }

    //- Reshuffle
    reshuffle();

    //- Peace Dividends
    peaceDividends();

    //- Turn Order
    start_player = &players[(start_player->getNationality()+1)%3];

    //- New Year Resolution
    if (year >= 1943)
        newYearRes();

    //- Production Phase
    production();
    
    //- Government Phase
    government();

    //- Hand Size Compliance
    for (auto& player : players){
        if (player.getHandSize() > player.getMaxCard()){
            handCheck(&player);
        }
    }
}

//- Production Phase
void Runner::production(){
    size_t max_prod[3] = {SIZE_MAX, SIZE_MAX, SIZE_MAX};

    //- Production Level

    //- Blockade Resolution

    //- Spending Resolution

        //- Building Units

        //- Buying Cards

}

//- Government Phase
void Runner::government(){
        //- Diplomacy

        //- Industry

        //- Technology

        //- Intelligence

        //- Pass

    //- Diplomacy Resolution

}

//- Spring Season
void Runner::spring(){
    //- Command Phase

    //- Player Turns
        //- Movement

        //- Combat

    //- Supply Phase
        //- Supply

}

//- Summer Season
void Runner::summer(){
    //- Command Phase

    //- Player Turns
        //- Movement

        //- Combat

    //- Supply Phase
        //- Supply

        //- Blockade
}

//- Check Blockades
void Runner::blockade(){

}

//- Fall Season
void Runner::fall(){
    //- Command Phase

    //- Player Turns
        //- Movement

        //- Combat

    //- Supply Phase
        //- Supply
}

//- Winter Season
void Runner::winter(){
    //- USSR plays one card

    //- USSR Turn
        //- Movement in USSR

        //- Combat in USSR

    //- Supply Phase for USSR
        //- Supply
}


void Runner::reshuffle(){

}

void Runner::peaceDividends(){

}

void Runner::newYearRes(){

}

void Runner::handCheck(Player* player){

}