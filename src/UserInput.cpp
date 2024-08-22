#include "Runner.h"

//& User Input

void Runner::handleUserInput(bool& running){
    SDL_Event event;

    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    cout << "Quiting through ESC" << endl;
                    freeMemory();
                    exit(0);
                }
                //TODO delete keys for full release
                else if (event.key.keysym.scancode == SDL_SCANCODE_Y){
                    current_player->popped_action_card = current_player->getActionCard(rand()%current_player->getActionSize());
                    current_player->setCommand(current_player->popped_action_card, (Season)(season-SPRING_COMMAND));
                    current_player->remove(current_player->popped_action_card);
                    current_player->updatePoppedActionCard(map.getCountries());
                    passedCommand(false);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_X){
                    west_player->passed = true;
                    axis_player->passed = true;
                    ussr_player->passed = true;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_A){
                    if (west_player->closest_map_city){
                        const auto& city = (west_player->closest_map_city);
                        const auto& country = map.getCountry(city->country);
                        const string names[4] = {"West", "Axis", "USSR", "Neutral"};
                        cout << names[country->allegiance] << " i:" << country->influence << " " << country->name << "->" << city->name << " o:" << city->occupier_priority[0] << " " <<  city->occupier_priority[1] << " " << city->occupier_priority[2] << " " << city->occupier_priority[3] << " :" << endl;
                        cout << "\tRuler Allegiance: " << names[city->ruler_allegiance] << endl;
                        cout << "\tOccupier Allegiance: " << names[city->occupier_allegiance] << endl;
                        cout << "\tAdjacent: ";
                        for (int i = 0; i < map.getAdjacency().size(); i++){
                            if (map.getBorder(i, west_player->closest_map_city->ID))
                                cout << map.getCity(i)->name << " " << (int)map.getBorderLimit(west_player->closest_map_city, map.getCity(i), WEST) << " | ";
                        }
                        cout << endl << endl;
                    }
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_EQUALS){
                    west_player->cursor_speed++;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_MINUS){
                    west_player->cursor_speed--;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_F){
                    west_player->app->updateScreen();
                    axis_player->app->updateScreen();
                    ussr_player->app->updateScreen();
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_S){
                    west_player->closest_map_city = map.getCity("Madrid");
                    declareVoN(*west_player);
                    auto unit = buildUnit(*west_player, map.getCity("London"), INFANTRY, 4);
                    map.getCity("London")->removeUnit(unit);
                    map.getCity("Madrid")->addUnit(unit);

                    west_player->achieveTech(ROCKET_ARTILLERY);
                    west_player->setTechPublic(ROCKET_ARTILLERY);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_W){
                    auto unit = buildUnit(*axis_player, map.getCity("Berlin"), INFANTRY, 1);
                    map.getCity("Berlin")->removeUnit(unit);
                    map.getCity("Madrid")->addUnit(unit);

                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_E){
                    auto unit = buildUnit(*axis_player, map.getCity("Moscow"), INFANTRY, 1);
                    map.getCity("Moscow")->removeUnit(unit);
                    map.getCity("Madrid")->addUnit(unit);

                }

                break;
            }
            case SDL_CONTROLLERBUTTONDOWN:{
                handleButtonDown(players[event.cbutton.which], event);
                break;
            }
            case SDL_CONTROLLERBUTTONUP:{
                handleButtonUp(players[event.cbutton.which], event);
                break;
            }
            default:
                break;
        }
    }

    for (auto& player : turn_order){
        //- Handle every frame actions
        handleCursorMovement(*player);
        handleTriggerMovement(*player);
        handleWidgetMovement(*player);
        handleJoystickMovement(*player);


        //- Handle periodic actions
        handleTimedJoystick(*player);
        handleHeldButtons(*player);
    }
}

void Runner::handleUserAnimationInput(bool& running){
    SDL_Event event;
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    cout << "Quiting through ESC" << endl;
                    freeMemory();
                    exit(0);
                }
            }
            default:
                break;
        }
    }

    for (auto& player : players){
        //- Handle every frame actions
        handleCursorMovement(player);
        handleTriggerMovement(player);
    }
}

void Runner::handleTitleInput(bool& running){
    SDL_Event event;
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    running = false;
                }
                break;
            }
            case SDL_CONTROLLERBUTTONUP:{
                handleButtonUp(players[event.cbutton.which], event);
                break;
            }
            case SDL_CONTROLLERBUTTONDOWN:{
                handleButtonDown(players[event.cbutton.which], event);
                break;
            }
            default:
                break;
        }
    }

    for (auto& player : players){
        //- Handle every frame actions
        if (!player.passed)
            handleCursorMovement(player);
        handleHeldButtons(player);
    }
}

//&^ Buttons

