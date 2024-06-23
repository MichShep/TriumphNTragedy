#include "Runner.h"


//& SDL Routines

bool Runner::InitSDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;

    
    }
    SDL_GameControllerEventState(SDL_ENABLE);
    const char* mapping_string = "030000000d0f0000f600000001000000,Lic Pro Controller,a:b0,b:b1,x:b2,y:b3,back:b8,guide:b12,start:b9,leftshoulder:b4,rightshoulder:b5,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,lefttrigger:b6,righttrigger:b7,platform:Mac OS X";

    cout << SDL_GameControllerAddMapping(mapping_string) << endl;
    //030000000d0f0000f600000001000000,Lic Pro Controller,a:b0,b:b1,x:b2,y:b3,back:b8,guide:b12,start:b9,leftshoulder:b4,rightshoulder:b5,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,lefttrigger:b6,righttrigger:b7,platform:Mac OS X
    int joysticks_found=0;
    for (int i = 0; i < SDL_NumJoysticks() && joysticks_found != 3; i++){
        if (SDL_IsGameController(i)){
            controllers[joysticks_found++] = SDL_GameControllerOpen(i);
        }
    }
    if (controllers[0] == nullptr){
        cout << "West controller not connected" << endl;
        exit(1);
    }
    west_controller = controllers[0];
    if (controllers[1] == nullptr){
        cout << "Axis controller not connected" << endl;
    }
    axis_controller = controllers[1];
    if (controllers[2] == nullptr){
        cout << "USSR controller not connected" << endl;
    }
    ussr_controller = controllers[2];

    //SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ); //* https://stackoverflow.com/questions/19859891/sdl2-antialiasing

    return true;
}

