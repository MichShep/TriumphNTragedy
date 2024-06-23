#include "Runner.h"

//& Sequence of Play

bool Runner::run(){
    reshuffle(false);

    //& Draw the initial Board
    drawPlayerBoard(players[WEST]);
    drawPlayerBoard(players[AXIS]);
    drawPlayerBoard(players[USSR]);
    
    //& Main game Loop
    CityType winner;
    while ((winner=newYear()) != WATER && year <= end_year){ //run the game unitl a winner is found

    }
    
    
    freeMemory();
    printf("Memory was deleted\n");

    return EXIT_SUCCESS;
}

//&^ New Year

CityType Runner::newYear(){
    season = NEW_YEAR;
    
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
    //peaceDividends();

    //- Turn Order..
    decideTurnOrder();

    //- New Year Resolution.
    newYearRes();

    //- Production Phase..
    //production();
    
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
    season = PRODUCTION;
    // Used to calculate fps
    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    double delta = 0;

    //- Get the production for all players so they can plan ahead
    players[WEST].calculateProduction();
    players[AXIS].calculateProduction();
    players[USSR].calculateProduction();

    //- Initial draw
    drawPhase(0);

    public_messages.push_back(PublicMessage(PRODUCTION_START, b));
    //- Go through each player in turn order
    for (auto& player : turn_order){
        bool running=true;
        current_player = player;

        //- Check trade routes
        //TODO fix animation
        checkTradeRoutes(*player, player->getCapital());

        while (running || !public_messages.empty()){
            a = SDL_GetTicks();
            delta = a - b;

            //ensures framerate of 60fps
            if (delta > 1000/60.0){
                b = a;  
                //- Player input
                handleUserInput(running, b);

                //- Render
                drawPhase(b);

                //- Check if player has passed
                running = !player->passed;
            }
        }
        //- Set production things to null
        player->selected_unit = {nullptr, nullptr};
        player->building_city = nullptr;
    }    
}

void Runner::drawPhase(const Uint32& delta){
    //- Check if things have changed and need to be redrawn

    if (map_changed){
        //drawMap(WEST, true, true, true, false, true);
    }
    
    if (players[WEST].board_change){
        drawPlayerBoard(players[WEST], delta);
        players[WEST].board_change = false;
    }
    if (players[AXIS].board_change){
        drawPlayerBoard(players[AXIS], delta);
        players[AXIS].board_change = false;
    }
    if (players[USSR].board_change){
        drawPlayerBoard(players[USSR], delta);
        players[USSR].board_change = false;
    }
}

//- Government Phase

void Runner::government(){
    season = GOVERNMENT;

    players[WEST].passed = false;
    players[AXIS].passed = false;
    players[USSR].passed = false;


    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    double delta = 0;

    //- Initial draw
    drawPhase(0);

    public_messages.push_back(PublicMessage(GOVERNMENT_START, b));

    //- Go through each player in turn order but it can loop so it will be an inner loop
    bool running=true;
    current_player = turn_order[0];
    cout << current_player->getName() << endl;

    while (running || !public_messages.empty()){
        a = SDL_GetTicks();
        delta = a - b;

        //ensures framerate of 60fps
        if (delta > 1000/60.0){
            b = a;  
            //- Player input
            handleUserInput(running, b);

            //- Render
            drawPhase(b);

            //- Check if player has passed
            running = !turn_order[0]->passed || !turn_order[1]->passed ||  !turn_order[2]->passed;
        }
    }

    //- Diplomacy Resolution
    resolveDiplomacy();
    
        //- Diplomacy

        //- Industry

        //- Technology

        //- Intelligence

        //- Pass
}

bool Runner::addDiplomacy(Player& player, Country* country){
    //- if there is a selected value and it can be influenced (less than a satellite)
    if (country == nullptr || country->influence_level == SATELLITES){
        return false;
    }

    //TODO add error messages
    if (country->armed_minor){
        return false;
    }

    //- if can add card remove fram hand
    ActionCard* used_card = player.popped_action_card;
    player.remove(used_card);

    player.popped_action_card_index = loopVal(player.popped_action_card_index, 0 , player.getActionSize()-1);
    player.selected_country = nullptr;
    player.show_left_country = true;
    player.show_right_country = true;
    player.popped_action_card = player.getActionCard(player.popped_action_card_index);
    if (player.popped_action_card->type == DIPLOMACY){
            player.popped_left_country = map.getCapital(player.popped_action_card->countryA);
            player.popped_right_country =  map.getCapital(player.popped_action_card->countryB);
    }

    //- add it to discard pile
    action_discard.push_back(used_card);

    country->addCard(player.getAllegiance());
    
    return true;
}

void Runner::resolveDiplomacy(){
    for (auto& country : map.getCountries()){
        country.second->resolveCards();
        cout << country.second->name << " " << country.second->influence << endl;
    }
    mapPlayerResPop(players[WEST]);
    mapPlayerResPop(players[AXIS]);
    mapPlayerResPop(players[USSR]);
}
//- Spring Season
void Runner::spring(){
    season = SPRING;
    //- Command Phase

    //- Player Turns
        //- Movement

        //- Combat

    //- Supply Phase
        //- Supply

}

//- Summer Season
void Runner::summer(){
    season = SUMMER;
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
    season = FALL;
    //- Command Phase

    //- Player Turns
        //- Movement

        //- Combat

    //- Supply Phase
        //- Supply
}

//- Winter Season
void Runner::winter(){
    season = WINTER;
    //- USSR plays one card

    //- USSR Turn
        //- Movement in USSR

        //- Combat in USSR

    //- Supply Phase for USSR
        //- Supply
}

//&^^ New Year Helpers

void Runner::reshuffle(const bool animation){
    season = RESHUFFLE;
    if (year == 1936)
        return;

    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    double delta = 0;

    //- Initial draw
    if (animation){
        drawPhase(0);
        public_messages.push_back(PublicMessage(RESHUFFLE_START, b));
    }

    //- Actual reshuffle
    //- Add action discard and shuffle
    action_deck.insert(action_deck.end(), action_discard.begin(), action_discard.end());
    shuffle(action_deck.begin(), action_deck.end(), g);

    //- Add invest discard and shuffle
    invest_deck.insert(invest_deck.end(), invest_discard.begin(), invest_discard.end());
    shuffle(invest_deck.begin(), invest_deck.end(), g);

    //- Go through each player in turn order
    if (animation){
        bool running=true;

        while (running){
            a = SDL_GetTicks();
            delta = a - b;

            //ensures framerate of 60fps
            if (delta > 1000/60.0){
                b = a;  
                //- Player input
                handleUserAnimationInput(running, b);

                //- Render
                animateReshuffle(running, action_discard.size(), invest_discard.size(), b);


            }
        }
    }

    //- Clear discard piles
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

void Runner::decideTurnOrder(const bool animation){
    //- Determine starting player and the rotation of turns (roll dice)
    int result = die.roll();
    cout << "Set turn order of WEST AXIS USSR loaded" << endl;
    result = 3;
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

    if (animation)
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

void Runner::applyProduction(Player& player){
    player.upgradeUnits();
    deal(&player, player.bought_action, 'A');
    deal(&player, player.bought_invest, 'I');
    player.bought_action=0;
    player.bought_invest=0;
    player.passed = true;
}

void Runner::handCheck(Player* player){

}