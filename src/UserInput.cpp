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
        //Pin city to display
        case SDL_CONTROLLER_BUTTON_B:{
            //check to see if adding cards 
            if (inBox(3, 875, 102, 102, player.cursor_x, player.cursor_y)){ //add investment card
                player.production_actions.push(BUY_AC);
            }
            else if (inBox(1407, 875, 102, 102, player.cursor_x, player.cursor_y)){ //add investment card
                player.production_actions.push(BUY_IC);
            }
            //pinning cities
            else{
                //if the current city isn't already being displayed then add it
                const auto& result = find(player.displayed_cities.begin(),  player.displayed_cities.end(), player.closest_map_city);
                if (result == player.displayed_cities.end()){
                    player.displayed_cities.push_back(player.closest_map_city);
                    if (player.city_viewing == -1){ //no current selected city
                        player.city_viewing = 0;
                        player.displayed_cities[player.city_viewing]->getFirst(player.unit_viewing, player.allegiance_viewing, &player.selected_unit);
                    }
                }
                else{ //if its already there then remove it
                    player.displayed_cities.erase(result);
                    if (player.displayed_cities.size() == 0)
                        player.city_viewing = -1;
                    else if (player.city_viewing > (player.displayed_cities.size()-1))
                        player.city_viewing = player.displayed_cities.size()-2;
                }
                player.board_change = true;
            }
            break;
        }
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
            if (player.city_viewing != -1){
                player.city_viewing = (player.city_viewing+1)%player.displayed_cities.size();
                player.displayed_cities[player.city_viewing]->getFirst(player.unit_viewing, player.allegiance_viewing, &player.selected_unit);
                player.board_change = true;
            }
            break;
        }
        //Move up city viewing
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
            if (player.city_viewing != -1){
                player.city_viewing = (player.city_viewing-1 < 0)? (player.displayed_cities.size()-1): ((player.city_viewing-1)%player.displayed_cities.size());
                player.displayed_cities[player.city_viewing]->getFirst(player.unit_viewing, player.allegiance_viewing, &player.selected_unit);
                player.board_change = true;
            }
            break;
        }  
        //Move right unit viewing
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            if (player.unit_viewing != -1){
                //cout << &player.selected_unit << " " << player.selected_unit << endl;
                player.displayed_cities[player.city_viewing]->getNext(player.unit_viewing, player.allegiance_viewing, &player.selected_unit);
                //cout << &player.selected_unit << " " << player.selected_unit << endl;
                player.board_change = true;
            }
            break;
        }    
        //Move left unit viewing
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            if (player.unit_viewing != -1){
                player.displayed_cities[player.city_viewing]->getPrev(player.unit_viewing, player.allegiance_viewing, &player.selected_unit);
                player.board_change = true;
            }
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
        player.cursor_x = SDL_clamp(player.cursor_x, 0, 1512-16);
        player.board_change = true;
    }
    if (y_moving){
        player.cursor_y += 5*scaleAxis(y_move);
        player.cursor_y = SDL_clamp(player.cursor_y, 0, 982-16);
        player.board_change = true;
    }

    if (!(x_moving || y_moving)){
        player.closest_map_city = map.getClosestCity(player.cursor_x, player.cursor_y);
        player.board_change = true;
    }

    //- Right stick movement for zooming
    y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_RIGHTY);
    if (pastDeadZone(y_move)){
        player.mapY = 5*scaleAxis(y_move);
    }

}