bool Runner::InitApplication(){
    //- Init SDL
    if (InitSDL() == false){
        ShutdownApplication();
        return false;
    }

    //- Init main app
    app.window = SDL_CreateWindow(
        "Triumph And Tragedy",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app.screen.WIDTH,
        app.screen.HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    //SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);

    //- Init axis app
    powers_app[AXIS].window = SDL_CreateWindow(
        "Axis Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        600,
        600, 
        SDL_WINDOW_OPENGL
    );

    //- Init ussr app
    powers_app[USSR].window = SDL_CreateWindow(
        "USSR Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app.screen.WIDTH,
        app.screen.HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    //- Init west app
    powers_app[WEST].window = SDL_CreateWindow(
        "West Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app.screen.WIDTH,
        app.screen.HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    //SDL_SetWindowFullscreen(powers_app[WEST].window, SDL_TRUE);
    SDL_SetWindowFullscreen(powers_app[USSR].window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(powers_app[AXIS].window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(powers_app[WEST].window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (app.window == nullptr){
        cout << "Unable to create main window. Error: "<< SDL_GetError() << endl;
        ShutdownApplication();
        return false;
    }

    if (!(app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC))){
        cout << "Unable to create main renderer. Error: "<< SDL_GetError() << endl;
        ShutdownApplication();
    }

    for (auto& a : powers_app){
        if (a.window == nullptr){
            cout << "Unable to create power window. Error: "<< SDL_GetError() << endl;
            ShutdownApplication();
            return false;
        }
        int width, height;
        SDL_GetWindowSize(a.window, &width, &height);
        a.screen.WIDTH = width;
        a.screen.HEIGHT = height;

        if (!(a.renderer = SDL_CreateRenderer(a.window, -1, SDL_RENDERER_PRESENTVSYNC))){
            cout << "Unable to create power renderer. Error: "<< SDL_GetError() << endl;
            ShutdownApplication();
        }
    }


    return true;
}

void Runner::ShutdownApplication(){
    if (app.window != nullptr) {
        SDL_DestroyWindow(app.window);
        app.window = nullptr;
    }

    if (app.renderer != nullptr) {
        SDL_DestroyRenderer(app.renderer);
        app.renderer = nullptr;
    }

    for (auto& a : powers_app){
        if (a.window != nullptr) {
            SDL_DestroyWindow(a.window);
            a.window = nullptr;
        }

        if (a.renderer != nullptr) {
            SDL_DestroyRenderer(a.renderer);
            a.renderer = nullptr;
        }
    }

    SDL_GameControllerClose(controllers[0]);
    SDL_GameControllerClose(controllers[1]);
    SDL_GameControllerClose(controllers[2]);


    SDL_Quit();
}

void Runner::ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 216, 216, 216, 255);
    if (SDL_RenderClear(renderer) < 0){
        cout << "SDL_RenderClear failed with error: " << SDL_GetError() << endl;
    }
}

//& Graphics
//&^ Drawing Player board

void Runner::drawPlayerBoard(Player& player, const Uint32& ticks){
    //- Draw the map and the cities
    drawMap(player, true, true, true, false, false);

    auto& sprite_sheet = player.sprite_sheet;
    
    //- Draw the current state of the cards
    drawPlayerCards(player);

    //- Draw the current actions avialable
    drawActionButtons(player, ticks);

    //- Draw the production left
    drawNumber(player.app->renderer, player.getCurrentProduction(), 50, 0, 5, 255, 255, 255);

    //- Draw the build UI
    drawBuild(player);

    //- Draw Turn Order
    drawTurnOrder(player);

    //- Draw the selected cards
    if (player.popped_action_card != nullptr && player.popped_action_card->type == DIPLOMACY){
        if (player.show_left_country) drawCity(player, player.popped_left_country->x, player.popped_left_country->y, player.popped_left_country->population_type);
        if (player.show_right_country) drawCity(player, player.popped_right_country->x, player.popped_right_country->y, player.popped_right_country->population_type);
    }

    //- Update Public Animations
   for (auto& message : public_messages){
        animateMessage(player, message, ticks);
   }

    //- Draw all cursor's
    //for (const auto& cursor : players){
        SDL_Rect cursor_target = {(int)player.cursor_x, (int)player.cursor_y, 32, 32};
        sprite_sheet->drawSprite(&cursor_target, 0, 11+player.getAllegiance(), 32, 32);
    //}

    SDL_RenderPresent(player.app->renderer);
}

void Runner::drawMap(Player& player, const bool cities, const bool influence, const bool resources, const bool connections, const bool clear, const int& fps){
    ClearScreen(player.app->renderer);
    int width, height;
    SDL_GetWindowSize(player.app->window, &width, &height);
    SDL_Rect tar = {0, 0, width, height};
    player.map_sprite->drawSprite(&tar, 0, 0, (int)(1512/player.app->screen.zoom_factor), (int)(982/player.app->screen.zoom_factor), 0, player.app->screen.zoom_x, player.app->screen.zoom_y);

    if (connections)
        drawConnections(player);

    if (cities){
        auto& cities = map.getCities();
        for (auto city : cities)
            drawCity(player, city.second, resources);
    }

    if (influence){
        drawInfluence(player);
    }

    if (clear)
        SDL_RenderPresent(player.app->renderer);

    if (fps != -1){
        drawNumber(player.app->renderer, (1000 / fps), 100, 100, 10, 0,0,0);
    }

    //TODO remove later
    for (const auto& country : map.getCountries()){
        if (country.second->added_influence != 0)
            drawNumber(player.app->renderer, country.second->added_influence, player.app->screen.getX(map.getCapital(country.first)->x), player.app->screen.getY(map.getCapital(country.first)->y), 1, BORDER_COLOR[country.second->top_card][0],  BORDER_COLOR[country.second->top_card][1],  BORDER_COLOR[country.second->top_card][2]);
    }
}

void Runner::drawBuild(Player& player){
    //- If one is selected
    if (nullptr != player.building_city){
        const auto& city = player.building_city;
        const int& zoom = player.zoom;
        const int center_x = player.app->screen.getX(city->x+(city->WIDTH/2))-ZOOM_DIMENSIONS[zoom-1][0]/2;
        const int center_y = player.app->screen.getY(city->y+((city->HEIGHT/2)))-ZOOM_DIMENSIONS[zoom-1][0]/2;
        const int real_center_x = player.app->screen.getX(city->x+(city->WIDTH/2));
        const int real_center_y = player.app->screen.getY(city->y+(city->HEIGHT/2));
        const int radius = 40*zoom;
        const int sqrt_radius = radius/1.4;

        //-Draw the selection line if there is one
        if (player.wheel_x != 0 && player.wheel_y != 0){
            drawLine(player, real_center_x, real_center_y, real_center_x+player.wheel_x*radius, real_center_y+player.wheel_y*radius); //city middle to the wheel coords
        }

        //- Draw the building UI if selected
        //FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY
        //- Draw units around
        if (player.unit_buildable[0]) drawUnit(player, FORTRESS, city->ruler_nationality, center_x, center_y-radius, zoom); //top

        if (player.unit_buildable[1]) drawUnit(player, AIR, city->ruler_nationality, center_x+sqrt_radius, center_y-sqrt_radius, zoom); //top right

        if (player.unit_buildable[2]) drawUnit(player, CARRIER, city->ruler_nationality, center_x+radius, center_y, zoom); //right

        if (player.unit_buildable[3]) drawUnit(player, SUB, city->ruler_nationality, center_x+sqrt_radius, center_y+sqrt_radius, zoom); //bottom right

        if (player.unit_buildable[4]) drawUnit(player, FLEET, city->ruler_nationality, center_x, center_y+radius, zoom); //bottom

        if (player.unit_buildable[5]) drawUnit(player, TANK, city->ruler_nationality, center_x-sqrt_radius, center_y+sqrt_radius, zoom); //bottom left

        if (player.unit_buildable[6]) drawUnit(player, INFANTRY, city->ruler_nationality, center_x-radius, center_y, zoom); //left

        //always draw the exit button
        SDL_Rect target = {(int)(center_x-sqrt_radius), (int)(center_y-sqrt_radius), ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][0]}; //top left
        if (zoom <= 2){
            player.units_sprite_z1->drawSprite(&target, 1, 41, 20, 20);
        } 
        if (zoom == 3){
            player.units_sprite_z3->drawSprite(&target, 1, 41, 64, 64);
        }

        //- Draw the closest or 'popped unit'
        if (player.wheel_x != 0 && player.wheel_y != 0){
            if (player.popped_unit[0] != 7)
                drawUnit(player, (UnitType)(player.popped_unit[0]+7), city->ruler_nationality, center_x+sqrt_radius*player.popped_unit[1], center_y+sqrt_radius*player.popped_unit[2], zoom, !player.unit_buildable[(int)player.popped_unit[0]]); //left
            else{
                target = {(int)(center_x+sqrt_radius*player.popped_unit[1]), (int)(center_y+sqrt_radius*player.popped_unit[2]), ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][0]};
                if (zoom <= 2){
                    player.units_sprite_z1->drawSprite(&target, 1, 42, 20, 20);
                } 
                if (zoom == 3){
                    player.units_sprite_z3->drawSprite(&target, 1, 42, 64, 64);
                }
            }

            //SDL_Rect target = {center_x+radius*player.popped_unit[1], center_y+radius*player.popped_unit[2], ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][0]};
            //player.units_sprite_z1->drawSprite(&target, 0, 42, 20, 20) ;//(UnitType)player.popped_unit[0], city->nationality, center_x+radius*player.popped_unit[1], center_y+radius*player.popped_unit[2]);
        }
        //-Redraw city for overlap
        drawCity(player, player.building_city, true, false);
    }
}

void Runner::drawPlayerCards(Player& player){
    //- Draw the current state of the action cards
    const int y = player.app->screen.HEIGHT-105;
    auto& sprite_sheet = player.sprite_sheet;
    SDL_Rect target = {3, y, 102, 102};
    if (player.show_action){ //draw all the action cards
        if (player.getActionSize() > 0){
            const int holder_size = SDL_clamp(player.getActionSize()+player.bought_action, 0, 15)*32;
            //- Draw the opening icon
            sprite_sheet->drawSprite(&target, 6, 1, 102, 102);

            //- calcualte how many cards need to be shown and draw background (max amount will be 12)
            target = {3, y-holder_size, 102, holder_size};
            sprite_sheet->drawSprite(&target, 6, 2, 102, 102);
            target = {3, y-holder_size, 102, 102};
            sprite_sheet->drawSprite(&target, 6, 2, 102, 102);

            //- Draw the cards
            drawActionCards(&player, 6, y-holder_size+3, 15);
        }
        else{
            target.y = 875-102/2;
            sprite_sheet->drawSprite(&target, 6, 2, 102, 102);

            target.y = 875;
            sprite_sheet->drawSprite(&target, 6, 1, 102, 102);
        }

        
    }
    else{ //draw just the icon
        sprite_sheet->drawSprite(&target, 6, 0, 102, 102);
    }
    //if cards aren't selected yet then show arrow pointing to the base if its selected
    if (player.widget == ACTION_HAND && player.popped_action_card_index == -1){
        target = {105, y+32, 32, 32};
        sprite_sheet->drawSprite(&target,0,0);
    }

    //- Draw the current state of the invest cards
    target = {player.app->screen.WIDTH-105, y, 102, 102};
    const int x = target.x;
    if (player.show_invest){ //draw all the invest cards
        if (player.getInvestSize() > 0){
            const int holder_size = SDL_clamp(player.getInvestSize()+player.bought_invest, 0, 15)*32;
            //- Draw the opening icon
            sprite_sheet->drawSprite(&target, 6, 4, 102, 102);

            //- calcualte how many cards need to be shown and draw background (max amount will be 12)
            target = {x, y-holder_size, 102, holder_size};
            sprite_sheet->drawSprite(&target, 6, 5, 102, 102);
            target = {x, y-holder_size, 102, 102};
            sprite_sheet->drawSprite(&target, 6, 5, 102, 102);

            //- Draw the cards
            drawInvestCards(&player, x+3, y-holder_size+3, 15);
        }
        else{
            target.y = 875-102/2;
            sprite_sheet->drawSprite(&target, 6, 5, 102, 102);

            target.y = 875;
            sprite_sheet->drawSprite(&target, 6, 4, 102, 102);
        }
    }
    else{
        sprite_sheet->drawSprite(&target, 6, 3, 102, 102);
    }
    if (player.widget == INVEST_HAND && player.popped_invest_card_index == -1){
        target = {player.app->screen.WIDTH-137, y+32, 32, 32};
        sprite_sheet->drawSprite(&target,0,1);
    }
}

void Runner::drawActionButtons(const Player& player, const Uint32& ticks){
    //  X
    // Y B
    //  A
    const int top_left_x = player.app->screen.WIDTH - 107;
    const int top_left_y = 1;
    SDL_Rect target_x = {top_left_x + 32, top_left_y, 45, 48};
    SDL_Rect target_y = {top_left_x, top_left_y+32, 45, 48};
    SDL_Rect target_a = {top_left_x+64, top_left_y+32, 45, 48};
    SDL_Rect target_b = {top_left_x+32, top_left_y+64, 45, 48};
    //total area should be 104 x 110
    if (season == PRODUCTION){
        //- Draw options for X
        if (player.passed){
            player.controller_button_sprites->drawSprite(&target_x, 0, 0, 45, 48);
        }
        else if (player.x_held_tick > 0){ // if it is held
            //3500 total ticks for loading and 35 animation frames, so every 100 ticks is another frame
            player.controller_button_sprites->drawSprite(&target_x, 0, 1+(ticks-player.x_held_tick) / 100 , 45, 48);
        }
        else{ 
            player.controller_button_sprites->drawSprite(&target_x, 0, 0, 45, 48);
        }

        //- Draw options for Y (buying/selling cards)
        if(player.passed){
            player.controller_button_sprites->drawSprite(&target_y, 1, 0, 45, 48);
        }
        else if (player.widget == ACTION_HAND && player.show_action){ //if action cards selected and showing then either
            if (player.y_held_tick > 0){ //delete cards
                // 1200 total ticks to hold y with 6 frames so every 200 ticks is a frame
                player.controller_button_sprites->drawSprite(&target_y, 1, 1+(ticks-player.y_held_tick) / 200, 45, 48);
            }
            else{ //or add one
                player.controller_button_sprites->drawSprite(&target_y, 1, 1, 45, 48);
            }

        }
        else if (player.widget == INVEST_HAND && player.show_invest){
            if (player.y_held_tick > 0){ //delete cards
                // 1200 total ticks to hold y with 6 frames so every 200 ticks is a frame
                player.controller_button_sprites->drawSprite(&target_y, 1, 10+(ticks-player.y_held_tick) / 200, 45, 48, 0, -1);
            }
            else{ //or add one
                player.controller_button_sprites->drawSprite(&target_y, 1, 9, 45, 48);
            }
        }
        else{
            player.controller_button_sprites->drawSprite(&target_y, 1, 0, 45, 48);
        }

        //- Draw options for A (pinning cities) (can do while passed)
        if (player.closest_map_city != nullptr){
            player.controller_button_sprites->drawSprite(&target_a, 3, 1, 45, 48);
        }
        else{
            player.controller_button_sprites->drawSprite(&target_a, 3, 0, 45, 48);
        }

        //TODO fix sprites to swap A and B
        //- Draw options for B (adding/upgrading units)
        if(player.passed){
            player.controller_button_sprites->drawSprite(&target_b, 2, 0, 45, 48);
        }
        else if (player.selected_unit.second != nullptr){
            if (player.selected_unit.second->upgrading && player.selected_unit.second->combat_value != 0){ //if its already upgrade then can remove
                player.controller_button_sprites->drawSprite(&target_b, 2, 7, 45, 48);
            }
            else if (player.selected_unit.second->combat_value == 0){ //if it has 0 cv its a new cadre and removing would be deleting it
                player.controller_button_sprites->drawSprite(&target_b, 2, 3, 45, 48);
            }
            else{ //if not then option to upgrade
                player.controller_button_sprites->drawSprite(&target_b, 2, 5, 45, 48);
            }

        }
        
        else if (player.popped_unit[0] != 7 && player.unit_buildable[(int)player.popped_unit[0]]){ //if a unit is popped and is buildable show option to build
            player.controller_button_sprites->drawSprite(&target_b, 2, 1, 45, 48);
        }

        else{ //all else show default B button
            player.controller_button_sprites->drawSprite(&target_b, 2, 0, 45, 48);
        }

    }
    else{
        player.controller_button_sprites->drawSprite(&target_x, 0, 0, 45, 48); //x
        player.controller_button_sprites->drawSprite(&target_y, 1, 0, 45, 48); //y
        player.controller_button_sprites->drawSprite(&target_a, 3, 0, 45, 48); //a
        player.controller_button_sprites->drawSprite(&target_b, 2, 0, 45, 48); //b

    }

}

void Runner::drawTurnOrder(const Player& player){
    auto& sprite_sheet = player.sprite_sheet;
    //- draw the actual turn order
    SDL_Rect turn_order_target = {3, 3, 124, 38};
    sprite_sheet->drawSprite(&turn_order_target, 3, 0, 124, 38);
    if (turn_order[0] != nullptr){
        turn_order_target = {6, 6, 32, 32};
        sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[0]->getAllegiance()*2+turn_order[0]->passed);
        turn_order_target = {49, 6, 32, 32};
        sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[1]->getAllegiance()*2+turn_order[1]->passed);
        turn_order_target = {92, 6, 32, 32};
        sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[2]->getAllegiance()*2+turn_order[2]->passed);
    }
    //- draw which phase in game
    turn_order_target = {3, 44, 124, 38};
    sprite_sheet->drawSprite(&turn_order_target, 3, season-4, 124, 38);
}

