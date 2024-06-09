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
        default:
            break;
    }
}

void Runner::handleJoyStickMovement(Player& player){
    int x_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_LEFTX);
    int y_move = SDL_GameControllerGetAxis(controllers[player.getAllegiance()], SDL_CONTROLLER_AXIS_LEFTY);
    bool x_moving=pastDeadZone(x_move), y_moving=pastDeadZone(y_move);
    if (x_moving){
        player.cursor_x += 5*scaleAxis(x_move);
        player.board_change = true;
    }
    if (y_moving){
        player.cursor_y += 5*scaleAxis(y_move);
        player.board_change = true;
    }

    if (!(x_moving || y_moving)){
        player.closest_map_city = map.getClosestCity(player.cursor_x, player.cursor_y);
    }

}