//&^^ Held Buttons
void Runner::handleHeldButtons(Player& player) {
    constexpr tick_t a_wait_time = 2000;
    constexpr tick_t dow_wait_time = 3500;
    constexpr tick_t x_wait_time = 3500;
    /*constexpr tick_t y_wait_time_short = 1200;
    constexpr tick_t y_wait_time_long = 3000;
    constexpr tick_t y_wait_time_very_long = 4500;*/

    // Pass button actions
    if (player.widget == TECH_HAND && player.tech_view == player.getAllegiance() &&
        player.AHeld(clock, a_wait_time) && player.setTechPublic(*player.popped_tech)) {
        public_messages.push_back(PublicMessage((Message)(WEST_TECH_REVEALED + player.getAllegiance()), SDL_GetTicks(), 150, 197, 32, 14));
        player.a_held_tick = 0;
    }

    if (player.multiHeld(true, true, false, false, clock, dow_wait_time)) {
        if (player.widget == STAT_WIDGET) {
            declareDoW(player, players[player.stat_view]);
        }
        player.x_held_tick = 0;
        player.y_held_tick = 0;
    }

    if (player.XHeld(clock, x_wait_time)) {
        handleXHeld(player);
    }

    if (player.BHeld(clock, 1000)){
        pinCity(player); 
        player.b_held_tick = 0;
    }

    switch (season) {
        case PRODUCTION: {
            if (!player.passed)
                handleProductionSeason(player);
            break;
        }
        case GOVERNMENT: {
            if (!player.passed)
                handleGovernmentSeason(player);
            break;
        }
        case FALL_COMMAND:
        case SUMMER_COMMAND:
        case SPRING_COMMAND: {
            if (!player.passed)
                handleCommandSeason(player);
            break;
        }
        case FALL:
        case SUMMER:
        case SPRING: {
            handleRegularSeason(player);
            break;
        }
        default:
            break;
    }
}

void Runner::handleXHeld(Player& player) {
    //house_target = {width/2-206, height/2-72/2, 412,72}, // 90
    //start_target = {width/2-206, house_target.y-90, 412,72},
    //credits_target = {width/2-206, house_target.y+90, 412,72},
    if (season == TITLE_SCREEN && player.in_start){
        player.passed = !player.passed;
    }

    else if (season == INIT_UNITS){
        if (player.curr_unit_init == player.num_start_units)
            initPass(player);
    }
    else if (season == PRODUCTION && player.getCurrentProduction() >= 0 && current_player == &player){
        applyProduction(player);
        public_messages.push_back(PublicMessage((Message)player.getAllegiance(), clock, 250, 100, 32, 10));
    } 
    
    else if (season == GOVERNMENT && current_player == &player){
        player.passed = true;
        public_messages.push_back(PublicMessage((Message)player.getAllegiance(), clock, 250, 100, 32, 10));
        playerActed();
    } 
    
    else if (season >= SPRING_COMMAND && current_player == &player){
        player.passed = true;
        public_messages.push_back(PublicMessage((Message)player.getAllegiance(), clock, 250, 100, 32, 10));
        passedCommand(true);
    }
    
    else if (season <= WINTER){
        seasonActed(*current_player);
    }
    

    player.x_held_tick = 0;
}

void Runner::handleYHeld(Player& player){
    //happens any season
    if (player.selected_unit.second == nullptr && player.closest_map_city != nullptr && map.getCountry(player.closest_map_city->country)->allegiance == (int)player && map.getCountry(player.closest_map_city->country)->influence_level != SATELLITES){
        map.getCountry(player.closest_map_city->country)->influence--;
        map.getCountry(player.closest_map_city->country)->resolveDiplomacy();

        player.y_held_tick = 0;
    }
}

void Runner::handleProductionSeason(Player& player) {
    constexpr tick_t y_wait_time = 1200;
    auto processReturn = [&](const bool show_hand, const ProductionAction buy_action, int& num_bought) {
        if (num_bought > 0 && show_hand){
            player.spendProduction(buy_action, true);
            num_bought--;
            player.board_change = true;
            player.y_resolved = false;
            player.y_held_tick = clock;
        } 
        else{
            player.y_held_tick = 0;
        }
    };

    switch (player.widget) {
        case ACTION_HAND:{
            if (player.YHeld(clock, y_wait_time)){
                processReturn(player.show_action, BUY_AC, action_bought);
            }
            break;
        }
        case INVEST_HAND:{
            if (player.YHeld(clock, y_wait_time)){
                processReturn(player.show_invest, BUY_IC, invest_bought);
            }
            break;
        }
        default:
            break;
    }
}

void Runner::handleGovernmentSeason(Player& player) {
    constexpr tick_t y_wait_time = 3000;
    constexpr tick_t a_wait_time = 2000;
    
    if (player.YHeld(clock, y_wait_time)) {
        handleCardPlaying(player);
        player.y_held_tick = 0;
    }

    if (player.AHeld(clock, a_wait_time)) {
        if (current_player != &player){
            return;
        }
        
        if (player.show_invest && player == player.invest_view && increaseIndustry(player)) {
            playerActed();
        } 
        
        else if (player.show_action && player.canPeakAction()) {
            performIntel(player, WEST_CARD_PEAKING, &Runner::peakRivalAction);
        }
        
        else if (player.canPeakUnit()){
            performIntel(player, WEST_UNIT_PEAKING, &Runner::peakRivalUnit);
        } 
        
        else if (canCoup(player)){
            performIntel(player, WEST_SABOTAGE, &Runner::coupRival);
        } 
        
        else if (canSabotage(player)){
            performIntel(player, WEST_SABOTAGE, &Runner::sabotageRival);
        } 
        
        else if (canSpyRing(player)){
            performIntel(player, WEST_SABOTAGE, &Runner::spyRingRival);
        }
        player.a_held_tick = 0;
    }
}

