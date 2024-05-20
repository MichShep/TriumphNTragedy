#include "Runner.h"

//& Sequence of Play

bool Runner::run(){
    bool running = true;

    test();

    //& Draw the initial Board
    ClearScreen(app.renderer);
    for (auto& a : powers_app){
        ClearScreen(a.renderer);
    }

    //- Draw Player Stats
    SDL_Rect tar = {0,0,1512,912};
    map_sprite.drawSprite(app.renderer, &tar, 0, 0, 1512, 912);

    DrawConnections();

    auto& cities = map.getCities();
    for (auto city : cities)
        drawCity(city.second);

    drawInfluence();

    SDL_RenderPresent(app.renderer);

    bool player_board_changed[3] = {true, true, true}; //true for first time for initial draw
    SDL_Event event;
    while (running){
        if (player_board_changed[WEST]){
            drawPlayerBoard(players[WEST], powers_app[WEST].renderer);
            player_board_changed[WEST] = false;
        }
        if (player_board_changed[AXIS]){
            drawPlayerBoard(players[AXIS], powers_app[AXIS].renderer);
            player_board_changed[AXIS] = false;
        }
        if (player_board_changed[USSR]){
            drawPlayerBoard(players[USSR], powers_app[USSR].renderer);
            player_board_changed[USSR] = false;
        }
 
        if (SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:{
                    int mouseX,mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    const auto& allegiance = event.window.windowID-2;
                    if (event.window.windowID > 1){ //is a player window //TODO Optomize
                        if (mouseY > 40*3){
                            if (inBox(53*3, 47*3, 27, 51, mouseX, mouseY)){ // is button #1
                                player_board_changed[allegiance] = true;
                                if ((players[allegiance].action_card_start-=2) < 0)
                                    players[allegiance].action_card_start = players[allegiance].getActionSize()-2;
                            }
                            else if (inBox(262*3, 47*3, 27, 51, mouseX, mouseY)){ // is button #2
                                player_board_changed[allegiance] = true;
                                if ((players[allegiance].action_card_start+= 2) >= players[allegiance].getActionSize())
                                    players[allegiance].action_card_start = 0;
                            }

                            else if (inBox(53*3, 86*3, 27, 51, mouseX, mouseY)){ // is button #3
                                player_board_changed[allegiance] = true;
                                if ((players[allegiance].invest_card_start-=2) < 0)
                                    players[allegiance].invest_card_start = players[allegiance].getInvestSize()-2;
                            }
                            else if (inBox(262*3, 86*3, 27, 51, mouseX, mouseY)){ // is button #4
                                player_board_changed[allegiance] = true;
                                if ((players[allegiance].invest_card_start+= 2) >= players[allegiance].getInvestSize())
                                    players[allegiance].invest_card_start = 0;
                            }

                            else if (inBox(70*3, 128*3, 27, 51, mouseX, mouseY)){ // is button #5
                                player_board_changed[allegiance] = true;
                                if ((players[allegiance].tech_card_start-=5) < 0)
                                    players[allegiance].tech_card_start = players[allegiance].getTechSize()-2;
                            }
                            else if (inBox(245*3, 128*3, 27, 51, mouseX, mouseY)){ // is button #6
                                player_board_changed[allegiance] = true;
                                if ((players[allegiance].tech_card_start+= 5) >= players[allegiance].getTechSize()){
                                    players[allegiance].tech_card_start = 0;
                                }
                            }
                        }
                        else if (inBox(9*3, 8*3, 81*3, 23*3, mouseX, mouseY)){ //is a change screen button
                            if (mouseX >= 35*3 && players[allegiance].state != PRODUCTION_BOARD){ //production button
                                players[allegiance].state = PRODUCTION_BOARD;
                                player_board_changed[allegiance] = true;
                            }

                            else if (mouseX <= 30*3 && mouseX >= 10*3 && players[allegiance].state != HOME_BOARD){ //home button
                                players[allegiance].state = HOME_BOARD;
                                player_board_changed[allegiance] = true;
                            }
                        }
                    }
                }
                break;

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
    while ((winner=newYear()) != WATER && year <= end_year){ //run the game unitl a winner is found

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

    //- Reshuffle..
    reshuffle(true);

    //- Peace Dividends.
    peaceDividends();

    //- Turn Order..
    decideTurnOrder();

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
    int num_production;
    bool running=true;
    bool player_board_changed[3] = {true, true, true};

    bool map_changed = true;

    //1:add invest card 1:add action card
    stack<int> actions;

    int bought_action=0, bought_invest=0;

    SDL_Event event;
    //- Go through each player in turn order
    for (auto& player : turn_order){
        //- Check trade routes
        checkTradeRoutes(*player, player->getCapital());

        num_production = player->getProduction();

        while (running){

            if (map_changed){
                ClearScreen(app.renderer);
                SDL_Rect tar = {0,0,1512,912};
                map_sprite.drawSprite(app.renderer, &tar, 0, 0, 1512, 912);

                DrawConnections();

                auto& cities = map.getCities();
                for (auto city : cities)
                    drawCity(city.second);

                drawInfluence();

                SDL_RenderPresent(app.renderer);
            }

            if (player_board_changed[WEST]){
                drawPlayerBoard(players[WEST], powers_app[WEST].renderer, bought_action, bought_invest);
                player_board_changed[WEST] = false;
            }
            if (player_board_changed[AXIS]){
                drawPlayerBoard(players[AXIS], powers_app[AXIS].renderer, bought_action, bought_invest);
                player_board_changed[AXIS] = false;
            }
            if (player_board_changed[USSR]){
                drawPlayerBoard(players[USSR], powers_app[USSR].renderer, bought_action, bought_invest);
                player_board_changed[USSR] = false;
            }

            if (SDL_PollEvent(&event)){
                switch (event.type) {
                    case SDL_MOUSEBUTTONDOWN:{
                        int mouseX,mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);
                        const auto& allegiance = event.window.windowID-2;
                        if (event.window.windowID > 1){ //is a player window //TODO Optomize
                            //- Check on all boards if the board needs to change
                            if (inBox(9*3, 9*3, 73*3, 23*3, mouseX, mouseY)){ //is a change screen button
                                if (mouseX <= 30*3 && mouseX >= 10*3 && players[allegiance].state != HOME_BOARD){ //home button
                                    players[allegiance].state = HOME_BOARD;
                                    player_board_changed[allegiance] = true;
                                }
                                else if (mouseX >= 35*3 && players[allegiance].state != PRODUCTION_BOARD){ //production button
                                    players[allegiance].state = PRODUCTION_BOARD;
                                    player_board_changed[allegiance] = true;
                                }
                            }

                            //- Check home board buttons
                            if (players[allegiance].state == HOME_BOARD){
                                if (inBox(53*3, 47*3, 27, 51, mouseX, mouseY)){ // is button #1
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].action_card_start-=2) < 0)
                                        players[allegiance].action_card_start = players[allegiance].getActionSize()-2;
                                }
                                else if (inBox(262*3, 47*3, 27, 51, mouseX, mouseY)){ // is button #2
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].action_card_start+= 2) >= players[allegiance].getActionSize())
                                        players[allegiance].action_card_start = 0;
                                }

                                else if (inBox(53*3, 86*3, 27, 51, mouseX, mouseY)){ // is button #3
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].invest_card_start-=2) < 0)
                                        players[allegiance].invest_card_start = players[allegiance].getInvestSize()-2;
                                }
                                else if (inBox(262*3, 86*3, 27, 51, mouseX, mouseY)){ // is button #4
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].invest_card_start+= 2) >= players[allegiance].getInvestSize())
                                        players[allegiance].invest_card_start = 0;
                                }

                                else if (inBox(70*3, 128*3, 27, 51, mouseX, mouseY)){ // is button #5
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].tech_card_start-=5) < 0)
                                        players[allegiance].tech_card_start = players[allegiance].getTechSize()-2;
                                }
                                else if (inBox(245*3, 128*3, 27, 51, mouseX, mouseY)){ // is button #6
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].tech_card_start+= 5) >= players[allegiance].getTechSize()){
                                        players[allegiance].tech_card_start = 0;
                                    }
                                }
                            }
                            
                            //- Only the currenyt player will have access to confirm, others can plan ahead
                            else if (players[allegiance].state == PRODUCTION_BOARD){
                                //- PRODUCTION BUTTON ACTIONS
                                if (inBox(289*3, 87*3, 23*3, 23*3, mouseX, mouseY)){ //add investment card
                                    bought_invest++;
                                    actions.push(1);
                                    player_board_changed[allegiance] = true;
                                }
                                else if (inBox(289*3, 113*3, 23*3, 23*3, mouseX, mouseY)){ //add investment card
                                    bought_action++;
                                    actions.push(2);
                                    player_board_changed[allegiance] = true;
                                }
                                else if (inBox(3*6, 3*100, 3*9, 3*17, mouseX, mouseY)){ //scroll left
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].controlled_cities_start-=6) < 0)
                                        players[allegiance].controlled_cities_start = players[allegiance].getControlledSize()-6;
                                }

                                else if (inBox(3*242, 3*100, 3*9, 3*17, mouseX, mouseY)){ //scroll right
                                    player_board_changed[allegiance] = true;
                                    if ((players[allegiance].controlled_cities_start+= 6) >= players[allegiance].getControlledSize())
                                        players[allegiance].controlled_cities_start = 0;
                                }

                            }
                            
                        }
                    }
                    break;

                    case SDL_KEYDOWN:{
                        running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                    }
                    break;

                    default: {
                        break;
                    }
                }
            }
        }
    }
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
    if (year == 1936)
        return;
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

