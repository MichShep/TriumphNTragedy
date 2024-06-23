#include "Runner.h"

//& User Input

void Runner::handleUserInput(bool& running, const Uint32& delta){
    SDL_Event event;
    const Uint32 ticks = SDL_GetTicks();
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    cout << "Quiting through ESC" << endl;
                    freeMemory();
                    exit(0);
                }
                //TODO delete for full release
                else if (event.key.keysym.scancode == SDL_SCANCODE_S){
                    public_messages.push_back(PublicMessage((Message)current_player->getAllegiance(), ticks));
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

void Runner::handleUserAnimationInput(bool& running, const Uint32& delta){
    SDL_Event event;
    const Uint32 ticks = SDL_GetTicks();
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    cout << "Quiting through ESC" << endl;
                    freeMemory();
                    exit(0);
                }
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

    for (auto& player : players){
        //- Handle every frame actions
        handleCursorMovement(player);
        handleTriggerMovement(player);
        handleWidgetMovement(player, ticks);
        handleJoystickMovement(player);

        //- Handle periodic actions
        handleTimedJoystick(player, ticks);
    }
}

//&^ Buttons

void Runner::handleHeldButtons(Player& player, const Uint32& ticks){
    //pass button
    constexpr unsigned int x_wait_time = 3500;
    if (player.x_held_tick != 0 && ticks - player.x_held_tick > x_wait_time){
        if (season == PRODUCTION && player.getCurrentProduction() >= 0 && current_player == &player){
            //- Make the changes from the production
            applyProduction(player);

            //- Add the message to be seen by all that the player passed
            public_messages.push_back(PublicMessage((Message)player.getAllegiance(), ticks));
        }
        else if (season == GOVERNMENT && current_player == &player){ //- if the player whose turn it is is passing
            //- Set to passed (government changes are applied at the end)
            player.passed = true;
            
            //- Add the message to be seen by all that the player passed
            public_messages.push_back(PublicMessage((Message)player.getAllegiance(), ticks));
        }
        player.x_held_tick = 0;
    }

    constexpr unsigned int y_wait_time = 1200;
    switch (season){
        case (PRODUCTION):{
            if (!player.passed && player.y_held_tick != 0 && ticks - player.y_held_tick > y_wait_time){
                if (player.widget == ACTION_HAND && player.bought_action > 0){
                        player.spendProduction(BUY_AC, true);
                        action_bought--;
                        player.board_change = true;
                        player.y_resolved = false;
                }
                else if (player.widget == INVEST_HAND && player.bought_invest > 0){
                        player.spendProduction(BUY_IC, true);
                        invest_bought--;
                        player.board_change = true;
                        player.y_resolved = false;
                }
                player.y_held_tick = ticks;
            }
            break;
        }
        case (GOVERNMENT):{
            if (!player.passed && player.y_held_tick != 0 && ticks - player.y_held_tick > y_wait_time){
                handleCardPlaying(player);
                player.y_held_tick = 0;
            }
            break;
        }
        default:
            break;
    }
}

void Runner::handleButtonUp(Player& player, const SDL_Event& event, const Uint32& ticks){
    switch (event.cbutton.button){
        case SDL_CONTROLLER_BUTTON_X:{
            player.x_held_tick = 0;
            break;
        }
        case SDL_CONTROLLER_BUTTON_Y:{
            if (season == PRODUCTION){
                handleCardBuying(player);
            }
            else if (season == GOVERNMENT){
                player.y_held_tick = 0;
            }
            break;
        }
        /*
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            player.d_right_held = false;            
            break;
        }

        case SDL_CONTROLLER_BUTTON_DPAD_UP:{
            player.d_up_held = false;
            break;
        }
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
            player.d_down_held = false;
            break;
        }*/
        default:
            break;
    }
}