void Runner::handleCommandSeason(Player& player) {
    constexpr tick_t y_wait_time = 4500;
    if (player.YHeld(clock, y_wait_time) && current_player == &player) {
        if (player.widget == ACTION_HAND && player.popped_action_card != nullptr) {
            player.setCommand(player.popped_action_card, (Season)(season - SPRING_COMMAND));
            player.remove(player.popped_action_card);
            player.updatePoppedActionCard(map.getCountries());
            passedCommand(false);
        } 
        else if (player.widget == INVEST_HAND && player.popped_invest_card != nullptr) {
            player.setCommand(player.popped_invest_card);
            player.remove(player.popped_invest_card);
            player.updatePoppedInvestCard();
            passedCommand(false);
        }
        player.y_held_tick = 0;
    }
}

void Runner::handleRegularSeason(Player& player) {
    constexpr tick_t y_wait_time = 3000;
    constexpr tick_t a_wait_time = 2000;

    if (player.AHeld(clock, a_wait_time)){
        //for battle actions that only the current player can do
        if (player == current_player){ 
            switch (player.combat_phase){
                case MOVEMENT:
                    moveUnit(player);
                    break;
                default:
                    break;
            }
        }
        //for actions any player can do on their turn
        switch (player.combat_phase){
            case COMBAT_SELECT_RETREAT:
                retreatUnit(player);
                break;
            case COMBAT_FINISHED_FORCED_REBASE:
            case COMBAT_SELECT_REBASE:
                reBaseUnit(player);
                break;
            case COMBAT_DEAL_HITS:
                if (canHitUnit()){
                    hitUnit(current_battle.first, player.popped_hit_unit);
                    //reset player views
                    west_player->popped_unit_index = 0;
                    axis_player->popped_unit_index = 0;
                    ussr_player->popped_unit_index = 0;
                }
                else{
                    //todo error message
                }
                break;
            case COMBAT_SELECT_BATTLE_GROUP:
                finalizeBattleGroup(player);
                break;
            default:
                break;
        }
        
        player.a_held_tick = 0;
    }
    else if (player.YHeld(clock, y_wait_time)){
        if (player.combat_phase == MOVEMENT && player.selected_unit.second != nullptr){
            flipConvoy(player, player.selected_unit.first, player.selected_unit.second);
        }

        player.y_held_tick = 0;
    }
    else if (player.multiHeld(false, true, true, false, clock, y_wait_time)){
        if (player == current_player) {
            if (!declareVoN(player)){ //if couldn't declare VoN check if they are attempting to have an Intervention
                cout << declareIntervention(player);
            }
        }

        player.y_held_tick = 0;
        player.a_held_tick = 0;
    }
}

void Runner::handleCombatActions(Player& player){
}

void Runner::performIntel(Player& player, Message message_type, void (Runner::*espionageAction)(Player&)) {
    invest_discard.push_back(player.popped_invest_card);

    (this->*espionageAction)(player);

    public_messages.push_back(PublicMessage((Message)(message_type + player.getAllegiance()), 250U, 25000U, 64, 32, 128 * player.action_view, true));

    playerActed();
}

