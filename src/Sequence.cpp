#include "Runner.h"

//& Sequence of Play

bool Runner::run(){
    bool running = true;

    test();

    //& Draw the initial Board
    drawMap(true, false, false, true);

    /*bool player_board_changed[3] = {true, true, true}; //true for first time for initial draw
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

                case SDL_CONTROLLERBUTTONDOWN:{
                    if (event.cbutton.button == SDL_CONTROLLER_BUTTON_A){
                        cout << "A was mapped!" << endl;
                    }
                    if (event.cbutton.button == SDL_CONTROLLER_BUTTON_A){
                        cout << "B was mapped!" << endl;
                    }
                }

                case SDL_KEYDOWN:{
                    running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                    switch(event.key.keysym.scancode){
                        case SDL_SCANCODE_RIGHT:{
                            players[WEST].mapX += 6;
                            player_board_changed[WEST] = true;
                            break;

                        }

                        case SDL_SCANCODE_LEFT:{
                            players[WEST].mapX -= 6;
                            player_board_changed[WEST] = true;
                            break;
                        }

                        case SDL_SCANCODE_UP:{
                            players[WEST].mapY -= 6;
                            player_board_changed[WEST] = true;
                            break;
                        }

                        case SDL_SCANCODE_DOWN:{
                            players[WEST].mapY += 6;
                            player_board_changed[WEST] = true;
                            break;
                        }
                        default:{
                            break;
                        }
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
    }*/
    
    //& Main game Loop
    CityType winner;
    while ((winner=newYear()) != WATER && year <= end_year){ //run the game unitl a winner is found

    }
    
    
    freeMemory();
    printf("Memory was deleted\n");


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
    //reshuffle(true);

    //- Peace Dividends.
    //peaceDividends();

    //- Turn Order..
    //decideTurnOrder();

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
    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    double delta = 0;

    bool map_changed = true;

    //1:add invest card 1:add action card
    stack<int> actions;

    int bought_action=0, bought_invest=0;

    SDL_Event event;
    //- Go through each player in turn order
    for (auto& player : turn_order){
        //- Check trade routes
        //checkTradeRoutes(*player, player->getCapital());

        //- Get the production for this round
        num_production = player->getProduction();

        while (running){
            a = SDL_GetTicks();
            delta = a - b;

            if (delta > 1000/30.0){
                //cout << "fps:" << (1000/delta) << endl;

                b = a;  
                //- Check if things have chnaged to redraw
                if (map_changed){
                    drawMap(true, true, true, false, true, (1000/delta));
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


                //- Check Player input
                if (SDL_PollEvent(&event)){
                    switch (event.type) {
                        case (SDL_CONTROLLERBUTTONDOWN):{
                            int allegiance = event.cbutton.which;
                            switch(event.cbutton.button){
                                //- Change current screen to the one on the left
                                case (SDL_CONTROLLER_BUTTON_LEFTSHOULDER):{
                                    cout << "Left bumber pressed" << endl;
                                    player_board_changed[allegiance] = true;
                                    if (players[allegiance].state == HOME_BOARD){
                                        players[allegiance].state = GOVERNMENT_BOARD;
                                    }
                                    else{
                                        players[allegiance].state = (BoardState)(players[allegiance].state-1);  
                                    }
                                    break;
                                }

                                //- Change current screen to the one on the right
                                case (SDL_CONTROLLER_BUTTON_RIGHTSHOULDER):{
                                    cout << "Right bumber pressed" << endl;
                                    player_board_changed[allegiance] = true;
                                    players[allegiance].state = (BoardState)((players[allegiance].state+1)%3);
                                    break;
                                }

                                case (SDL_CONTROLLER_BUTTON_DPAD_LEFT):{
                                    cout << "DPAD left pressed" << endl;
                                    players[allegiance].mapX -= 6;
                                    if (players[allegiance].state == PRODUCTION_BOARD)
                                        player_board_changed[allegiance] = true;
                                    break;
                                }

                                case (SDL_CONTROLLER_BUTTON_DPAD_RIGHT):{
                                    cout << "DPAD right pressed" << endl;
                                    players[allegiance].mapX += 6;
                                    if (players[allegiance].state == PRODUCTION_BOARD)
                                        player_board_changed[allegiance] = true;
                                    break;
                                }

                                case (SDL_CONTROLLER_BUTTON_DPAD_UP):{
                                    cout << "DPAD up pressed" << endl;
                                    players[allegiance].mapY -= 6;
                                    if (players[allegiance].state == PRODUCTION_BOARD)
                                        player_board_changed[allegiance] = true;
                                    break;
                                }

                                case (SDL_CONTROLLER_BUTTON_DPAD_DOWN):{
                                    cout << "DPAD down pressed" << endl;
                                    players[allegiance].mapY += 6;
                                    if (players[allegiance].state == PRODUCTION_BOARD)
                                        player_board_changed[allegiance] = true;
                                    break;
                                }
                                
                                default:{
                                    break;
                                }
                            }
                        
                        }

                        case SDL_KEYDOWN:{
                            running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;                       
                            break;
                        }

                        default: {
                            cout << event.type << endl;
                            break;
                        }
                    }
                }
            }
            else{

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
        start_player = &players[AXIS];
        turn_order[0] = &players[AXIS];
        turn_order[1] = &players[USSR];
        turn_order[2] = &players[WEST];
        break;
    case 2:
        start_player = &players[AXIS];
        turn_order[0] = &players[AXIS];
        turn_order[1] = &players[WEST];
        turn_order[2] = &players[USSR];
        break;
    case 3:
        start_player = &players[WEST];
        turn_order[0] = &players[WEST];
        turn_order[1] = &players[AXIS];
        turn_order[2] = &players[USSR];
        break;
    case 4:
        start_player = &players[WEST];
        turn_order[0] = &players[WEST];
        turn_order[1] = &players[USSR];
        turn_order[2] = &players[AXIS];
        break;
    case 5:
        start_player = &players[USSR];
        turn_order[0] = &players[USSR];
        turn_order[1] = &players[WEST];
        turn_order[2] = &players[AXIS];
        break;
    case 6:
        start_player = &players[USSR];
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
    bool animates1=false, animates2=false, animates3=false;
    if (peace_dividends_bag.size() == 0) //in game its impossible to runnout of chits so this is for testing
        return;

    //- Check for West
    if (players[0].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[0].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
        animates1 = true;
    }

    //- Axis
    if (players[1].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[1].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
        animates2 = true;
    }

    //-USSR
    if (players[2].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[2].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
        animates3 = true;
    }

    drawPeaceDividends(animates1, animates2, animates3);
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