void Runner::decideTurnOrder(){
    //- Determine starting player and the rotation of turns (roll dice)
    int result = die.roll();
    switch (result){
    case 1:
        start_player = players[AXIS];
        turn_order[0] = &players[AXIS];
        turn_order[1] = &players[USSR];
        turn_order[2] = &players[WEST];
        break;
    case 2:
        start_player = players[AXIS];
        turn_order[0] = &players[AXIS];
        turn_order[1] = &players[WEST];
        turn_order[2] = &players[USSR];
        break;
    case 3:
        start_player = players[WEST];
        turn_order[0] = &players[WEST];
        turn_order[1] = &players[AXIS];
        turn_order[2] = &players[USSR];
        break;
    case 4:
        start_player = players[WEST];
        turn_order[0] = &players[WEST];
        turn_order[1] = &players[USSR];
        turn_order[2] = &players[AXIS];
        break;
    case 5:
        start_player = players[USSR];
        turn_order[0] = &players[USSR];
        turn_order[1] = &players[WEST];
        turn_order[2] = &players[AXIS];
        break;
    case 6:
        start_player = players[USSR];
        turn_order[0] = &players[USSR];
        turn_order[1] = &players[AXIS];
        turn_order[2] = &players[WEST];
        break;
    default:
        printf("Uh this dice need to be fixed");
        exit(1);
    }

    drawTurnRoll(result);
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