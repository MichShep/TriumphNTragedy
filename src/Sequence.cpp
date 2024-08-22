#include "Runner.h"

//& Sequence of Play
bool Runner::runTitle(){
    season = TITLE_SCREEN;

    bool fade=true;
    tick_t current_tick = SDL_GetTicks();
    clock = SDL_GetTicks();

    tick_t start;
    
    int alpha = 255;
    double delta = 0;
    while (alpha >= 0){
        current_tick = SDL_GetTicks();
        delta = current_tick - clock;

        //ensures framerate of 60fps
        if (delta > 1000/60.0){
            clock = current_tick;  

            handleTitleInput(fade);

            drawTitle(*west_player, alpha);
            drawTitle(*axis_player, alpha);
            drawTitle(*ussr_player, alpha);

            if (fade){
                if (!(fade = fade && !(west_player->passed + axis_player->passed + ussr_player->passed == (controllers[0]!=NULL)+(controllers[1]!=NULL)+(controllers[2]!=NULL))))                  start = clock;  
            }
            else
                alpha = alpha - ((clock-start)/5000);
        }
    }
    fade = true; //just reuse for running
    start = clock;
    while (fade){    //animate poem start
        current_tick = SDL_GetTicks();
        delta = current_tick - clock;

        if (delta > 1000/60.0){
            clock = current_tick;

            animatePoem(*west_player);
            animatePoem(*axis_player);
            animatePoem(*ussr_player);

            fade = !pastWait(start, clock, 15000);
        }
    }

    west_player->passed = false; axis_player->passed = false; ussr_player->passed = false;

    return true;
}

bool Runner::run(){
    //runTitle();

    drawPlayerBoard(players[WEST]);
    drawPlayerBoard(players[AXIS]);
    drawPlayerBoard(players[USSR]);

    //initUnits();

    reshuffle(false);
    
    //& Main game Loop
    CityType winner;
    while ((winner=newYear()) == WATER && year <= end_year){ //run the game unitl current_tick winner is found
        //production(); //- Production Phase
        
        //government(); //- Government Phase  

        checkHands(); //- Check Hand Size

        spring(); //- Spring season of fighting

        summer(); //- Summer season of fighting

        blockade(); //- Add new blockades

        fall(); //- Fall season of fighting

        winter(); //- Winter season of fighting (only USSR)
    }

     
    freeMemory();
    printf("Memory was deleted\n");

    return EXIT_SUCCESS;
}

//&^ Initalizing Game

bool Runner::initUnits(){
    bool running = true;
    double delta = 0;

    tick_t current_tick = SDL_GetTicks();
    clock = SDL_GetTicks();

    season = INIT_UNITS;

    turn_order[0] = axis_player;
    turn_order[1] = west_player;
    turn_order[2] = ussr_player;

    while (running){
        current_tick = SDL_GetTicks();
        delta = current_tick - clock;

        if (delta > 1000/60.0){
            clock = current_tick;
            fps = (1000.0f / (delta));

            handleUserInput(running);

            drawPhase();

            running = !west_player->passed || !axis_player->passed || !ussr_player->passed;
        } 
    }


    applyProduction(*west_player);
    applyProduction(*axis_player);
    applyProduction(*ussr_player);

    west_player->passed = false;
    axis_player->passed = false;
    ussr_player->passed = false;

    return true;
}

//&^ New Year

CityType Runner::newYear(){
    season = NEW_YEAR;
    
    year++; //- Advance Year

    //- Victroy Check 
    for (Player player : players){
        if (player.getVP() >= 25){
            return player.getAllegiance();
        }
    }

    reshuffle(false); //- Reshuffle..

    peaceDividends(); //- Peace Dividends.

    decideTurnOrder(); //- Turn Order..

    newYearRes(); //- New Year Resolution.

    return CityType::WATER;
}

//&^^ Production Phase

void Runner::production(){
    season = PRODUCTION;
    // Used to calculate fps
    tick_t current_tick = SDL_GetTicks();
    clock = SDL_GetTicks();
    double delta = 0;

    //- Get the production for all players so they can plan ahead
    players[WEST].calculateProduction();
    players[AXIS].calculateProduction();
    players[USSR].calculateProduction();

    //- Initial draw
    drawPhase();

    public_messages.push_back(PublicMessage(PRODUCTION_START, clock, 500, 160, 32, 20));
    //- Go through each player in turn order
    for (auto& player : turn_order){
        bool running=true;
        current_player = player;

        //- Check trade routes
        //TODO fix animation
        checkTradeRoutes(*player, player->getCapital());

        while (running || !public_messages.empty()){
            current_tick = SDL_GetTicks();
            delta = current_tick - clock;
            fps = (1000.0f / (delta));

            //ensures framerate of 60fps
            if (delta > 1000/60.0){
                clock = current_tick;
                //- Player input
                handleUserInput(running);

                //- Render
                drawPhase();

                //- Check if player has passed
                running = !player->passed;
            }
        }
        //- Set production things to null
        player->selected_unit = {nullptr, nullptr};
        player->option_select_city = nullptr;
    }    
}