//&^ Drawing Units

void Runner::drawUnit(const Player& player, const Unit* unit, const int x, const int y, const int zoom, const bool secret){
    //- Get the sprite depending on thenationality and current CV

    SDL_Rect target {x, y, ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][0]};
    if (zoom <= 2){
        if (secret)
            player.units_sprite_z1->drawSprite(&target, 0+unit->upgrading+(unit->combat_value == 0), 35+unit->nationality, 20, 20);
        else
            player.units_sprite_z1->drawSprite(&target, unit->unit_type+7*unit->upgrading, 5*unit->nationality+unit->combat_value+unit->upgrading, 20, 20);
    } 
    if (zoom == 3){
        if (secret)
            player.units_sprite_z3->drawSprite(&target, 0+unit->upgrading+(unit->combat_value == 0), 35+unit->nationality, 64, 64);
        else 
            player.units_sprite_z3->drawSprite(&target, unit->unit_type+7*unit->upgrading, 5*unit->nationality+unit->combat_value+unit->upgrading, 64, 64);
    }
}

void Runner::drawUnit(const Player& player, const UnitType unit_type, const UnitCountry nationality, const int x, const int y, const int zoom, const bool invalid, const int scale){
    SDL_Rect target {x, y, ZOOM_DIMENSIONS[zoom-1][0]*scale, ZOOM_DIMENSIONS[zoom-1][0]*scale};
    if (invalid){
        if (zoom <= 2){
            player.units_sprite_z1->drawSprite(&target, unit_type, 35+(MAX_CV_TABLE[nationality]==3), 20, 20);
        } 
        if (zoom == 3){
            player.units_sprite_z3->drawSprite(&target,unit_type, 35+(MAX_CV_TABLE[nationality]==3), 64, 64);
        }
        
    }
    else{
        if (zoom <= 2){
            player.units_sprite_z1->drawSprite(&target, unit_type, 44+nationality, 20, 20);
        } 
        if (zoom == 3){
            player.units_sprite_z3->drawSprite(&target,unit_type, 44+nationality, 64, 64);
        }
    }
}

