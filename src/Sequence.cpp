#include "Runner.h"

//& Sequence of Play

bool Runner::run(){
    bool running = true;

    SDL_Event event;

    test();

    //& Draw the initial Board
    ClearScreen(app.renderer);
    ClearScreen(west_app.renderer);

    //- Draw Player Stats
    drawPlayerStats(players[0]);
    drawPlayerStats(players[1]);
    drawPlayerStats(players[2]);
    drawPlayerCards(players[0], west_app.renderer);
    

    DrawConnections();

    auto& cities = map.getCities();
    for (auto city : cities)
        drawCity(city.second);

    //- Draw the time track
    //DrawTimeTrack();

    SDL_RenderPresent(app.renderer);

    while (running){
        

        //-Draw the connections

        
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
    }

    //& Main game Loop
    CityType winner;
    while ((winner=newYear()) != WATER){ //run the game unitl a winner is found

    }
    
    
    freeMemory();

    printf("Memory was deleted\n");
    //!!    

    ShutdownApplication();
    return EXIT_SUCCESS;
}

//- New Year
CityType Runner::newYear(){
    //- Advance Year
    year++;

    //- Victroy Check 
    for (Player player : players){
        if (player.getVP() >= 25){
            return player.getAllegiance();
        }
    }

    //- Reshuffle.
    if (year != 1936)
        reshuffle(true);

    //- Peace Dividends.
    peaceDividends();

    //- Turn Order.
    start_player = &players[(start_player->getAllegiance()+1)%3];

    //- New Year Resolution.
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
    //- Blockade Resolution

    //- Production Level
    size_t production[3] = {players[WEST].getProduction(), players[AXIS].getProduction(), players[USSR].getProduction()};    
   
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


void Runner::reshuffle(const bool animation){
    //- Add action discard and shuffle
    action_deck.insert(action_deck.end(), action_discard.begin(), action_discard.end());
    shuffle(action_deck.begin(), action_deck.end(), g);

    //- Add invest discard and shuffle
    invest_deck.insert(invest_deck.end(), invest_discard.begin(), invest_discard.end());
    shuffle(invest_deck.begin(), invest_deck.end(), g);

    if (animation)
        reshuffleAnimation(action_discard.size(), invest_discard.size());

    //- Clear discard pile
    action_discard.clear();
    invest_discard.clear();
}

bool Runner::deal(Player* player, size_t amount, const char state){
    switch (state){
    case 'A': //action cards
        if (action_deck.empty())
            return false;
        while (amount--){
            player->deal(action_deck.back());
            action_deck.pop_back();
        }
        break;
    case 'I': //action cards
        if (invest_deck.empty())
            return false;
        while (amount--){
            player->deal(invest_deck.back());
            invest_deck.pop_back();
        }
        break;
    
    default:
        break;
    }

    return true;
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
    auto usa = map.getCountry("USA");
    if (year >= 1941 && year < 1945){
        usa->influence++;
        usa->resolveDiplomacy(); //? 8.44 Becomes a satellite immediately
        
        if (year != 1941 && usa->influence_level == SATELLITES){ //? 8.54 during 1942 to 1944 USA forces [AF/Fleet/Infantry/Tank] arrive with 1 CV up to 3 CV depending on the year
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_A, AIR, year-1941, 2, true));
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_N, FLEET, year-1941, 3, true, true));
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_G, INFANTRY, year-1941, 2, true));
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_A, TANK, year-1941, 3, true));
        }
    }


}

void Runner::handCheck(Player* player){

}