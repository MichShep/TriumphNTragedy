#include "Runner.h"

//& Sequence of Play

bool Runner::run(){
    bool running = true;

    SDL_Event event;

    test();
    City* closest = map.getCity("A");

    while (running){
        ClearScreen();

        //-Draw the connections
        DrawConnections();

        
        if (SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_MOUSEMOTION:{
                    int x, y;
                    SDL_GetMouseState(&x, &y);

                    closest = map.getClosestCity(x, y);

                }

                case SDL_KEYDOWN:{
                    running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;

                    if (event.key.keysym.scancode == SDL_SCANCODE_M){
                        test1();
                    }
                    if (event.key.keysym.scancode == SDL_SCANCODE_N){
                        year++;
                    }
                    if (event.key.keysym.scancode == SDL_SCANCODE_B){
                        map["C"]->occupants[0][0]->combat_value++;
                    }
                    if (event.key.keysym.scancode == SDL_SCANCODE_V){
                        players[0].setUsaDow(DECLARED);
                        players[0].setUssrDow(VICTIM);
                        players[0].setAxisDow(DECLARED);

                        players[1].setUssrDow(DECLARED);
                        players[1].setWestDow(VICTIM);

                        players[2].setWestDow(DECLARED);
                        players[2].setAxisDow(VICTIM);
                    }
                    break;
                }

                case SDL_QUIT:{
                    running = false;
                    break;
                }

                default: {
                    break;
                }
            }
        }

        drawCity(closest);

        //- Draw the time track
        DrawTimeTrack();

        //- Draw Player Stats
        drawPlayerStats(players[0]);
        drawPlayerStats(players[1]);
        drawPlayerStats(players[2]);

        //- New Year
        newNear();
        

        SDL_RenderPresent(app.renderer);
    }
    
    
    freeMemory();

    printf("Memory was deleted\n");
    //!!    

    ShutdownApplication();
    return EXIT_SUCCESS;
}

//- New Year
CityType Runner::newNear(){
    //- Advance Year
    //year++;

    //- Victroy Check 
    for (Player player : players){
        if (player.getVP() >= 25){
            return player.getAllegiance();
        }
    }

    //- Reshuffle
    reshuffle();

    //- Peace Dividends
    peaceDividends();

    //- Turn Order
    start_player = &players[(start_player->getAllegiance()+1)%3];

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

    return CityType::WATER;
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
    if (peace_dividends_bag.size() == 0) //in game its impossible to runnout of chits so this is for testing
        return;

    //- Check for West
    if (players[0].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[0].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
    }

    //- Axis
    if (players[1].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[1].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
    }

    //-USSR
    if (players[2].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[2].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
    }
}

void Runner::newYearRes(){

}

void Runner::handCheck(Player* player){

}