void Runner::drawPhase(){
    //- Check if things have changed and need to be redrawn    
    if (players[WEST].board_change){
        ClearScreen(players[WEST].app->renderer);
        drawPlayerBoard(players[WEST], true);
        players[WEST].board_change = false;
    }
    if (players[AXIS].board_change){
        ClearScreen(players[AXIS].app->renderer);
        drawPlayerBoard(players[AXIS], true);
        players[AXIS].board_change = false;
    }
    if (players[USSR].board_change){
        ClearScreen(players[USSR].app->renderer);
        drawPlayerBoard(players[USSR], true);
        players[USSR].board_change = false;
    }

    //- Check if any animations need to be cleared
    for (int i = public_animations.size()-1; i >= 0; i--){
        if (public_animations[i].updateNext(clock)){
            public_animations.erase(public_animations.begin()+i);
        }
    }

}

//&^^ Government Phase

void Runner::government(){
    season = GOVERNMENT;

    players[WEST].passed = false;
    players[AXIS].passed = false;
    players[USSR].passed = false;


    tick_t current_tick = SDL_GetTicks();
    clock = SDL_GetTicks();
    double delta = 0;

    //- Initial draw
    drawPhase();

    public_messages.push_back(PublicMessage(GOVERNMENT_START, clock, 300, 160, 32, 25));

    //- Go through each player in turn order but it can loop so it will be an inner loop
    bool running=true;
    current_player = turn_order[0];

    while (running || !public_messages.empty()){
        current_tick = SDL_GetTicks();
        delta = current_tick - clock;

        //ensures framerate of 60fps
        if (delta > 1000/60.0){
            
            clock = current_tick;  
            //- Player input
            handleUserInput(running);

            //- Render
            drawPhase();

            //- Check if player has passed
            running = !turn_order[0]->passed || !turn_order[1]->passed ||  !turn_order[2]->passed;
        }
    }

    //- Diplomacy Resolution
    resolveDiplomacy();

    players[WEST].passed = false;
    players[AXIS].passed = false;
    players[USSR].passed = false;

    current_index = 0;
}