//&^^ Button Up
void Runner::handleButtonUp(Player& player, const SDL_Event& event){
    switch (event.cbutton.button){
        case (SDL_CONTROLLER_BUTTON_X):{
            player.x_held_tick = 0;
            break;
        }
        case (SDL_CONTROLLER_BUTTON_A):{
            switch (season){
                case TITLE_SCREEN:{
                    handleControllerSwitch(player);
                    break;
                }
                
                case INIT_UNITS:
                case PRODUCTION:{
                    player.widget = MAP;
                    handleUnitBuilding(player);
                    break; 
                }
                
                case GOVERNMENT:{
                    selectTechCard(player);
                    break;
                }
                
                case SPRING:
                case SUMMER:
                case FALL:{
                    switch (player.combat_phase){
                        case MOVEMENT:{
                            addMovement(player);
                            break;
                        }
                        case COMBAT_SELECT_BATTLE:{
                            handleBattleSelect(player);
                            break;
                        }
                        case COMBAT_SELECT_ACTION:{
                            handleActionSelect(player);
                            break;
                        }
                        case COMBAT_SELECT_CLASS:{
                            handleTypeSelect(player);
                            break;
                        }
                        case COMBAT_SELECT_RETREAT:{
                            selectRetreat(player);
                            break;
                        }
                        case COMBAT_FINISHED_FORCED_REBASE:
                        case COMBAT_SELECT_REBASE:{
                            addReBase(player);
                            break;
                        }
                        case COMBAT_SELECT_REBASE_OPT:{
                            handleOptReBase(player);
                            break;
                        }
                        case COMBAT_SELECT_BATTLE_GROUP:{
                            handleBattleGroupSelect(player);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                
                default:
                    break;
            }     
            player.a_held_tick = 0;
            break;
        }
        
        case (SDL_CONTROLLER_BUTTON_Y):{
            switch (season){
                case (PRODUCTION):{
                    handleCardBuying(player);
                    player.y_resolved = true;
                    break;
                }
                case (GOVERNMENT):{
                    /* code */
                    break;
                }
                default:
                    break;
            }
            player.y_held_tick = 0;
            break;
        }

        case (SDL_CONTROLLER_BUTTON_B):{
            selectCity(player);
            player.b_held_tick = 0;
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            player.d_right_held = false;            
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            player.d_left_held = false;            
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_UP:{
            player.d_up_held = false;
            break;
        }
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
            player.d_down_held = false;
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:{
            toggleView(player);
            player.rt_shoulder_held_tick = 0;
            break;
        }
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:{
            player.lf_shoulder_held_tick = 0;
            break;
        }
        
        default:
            break;
    }
}

void Runner::handleButtonDown(Player& player, const SDL_Event& event){
    //cout << "A button was pressed by player " << player.getAllegiance() << endl;
    switch (event.cbutton.button){
        //-Middle Buttons
        //Quit Game
        case SDL_CONTROLLER_BUTTON_START:{
            cout <<"Start pushed and exiting"<<endl;
            freeMemory();
            exit(0);
        }

        //-Shoulders
        //Toggle view on card widgets
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:{
            player.rt_shoulder_held_tick = clock;
            break;
        }

        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:{
            player.lf_shoulder_held_tick = clock;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            player.d_left_held = true;
            player.last_widget = clock;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            player.d_right_held = true;
            player.last_widget = clock;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
            player.d_down_held = true;
            player.last_widget = clock;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_UP:{
            player.d_up_held = true;
            player.last_widget = clock;
            break;
        }
        
        //-Letter buttons
        case SDL_CONTROLLER_BUTTON_X:{ //Δ
            player.x_held_tick = clock;
            break;
        }

        //Expand city display
        case SDL_CONTROLLER_BUTTON_B:{ //O
            player.b_held_tick = clock;
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_A:{ //X
            player.a_held_tick = clock; 
            break;
        }
    
        case SDL_CONTROLLER_BUTTON_Y:{
            player.y_held_tick = clock;
            break;
        }

    }
}

void Runner::handleBattleSelect(Player& player){
    if (player.passed)
        return;

    if (player.closest_map_city != nullptr){
        /*if (!battles.empty()){
            const auto& target = player.closest_map_city;
            const auto& res = std::find_if(battles.begin(), battles.end(), [&target](const pair<City*, CityType> p1){ return p1.first == target;});
            if (res == battles.end()){ //check that if its already selected if it should be deselected
                battles.erase(res);
                return; 
            }   
        }*/

        if (player.closest_map_city == player.option_select_city && (player.wheel_selection[0] == 0 ||  player.wheel_selection[0] == 2 || player.wheel_selection[0] == 4 || player.wheel_selection[0] == 6)){ //selecting target
            if (!player.unit_available[(int)(player.wheel_selection[0]/2)]) //check that the popped unit is available
                return;

            addBattle(player, (CityType)(int)(player.wheel_selection[0]/2));
            player.option_select_city = nullptr;
        }
        else{
            player.widget = MAP;
            if (player.option_select_city == player.closest_map_city){
                player.option_select_city = nullptr;
                return;
            }
            player.option_select_city = player.closest_map_city;
            
            if (!setDefenders(player)){
                player.option_select_city = nullptr;
            }
        }
    }
}

void Runner::handleActionSelect(Player& player){
    if (!player.show_combat) //make sure no accidental clicks
        return;
        
    const auto& select = player.wheel_selection[0];
    if (select==0 || (select == 7 && player.wheel_x != 0) || select == 1){ // if fire is selected
        player.combat_phase = COMBAT_SELECT_CLASS;
    }

    const auto& acting_troop = fire_order[0];

    if (acting_troop->class_type == CLASS_A){
        if (select==4 || select == 5 || select == 3){
            player.combat_phase = COMBAT_SELECT_REBASE;
            player.moving_units.push_back(acting_troop);
            player.movement_memo.push_back(current_battle.first);
        }
    }

    else if (isANS(acting_troop->class_type)){
        if (select == 5){ //retreat
            player.combat_phase = COMBAT_SELECT_RETREAT;
            player.moving_units.push_back(acting_troop);
            player.movement_memo.push_back(current_battle.first);
            player.movement_memo.push_back(nullptr);
        }
        else if (select == 3){ //rebase
            player.combat_phase = COMBAT_SELECT_REBASE;
            player.moving_units.push_back(acting_troop);
            player.movement_memo.push_back(current_battle.first);
        }
    }

    else{
        if (select==4 || select == 5 || select == 3){ //if retreat is selcted
            player.combat_phase = COMBAT_SELECT_RETREAT;
            player.moving_units.push_back(acting_troop);
            player.movement_memo.push_back(current_battle.first);
            player.movement_memo.push_back(nullptr);
        }
    }
}

void Runner::handleOptReBase(Player& player){
    if (!player.show_combat) //make sure no accidental clicks
        return;
        
    const auto& select = player.wheel_selection[0];
    if (select==0 || (select == 7 && player.wheel_x != 0) || select == 1){ // if rebase is selected
        player.combat_phase = COMBAT_SELECT_REBASE;
        player.moving_units.push_back(fire_order[0]);
        player.movement_memo.push_back(current_battle.first);
    }


    else if (select==4 || select == 5 || select == 3){ //if rebase in not selected
       fire_order[0]->rebase = true;
       handleUnitActionEnd();
    }
}

void Runner::handleTypeSelect(Player& player){
    if (!player.show_combat) //make sure no accidental clicks
        return;

    const auto& select = player.wheel_selection[0];
    const UnitClass u_class = (UnitClass)((int)select/2);
    if ((int)select%2 == 0 && player.unit_available[u_class]){
        public_animations.push_back(PublicAnimation((SeasonAnimation)(WEST_DICE+acting_player), -48, -190, 512, 288+acting_player*32, 32, 32, 3, clock, 100));
        public_animations.back().addPhase(AnimationPhase::RANDOM, 5000);
        (public_animations.back()).setRandom(6);
        public_animations.back().setFinishCallback([this]() { decideDice(); });

        players[acting_player].combat_phase = OBSERVING;
        players[watching_player].combat_phase = OBSERVING;

        target_class = u_class;
    }
}

void Runner::handleBattleGroupSelect(Player& player){
    const auto& hit_unit = players[(int)player].popped_hit_unit;
    hit_unit->battle_group = !hit_unit->battle_group;
}

void Runner::handleUnitBuilding(Player& player){
    //- Check that if they passed they can't do any more
    if (player.passed)
        return;

    if (player.selected_unit.first != nullptr && ABLE == canUpgrade(player,  player.selected_unit.first,  player.selected_unit.second->nationality,  player.selected_unit.second)){
        //if the unit has a 0 combat value (shows as upgrading to one) is a cadre and unupgrading would be deleting it
        if (player.selected_unit.second->combat_value != 0)
            player.spendProduction(UNIT_UP, !(player.selected_unit.second->upgrading = !player.selected_unit.second->upgrading));

        else{ //removing cadres
            if (player.getAllegiance() == player.selected_unit.first->ruler_allegiance){
                player.selected_unit.first->removeUnit(player.selected_unit.second);
                player.remove(player.selected_unit.second);
                player.curr_unit_init--;
                //need to recheck if counts were redone
                if (player.option_select_city != nullptr)
                    setBuildable(player);
                player.spendProduction(CADRE, true);
                player.selected_unit = {nullptr, nullptr};
            }
        }
        player.board_change = true;
    }
    else if (player.closest_map_city != nullptr){ //adding a new unit
        if (player.closest_map_city == player.option_select_city){ //adding unit
            if (player.wheel_selection[0] != 7 && player.unit_available[(int)player.wheel_selection[0]]){ //cancel
                buildCadre(player, player.option_select_city, (UnitType)player.wheel_selection[0]);
                player.curr_unit_init++;
                player.spendProduction(CADRE);
            }
            player.option_select_city = nullptr;
        }
        else{
            player.option_select_city = player.closest_map_city;
            if (!setBuildable(player)){
                player.option_select_city = nullptr;
            }
        }
        player.board_change = true;
    }
}

void Runner::handleCardBuying(Player& player){
    if (player.passed && !player.y_resolved) //used player.y_resolved to prvent the player from holding y and then when the button is up having it add the card back 
        return;

    // lambda function
    auto processPurchase = [&](bool (Runner::*canBuy)() const, ProductionAction buy_action, int& num_bought){
        if (player.y_resolved && (this->*canBuy)()) {
            player.spendProduction(buy_action, false);
            num_bought++;
            player.board_change = true;
        }
    };

    switch (player.widget){
        case ACTION_HAND:{
            processPurchase(&Runner::canBuyAction, BUY_AC, action_bought);
            break;
        }
        case INVEST_HAND:{
            processPurchase(&Runner::canBuyInvest, BUY_IC, invest_bought);
            break;
        }
        default:
            break;
    }
}

void Runner::handleCardPlaying(Player& player){
    //- Card playing can only happen on the curreny player's turn
    if (player != current_player){
        return;
    }

    switch (player.widget){
        //? 7.32 Industry (several cards) The Active Player can play Investment cards with Factory values totalling at least his current Factory Cost (sidebar) to raise his IND level by one (immediately adjust marker on Production track). 
        //? Important: IND cannot be raised more than twice per Year.
        case (ACTION_HAND):{ //- If action hand then playing diplomacy
            if (canWildAction(player) || addDiplomacy(player, player.selected_country)){
                cout << "played the card" << endl;
                playerActed();
            }
            else{
                cout << "failed to play card" << endl;
            }
            break;
        }
        case (INVEST_HAND):{ 
            if (player == player.invest_view && achieveTechnology(player))
                playerActed();

            break;
        }
        case (TECH_HAND):{
            break;
        }
        default:
            break;
    }


}

void Runner::handleControllerSwitch(Player& player){
    const auto& height = player.app->screen.HEIGHT;
    const auto& cursor_x = player.cursor_x;
    const auto& cursor_y = player.cursor_y;
    /*west_target = {22, height-21-176, 176, 176},
    axis_target = {226, height-21-176, 176, 176},
    ussr_target = {430, height-21-176, 176, 176};*/
    cout << controllers[0] << "|" << controllers[1] << "|" << controllers[2] << " to ";
    if (inBox(22, height-21-176, 176, 176, cursor_x, cursor_y) && player != west_player){
        auto& controller1 = controllers[WEST];
        auto& controller2 = controllers[(int)player];

        SDL_GameControllerClose(controller1);
        SDL_GameControllerClose(controller2);

        controller2 = SDL_GameControllerOpen(WEST);
        controller1 = SDL_GameControllerOpen((int)player);
        cout << "swapped 0" << endl;
    }
    else if (inBox(226, height-21-176, 176, 176, cursor_x, cursor_y) && player != axis_player){
        auto& controller1 = controllers[AXIS];
        auto& controller2 = controllers[(int)player];

        SDL_GameControllerClose(controller1);
        SDL_GameControllerClose(controller2);

        controller2 = SDL_GameControllerOpen(AXIS);
        controller1 = SDL_GameControllerOpen((int)player);
    }

    else if(inBox(430, height-21-176, 176, 176, cursor_x, cursor_y) && player != ussr_player){
        auto& controller1 = controllers[USSR];
        auto& controller2 = controllers[(int)player];

        SDL_GameControllerClose(controller1);
        SDL_GameControllerClose(controller2);
    
        controller2 = SDL_GameControllerOpen(USSR);
        controller1 = SDL_GameControllerOpen((int)player);
    }
    cout << controllers[0] << "|" << controllers[1] << "|" << controllers[2] << endl;

}

//&^ Joystick moving

void Runner::handleCursorMovement(Player& player){
    //- Left stick movement for cursor movement
    const auto& allegiance = player.getAllegiance();
    int x_move = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_LEFTX);
    int y_move = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_LEFTY);

    bool x_moving=pastDeadZone(x_move), y_moving=pastDeadZone(y_move);

    if (x_moving || y_moving){
        if (x_moving){
            clampCursorX(player, player.cursor_speed * scaleAxis(x_move));
            player.cursor_x = SDL_clamp(player.cursor_x, -16, powers_app[allegiance].screen.WIDTH - 16);
        }
        if (y_moving){
            clampCursorY(player, player.cursor_speed * scaleAxis(y_move));
            player.cursor_y = SDL_clamp(player.cursor_y, -16, powers_app[allegiance].screen.HEIGHT - 16);
        }
        player.selected_unit = {nullptr, nullptr};
        player.board_change = true;
    } 
    else{ //if there is no movement
        player.closest_map_city = getClosestCity(player, player.cursor_x, player.cursor_y);
        player.board_change = true;
    }
}

void Runner::handleUnitSelection(Player& player, const bool move_x, const bool move_y){
    const auto& allegiance = player.getAllegiance();
    const int& num_units = current_battle.first->occupants[allegiance].size()-1;
    const int y_movement = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTY);
    const int x_movement = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTX);
    int& curr_unit = player.popped_hit_index;

    auto checkMove = [&](const int& movement, tick_t& held_tick, const bool vertical){
        curr_unit = loopVal(curr_unit+(movement<0? -1 : 1)*(vertical? 4: 1), 0, num_units);
    };

    if (move_y && pastDeadZone(y_movement))
        checkMove(y_movement, player.right_stick_y_tick, true);
    if (move_x && pastDeadZone(x_movement))
        checkMove(x_movement, player.right_stick_x_tick, false);

    if (move_x || move_y)
        player.popped_hit_unit = current_battle.first->occupants[(int)player][curr_unit];

    /*if ((pastDeadZone(x_move) && pastWait(player.right_stick_x_tick, clock, 1000))){ // || 
        player.right_stick_x_tick = clock;
        
        

        curr_unit = loopVal(curr_unit+(x_move<0? -1 : 1), 0, num_units-1);
    }

    if ((pastDeadZone(y_move) && pastWait(player.right_stick_y_tick, clock, 1000))){
        player.right_stick_y_tick = clock;

    }*/
}

void Runner::handleJoystickMovement(Player& player){
    const auto& allegiance = player.getAllegiance();
    if ((player.widget == MAP && player.option_select_city != nullptr) || (player.widget == COMBAT_WIDGET && player.combat_phase != OBSERVING)){ //if there is a city where there is going to be something built then use the right joy stick to select
        const int& x_move = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTX);
        const int& y_move = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTY);

        if (pastDeadZone(x_move) || pastDeadZone(y_move)){ //if there is movement then move the line cursor
            //- Need to get the angle 
            const double R = sqrt(x_move * x_move + y_move * y_move); //* https://stackoverflow.com/questions/8721511/how-do-i-get-the-angle-from-a-joystick?rq=4
            player.wheel_x = x_move/R;
            player.wheel_y = y_move/R;
            player.board_change = true;
            const double angle = atan2(scaleAxis(y_move), scaleAxis(x_move))*57;
            //- Need to find which unit is closest to the cursor (on unit circle) out of the 8 options
            int min_dist = INT32_MAX;
            for (int i = 0; i < 8; i++){ //BUG 6 and 7 option overlap since unit circle loops from 360 to 0
                const int pot = (UNIT_CIRCLE_RADIANS[i][0] - angle)*(UNIT_CIRCLE_RADIANS[i][0] - angle);
                if (pot < min_dist){
                    min_dist = pot;
                    player.wheel_selection[0] = i;
                    player.wheel_selection[1] = UNIT_CIRCLE_RADIANS[i][1]; 
                    player.wheel_selection[2] = UNIT_CIRCLE_RADIANS[i][2];
                }
            }
        }

        else{
            player.wheel_selection[0] = 7;
            player.wheel_x = 0;
            player.wheel_y = 0;
        }
    }
}