//&^ Drawing Cities

void Runner::drawCity(Player& player, City* city, const bool resources, const bool units){
    SDL_Rect target;
    auto& sprite_sheet = player.sprite_sheet;
    target = {player.app->screen.getX(city->x), player.app->screen.getY(city->y), city->HEIGHT*player.zoom, city->WIDTH*player.zoom};
    //- Draw the Population type (capital, subcapital, ...)
    sprite_sheet->drawSprite(&target, 8, getCitySprite(city));
    int scale = 1;
    //- Draw the resources
    if (resources){
        target = {player.app->screen.getX(city->res_x), player.app->screen.getY(city->res_y),23*scale , 23*scale};
        if (city->resource > 0){ //can blockade even with no resources
            sprite_sheet->drawSprite(&target, 0, (city->blockcade)? 25 : 25 + (city->resource)/((city->resource_type == TRANS_ATLANTIC)? 2 : 1), 23, 23);
            if (city->resource_type == TRANS_ATLANTIC){
                target.x +=24;
                sprite_sheet->drawSprite(&target, 0, (city->med_blockcade)? 29 : 29 + (city->resource/2), 23, 23);
            }
        }
    }
    //-Draw Units
    if (units)
        drawCityUnits(player, city);
}

void Runner::drawCity(Player& player, const int& x, const int& y, const PopulationType& population_type){
    SDL_Rect target = {player.app->screen.getX(x), player.app->screen.getY(y), 32*player.zoom, 32*player.zoom};
    player.sprite_sheet->drawSprite(&target, 8, 14+5-(int)population_type);
}

