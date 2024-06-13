#include "Runner.h"

//& User Input
void Runner::handleUserInput(bool& running){
    SDL_Event event;
    if (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN:{
                running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
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

    for (auto& player : turn_order){
        handleJoyStickMovement(*player);
        handleTriggerMovement(*player);
    }
}

void Runner::handleButtonDown(Player& player, const SDL_Event& event){
    //cout << "A button was pressed by player " << player.getAllegiance() << endl;
    switch (event.cbutton.button){
        //-Shoulders
        //Toggle view on action cards
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:{
            player.show_action = !player.show_action;
            player.board_change = true;
            break;
        }
        //Toggle view on invest cards
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:{
            player.show_invest = !player.show_invest;
            player.board_change = true;
            break;
        }
        
        //-Letter buttons
        //Expand city display
        case SDL_CONTROLLER_BUTTON_B:{
            //check to see if adding cards 
            player.closest_map_city->full_display = ! player.closest_map_city->full_display;
        }
        break;
        //Upgrade Unit
        case SDL_CONTROLLER_BUTTON_X:{
            if (player.unit_viewing != -1){
                player.selected_unit->upgrading = !player.selected_unit->upgrading;
                player.production_actions.push(UNIT_UP);
                player.board_change = true;
            }
            break;
        }


        //-Middle Buttons
        //Quit Game
        case SDL_CONTROLLER_BUTTON_START:{
            cout <<"Start pushed and exiting"<<endl;
            freeMemory();
            exit(0);
        }
        
        //-DPAD
        //Move down city viewing
        case SDL_CONTROLLER_BUTTON_DPAD_UP:{
            cout <<"DU" <<endl;
            player.app->screen.zoom_y -= 5;
            break;
        }
        //Move up city viewing
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
            cout <<"DD" <<endl;
            player.app->screen.zoom_y += 5;
            break;
        }  
        //Move right unit viewing
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            cout <<"DR" <<endl;
            player.app->screen.zoom_x += 5;
            break;
        }    
        //Move left unit viewing
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            cout <<"DL" <<endl;
            player.app->screen.zoom_x -= 5;
            break;
        }      
        default:
            break;
    }
}

void Runner::handleJoyStickMovement(Player& player){
    //- Left stick movement for cursor movement
    int x_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_LEFTX);
    int y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_LEFTY);
    bool x_moving=pastDeadZone(x_move), y_moving=pastDeadZone(y_move);
    if (x_moving){
        player.cursor_x += 5*scaleAxis(x_move);
        player.cursor_x = SDL_clamp(player.cursor_x, -16, powers_app[player.getAllegiance()].screen.WIDTH-16);
        player.board_change = true;
    }
    if (y_moving){
        player.cursor_y += 5*scaleAxis(y_move);
        player.cursor_y = SDL_clamp(player.cursor_y, -16, powers_app[player.getAllegiance()].screen.HEIGHT-16);
        player.board_change = true;
    }

    if (!(x_moving || y_moving)){
        player.closest_map_city = map.getClosestCity(player.cursor_x, player.cursor_y, player.app->screen.zoom_factor*player.app->screen.WIDTH/1512, player.app->screen.zoom_factor*player.app->screen.HEIGHT/982);
        player.board_change = true;
    }
}

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

        //player.app->screen.zoom_x = (player.app->screen.zoom_factor == 1.0)? 0 :  (player.cursor_x - (player.cursor_x - player.app->screen.zoom_x) * player.app->screen.zoom_factor);
        //player.app->screen.zoom_y = (player.app->screen.zoom_factor == 1.0)? 0 : (player.cursor_y - (player.cursor_y - player.app->screen.zoom_y) * player.app->screen.zoom_factor);
    }
}