void Runner::handleTimedJoystick(Player& player){
    //- Right stick movement is for actions when you need to select something but don't want the selection whizzing past
    constexpr tick_t y_joy_wait_time = 100;
    constexpr tick_t x_joy_wait_time = 150;

    bool move_y = clock - player.right_stick_y_tick > y_joy_wait_time;
    bool move_x = clock - player.right_stick_x_tick > x_joy_wait_time;

    if (move_y){ //if the delta time is less than 100 ms then skip right joystick movement
        player.right_stick_y_tick = clock;
    }
    if (move_x){
        player.right_stick_x_tick = clock;
    }
    
    switch (player.widget){
        case ACTION_HAND:{
            if (player.show_action) {
                handleActionHandMovement(player, move_x, move_y);
            }
            break;
        }
        case INVEST_HAND:{
            if (player.show_invest){
                handleInvestHandMovement(player, move_x, move_y);
            }
            break;
        }
        case TECH_HAND:{
            if (player.show_tech){
                handleTechMovement(player, move_y);
            }
            break;
        }
        case COMBAT_WIDGET:{
            if (player.show_combat && (player.combat_phase == COMBAT_DEAL_HITS || player.combat_phase == COMBAT_SELECT_BATTLE_GROUP)){
                handleUnitSelection(player, move_x, move_y);
            }
            break;
        }
        default:
            break;
    }
}