void Runner::drawCityUnits(Player& player, City* city){
    if (city->full_display[player.getAllegiance()]){
        drawFullCityUnits(player, city);
        return;
    }

    const CityType& allegiance = player.getAllegiance();
    const auto& zoom = (int)player.app->screen.zoom_factor;
    const int off = ZOOM_DIMENSIONS[zoom-1][1];

    int unit_count = 0;
    int skipped = 0;
    SDL_Rect target = {player.app->screen.getX(city->x), player.app->screen.getY(city->y)+33*zoom, 20, 20};
    int offset = -(SDL_clamp(city->num_occupants, 0, 5)*off)/2 + 16*zoom;
    if (offset + target.x < 0){
        offset = 0;
    }


    //For the closest unit to the cursor
    const int cursor_x = player.cursor_x+16;
    const int cursor_y = player.cursor_y+16;
    const int width = ZOOM_DIMENSIONS[zoom-1][0];
    bool found = false;


    bool hide_rivals = !city->isConflict() && WEST != allegiance; //if there is no conflict then rival units are placed 'face up' and not viewable by rivals
    for (const auto& unit : city->occupants[0]){ //west units
        if (unit_count == 5)
            break;
        if (skipped < city->skip_troop[allegiance]){
            skipped++;
            continue;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        if (!found && inBox(target.x+offset, target.y, width, width, cursor_x, cursor_y)){
            found = true;
            player.selected_unit = {city, unit};
        }
        offset += off;  unit_count++;
    }

    hide_rivals = !city->isConflict() && AXIS != allegiance;
    if (unit_count != 5)
    for (const auto& unit : city->occupants[1]){ //axis units
        if (unit_count == 5)
            break;
        if (skipped < city->skip_troop[allegiance]){
            skipped++;
            continue;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        if (!found && inBox(target.x+offset, target.y, width, width, cursor_x, cursor_y)){
            found = true;
            player.selected_unit = {city, unit};
        }
        offset += off; unit_count++;
    }

    hide_rivals = !city->isConflict() && USSR != allegiance;
    if (unit_count != 5)
    for (const auto& unit : city->occupants[2]){ //ussr units
        if (unit_count == 5)
            break;
        if (skipped < city->skip_troop[allegiance]){
            skipped++;
            continue;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        if (!found && inBox(target.x+offset, target.y, width, width, cursor_x, cursor_y)){
            found = true;
            player.selected_unit = {city, unit};
        }
        offset += off; unit_count++;
    }

    //always show neutral units (only forts)
    if (unit_count != 5)
    for (const auto& unit : city->occupants[3]){ //neutral units
        if (unit_count == 5)
            break;
        if (skipped < city->skip_troop[allegiance]){
            skipped++;
            continue;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom);
        if (!found && inBox(target.x+offset, target.y, width, width, cursor_x, cursor_y)){
            found = true;
            player.selected_unit = {city, unit};
        }
        offset += off; unit_count++;
    }

    //- Cycling to next 5 troops
    Uint32 res = SDL_GetTicks();
    if (res - city->last_skip[allegiance] >= 2500 && city->num_occupants > 5){
        city->skip_troop[allegiance] = ((city->skip_troop[allegiance]+5 >= (((city->num_occupants / 5) + 1)) * 5) || city->num_occupants == city->skip_troop[allegiance]+5 )? 0 : city->skip_troop[allegiance]+5;
        city->last_skip[allegiance] = res;
        player.selected_unit = {nullptr, nullptr};
    }
}

void Runner::drawFullCityUnits(Player& player, City* city){
    const CityType& allegiance = player.getAllegiance();
    const auto& zoom = (int)player.app->screen.zoom_factor;
    const int off = ZOOM_DIMENSIONS[zoom-1][1];

    SDL_Rect target = {player.app->screen.getX(city->x), player.app->screen.getY(city->y)+33*zoom-off, 20, 20};
    int offset = -(SDL_clamp(city->num_occupants, 0, 5)*off)/2 + 16*zoom;
    if (offset + target.x < 0){
        offset = 0;
    }
    const int og_offset = offset;
    int unit_count = 0;

    //For the closest unit to the cursor
    const int cursor_x = player.cursor_x+16;
    const int cursor_y = player.cursor_y+16;
    const int width = ZOOM_DIMENSIONS[zoom-1][0];
    bool found = false;

    bool hide_rivals = !city->isConflict() && WEST != allegiance; //if there is no conflict then rival units are placed 'face up' and not viewable by rivals
    for (const auto& unit : city->occupants[0]){ //west units
        if (unit_count % 5 == 0){
            target.y += off;
            offset = og_offset;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        if (!found && inBox(target.x+offset, target.y, width, width, cursor_x, cursor_y)){
            found = true;
            player.selected_unit = {city, unit};
        }
        offset += off;  unit_count++;
    }

    hide_rivals = !city->isConflict() && AXIS != allegiance;
    for (const auto& unit : city->occupants[1]){ //axis units
        if (unit_count % 5 == 0){
            target.y += off;
            offset = og_offset;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        if (!found && inBox(target.x+offset, target.y, width, width, cursor_x, cursor_y)){
            found = true;
            player.selected_unit = {city, unit};
        }
        offset += off; unit_count++;
    }

    hide_rivals = !city->isConflict() && USSR != allegiance;
    for (const auto& unit : city->occupants[2]){ //ussr units
        if (unit_count % 5 == 0){
            target.y += off;
            offset = og_offset;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        offset += off; unit_count++;
    }

    //always show neutral units (only forts)
    for (const auto& unit : city->occupants[3]){ //neutral units
        if (unit_count % 5 == 0){
            target.y += off;
            offset = og_offset;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom);
        offset += off; unit_count++;
    }
}

int Runner::getCitySprite(City* city){
    switch (city->population_type){
        case MAIN_CAPITAL:
            return 11 + city->city_type;
        case SUB_CAPITAL:
            return 5 + city->city_nationality;
        // Cities below don't have any change in colors
        default:
            return (city->city_type != WATER) + city->population_type;
    }


    return -1;
}

//&^ Extra board things

void Runner::drawInfluence(const Player& player){
    //- Draw influence at the capitals
    SDL_Rect target;
    const int& zoom = player.app->screen.zoom_factor;

    for (const auto& country : map.getCountries()){
        target = {player.app->screen.getX(country.second->capital->x), player.app->screen.getY(country.second->capital->y), 32*zoom, 32*zoom};

        if (country.second->influence_level == SATELLITES){ //draw one big token
            player.sprite_sheet->drawSprite(&target, 13, country.second->allegiance*2);
        }
        else{ //draw how many influnece token it has
            for (size_t i = 0; i < country.second->influence; i++){
                player.sprite_sheet->drawSprite(&target, 13, country.second->allegiance*2+1, 32, 32, zoom*16);
            }
        }
    }
}

void Runner::drawConnections(const Player& player){
    const auto& map = getMap();
    const auto& adjacency = getMap().getAdjacency();
    auto& renderer = player.app->renderer;
    for (size_t city=0; city < adjacency.size(); city++){
        for (size_t border=0; border < adjacency.size(); border++){
            if (adjacency[city][border] == 0) //no connection
                continue;

            auto& temp = adjacency[city][border];

            SDL_SetRenderDrawColor(renderer, BORDER_COLOR[temp][0], BORDER_COLOR[temp][1], BORDER_COLOR[temp][2], 255);

            City* start_city = map.getCity(city);
            City* end_city = map.getCity(border);
            SDL_RenderDrawLine(renderer, start_city->x + start_city->WIDTH/2, start_city->y+ start_city->HEIGHT/2, end_city->x+ end_city->WIDTH/2, end_city->y+ end_city->HEIGHT/2);
            SDL_RenderDrawLine(renderer, start_city->x-1 + start_city->WIDTH/2, start_city->y+1+ start_city->HEIGHT/2, end_city->x-1+ end_city->WIDTH/2, end_city->y+1+ end_city->HEIGHT/2);
            SDL_RenderDrawLine(renderer, start_city->x + start_city->WIDTH/2, start_city->y+1+ start_city->HEIGHT/2, end_city->x+ end_city->WIDTH/2, end_city->y+1+ end_city->HEIGHT/2);
        }
    }
}

void Runner::drawNumber(SDL_Renderer* renderer, int num, const int x, const int y, const float scale, const uint8_t r, const uint8_t g, const uint8_t b) const{
    int digits = 0;
    bool negative = num < 0;
    num = abs(num);
    auto copy = num;
    while (copy) {
        copy /= 10;
        digits++;
    }

    (negative)? SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255) : SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    if (digits == 0) //for drawing 0
        digits = 1;

    int offset = -(7*scale)/2;
    copy = num;

    SDL_Rect target;
    if (negative){ //Negatie Sign
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y+6*scale;
            offset += 8*scale;
            SDL_RenderFillRect(renderer, &target);
    }
    for (int i = 1; i <= digits; i++, offset += 8*scale){
        auto f = pow(10, digits-1);
        int digit = copy/f;
        copy -= digit * f;
        copy *= 10;

        if (SEVEN_SEGMENT_DISPLAY[digit][0]){ //A
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y;
            SDL_RenderFillRect(renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][1]){ //B
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+6*scale+offset;
            target.y = y+1*scale;
            SDL_RenderFillRect(renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][2]){ //C
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+6*scale+offset;
            target.y = y+7*scale;
            SDL_RenderFillRect(renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][3]){ //D
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y+12*scale;
            SDL_RenderFillRect(renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][4]){ //E
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+0*scale+offset;
            target.y = y+7*scale;
            SDL_RenderFillRect(renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][5]){ //F
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+0*scale+offset;
            target.y = y+1*scale;
            SDL_RenderFillRect(renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][6]){ //G
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y+6*scale;
            SDL_RenderFillRect(renderer, &target);
        }
    }


}

//&^ Cards

void Runner::drawActionCards(const Player* player, int start_x, int start_y, int count, int scale){
    int scaled_size = 32*scale;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};

    auto& sprite_sheet = player->sprite_sheet;

    size_t i;
    for (i = player->action_card_start; i < count && i < player->getActionSize(); i++){
        const auto& card = player->getActionCard(i);
        //- draw left
        sprite_sheet->drawSprite(&target, 15, card->sprite_offset_left, 32, 32, 0);

        //- draw base middle
        sprite_sheet->drawSprite( &target, 16, 0, 32, 32, scaled_size);

        //- draw season
        sprite_sheet->drawSprite( &target, 16, card->season-1, 32, 32);

        //- draw letter
        sprite_sheet->drawSprite( &target, 16, 4+card->letter-'A', 32, 32);

        //- draw number
        sprite_sheet->drawSprite(  &target, 16, 28+card->number, 32, 32);

        //- draw right
        sprite_sheet->drawSprite( &target, 15, card->sprite_offset_right, 32, 32, scaled_size);

        //is the popped card then draw select icon to the right of it
        if (player->popped_action_card_index == i){
            SDL_Rect target2 = {target.x + scaled_size + 3, target.y, 32,32};
            sprite_sheet->drawSprite(&target2, player->widget != ACTION_HAND, 0);
            
        }

        target.y += scaled_size;
        target.x = start_x;
    }

    //- Draw bought cards
    target.w=96;
    for (size_t j = 0; j < (count-i) && j < player->bought_action; j++){
        //- draw left
        sprite_sheet->drawSprite(&target, 15, 15, 96, 32, 0, -32, 0);

        target.y += scaled_size;
        target.x = start_x;
    }
}

void Runner::drawInvestCards(const Player* player, int start_x, int start_y, int count, int scale){
    int scaled_size = 32*scale;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};

    auto& sprite_sheet = player->sprite_sheet;

    //- Draw known cards in hands
    size_t i;
    for (i = player->invest_card_start; i < count && i < player->getInvestSize(); i++){ //TODO have it so the seasons are already imprinted on the back for one less call
        const auto& card = player->getInvestCard(i);
        //- draw left
        sprite_sheet->drawSprite(&target, 14, card->sprite_offset_left, 32, 32, 0);

        //- draw base factory cost
        sprite_sheet->drawSprite(&target, 14, 24+card->amount, 32, 32, scaled_size);

        //- draw right
        sprite_sheet->drawSprite(&target, 14, card->sprite_offset_right, 32, 32, scaled_size);

        //is the popped card then draw select icon to the right of it
        if (player->popped_invest_card_index == i){
            SDL_Rect target2 = {target.x - 99, target.y, 32,32};
            sprite_sheet->drawSprite(&target2, player->widget != INVEST_HAND, 1);
        }

        target.y += scaled_size;
        target.x = start_x;
    }   

    //- Draw bought cards
    target.w=96;
    for (size_t j = 0; j < (count-i) && j < player->bought_invest; j++){
        //- draw left
        sprite_sheet->drawSprite(&target, 15, 15, 96, 32, 0, -32, 0);

        target.y += scaled_size;
        target.x = start_x;
    }
}

//&&& Animations

void Runner::animateMessage(Player& player, PublicMessage& message, const Uint32& ticks){
    if (message.message <= USSR_PASSED){ //for passed messages there ar 10 frame that are to be done in 5000 ticks (500 ticks per frame)
        constexpr int ticks_per_frame = 250;
        SDL_Rect target = {player.app->screen.getCenterX()-50, 3, 100, 32};
        player.message_animation_sheets->drawSprite(&target, message.message, (ticks-message.start_tick)/ticks_per_frame, 100, 32);
        if ((ticks-message.start_tick)/ticks_per_frame >= 10) //if animation is done remove from vector
            public_messages.erase(std::find(public_messages.begin(), public_messages.end(), message));
    }
    else if (message.message == PRODUCTION_START){ //for production start there are 20 frames to be in 5000 ticks (250 ticks per frame)
        constexpr int ticks_per_frame = 500;
        SDL_Rect target = {player.app->screen.getCenterX()-80, 3, 160, 32};
        player.message_animation_sheets->drawSprite(&target, PRODUCTION_START, (ticks-message.start_tick)/ticks_per_frame, 160, 32);
        if ((ticks-message.start_tick)/ticks_per_frame >= 20) //if animation is done remove from vector
            public_messages.erase(std::find(public_messages.begin(), public_messages.end(), message));
    }
    else if (message.message == GOVERNMENT_START){ //for government start there are 25 frames to be in 7500 ticks (250 ticks per frame)
        constexpr int ticks_per_frame = 300;
        SDL_Rect target = {player.app->screen.getCenterX()-80, 3, 160, 32};
        player.message_animation_sheets->drawSprite(&target, GOVERNMENT_START, (ticks-message.start_tick)/ticks_per_frame, 160, 32);
        if ((ticks-message.start_tick)/ticks_per_frame >= 25) //if animation is done remove from vector
            public_messages.erase(std::find(public_messages.begin(), public_messages.end(), message));
    }
    else if (message.message == RESHUFFLE_START){ //for government start there are 27 frames to be in 7500 ticks (250 ticks per frame)
        constexpr int ticks_per_frame = 150;
        SDL_Rect target = {player.app->screen.getCenterX()-75, 3, 150, 32};
        player.message_animation_sheets->drawSprite(&target, RESHUFFLE_START, (ticks-message.start_tick)/ticks_per_frame, 150, 32);
        if ((ticks-message.start_tick)/ticks_per_frame >= 27) //if animation is done remove from vector
            public_messages.erase(std::find(public_messages.begin(), public_messages.end(), message));
    }
}

void Runner::animateReshuffle(const bool& running, const size_t& action_size, const size_t& invest_size, const Uint32& ticks){
    //- Draw all boards (will draw things over it)
    drawPhase(ticks);
}

void Runner::drawMemoResolution(const vector<std::array<size_t, 6>>& memo, vector<City*> unblocked){    
    /*for (const auto& city : unblocked){
        drawMap(players[WEST], true, true, false, false, false);
        size_t city_indx = city->ID;
        City* city_obj1 = map.getCity(city_indx);
        //printf("To link %s to the capital go: ", city->name.c_str());
        SDL_SetRenderDrawColor(powers_app[WEST].renderer, 225, 194, 20, 255);
        while (memo[city_indx][1] != 0){ //1 is previous
            //printf("%s [land:%d sea %d]to ", map.getCity(city_indx)->name.c_str(), (int)memo[city_indx][4], (int)memo[city_indx][5]);
            city_obj1 = map.getCity(city_indx);
            city_indx = memo[city_indx][1];
            drawLine(players[WEST], city_obj1,  map.getCity(city_indx));
        }
        //printf("%s .\n", map.getCity(city_indx)->name.c_str());
        SDL_RenderPresent(powers_app[WEST].renderer);
        SDL_Delay(1600);

    }*/
    
}

void Runner::drawMemoResolution(Player& player, const vector<std::array<size_t, 4>>& memo){
    //- Draw Map
    drawMap(player, true, true, false, false, false);
    SDL_SetRenderDrawColor(player.app->renderer, 225, 194, 20, 255);
    
    const int scale_x = player.app->screen.getXScale();
    const int scale_y = player.app->screen.getYScale();
    

    //-Go through and draw all connections in the memo since all of them can go through the og city and then to the supplier (draw all previouses)
    for (size_t city_indx = 0; city_indx < map.getNumCity(); city_indx++){
        if (memo[city_indx][0] && memo[city_indx][1]!= 0){ //vistited and if there is a prev from here (discount starting one from error)
            const int oldx=map.getCity(city_indx)->x*scale_x, oldy=map.getCity(city_indx)->y*scale_y;
            
            const int newx=map.getCity(memo[city_indx][1])->x*scale_x, newy=map.getCity(memo[city_indx][1])->y*scale_y;

            SDL_RenderDrawLine(player.app->renderer, oldx, oldy, newx, newy);
            //SDL_RenderDrawLine(player.app->renderer, oldx-1 + 16, oldy+1+ 16,   newx-1+ 16,newy+1+ 16);
            //SDL_RenderDrawLine(player.app->renderer, oldx + 16, oldy+1+ 16,     newx+ 16, newy+1+ 16);
        }
    }
    SDL_RenderPresent(player.app->renderer);
    SDL_Delay(1600);
}
void Runner::drawTurnRoll(const int& result){
    int scale = 5;
    int scaled_size = scale*32;
    SDL_Rect target = {app.screen.WIDTH/2-scaled_size/2, app.screen.HEIGHT/2-scaled_size/2, scaled_size, scaled_size};
    SDL_Event event;
    bool running = true;
    for (int i = 0; i < 50 && running; i ++){
        ClearScreen(app.renderer);
        sprite_map.drawSprite(&target, 12, i%6);
        SDL_RenderPresent(app.renderer);
        SDL_Delay(50);

        //- Player can skip cutscene
        if (SDL_PollEvent(&event)){
            switch (event.type) {

                case SDL_CONTROLLERBUTTONDOWN:{
                    if (event.cbutton.button == SDL_CONTROLLER_BUTTON_START){
                        ClearScreen(app.renderer);
                        return;
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
    
    ClearScreen(app.renderer);
    sprite_map.drawSprite(&target, 12, result-1);
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    target = {app.screen.WIDTH/2-(scale*96)/2, app.screen.HEIGHT/2-(scale*64)/2, (scale*96),(scale*64)};
    SDL_Rect target2 = {(target.x+5*scale), target.y+22*scale, scaled_size, scaled_size};
    SDL_Rect target3 = {target.x+38*scale, target.y+22*scale, scaled_size, scaled_size};
    SDL_Rect target4 = {target.x+71*scale, target.y+22*scale, scaled_size, scaled_size};

    //blank
    ClearScreen(app.renderer);
    sprite_map.drawSprite(&target, 5, 8, 96, 64);
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    //add first
    ClearScreen(app.renderer);
    sprite_map.drawSprite( &target, 5, 9, 96, 64);
    sprite_map.drawSprite( &target2, 0, 8+turn_order[0]->getAllegiance());
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    ClearScreen(app.renderer);
    sprite_map.drawSprite( &target, 5, 10, 96, 64);
    sprite_map.drawSprite( &target2, 0, 8+turn_order[0]->getAllegiance());
    sprite_map.drawSprite( &target3, 0, 8+turn_order[1]->getAllegiance());
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    ClearScreen(app.renderer);
    sprite_map.drawSprite( &target, 5, 11, 96, 64);
    sprite_map.drawSprite( &target2, 0, 8+turn_order[0]->getAllegiance());
    sprite_map.drawSprite( &target3, 0, 8+turn_order[1]->getAllegiance());
    sprite_map.drawSprite( &target4, 0, 8+turn_order[2]->getAllegiance());
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);
    

    for (int i = 0; i < 12; i++){
        ClearScreen(app.renderer);
        sprite_map.drawSprite( &target, 5, 8+i%4, 96, 64);
        sprite_map.drawSprite( &target2, 0, 8+turn_order[0]->getAllegiance());
        sprite_map.drawSprite( &target3, 0, 8+turn_order[1]->getAllegiance());
        sprite_map.drawSprite( &target4, 0, 8+turn_order[2]->getAllegiance());
        SDL_RenderPresent(app.renderer);
        SDL_Delay(200);
    }

    ClearScreen(app.renderer);

}
void Runner::drawPeaceDividends(const bool west, const bool axis, const bool ussr){
    int scale = 6;
    int scaled_size = scale*32/2;
    SDL_Rect target  = {(app.screen.WIDTH/2-(scale*96)/2), (app.screen.HEIGHT/2-(scale*64)/2), (scale*96), (scale*64)}, 
             target2 = {0, (app.screen.HEIGHT/2-(scale*64)/2)+scale*40, scaled_size, scaled_size},
             target_west = {target.x+46*scale,target.y+6*scale, 64, 64},
             target_axis = target_west,
             target_ussr = target_west;
    SDL_Event event;
    bool running = true, move = true;

    float offsetX1=target_west.x, offsetX2=target_axis.x, offsetX3=target_ussr.x;
    float offsetY=target_west.y;

    while (running){
        
        ClearScreen(app.renderer);

        //- Always draw the board
        sprite_map.drawSprite( &target, 5, 12, 96, 64);

        if (move){        
            offsetY += .88; // all decrease the same amount
            if (west){ //west need to be drawn and the peace chit
                //- Draw Peace Chit
                sprite_map.drawSprite( &target_west, 9, 0);
                offsetX1 -= .56;
                target_west.x = (int)offsetX1;
                target_west.y = (int)offsetY;
            }

            if (axis){ //west need to be drawn and the peace chit
                //- Draw Peace Chit
                sprite_map.drawSprite(&target_axis, 9, 0);
                offsetX2 -= .02;
                target_axis.x = (int)offsetX2;
                target_axis.y = (int)offsetY;
            }

            if (ussr){ //west need to be drawn and the peace chit
                //- Draw Peace Chit
                sprite_map.drawSprite( &target_ussr, 9, 0);
                offsetX3 += .51;
                target_ussr.x = (int)offsetX3;
                target_ussr.y = (int)offsetY;
            }

            //- Check for when main animation is done
            if (offsetY > target.y+42*scale){
                running = false;
                target_west = target;
            }
        }

        if (west) {target2.x = app.screen.WIDTH/2-(scale*96)/2 + scale*18; sprite_map.drawSprite(&target2, 13, 0);}
        if (axis) {target2.x = app.screen.WIDTH/2-(scale*96)/2 + scale*41; sprite_map.drawSprite(&target2, 13, 2);}
        if (ussr) {target2.x = app.screen.WIDTH/2-(scale*96)/2 + scale*63; sprite_map.drawSprite( &target2, 13, 4);}

        SDL_RenderPresent(app.renderer);

        //- Player can skip cutscene
        if (SDL_PollEvent(&event)){
            switch (event.type) {

                case SDL_KEYDOWN:{
                    running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
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

}