#include "Runner.h"

//& User Input

void Runner::handleUserInput(bool& running, const tick_t& delta){
    SDL_Event event;
    const tick_t ticks = SDL_GetTicks();
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    cout << "Quiting through ESC" << endl;
                    freeMemory();
                    exit(0);
                }
                //TODO delete keys for full release
                else if (event.key.keysym.scancode == SDL_SCANCODE_S){
                    public_messages.push_back(PublicMessage((Message)current_player->getAllegiance(), ticks, 250, 100, 32, 10));
                    applyProduction(*current_player);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_C){
                    std::swap(players[WEST], players[USSR]);
                    std::swap(controllers[WEST], controllers[USSR]);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_D){
                    std::swap(players[WEST], players[AXIS]);
                    std::swap(controllers[WEST], controllers[AXIS]);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_F){
                    playerActed();
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_R){
                    resolveDiplomacy();
                }
                break;
            }
            case SDL_CONTROLLERBUTTONDOWN:{
                handleButtonDown(players[event.cbutton.which], event, ticks);
                break;
            }
            case SDL_CONTROLLERBUTTONUP:{
                handleButtonUp(players[event.cbutton.which], event, ticks);
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
        handleWidgetMovement(*player, ticks);
        handleJoystickMovement(*player);


        //- Handle periodic actions
        handleTimedJoystick(*player, ticks);
        handleHeldButtons(*player, ticks);
    }
}