void Runner::handleActionHandMovement(Player& player, const bool move_x,  const bool move_y){
    //- Collect movement of the right joy stick
    const auto& allegiance = player.getAllegiance();
    int y_movement = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTY);
    int x_movement = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTX);

    auto changeLook = [&](Country* new_country, const bool left_change, const bool right_change){
        player.selected_country = new_country;
        player.show_left_country = left_change;
        player.show_right_country = right_change;
    };

    //- Change cards
    if (move_y && pastDeadZone(y_movement)){
        constexpr int max_card_view = 15;


        if (players[player.action_view].getActionSize() == 0)
            return;

        auto& result = player.popped_action_card_index;
        result += y_movement > 0 ? 1 : -1;

        if (result < 0){
            result = 0;
        } 
        else if (result >= players[player.action_view].getActionSize()) {
            result = players[player.action_view].getActionSize() - 1;
        }

        if ((result - player.action_card_start) >= max_card_view){
            player.action_card_start++;
        }
        else if (result < player.action_card_start){
            player.action_card_start--;
        }

            
        //player.popped_action_card_index = loopVal(player.popped_action_card_index+(y_movement > 0? 1 : -1), 0 , players[player.action_view].getActionSize()-1);
        
        changeLook(nullptr, true, true);

        if (player == player.action_view){
            player.popped_action_card = player.getActionCard(player.popped_action_card_index);

            //- Set new cities to be highlighted
            if (player.popped_action_card->type == DIPLOMACY){
                player.popped_left_country = map.getCapital(player.popped_action_card->countryA);
                player.popped_right_country = map.getCapital(player.popped_action_card->countryB);
            }
        }
    }

    //- Change selected cities
    if (move_x && player.popped_action_card != nullptr && player == player.action_view && player.popped_action_card->type == DIPLOMACY && pastDeadZone(x_movement)){ //change from viewing both countries to just one side
        //4 cases: middle to right, middle to left, right to middle, left to middle
        if (player.show_left_country && player.show_right_country){ //middle
            if (x_movement > 0){ //positive move means look at right country
                changeLook(map.getCountry(player.popped_action_card->countryB), false, true);
            }
            else{ //negative means look at left
                changeLook(map.getCountry(player.popped_action_card->countryA), true, false);
            }
        }
        //moving from sides to middle
        else if (player.show_left_country && !player.show_right_country && x_movement > 0){ //left
            changeLook(nullptr, true, true);
        }
        else if (!player.show_left_country && player.show_right_country && x_movement < 0){ //right
            changeLook(nullptr, true, true);
        }
    }
}