bool Runner::addDiplomacy(Player& player, Country* country){
    //- if there is current_tick selected value and it can be influenced (less than current_tick satellite)
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

void Runner::checkHands(){
    for (auto& player: turn_order){
        (void)player;
    }
}

//& General Wartime 

void Runner::sortCommand(){
    temp_order[0] = turn_order[0];
    temp_order[1] = turn_order[1];
    temp_order[2] = turn_order[2];
    // current season then earlier letter then random on tie
    if (compareCards(temp_order[0]->command_card, temp_order[1]->command_card))
        std::swap(temp_order[0], temp_order[1]);
    if (compareCards(temp_order[0]->command_card, temp_order[2]->command_card))
        std::swap(temp_order[0], temp_order[2]);
    if (compareCards(temp_order[1]->command_card, temp_order[2]->command_card))
        std::swap(temp_order[1], temp_order[2]);

}

bool Runner::declareDoW(Player& declarer, Player& victim){
    const CityType& rival_all = victim.getAllegiance();
    //* Check that they aren't declaring on themselves
    if (declarer == victim)
        return false;

    //* Check that they don't already have a DoW
    if (declarer.getDoW(rival_all) != PEACE)
        return false;

    //* Apply DoW
    declarer.setDoW(rival_all, DECLARED);
    victim.setDoW(declarer.getAllegiance(), VICTIM);
    declarer.setWartime();
    victim.setWartime();

    return true;
}

bool Runner::declareVoN(Player& declarer){
    const auto& allegiance = declarer.getAllegiance();

    const auto& city = declarer.closest_map_city;

    if (city == nullptr)
        return false;

    //* Closest city must be a NEUTRAL capital
    if (!city->capital || city->ruler_allegiance != NEUTRAL || city->ruler_allegiance == declarer){
        return false;
    }

    Country* country = map.getCountry(city->country);

    //* Check if its been VoNed already
    if (country->voilation_of_neutrality[0] || country->voilation_of_neutrality[1] || country->voilation_of_neutrality[2]){
        return false;
    }

    // Set VoN
    country->voilation_of_neutrality[allegiance] = true;
    country->first_violator_allegiance = declarer;

    //Put out forts
    for (auto& c : country->cities){
        if (c->muster > 0){
            Unit* new_unit = new Unit(0, NEUTRAL_U, FORTRESS, c->muster, year);
            c->addUnit(new_unit);
            neutral_units.push_back(new_unit);
        }
    }

    country->influence = 0;
    country->armed_minor = true;
    country->allegiance = NEUTRAL;

    //World Reaction
    for (auto& p : players){
        if (declarer != p){
            deal(&p, city->muster, 'A');
        }
    }

    return true;
}

bool Runner::declareIntervention(Player& declarer){
    const auto& allegiance = declarer.getAllegiance();

    const auto& city = declarer.closest_map_city;

    if (city == nullptr)
        return false;

    // Closest city must be a NEUTRAL capital
    if (!city->capital || city->ruler_allegiance != NEUTRAL || city->start_allegiance == WATER){
        return false;
    }

    // Check for a ground unit in (any?) city
    Country* country = map.getCountry(city->country);

    // Check if its been VoNed already AND if the player hasn't violated it yet
    if ((country->first_violator_allegiance != NULL_ALLEGIANCE) && country->voilation_of_neutrality[allegiance]){
        return false;
    }

    // Check if the first (real) violator is an enemy
    if (!declarer.isEnemy(country->first_violator_allegiance)){
        return false;
    }

    bool has_ground = false;
    for (const auto& c : country->cities){
        for (const auto& unit : c->occupants[allegiance]){
            has_ground = has_ground || unit->class_type == CLASS_G;
        }
    }

    if (!has_ground){
        return false;
    }

    //If survived all checks then set player to change all units
    country->intervened = true;
    country->intervenie = allegiance;
    declarer.intervened_countries.push_back(country);
    return true;
}

bool Runner::compareCards(const ActionCard* lhs, const ActionCard* rhs){
    if (!rhs && !lhs)
        return true;

    if (lhs == nullptr)
        return true;

    if (rhs == nullptr)
        return false;        

    // the one with the correct season has priority
    if (lhs->season == season-SPRING_COMMAND && rhs->season != season-SPRING_COMMAND)
        return false;

    if (rhs->season == season-SPRING_COMMAND && lhs->season != season-SPRING_COMMAND)
        return true;

    // if either both have the priority season or both dont then compare priority letter
    if (lhs->command_priority == rhs->command_priority) //if the priorities are tied then randomize 
        return rand()%2;

    return lhs->command_priority > rhs->command_priority;
}

bool Runner::flipConvoy(Player& player,  City* city, Unit* unit){
    if (unit->class_type == CLASS_G && unit->unit_type != FORTRESS){
        const auto& adj = map.getAdjacency()[city->ID];

        bool able = false;
        for (const auto& border : adj) //check if the unit is even around water to turn into current_tick convo
            able = able || border==COAST;

        if (!able)
            return false;

        unit->convoy = !unit->convoy;

        return true;
    }

    return false;
}

//&^ Spring Season

void Runner::spring(){
    season = SPRING;
    year = (int)year + ((double)season)/10;

    tick_t current_tick = SDL_GetTicks();
    clock = SDL_GetTicks();
    double delta = 0;

    drawPhase(); //- Initial draw

    bool running=true;
    current_index = 0;
    current_player = turn_order[0];

    /*season = SPRING_COMMAND;
    //- Command Phase
    while (running || !public_messages.empty()){
        current_tick = SDL_GetTicks();
        delta = current_tick - b;

        //ensures framerate of 60fps
        if (delta > 1000/60.0){
            b = current_tick;
        
            //- Player input
            handleUserInput(running, b);

            //- Render
            drawPhase(b);

            running = !west_player->passed || !axis_player->passed ||  !ussr_player->passed;
        }
    }
    sortCommand();

    //- Animate Command Phase Change
    running = true;

    const int west_start = west_player->getCommandNumber() == -1 ? -1 : (turn_order[0] == west_player? 0 : (turn_order[1] == west_player? 1 : (turn_order[2] == west_player? 2: -1)));
    const int axis_start = axis_player->getCommandNumber() == -1 ? -1 :  (turn_order[0] == axis_player? 0 : (turn_order[1] == axis_player? 1 : (turn_order[2] == axis_player? 2: -1)));
    const int ussr_start = ussr_player->getCommandNumber() == -1 ? -1 :  (turn_order[0] == ussr_player? 0 : (turn_order[1] == ussr_player? 1 : (turn_order[2] == ussr_player? 2: -1)));
    const int west_end  = west_player->getCommandNumber() == -1 || west_player->getCommandNumber() == 0? -1 : (temp_order[0] == west_player? 0 : (temp_order[1] == west_player? 1 : (temp_order[2] == west_player? 2: -1)));
    const int axis_end  = axis_player->getCommandNumber() == -1 || axis_player->getCommandNumber() == 0? -1 :  (temp_order[0] == axis_player? 0 : (temp_order[1] == axis_player? 1 : (temp_order[2] == axis_player? 2: -1)));
    const int ussr_end  = ussr_player->getCommandNumber() == -1 || ussr_player->getCommandNumber() == 0? -1 :  (temp_order[0] == ussr_player? 0 : (temp_order[1] == ussr_player? 1 : (temp_order[2] == ussr_player? 2: -1)));
    //cout << west_start << " " << axis_start << " " << ussr_start << endl;
    //cout << west_end << " " << axis_end << " " << ussr_end << endl;

    


    last_tick = b;

    while (running){
        current_tick = SDL_GetTicks();
        delta = current_tick - b;

        if (delta > 1000/60.0){
            b = current_tick;

            running = !pastWait(last_tick,b, 10000);

            //- Player input
            handleUserAnimationInput(running, b);

            animateCommandOrder(running, b, west_start, axis_start, ussr_start, west_end, axis_end, ussr_end);
        } 
    }
    phase = 0;
    last_tick = 0;*/

    season = SPRING;

    turn_order[0] = west_player;
    turn_order[1] = axis_player;
    turn_order[2] = ussr_player;
    turn_order[0]->setCommandNumber(5); //todo remove for full
    turn_order[1]->setCommandNumber(2);
    turn_order[2]->setCommandNumber(-1);

    ussr_player->passed = true;
    axis_player->passed = true;

    running = true;
    current_player = turn_order[0];
    current_player->combat_phase = MOVEMENT;
    while (running){
        current_tick = SDL_GetTicks();
        delta = current_tick - clock;

        if (delta > 1000/60.0){
            clock = current_tick;
            fps = (1000.0f / (delta));

            handleUserInput(running);

            drawPhase();

            running = !west_player->passed || !axis_player->passed || !ussr_player->passed;
        } 
    }

    updateCityRulers();

    //- Player Turns
        //- Movement

        //- Combat

    //- Supply Phase
        //- Supply

    west_player->resetCommand();
    axis_player->resetCommand();
    ussr_player->resetCommand();

    west_player->resetUnits();
    axis_player->resetUnits();
    ussr_player->resetUnits();

    map.resetBorderLimits();

    west_player->passed = false;
    axis_player->passed = false;
    ussr_player->passed = false;
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
    if (year == 1937)
        return;

    tick_t current_tick = SDL_GetTicks();
    clock = SDL_GetTicks();
    double delta = 0;

    //- Initial draw
    if (animation){
        drawPhase();
        public_messages.push_back(PublicMessage(RESHUFFLE_START, clock,  150, 150, 32, 27));
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
            current_tick = SDL_GetTicks();
            delta = current_tick - clock;

            //ensures framerate of 60fps
            if (delta > 1000/60.0){
                clock = current_tick;  
                //- Player input
                handleUserAnimationInput(running);

                //- Render
                animateReshuffle(running, action_discard.size(), invest_discard.size());
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

    auto setOrder = [&](const CityType first, const CityType second, const CityType third){
        start_player = &players[first];
        turn_order[0] = start_player;
        turn_order[1] = &players[second];
        turn_order[2] = &players[third];
    };

    switch (result){
    case 0: //DEV
    case 1:
        setOrder(AXIS, USSR, WEST);
        break;
    case 2:
        setOrder(AXIS, WEST, USSR);
        break;
    case 3:
        setOrder(WEST, AXIS, USSR);
        break;
    case 4:
        setOrder(WEST, USSR, AXIS);
        break;
    case 5:
        setOrder(USSR, WEST, AXIS);
        break;
    case 6:
        setOrder(USSR, AXIS, WEST);
        break;
    default:
        printf("Uh this dice need to be fixed");
        exit(1);
    }

    if (animation)
        ;//drawTurnRoll(result);
}

void Runner::peaceDividends(){
    bool animates1=false, animates2=false, animates3=false;
    if (peace_dividends_bag.size() == 0) //in game its impossible to runnout of chits so this is for testing
        return;

    //- Check for West
    if (players[WEST].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[WEST].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
        animates1 = true;
    }

    //- Axis
    if (players[AXIS].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[AXIS].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
        animates2 = true;
    }

    //-USSR
    if (players[USSR].getYearAtPeace() == (year)){ //if the year at peace is this year then draw chit
        players[USSR].givePeaceDividend(peace_dividends_bag.back());
        peace_dividends_bag.pop_back();
        animates3 = true;
    }

    (void)(animates1);
    (void)(animates2);
    (void)(animates3);
    //drawPeaceDividends(animates1, animates2, animates3);
}

void Runner::newYearRes(){
    auto usa = map.getCountry("USA");
    if (year >= 1941 && year < 1945){
        usa->influence++;
        usa->resolveDiplomacy(); //? 8.44 Becomes current_tick satellite immediately
        
        if (year != 1941 && usa->influence_level == SATELLITES){ //? 8.54 during 1942 to 1944 USA forces [AF/Fleet/Infantry/Tank] arrive with 1 CV up to 3 CV depending on the year
            const int cv = year-1941;
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_A, AIR, cv, 2, true));
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_N, FLEET, cv, 3, true, true));
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_G, INFANTRY, cv, 2, true));
            map["Washington"]->addUnit(new Unit(USA_U, WEST, CLASS_A, TANK, cv, 3, true));
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