void Runner::handleUserAnimationInput(bool& running, const tick_t& delta){
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

//&^ Buttons

void Runner::handleHeldButtons(Player& player, const tick_t& ticks){
    //pass button

    //! Actions that can happen any time
    constexpr unsigned int a_wait_time = 2000;
    if (player.widget == TECH_HAND && player.tech_view == player.getAllegiance() && pastWait(player.a_held_tick, ticks, a_wait_time) && player.setTechPublic(*player.popped_tech)){
        public_messages.push_back(PublicMessage((Message)(WEST_TECH_REVEALED+player.getAllegiance()), SDL_GetTicks(), 150, 197, 32, 14));
        player.a_held_tick = 0;
    }

    constexpr unsigned int x_wait_time = 3500;
    if (pastWait(player.x_held_tick, ticks, x_wait_time)){
        if (season == PRODUCTION && player.getCurrentProduction() >= 0 && current_player == &player){
            //- Make the changes from the production
            applyProduction(player);

            //- Add the message to be seen by all that the player passed
            public_messages.push_back(PublicMessage((Message)player.getAllegiance(), ticks, 250, 100, 32, 10));
        }
        else if (season == GOVERNMENT && current_player == &player){ //- if the player whose turn it is is passing
            //- Set to passed (government changes are applied at the end)
            player.passed = true;
            
            //- Add the message to be seen by all that the player passed
            public_messages.push_back(PublicMessage((Message)player.getAllegiance(), ticks, 250, 100, 32, 10));
            playerActed();
        }
        player.x_held_tick = 0;
    }
    
    if (player.passed){
        return;
    }

    // lambda function
    auto processReturn = [&](const bool show_hand, const ProductionAction buy_action, int& num_bought){
        if (num_bought > 0 && show_hand) {
            player.spendProduction(buy_action, true);
            num_bought--;
            player.board_change = true;
            player.y_resolved = false;
            player.y_held_tick = ticks;
        }
        else{
            player.y_held_tick = 0;
        }
    };

    switch (season){
        case (PRODUCTION):{
            switch (player.widget){
                case ACTION_HAND:{
                    constexpr unsigned int y_wait_time = 1200;
                    if (pastWait(player.y_held_tick, ticks, y_wait_time)){
                        processReturn(player.show_action, BUY_AC, action_bought);
                    }
                    break;
                }
                case INVEST_HAND:{
                    constexpr unsigned int y_wait_time = 1200;
                    if (pastWait(player.y_held_tick, ticks, y_wait_time)){
                        processReturn(player.show_invest, BUY_IC, invest_bought);
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case (GOVERNMENT):{
            //Y is for moving things from your hand to the board
            constexpr unsigned int y_wait_time = 3000;
            if (pastWait(player.y_held_tick, ticks, y_wait_time)){
                handleCardPlaying(player);
                player.y_held_tick = 0;
            }

            //A if for changing things in your hands
            constexpr unsigned int a_wait_time = 2500;
            if (pastWait(player.a_held_tick, ticks, a_wait_time)){
                if (player.show_invest && player == player.invest_view && increaseIndustry(player)){
                    playerActed();
                }

                //! Espionage actions !//
                else if (player.show_action && player.canPeakAction()){
                    invest_discard.push_back(player.popped_invest_card); //discard card
                    player.peakAction(ticks); //set player able to peak and remove card
                    public_messages.push_back(PublicMessage(
                        (Message)(WEST_CARD_PEAKING+player.getAllegiance()), ticks, 250U, 25000U, 64, 32, 128*player.action_view, true)
                    );
                    playerActed();
                }

                else if (player.canPeakUnit()){
                    invest_discard.push_back(player.popped_invest_card);
                    player.peakUnit(ticks);
                    public_messages.push_back(PublicMessage(
                        (Message)(WEST_UNIT_PEAKING+player.getAllegiance()), ticks, 250U, 15000U, 64, 32, 128*player.peaked_unit.second->allegiance, true)
                    );
                    playerActed();

                }

                else if (canCoup(player)){
                    invest_discard.push_back(player.popped_invest_card);
                    coup(player);
                    playerActed();
                }

                else if (canSabotage(player)){
                    invest_discard.push_back(player.popped_invest_card);
                    sabotage(player);
                    public_messages.push_back(PublicMessage(
                        (Message)(WEST_SABOTAGE+player.getAllegiance()), ticks, 250U, 7500U, 32, 32, 64*player.stat_view, false)
                    );
                    playerActed();
                }

                else if (canSpyRing(player)){
                    invest_discard.push_back(player.popped_invest_card);
                    spyRing(player);
                    playerActed();
                }

                player.a_held_tick = 0;
            }
            break;
        }
        default:
            break;
    }
}

void Runner::handleButtonUp(Player& player, const SDL_Event& event, const tick_t& ticks){
    switch (event.cbutton.button){
        case (SDL_CONTROLLER_BUTTON_X):{
            player.x_held_tick = 0;
            break;
        }
        case (SDL_CONTROLLER_BUTTON_A):{
            switch (season){
                case GOVERNMENT:
                    if (player.widget == INVEST_HAND && player == player.invest_view && player.popped_invest_card != nullptr && player.a_held_tick != 0){
                        if (!player.hasSelected(player.popped_invest_card)){
                            player.selected_invest_cards.push_back(player.popped_invest_card);
                        }
                        else{
                            player.deselect(player.popped_invest_card);
                        }
                    }
                    else if (player.widget == SELECT_CITY){

                    }
                    break;
                
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
        default:
            break;
    }
}

void Runner::handleButtonDown(Player& player, const SDL_Event& event, const tick_t& ticks){
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
            if (player.widget <= STAT_WIDGET){
                switch (player.widget){
                    case ACTION_HAND:
                        player.show_action = !player.show_action;
                        player.popped_action_card_index = -1;
                        break;
                    case INVEST_HAND:
                        player.show_invest = !player.show_invest;
                        player.popped_invest_card_index = -1;
                        break;
                    case TECH_HAND:
                        player.show_tech = !player.show_tech;
                        player.popped_tech_index = -1;
                        break;
                    case STAT_WIDGET:
                        player.show_stat = !player.show_stat;
                        break;
                    
                    default:
                        break;
                }
                player.board_change = true;
            }
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            player.d_left_held = true;
            player.last_widget = ticks;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            player.d_right_held = true;
            player.last_widget = ticks;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
            player.d_down_held = true;
            player.last_widget = ticks;
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_UP:{
            player.d_up_held = true;
            player.last_widget = ticks;
            break;
        }
        
        //-Letter buttons
        case SDL_CONTROLLER_BUTTON_X:{ //Δ
            player.x_held_tick = ticks;
            break;
        }

        //Expand city display
        case SDL_CONTROLLER_BUTTON_B:{ //O
            if (player.closest_map_city != nullptr){
                player.closest_map_city->full_display[player.getAllegiance()] = ! player.closest_map_city->full_display[player.getAllegiance()];
                player.widget = MAP;
            }
            break;
        }
        // Upgrading unit Unit
        case SDL_CONTROLLER_BUTTON_A:{ //X
            player.a_held_tick = ticks; 
            if (season == PRODUCTION){
                player.widget = MAP;
                handleUnitBuilding(player);
            }
            break;
        }
    
        case SDL_CONTROLLER_BUTTON_Y:{
            player.y_held_tick = ticks;
        }
    }
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
            if (player.getAllegiance() == player.selected_unit.first->ruler_type){
                player.selected_unit.first->removeUnit(player.selected_unit.second);
                player.remove(player.selected_unit.second);
                //need to recheck if counts were redone
                if (player.building_city != nullptr)
                    setBuildable(player);
                player.spendProduction(CADRE, true);
                delete player.selected_unit.second;
                player.selected_unit = {nullptr, nullptr};
            }
        }
        player.board_change = true;
    }
    else if (player.closest_map_city != nullptr){
        if (player.closest_map_city == player.building_city){ //adding unit
            if (player.popped_unit[0] != 7 && player.unit_buildable[(int)player.popped_unit[0]]){ //cancel
                buildUnit(player, player.building_city, (UnitType)player.popped_unit[0]);
                player.spendProduction(CADRE);
            }
            player.building_city = nullptr;
        }
        else{
            player.building_city = player.closest_map_city;
            setBuildable(player);
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
    if (&player != current_player){
        return;
    }

    switch (player.widget){
        //? 7.32 Industry (several cards) The Active Player can play Investment cards with Factory values totalling at least his current Factory Cost (sidebar) to raise his IND level by one (immediately adjust marker on Production track). 
        //? Important: IND cannot be raised more than twice per Year.
        case (ACTION_HAND):{ //- If action hand then playing diplomacy
            if (addDiplomacy(player, player.selected_country))
                playerActed();

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

//&^ Joystick moving

void Runner::handleCursorMovement(Player& player){
    //- Left stick movement for cursor movement
    int x_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_LEFTX);
    int y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_LEFTY);

    bool x_moving=pastDeadZone(x_move), y_moving=pastDeadZone(y_move);

    if (x_moving || y_moving){
        if (x_moving){
            clampCursorX(player, 5 * scaleAxis(x_move));
            player.cursor_x = SDL_clamp(player.cursor_x, -16, powers_app[player.getAllegiance()].screen.WIDTH - 16);
        }
        if (y_moving){
            clampCursorY(player, 5 * scaleAxis(y_move));
            player.cursor_y = SDL_clamp(player.cursor_y, -16, powers_app[player.getAllegiance()].screen.HEIGHT - 16);
        }
        player.selected_unit = {nullptr, nullptr};
        player.board_change = true;
    } 
    else{ //if there is no movement
        player.closest_map_city = getClosestCity(player, player.cursor_x, player.cursor_y);
        player.board_change = true;
    }
}

void Runner::handleJoystickMovement(Player& player){
    if (player.widget == MAP && player.building_city != nullptr){ //if there is a city where there is going to be something built then use the right joy stick to select
        int x_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTX);
        int y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);

        if (pastDeadZone(x_move) || pastDeadZone(y_move)){ //if there is movement then move the line cursor
            //- Need to get the angle 
            const double R = sqrt(x_move * x_move + y_move * y_move); //* https://stackoverflow.com/questions/8721511/how-do-i-get-the-angle-from-a-joystick?rq=4
            player.wheel_x = x_move/R;
            player.wheel_y = y_move/R;
            player.board_change = true;
            const double angle = atan2(scaleAxis(y_move), scaleAxis(x_move))*57;
            //- Need to find which unit is closest to the cursor (on unit circle) out of the 8 options
            int min_dist = INT32_MAX;
            for (int i = 0; i < 8; i++){
                const int pot = (UNIT_CIRCLE_RADIANS[i][0] - angle)*(UNIT_CIRCLE_RADIANS[i][0] - angle);
                if (pot < min_dist){
                    min_dist = pot;
                    player.popped_unit[0] = i;
                    player.popped_unit[1] = UNIT_CIRCLE_RADIANS[i][1]; 
                    player.popped_unit[2] = UNIT_CIRCLE_RADIANS[i][2];
                }
            }
            //- Snap it to the closest

        }
        else{
            player.popped_unit[0] = 7;
            player.wheel_x = 0;
            player.wheel_y = 0;
        }
    }
}

void Runner::handleTimedJoystick(Player& player, const tick_t& ticks){
    //- Right stick movement is for actions when you need to select one more thing
    constexpr tick_t y_wait_time = 100;
    constexpr tick_t x_wait_time = 150;

    bool move_y = ticks - player.right_stick_y_tick > y_wait_time;
    bool move_x = ticks - player.right_stick_x_tick > x_wait_time;

    if (move_y){ //if the delta time is less than 100 ms then skip right joystick movement
        player.right_stick_y_tick = ticks;
    }
    if (move_x){
        player.right_stick_x_tick = ticks;
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
        case (TECH_HAND):{
            if (player.show_tech){
                handleTechMovement(player, move_y);
            }
        }
        default:
            break;
    }
}

void Runner::handleActionHandMovement(Player& player, const bool& move_x,  const bool& move_y){
    //- Collect movement of the right joy stick
    int y_movement = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);
    int x_movement = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTX);

    auto changeLook = [&](Country* new_country, const bool left_change, const bool right_change){
        player.selected_country = new_country;
        player.show_left_country = left_change;
        player.show_right_country = right_change;
    };

    //- Change cards
    if (move_y && pastDeadZone(y_movement)){
        if (players[player.action_view].getActionSize() == 0)
            return;

        player.popped_action_card_index = loopVal(player.popped_action_card_index+(y_movement > 0? 1 : -1), 0 , players[player.action_view].getActionSize()-1);
        
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

void Runner::handleInvestHandMovement(Player& player, const bool& move_x,  const bool& move_y){
    //- Collect movement of the right joy stick
    int y_movement = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);
    int x_movement = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTX);

    //- Change selected card
    if (move_y && pastDeadZone(y_movement)){
        if (players[player.invest_view].getInvestSize() == 0)
            return;

        player.popped_invest_card_index = loopVal(player.popped_invest_card_index + (y_movement > 0 ? 1 : -1), 0,  players[player.invest_view].getInvestSize() - 1);
        
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

void Runner::handleTechMovement(Player& player, const bool& move_y){
    int y_movement = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);

    if (move_y && pastDeadZone(y_movement)){
        if (players[player.tech_view].getTechSize() > 0)
            player.popped_tech_index = loopVal(player.popped_tech_index + (y_movement < 0 ? 1 : -1), 0, players[player.tech_view].getTechSize() - 1);
        //player.popped_tech = &player.getTech(player.popped_invest_card_index)->tech;
    }
}

//&^ Triggers

void Runner::handleTriggerMovement(Player& player){
    bool zooming_out = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_TRIGGERLEFT);
    bool zooming_in = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
    
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

void Runner::handleWidgetMovement(Player& player, const tick_t& ticks){

    auto scroll = [&](int& widet_view, int& view_index, const int incriment){
        widet_view = loopVal(widet_view+incriment, WEST, USSR);
        view_index = -1;
    };

    if (pastWait(player.last_widget, ticks, 150)){ //only take inputs every 100 ticks
        player.last_widget = ticks;
    
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
                default:
                    break;
            }
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