void Runner::handleInvestHandMovement(Player& player, const bool move_x,  const bool move_y){
    //- Collect movement of the right joy stick
    const auto& allegiance = player.getAllegiance();
    int y_movement = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTY);
    int x_movement = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_RIGHTX);

    //- Change selected card
    if (move_y && pastDeadZone(y_movement)){
        constexpr int max_card_view = 15;

        if (players[player.action_view].getInvestSize() == 0)
            return;

        auto& result = player.popped_invest_card_index;
        result += y_movement > 0 ? 1 : -1;

        if (result < 0){
            result = 0;
        } 
        else if (result >= players[player.invest_view].getInvestSize()) {
            result = players[player.invest_view].getInvestSize() - 1;
        }

        if ((result - player.invest_card_start) >= max_card_view){
            player.invest_card_start++;
        }
        else if (result < player.invest_card_start){
            player.invest_card_start--;
        }
        
        if (player == player.invest_view)
            player.popped_invest_card = player.getInvestCard(player.popped_invest_card_index);
    }

    //- Change selected tech
    if (player == player.invest_view && move_x && player.popped_invest_card != nullptr && pastDeadZone(x_movement)){
        Tech* card_selected_tech = nullptr;

        if (player.popped_invest_card->type == TECHNOLOGY){
            card_selected_tech = (x_movement < 0) ? &player.popped_invest_card->tech1 : &player.popped_invest_card->tech2;
        } 
        else if (player.popped_invest_card->type == YEAR && x_movement < 0){
            card_selected_tech = &player.popped_invest_card->tech1;
        }

        if (card_selected_tech != nullptr){
            if (player.tech_select_flip && card_selected_tech != player.selected_tech2){
                player.selected_tech1 = card_selected_tech;
                player.selected_tech1_card = player.popped_invest_card;
                player.tech_select_flip = (season == GOVERNMENT)? false : true; //only in government phase can you select two techs
            }
            else if (!player.tech_select_flip && card_selected_tech != player.selected_tech1){
                player.selected_tech2 = card_selected_tech;
                player.selected_tech2_card = player.popped_invest_card;
                player.tech_select_flip = true;
            }
        }

        //- if intelligence then player NEEDS to select somthing to finish the action
        if (player.popped_invest_card->type == INTELLIGENCE){
            player.selected_tech1 = &player.popped_invest_card->tech1;
            player.selected_tech2 = nullptr;
        }
    }
}

