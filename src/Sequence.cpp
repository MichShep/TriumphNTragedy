#include "Runner.h"

//& Sequence of Play

bool Runner::run(){
    bool running = true;

    SDL_Event event;

    test();

    auto& cities = map.getCities();

    while (running){
        ClearScreen();

        //-Draw the connections
        DrawConnections();

        //-Draw the cities and troops
        for (auto city : cities){
            //printf("%d %d\n", city.second->x, city.second->y);
            DrawCity(city.second);
        }

        if (SDL_PollEvent(&event)){
            switch (event.type) {
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

        //- Draw the time track
        DrawTimeTrack();

        //- Draw Player Stats
        
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
    year++;

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

}

void Runner::newYearRes(){

}

void Runner::handCheck(Player* player){

}