void Runner::resolveDiplomacy(){
    for (auto& country : map.getCountries()){
        country.second->resolveCards();
    }
    mapPlayerResPop(players[WEST]);
    mapPlayerResPop(players[AXIS]);
    mapPlayerResPop(players[USSR]);
}

bool Runner::increaseIndustry(Player& player){
    //- If cannot raise IND (already did twice this year or not enough cost)
    if (!player.canIncreaseIND()){
        return false;
    }

    //- Increase IND
    player.raiseIND();

    //- Remove cards from player hand and add to discard to raise IND

    for (auto& card : player.selected_invest_cards){
        player.remove(card);
        card->selected = false;
        invest_discard.push_back(card);
    }
    player.selected_invest_cards.clear();

    player.updatePoppedInvestCard();

    return true;
}

bool Runner::canPair(const Player& player, const Tech* tech1, const Tech* tech2) const{
    if ((tech1 == nullptr || tech2 == nullptr)){
        return false;
    }

    if (*tech1 >= Y_1938 && *tech2 >= Y_1938 ){ //cannot pair year with year
        return false;
    }
    if (*tech2 >= Y_1938){ //is current_tick year card but in the second spot then flip so code doesn't need to be copy and pasted 
        return canPair(player, tech2, tech1);
    }

    if (ATOMIC_TWO <= *tech1 && *tech1 <= ATOMIC_FOUR && player.getTech(*tech1-1) == nullptr){ //if its atomic but doesn't have the previous atomic level then reject
        return false;
    }   

    if (ATOMIC_TWO <= *tech2 && *tech2 <= ATOMIC_FOUR && player.getTech(*tech2-1) == nullptr){ //if its atomic but doesn't have the previous atomic level then reject
        return false;
    }
    
    if (*tech1 >= Y_1938){ // is current_tick year card then make sure tech2 is in the pairable list
        if (*tech1-Y_1938 + 1938 > year) //todo change back after testing
            return false;
        const auto& pairable_techs = YEAR_TECHS[*tech1 - Y_1938];
        for (const Tech& t : pairable_techs){
            if (*tech2 == t)
                return true;
        }

        return false;
    }

    return *tech1 == *tech2;

}

bool Runner::achieveTechnology(Player&player){
    //- Check that two techs are selected, that they are the same, and player doens't already have the tech
    if (!canPair(player, player.selected_tech1, player.selected_tech2) || player.hasTech((*player.selected_tech1 >= Y_1938)? player.selected_tech2 : player.selected_tech1))
        return false;

    //- If passed all checks then add tech to player hand
    player.achieveTech((*player.selected_tech1 >= Y_1938)? *player.selected_tech2 : *player.selected_tech1);

    //- Remove the two cards
    player.remove(player.selected_tech1_card);
    player.remove(player.selected_tech2_card);
    player.updatePoppedInvestCard();

    return true;
}