void Runner::handleTechMovement(Player& player, const bool move_y){
    int y_movement = SDL_GameControllerGetAxis(controllers[(int)player], SDL_CONTROLLER_AXIS_RIGHTY);

    if (move_y && pastDeadZone(y_movement)){
        if (players[player.tech_view].getTechSize() > 0)
            player.popped_tech_index = loopVal(player.popped_tech_index + (y_movement < 0 ? 1 : -1), 0, players[player.tech_view].getTechSize() - 1);
        //player.popped_tech = &player.getTech(player.popped_invest_card_index)->tech;
    }
}

//&^ Triggers

void Runner::handleTriggerMovement(Player& player){
    const auto& allegiance = player.getAllegiance();
    bool zooming_out = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_TRIGGERLEFT);
    bool zooming_in = SDL_GameControllerGetAxis(controllers[allegiance], SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
    
    if (zooming_out && !zooming_in) {
        player.app->screen.zoom_factor = SDL_clamp(player.app->screen.zoom_factor+0.1, 1.00, 3.00);
    }
    if (zooming_in && !zooming_out){
        player.app->screen.zoom_factor = SDL_clamp(player.app->screen.zoom_factor-0.1, 1.00, 3.00);
    }
    if (zooming_in || zooming_out){
        player.zoom = (int)player.app->screen.zoom_factor;
        player.board_change = true;

        if (player.app->screen.zoom_factor == 1.0){
            player.app->screen.zoom_x = 0;
            player.app->screen.zoom_y = 0;
        }
    }
}

void Runner::handleWidgetMovement(Player& player){

    auto scroll = [&](int& widet_view, int& view_index, const int incriment){
        widet_view = loopVal(widet_view+incriment, WEST, USSR);
        view_index = -1;
    };

    if (pastWait(player.last_widget, clock, 150)){ //only take inputs every 100 clock
        player.last_widget = clock;
    
        if ((player.d_left_held && player.d_right_held)){ //holding both down so ignore any changes
            player.d_left_held = false; player.d_right_held=false;
            return;
        }

        if(player.d_left_held){ //move left one button
            player.widget = WIDGET_ADJACENCY[player.widget][2]; //up0 down1 left2 right3
        }

        else if (player.d_right_held){ //move right one button
            player.widget = WIDGET_ADJACENCY[player.widget][3];
        }

        else if (player.d_down_held || player.d_up_held){ //changing what widget is being looked at
            switch (player.widget){
                case TECH_HAND:
                    scroll(player.tech_view, player.popped_tech_index, player.d_up_held? -1 : 1);
                    player.popped_tech = nullptr;
                    break;
                case ACTION_HAND:
                    scroll(player.action_view, player.popped_action_card_index, player.d_up_held? -1 : 1);
                    player.popped_action_card = nullptr;
                    break;
                case INVEST_HAND:
                    scroll(player.invest_view, player.popped_invest_card_index, player.d_up_held? -1 : 1);
                    player.popped_invest_card = nullptr;
                    break;  
                case STAT_WIDGET:
                    int i;
                    scroll(player.stat_view, i, player.d_up_held? -1 : 1);
                    break;
                case COMBAT_WIDGET:
                    player.popped_unit_index = SDL_clamp(player.popped_unit_index+(player.d_up_held? -1 : 1), 0, fire_order.size()-1);
                    break;
                default:
                    break;
            }
        }

        if (player.widget == MAP && current_battle.first){
            player.widget = COMBAT_WIDGET;
        }
    }
    //cout <<  player.widget << endl;
}

//&^ Helpers

void Runner::clampCursorX(Player& player, const double amount){
    //- If the current cursor x minus the amount would stretch the image (i.e the clip would go negative) then move cursor
    double& cursor_x = player.cursor_x;
    if (player.app->screen.zoom_x + amount < 0){
        cursor_x += amount;
    }
    //- If the current cursor x minus the amount would have the image bound out (i.e the clip is greater than the width) then move cursor
    else if (player.app->screen.zoom_x + amount >= (player.app->screen.WIDTH-(int)(player.app->screen.WIDTH/player.app->screen.zoom_factor))){
        cursor_x += amount;
    }
    //- Let cursor move half out before shifting screen
    else if (cursor_x < player.app->screen.WIDTH/2.10&& amount > 0)
        cursor_x += amount;
    else if (cursor_x > player.app->screen.WIDTH/1.90 && amount < 0)
        cursor_x += amount;
    
    //- All else then move the map sprite clip
    else{
        player.app->screen.zoom_x += amount;
    }
}

void Runner::clampCursorY(Player& player, const double amount){
    //- If the current cursor y minus the amount would stretch the image (i.e the clip would go negative) then move cursor
    double& cursor_y = player.cursor_y;
    if (player.app->screen.zoom_y + amount < 0){
        cursor_y += amount;
    }
    //- If the current cursor y plus the amount would have the image bound out (i.e the clip is greater than the height) then move cursor instead
    else if (player.app->screen.zoom_y + amount >= (player.app->screen.HEIGHT-(int)(player.app->screen.HEIGHT/player.app->screen.zoom_factor))){ //-(int)(982/player.app->screen.zoom_factor)
        cursor_y += amount;
    }
    //- Let cursor move half out before shifting screen
    else if (cursor_y < player.app->screen.HEIGHT/2.10&& amount > 0)
        cursor_y += amount;
    else if (cursor_y > player.app->screen.HEIGHT/1.90&& amount < 0)
        cursor_y += amount;
    
    //- All else then move the map sprite clip
    else{
        player.app->screen.zoom_y += amount;
    }
}