void Runner::handleButtonDown(Player& player, const SDL_Event& event, const Uint32& ticks){
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
        //Toggle view on action cards
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:{
            player.show_action = !player.show_action;
            player.popped_action_card_index = -1;
            player.board_change = true;
            break;
        }
        //Toggle view on invest cards
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:{
            player.show_invest = !player.show_invest;
            player.popped_invest_card_index = -1;
            player.board_change = true;
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
        
        //-Letter buttons
        case SDL_CONTROLLER_BUTTON_X:{ //Δ
            player.x_held_tick = SDL_GetTicks();
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
            player.widget = MAP;
            if (season == PRODUCTION)
                handleUnitBuilding(player);
            
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
    if (player.passed)
        return;

    if (player.y_resolved && player.widget == ACTION_HAND && canBuyAction()){
        player.spendProduction(BUY_AC, false);
        action_bought++;
        player.board_change = true;
    }
    else if (player.y_resolved && player.widget == INVEST_HAND && canBuyInvest()){
        player.spendProduction(BUY_IC, false);
        invest_bought++;
        player.board_change = true;
    }
    player.y_held_tick = 0;
    player.y_resolved = true;
}

void Runner::handleCardPlaying(Player& player){
    //- Card playing can only happen on the curreny player's turn
    if (&player != current_player){
        return;
    }

    switch (player.widget){
        case (ACTION_HAND):{ //- If action hand then playing diplomacy
            addDiplomacy(player, player.selected_country);
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
    if (x_moving){
        clampCursorX(player, 5*scaleAxis(x_move));
        player.cursor_x = SDL_clamp(player.cursor_x, -16, powers_app[player.getAllegiance()].screen.WIDTH-16);
        player.selected_unit = {nullptr, nullptr};
        player.board_change = true;
    }
    if (y_moving){
        clampCursorY(player, 5*scaleAxis(y_move));
        player.cursor_y = SDL_clamp(player.cursor_y, -16, powers_app[player.getAllegiance()].screen.HEIGHT-16);
        player.selected_unit = {nullptr, nullptr};
        player.board_change = true;
    }

    if (!(x_moving || y_moving)){
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
            //- Need to find which unit is cloest to the cursor (on unit circle) out of the 8 options
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

void Runner::handleTimedJoystick(Player& player, const Uint32& ticks){
    //- Right stick movement is for actions when you need to select one more thing
    constexpr Uint32 wait_time = 100;
    if (ticks - player.right_stick_tick > wait_time ){ //if the delta time is less than 100 ms then skip right joystick movement
        player.right_stick_tick = ticks;
    }
    else{
        return; //wait unitl it is
    }
    
    if (player.show_action && player.widget == ACTION_HAND){
        int y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);
        int x_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTX);

        if (player.show_action && pastDeadZone(y_move)){
            if (y_move > 0) //positive up movement
                player.popped_action_card_index = loopVal(player.popped_action_card_index+1, 0 , player.getActionSize()-1);
            else //negative down movement
                player.popped_action_card_index = loopVal(player.popped_action_card_index-1, 0 , player.getActionSize()-1);
            
            player.selected_country = nullptr; //- since the countries changed need to reselect selected country
            player.show_left_country = true;
            player.show_right_country = true;
            player.popped_action_card = player.getActionCard(player.popped_action_card_index);

            //- Set new cities to be highlighted
            if (player.popped_action_card->type == DIPLOMACY){
                player.popped_left_country = map.getCapital(player.popped_action_card->countryA);
                player.popped_right_country = map.getCapital(player.popped_action_card->countryB);
            }
        }
        if (player.show_action && pastDeadZone(x_move) && player.popped_action_card->type == DIPLOMACY){ //change from viewing both countries to just one side
            //4 cases: middle to right, middle to left, right to middle, left to middle
            if (player.show_left_country && player.show_right_country){ //middle
                if (x_move > 0){ //positive move means look at right country
                    player.selected_country = map.getCountry(player.popped_action_card->countryB);
                    player.show_left_country = false;
                    player.show_right_country = true;
                }
                else{ //negative means look at left
                    player.selected_country = map.getCountry(player.popped_action_card->countryA);
                    player.show_left_country = true;
                    player.show_right_country = false;
                }
            }
            else if (player.show_left_country && !player.show_right_country){ //left
                if (x_move > 0){ //positive move back to middle
                    player.selected_country = nullptr;
                    player.show_left_country = true;
                    player.show_right_country = true;
                }
            }
            else if (!player.show_left_country && player.show_right_country){ //right
                if (x_move < 0){ //positive move back to middle
                    player.selected_country = nullptr;
                    player.show_left_country = true;
                    player.show_right_country = true;
                }
            }
        }
    }

    else if (player.show_invest && player.widget == INVEST_HAND){
        int y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);

        if (pastDeadZone(y_move)){
            if (y_move > 0) //positive up movement
                player.popped_invest_card_index = loopVal(player.popped_invest_card_index+1, 0 , player.getInvestSize()-1);
            else //negative down movement
                player.popped_invest_card_index = loopVal(player.popped_invest_card_index-1, 0 , player.getInvestSize()-1);
        }
    }
}

//&^ Trigggers

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

void Runner::handleWidgetMovement(Player& player, const Uint32& ticks){
        if (ticks - player.last_widget > 100){ //only take inputs every 100 ticks
            player.last_widget = ticks;
        
            if ((player.d_left_held && player.d_right_held)){ //holding both down so ignore any changes
                player.d_left_held = false; player.d_right_held=false;
                return;
            }

            if(player.d_left_held){ //move left one button
                player.widget = WIDGET_ADJACENCY[player.widget][2]; //up0 down1 left2 right3
                player.d_left_held = false;
            }

            else if (player.d_right_held){ //move right one button
                player.widget = WIDGET_ADJACENCY[player.widget][3];
                player.d_right_held=false;
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