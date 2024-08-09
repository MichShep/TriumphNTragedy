#include "Runner.h"


//& SDL Routines

bool Runner::InitSDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;
    }

    SDL_GameControllerEventState(SDL_ENABLE);
    
    //030000000d0f0000f600000001000000,Lic Pro Controller,a:b0,b:b1,x:b2,y:b3,back:b8,guide:b12,start:b9,leftshoulder:b4,rightshoulder:b5,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,lefttrigger:b6,righttrigger:b7,platform:Mac OS X
    
    int joysticks_found=offset;
    for (int i = 0; i < SDL_NumJoysticks() && joysticks_found != 3; i++){
        if (SDL_IsGameController(i)){
            controllers[joysticks_found++] = SDL_GameControllerOpen(i);
            const auto s = SDL_GameControllerName(controllers[joysticks_found]);
            if  (s)
                cout << s << endl;
        }
    }
    if (controllers[0] == nullptr){
        cout << "West controller not connected" << endl;
        //exit(1);
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

bool Runner::InitFonts(){
    west_player->app->font1 = FC_CreateFont();
    axis_player->app->font1 = FC_CreateFont();
    ussr_player->app->font1 = FC_CreateFont();

    FC_LoadFont(west_player->app->font1, west_player->app->renderer, "./fonts/StayPixelRegular-EaOxl.ttf", 40, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);
    FC_LoadFont(axis_player->app->font1, axis_player->app->renderer, "./fonts/StayPixelRegular-EaOxl.ttf", 40, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);
    FC_LoadFont(ussr_player->app->font1, ussr_player->app->renderer, "./fonts/StayPixelRegular-EaOxl.ttf", 40, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);

    return true;
 }

bool Runner::InitApplication(){
    //- Init SDL
    if (InitSDL() == false){
        ShutdownApplication();
        return false;
    }

    constexpr int my_screen_width = 1512;
    constexpr int my_screen_height = 916;


    //- Init main app
    //SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);

    //- Init axis app
    powers_app[AXIS].window = SDL_CreateWindow(
        "Axis Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        my_screen_width,
        my_screen_height, 
        SDL_WINDOW_OPENGL
    );

    //- Init ussr app
    powers_app[USSR].window = SDL_CreateWindow(
        "USSR Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        my_screen_width,
        my_screen_height, 
        SDL_WINDOW_OPENGL
    );

    //- Init west app
    powers_app[WEST].window = SDL_CreateWindow(
        "West Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        my_screen_width,
        my_screen_height, 
        SDL_WINDOW_OPENGL
    );

    //SDL_SetWindowFullscreen(powers_app[WEST].window, SDL_TRUE);
    SDL_SetWindowFullscreen(powers_app[USSR].window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(powers_app[AXIS].window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(powers_app[WEST].window, SDL_WINDOW_FULLSCREEN_DESKTOP);

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

        SDL_SetRenderDrawBlendMode(a.renderer, SDL_BLENDMODE_BLEND);
    }


    return true;
}

void Runner::ShutdownApplication(){
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

void Runner::ClearScreen(SDL_Renderer* renderer) const{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if (SDL_RenderClear(renderer) < 0){
        cout << "SDL_RenderClear failed with error: " << SDL_GetError() << endl;
    }
}

//& Graphics
//&^ Drawing Player board

void Runner::drawPlayerBoard(Player& player, const bool render){
    //- check limited time things
    for (auto& peak_tick : player.peak_ticks){
        if (clock-peak_tick > 25000U){
            peak_tick = 0;
        }
    }

    if (clock - player.unit_peak_tick > 15000U){
        player.unit_peak_tick = 0;
        player.peaked_unit = {nullptr, nullptr};
    }

    //- Draw the map and the cities
    drawMap(player, true, true, true, false, false);

    auto& sprite_sheet = player.sprite_sheet;
    
    //- Draw the current state of the cards
    //- Draw the current state of the action cards
    drawActionWidget(player, players[player.action_view]);
    
    //- Draw the current state of the invest cards
    drawInvestWidget(player, players[player.invest_view]);
 
    //- Draw the techs
    drawTechWidget(player, players[player.tech_view]);

    //- Draw the player stats
    drawStatWidget(player, players[player.stat_view]);

    //- Draw movement trail
    if (player.combat_phase == MOVEMENT && player.movement_memo.size() > 1){
        for (int i = 1; i < player.movement_memo.size(); i++){
            drawLine(player, player.movement_memo[i-1], player.movement_memo[i], false);
        }
    }

    //- Draw the build UI
    if (season == PRODUCTION)
        drawBuild(player);

    //- Draw the selection wheel for battle
    else if (player.combat_phase == COMBAT_BATTLE_SELECT)
        drawBattleSelect(player);

    //- Draw the combat widget
    else if (current_battle.first)
        drawCombatWidget(player);

    //- Draw Turn Order
    drawTurnOrder(player);

    //- Draw the selected countries
    if (player.popped_action_card != nullptr && player.popped_action_card->type == DIPLOMACY){
        if (player.show_left_country) drawCity(player, player.popped_left_country->x, player.popped_left_country->y, player.popped_left_country->population_type);
        if (player.show_right_country) drawCity(player, player.popped_right_country->x, player.popped_right_country->y, player.popped_right_country->population_type);
    }

    drawSeasonSpecific(player);

    //- Draw the current actions avialable
    drawActionButtons(player);

    //- Update Public Messages
    for (auto& message : public_messages){
        animateMessage(player, message);
    }    

    //- draw Public Animations
    for (auto& animation : public_animations){
        animation.animate(player, clock);
    }

    //- Draw all cursor's
    for (const auto& cursor : players){
        SDL_Rect cursor_target;
        if (&cursor == &player)
            cursor_target = {(int)cursor.cursor_x, (int)cursor.cursor_y, 34, 34};
        else
            cursor_target = {player.app->screen.getX((int)cursor.cursor_x+cursor.app->screen.zoom_x), player.app->screen.getY((int)cursor.cursor_y+cursor.app->screen.zoom_y), 34, 34};
        sprite_sheet->drawSprite(&cursor_target, 0, 10+cursor.getAllegiance(), 34, 34);
    }

    //DEV fps
    drawNumber(player.app->renderer, fps, player.app->screen.WIDTH/2, 0, 4, 0, 0, 0, 200);

    if (render)
        SDL_RenderPresent(player.app->renderer);
}

void Runner::drawMap(Player& player, const bool cities, const bool influence, const bool resources, const bool connections, const bool clear){
    int width, height;
    SDL_GetWindowSize(player.app->window, &width, &height);
    SDL_Rect tar = {0, 0, width, height};
    player.map_sprite->drawSprite(&tar, 0, 0, (int)(1512/player.app->screen.zoom_factor), (int)(982/player.app->screen.zoom_factor), 0, player.app->screen.zoom_x, player.app->screen.zoom_y);

    if (connections)
        drawConnections(player);

    if (cities){
        auto& cities = map.getCities();
        for (auto& city : cities)
            drawCity(player, city.second, resources);

        //draw all current battles
        int i = 0;
        Target target = {0, 0, 23*player.zoom, 23*player.zoom};
        for (auto& city : battles){
            target.x = player.app->screen.getX(city.first->x);
            target.y = player.app->screen.getY(city.first->y);
            player.sprite_sheet->drawSprite(&target, 0, 21+city.second, 23, 23);
            drawNumber(player.app->renderer, ++i, target.x, target.y, 3, 0, 0, 0);
        }

        //draw peaked unit if there is one
    }

    if (influence){
        drawInfluence(player);
    }

    if (clear)
        SDL_RenderPresent(player.app->renderer);
}

void Runner::drawBuild(Player& player) const{
    //- If one is selected
    if (nullptr != player.selecting_city){
        const auto& city = player.selecting_city;
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
        if (player.unit_available[0]) drawUnit(player, FORTRESS, city->ruler_nationality, center_x, center_y-radius, zoom); //top

        if (player.unit_available[1]) drawUnit(player, AIR, city->ruler_nationality, center_x+sqrt_radius, center_y-sqrt_radius, zoom); //top right

        if (player.unit_available[2]) drawUnit(player, CARRIER, city->ruler_nationality, center_x+radius, center_y, zoom); //right

        if (player.unit_available[3]) drawUnit(player, SUB, city->ruler_nationality, center_x+sqrt_radius, center_y+sqrt_radius, zoom); //bottom right

        if (player.unit_available[4]) drawUnit(player, FLEET, city->ruler_nationality, center_x, center_y+radius, zoom); //bottom

        if (player.unit_available[5]) drawUnit(player, TANK, city->ruler_nationality, center_x-sqrt_radius, center_y+sqrt_radius, zoom); //bottom left

        if (player.unit_available[6]) drawUnit(player, INFANTRY, city->ruler_nationality, center_x-radius, center_y, zoom); //left

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
            if (player.wheel_selection[0] != 7)
                drawUnit(player, (UnitType)(player.wheel_selection[0]+7), city->ruler_nationality, center_x+sqrt_radius*player.wheel_selection[1], center_y+sqrt_radius*player.wheel_selection[2], zoom, !player.unit_available[(int)player.wheel_selection[0]]); //left
            else{
                target = {(int)(center_x+sqrt_radius*player.wheel_selection[1]), (int)(center_y+sqrt_radius*player.wheel_selection[2]), ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][0]};
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
        drawCity(player, player.selecting_city, true);
    }
}

void Runner::drawBattleSelect(Player& player) const{
    if (nullptr != player.selecting_city){
        const auto& city = player.selecting_city;
        const auto& targets = player.unit_available;
        //const auto& sprite_sheet = player.sprite_sheet;
        const int& zoom = player.zoom;
        const int center_x = player.app->screen.getX(city->x+(city->WIDTH/2))-ZOOM_DIMENSIONS[zoom-1][0]/2;
        const int center_y = player.app->screen.getY(city->y+((city->HEIGHT/2)))-ZOOM_DIMENSIONS[zoom-1][0]/2;
        const int real_center_x = player.app->screen.getX(city->x+(city->WIDTH/2));
        const int real_center_y = player.app->screen.getY(city->y+(city->HEIGHT/2));
        const int radius = 40*zoom;

        //-Draw the selection line if there is one
        if (player.wheel_x != 0 && player.wheel_y != 0){
            drawLine(player, real_center_x, real_center_y, real_center_x+player.wheel_x*radius, real_center_y+player.wheel_y*radius); //city middle to the wheel coords
        }

        Target target = {0, 0, 23*player.zoom, 23*player.zoom};
        if (targets[WEST]){
            target.x = center_x;
            target.y = center_y-radius;
            player.sprite_sheet->drawSprite(&target, 0, 21, 23, 23);
        }

        if (targets[AXIS]){
            target.x = center_x+radius;
            target.y = center_y;
            player.sprite_sheet->drawSprite(&target, 0, 22, 23, 23);
        }

        if (targets[USSR]){
            target.x = center_x;
            target.y = center_y+radius;
            player.sprite_sheet->drawSprite(&target, 0, 23, 23, 23);
        }

        if (targets[NEUTRAL]){
            target.x = center_x-radius;
            target.y = center_y;
            player.sprite_sheet->drawSprite(&target, 0, 24, 23, 23);
        }

        //- Draw the closest or 'popped country(under unit)'
        if (player.wheel_x != 0 && player.wheel_y != 0){
            if (player.unit_available[(int)(player.wheel_selection[0]/2)] && (player.wheel_selection[0] == 0 ||  player.wheel_selection[0] == 2 || player.wheel_selection[0] == 4 || player.wheel_selection[0] == 6)){
                target.x = center_x+player.wheel_selection[1]*radius/1.4;
                target.y = center_y+player.wheel_selection[2]*radius/1.4;
                player.sprite_sheet->drawSprite(&target, 1, 21+player.wheel_selection[0]/2, 23, 23);
            }
        }
    }
}

//&^ Widgets

void Runner::drawActionWidget(Player& drawing_player, Player& target_player) const{
    //for sprite sheet
    auto& sprite_sheet = drawing_player.sprite_sheet;
    constexpr int row = 7;
    const int start_pos = target_player.getAllegiance()*6;

    const int y = drawing_player.app->screen.HEIGHT-105;
    
    SDL_Rect target = {3, y, 102, 102};
    if (drawing_player.show_action){ //draw all the action cards
        if (drawing_player.getActionSize()+drawing_player.bought_action > 0){

            //- calcualte how many cards need to be shown and draw background (max amount will be 15)
            const int num_card = SDL_clamp(target_player.getActionSize()+ (&target_player == &drawing_player? target_player.bought_action : 0), 0, 15);
            const int holder_size = num_card*32;

            //- Draw the opening icon
            sprite_sheet->drawSprite(&target, row, start_pos+1, 102, 102);

            //- Draw outline
            target = {3, y-holder_size, 102, holder_size};
            sprite_sheet->drawSprite(&target, row, start_pos+2, 102, 102);
            target = {3, y-holder_size, 102, 102};
            sprite_sheet->drawSprite(&target, row, start_pos+2, 102, 102);

            //- Draw the cards
            if (&target_player == &drawing_player || drawing_player.peak_ticks[target_player.getAllegiance()]){ //if the target player is the target player 
                drawActionCards(&drawing_player, &target_player, 6, y-holder_size+3, 15);
            }
            else{
                target = {6, y-holder_size+3, 96, 32};
                for (int i = 0; i < num_card; i++){
                    sprite_sheet->drawSprite(&target, 15, 15, 96, 32, 0, -32, 0);
                    if (drawing_player.popped_action_card_index == i){
                        SDL_Rect target2 = {target.x + 99, target.y, 32,32};
                        sprite_sheet->drawSprite(&target2, drawing_player.widget != ACTION_HAND, 0);
                    }   
                    target.y += 32;
                }
            }   
            
        }
        else{
            target.y = drawing_player.app->screen.HEIGHT-204;
            sprite_sheet->drawSprite(&target, row, start_pos+2, 102, 102, 0, 0, -50);

            target.y = y;
            sprite_sheet->drawSprite(&target, row, start_pos+1, 102, 102);
        }        
    }
    else{ //draw just the icon
        sprite_sheet->drawSprite(&target, row, start_pos+0, 102, 102);
    }

    //if cards aren't selected yet then show arrow pointing to the base if its selected
    if (drawing_player.widget == ACTION_HAND && drawing_player.popped_action_card_index == -1){
        target = {105, y+32, 32, 32};
        sprite_sheet->drawSprite(&target,0,0);
    }

}

void Runner::drawInvestWidget(Player& drawing_player, Player& target_player) const{
    const int y = drawing_player.app->screen.HEIGHT-105;

    auto& sprite_sheet = drawing_player.sprite_sheet;
    constexpr int row = 7;
    const int start_pos = target_player.getAllegiance()*6;

    SDL_Rect target = {drawing_player.app->screen.WIDTH-105, y, 102, 102};
    const int x = target.x;
    if (drawing_player.show_invest){ //draw all the invest cards
        if (target_player.getInvestSize()+target_player.bought_invest > 0){
            //- calcualte how many cards need to be shown and draw background (max amount will be 15)
            const int num_card = SDL_clamp(target_player.getInvestSize()+(&target_player == &drawing_player? target_player.bought_invest : 0), 0, 15);
            const int holder_size = num_card*32;
            
            //- Draw the opening icon
            sprite_sheet->drawSprite(&target, row, start_pos+4, 102, 102);

            //- draw the outline
            target = {x, y-holder_size, 102, holder_size};
            sprite_sheet->drawSprite(&target, row, start_pos+5, 102, 102);
            target = {x, y-holder_size, 102, 102};
            sprite_sheet->drawSprite(&target, row, start_pos+5, 102, 102);

            //- Draw the cards
            if (&target_player == &drawing_player){ //the player IS that player or they are peaking at the target players hand
                drawInvestCards(&target_player, x+3, y-holder_size+3, 15);
            }
            else{
                target = { x+3, y-holder_size+3, 96, 32};
                for (int i = 0; i < num_card; i++){
                    sprite_sheet->drawSprite(&target, 15, 15, 96, 32, 0, -32, 0);

                    if (drawing_player.popped_invest_card_index == i){
                        SDL_Rect target2 = {target.x -35, target.y, 32,32};
                        sprite_sheet->drawSprite(&target2, drawing_player.widget != INVEST_HAND, 1);
                    }   
                    target.y += 32;
                }
            }
        }
        else{
            target.y = drawing_player.app->screen.HEIGHT-204;
            sprite_sheet->drawSprite(&target, row, start_pos+5, 102, 102, 0, 0, -50);

            target.y = y;
            sprite_sheet->drawSprite(&target, row, start_pos+4, 102, 102);
        }
    }
    else{
        sprite_sheet->drawSprite(&target, row, start_pos+3, 102, 102);
    }
    if (drawing_player.widget == INVEST_HAND && drawing_player.popped_invest_card_index == -1){
        target = {drawing_player.app->screen.WIDTH-137, y+32, 32, 32};
        sprite_sheet->drawSprite(&target,0,1);
    }
}

void Runner::drawTechWidget(Player& drawing_player, Player& target_player) const{
    auto& sprite_sheet = drawing_player.sprite_sheet;

    const int y2 = drawing_player.app->screen.HEIGHT - 41;
    SDL_Rect target = {drawing_player.app->screen.WIDTH-167, y2, 38, 38};
    const int viewed_allegiance = drawing_player.tech_view;
    
    if (drawing_player.show_tech){//(player.show_tech){
        if (players[viewed_allegiance].getTechSize() > 0){
            sprite_sheet->drawSprite(&target, 16, 18+viewed_allegiance*3, 38, 38); //- Draw opening button icon

            const int holder_size = std::min(players[viewed_allegiance].getTechSize(), 7)*32; //-draw holding area
            target = {target.x, y2-holder_size, 38, holder_size};
            sprite_sheet->drawSprite(&target, 16, 19+viewed_allegiance*3, 38, 38);

            target = {target.x, y2-holder_size, 38, 38}; //-draw the top
            sprite_sheet->drawSprite(&target, 16, 19+viewed_allegiance*3, 38, 38);

            drawAchievedTech(&drawing_player, &target_player, target.x+3, y2-29); //- draw techs
        }
        else{
            sprite_sheet->drawSprite(&target, 16, 18+viewed_allegiance*3, 38, 38); //- Draw opening button icon
            target = {target.x, y2-30, 38, 38}; //-draw the top
            sprite_sheet->drawSprite(&target, 16, 19+viewed_allegiance*3, 38, 38);
        }
        
    }
    else{
        sprite_sheet->drawSprite(&target, 16, 17+viewed_allegiance*3, 38, 38); //- Draw closed button icon
    }
    if (drawing_player.widget == TECH_HAND && drawing_player.popped_tech_index == -1){
        target = {drawing_player.app->screen.WIDTH-167-32, y2+3, 32, 32};
        sprite_sheet->drawSprite(&target,0,1);
    }
}

void Runner::drawStatWidget(Player& drawing_player, Player& target_player) const{
    auto& sprite_sheet = drawing_player.sprite_sheet;

    const int x = 140;
    const int y = drawing_player.app->screen.HEIGHT-73;

    const int viewed_allegiance = target_player.getAllegiance();
    
    SDL_Rect target;
    if (drawing_player.show_stat){
        target = {x , y, 307, 70};
        //- Draw the whole icon
        sprite_sheet->drawArea(&target, 70+410*viewed_allegiance, 840, 307, 70); 

        //- Draw pop number
        drawNumber(drawing_player.app->renderer, target_player.getPopulation(), x+77, y+24, 2);

        //- Draw ind number
        drawNumber(drawing_player.app->renderer, target_player.getIndustry(), x+126, y+24, 2);

        //- Draw Res
        drawNumber(drawing_player.app->renderer, target_player.getResource(), x+173, y+24, 2);

        //- Draw Dow 1
        target = {x+214 , y+7, 27, 27};
        sprite_sheet->drawArea(&target, getDoWOffset(target_player, 0)*27, 910, 27, 27); 

        //- Draw Dow 2
        target = {x+214 , y+36, 27, 27};
        sprite_sheet->drawArea(&target, getDoWOffset(target_player, 1)*27, 910, 27, 27); 

        //- draw cursor
        if (drawing_player.widget == STAT_WIDGET){
            target = {x+((target_player == WEST)? 307 : 270),y+19, 32, 32};
            sprite_sheet->drawSprite(&target,0,0);  
        }
    }
    else{
        target = {x, y, 70, 70};
        sprite_sheet->drawSprite(&target, 12, 0, 70, 70, 0, 410*viewed_allegiance); //- Draw closed button icon

        //- draw cursor
        if (drawing_player.widget == STAT_WIDGET){
            target = {x+70,y+19, 32, 32};
            sprite_sheet->drawSprite(&target,0,0);  
        }
    }  
}

void Runner::drawActionButtons(const Player& player) const{
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
            //3500 total clock for loading and 35 animation frames, so every 100 clock is another frame
            player.controller_button_sprites->drawSprite(&target_x, 0, 1+(clock-player.x_held_tick) / 100 , 45, 48);
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
                // 1200 total clock to hold y with 6 frames so every 200 clock is a frame
                player.controller_button_sprites->drawSprite(&target_y, 1, 1+(clock-player.y_held_tick) / 200, 45, 48);
            }
            else{ //or add one
                player.controller_button_sprites->drawSprite(&target_y, 1, 1, 45, 48);
            }

        }
        else if (player.widget == INVEST_HAND && player.show_invest){
            if (player.y_held_tick > 0){ //delete cards
                // 1200 total clock to hold y with 6 frames so every 200 clock is a frame
                player.controller_button_sprites->drawSprite(&target_y, 1, 10+(clock-player.y_held_tick) / 200, 45, 48, 0, -1);
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
        
        else if (player.wheel_selection[0] != 7 && player.unit_available[(int)player.wheel_selection[0]]){ //if a unit is popped and is buildable show option to build
            player.controller_button_sprites->drawSprite(&target_b, 2, 1, 45, 48);
        }

        else{ //all else show default B button
            player.controller_button_sprites->drawSprite(&target_b, 2, 0, 45, 48);
        }

    }
    else{
        const uint8_t alpha = inBox(top_left_x, top_left_y, 104, 110, player.cursor_x, player.cursor_y)? 200: 255;
        target_x.w = 40;
        target_y.w = 40;
        target_a.w = 40;
        target_b.w = 40;

        player.sprite_sheet->drawArea(&target_x, 40*(player.x_held_tick>0), 190, 40, 48, alpha); //x

        player.sprite_sheet->drawArea(&target_y, 80+40*(player.y_held_tick>0), 190, 40, 48, alpha); //y
        
        player.sprite_sheet->drawArea(&target_a, 160+40*(player.a_held_tick>0), 190, 40, 48, alpha); //a

        player.sprite_sheet->drawArea(&target_b, 240+40*(player.b_held_tick>0), 190, 40, 48, alpha); //b
        
    }

}

void Runner::drawTurnOrder(const Player& player) const{
    auto& sprite_sheet = player.sprite_sheet;
    //- draw the actual turn order
    SDL_Rect turn_order_target = {3, 3, 124, 38};
    sprite_sheet->drawSprite(&turn_order_target, 3, 0, 124, 38);
    if (turn_order[0] != nullptr){
        if (season >= SPRING_COMMAND){
            turn_order_target = {6, 6, 32, 32};
            sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[0]->passed?  turn_order[0]->getAllegiance()+ 8 : turn_order[0]->getAllegiance()*2);
            
            turn_order_target = {49, 6, 32, 32};
            sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[1]->passed?  turn_order[1]->getAllegiance()+ 8 : turn_order[1]->getAllegiance()*2);
            
            turn_order_target = {92, 6, 32, 32};
            sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[2]->passed?  turn_order[2]->getAllegiance()+ 8 : turn_order[2]->getAllegiance()*2);
        }
        else if (season <= WINTER){
            if (turn_order[0]->getCommandNumber() != -1){
                turn_order_target = {6, 6, 32, 32};
                sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[0]->getAllegiance()*2+turn_order[0]->passed);
            }
            if (turn_order[1]->getCommandNumber() != -1){
                turn_order_target = {49, 6, 32, 32};
                sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[1]->getAllegiance()*2+turn_order[1]->passed);
            }
            if (turn_order[2]->getCommandNumber() != -1){
                turn_order_target = {92, 6, 32, 32};
                sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[2]->getAllegiance()*2+turn_order[2]->passed);
            }
        }
        else{
            turn_order_target = {6, 6, 32, 32};
            sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[0]->getAllegiance()*2+turn_order[0]->passed);
            turn_order_target = {49, 6, 32, 32};
            sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[1]->getAllegiance()*2+turn_order[1]->passed);
            turn_order_target = {92, 6, 32, 32};
            sprite_sheet->drawSprite(&turn_order_target, 2, turn_order[2]->getAllegiance()*2+turn_order[2]->passed);
        }
    }
    //- highlight current acting player
    if (season == GOVERNMENT || season >= SPRING_COMMAND){
        turn_order_target = {6+current_index*43,6 ,32,32};
        sprite_sheet->drawSprite(&turn_order_target, 2, 7);
    }
    //- draw which phase in game
    turn_order_target = {3, 44, 124, 38};
    if (season > WINTER) //all other phases
        sprite_sheet->drawSprite(&turn_order_target, 3, season-4, 124, 38);
    else if (season <= WINTER) //for actual seasons
        sprite_sheet->drawSprite(&turn_order_target, 3, season+8, 124, 38);
    else
        sprite_sheet->drawSprite(&turn_order_target, 3, season+SPRING_COMMAND-4, 124, 38);

    //- draw the year 
    turn_order_target = {3+124/2 - 32, 44+38+3-15, 66, 24};
    sprite_sheet->drawSprite(&turn_order_target, 13, year-1936, 33, 12);

}

void Runner::drawSeasonSpecific(Player& player) const{
    switch (season){
        case SPRING_COMMAND:
        case SUMMER_COMMAND:
        case FALL_COMMAND:{
            if (west_player->passed && axis_player->passed &&  ussr_player->passed)
                return;

            //- Draw holder board
            const int x = (player.app->screen.WIDTH-640)/2;
            
            const int y = -50+112;
            //{16+x, 224+x, 432+x};
            auto& sprite_sheet = player.sprite_sheet;
            SDL_Rect target = {x, y-112, 640, 192};
            const int alpha = inBox(player.cursor_x, player.cursor_y, &target)? 100: 255;

            sprite_sheet->drawArea(&target, 0, 576, 320, 96, alpha); 

            //- Draw west card
            if (west_player->passed){
                target = {16+x, y, 96*2, 64};
                sprite_sheet->drawArea(&target, 0, 672, 96, 32, alpha);
            }
            if (west_player->getCommandNumber() != -1){ //
                if (&player == west_player){
                    if (player.command_fake != nullptr){
                        drawInvestCard(&player, player.command_fake, x+16, y, 64, alpha);
                    }
                    else{
                        drawActionCard(&player, player.command_card, x+16, y, 64, alpha);
                    }
                }
                else{
                    target = {x+16, y, 192, 64};
                    sprite_sheet->drawArea(&target, 1408, 480, 96, 32, alpha); 
                }
            }

            if (axis_player->passed){
                target = {224+x, y, 96*2, 64};
                sprite_sheet->drawArea(&target, 0, 672, 96, 32, alpha);
            }
            if (axis_player->getCommandNumber() != -1){
                if (&player == axis_player){
                    if (player.command_fake != nullptr){
                        drawInvestCard(&player, player.command_fake, x+224, y, 64, alpha);
                    }
                    else{
                        drawActionCard(&player, player.command_card, x+224, y, 64, alpha);
                    }
                }
                else{
                    target = {x+224, y, 192, 64};
                    sprite_sheet->drawArea(&target, 1408, 480, 96, 32, alpha); 
                }

            }

            if (ussr_player->passed){
                target = {432+x, y, 96*2, 64};
                sprite_sheet->drawArea(&target, 0, 672, 96, 32, alpha);
            }
            if (ussr_player->getCommandNumber() != -1){
                if (&player == ussr_player){
                    if (player.command_fake != nullptr){
                        drawInvestCard(&player, player.command_fake, x+432, y, 64, alpha);
                    }
                    else{
                        drawActionCard(&player, player.command_card, x+432, y, 64, alpha);
                    }
                }
                else{
                    target = {x+432, y, 192, 64};
                    sprite_sheet->drawArea(&target, 1408, 480, 96, 32, alpha); 
                }
            }

            break;
        }        
        
        default:
            break;
    }
    switch (player.combat_phase){
        case MOVEMENT:{
            //draw how many unit movements they have left
            Target target = {player.app->screen.WIDTH-110, 
                                                      -30 + (int)(2*sin((1/800.0)*clock+25000)),
                                                       107, 300};

            const uint8_t alpha = inBox((int)player.cursor_x, (int)player.cursor_y, &target)? 200: 255;

            player.sprite_sheet->drawArea(&target, 1836, 616, 107, 300, alpha);

            const uint8_t red = (player.getCommandNumber() != 0)*255;
            drawNumber(player.app->renderer, player.getCommandNumber(), target.x+50, target.y+210, 5, 255, red, red, alpha);

            break;
        }        
        default:
            //if (current_battle.first != nullptr)
              //  drawCombatWidget(player);
            break;
    }
}

//&^ Combat Widget

void Runner::drawCombatWidget(Player& player) const{
    if (player.show_combat){
        // Draw the 'rug' (aka units and fire order)
        drawCombatRug(player);

        // Draw highlight if players widet is combat
        if (player.widget == COMBAT_WIDGET){
            SDL_SetRenderDrawColor(player, 255, 193, 7, 255);
            Target outline = {player.app->screen.WIDTH/2-750/2, player.app->screen.HEIGHT-250, 750, 251};
            SDL_RenderDrawRect(player, &outline);
        }

        //COMBAT_BATTLE_SELECT,
        //COMBAT_ACTION_SELECT,
        //COMBAT_TYPE_SELECT

        // Draw the current actions of the player
        switch (player.combat_phase){
            case COMBAT_ACTION_SELECT:
                drawCombatActionSelect(player);
                break;
            case COMBAT_CLASS_SELECT:
                drawCombatTypeSelect(player);
                break;
            case COMBAT_DEAL_HITS:
                drawCombatDealHits(player);
                break;
            
            default:
                break;
        }
    }
    else{ //just show the dropdown bar thing
        Target target = {player.app->screen.WIDTH/2-750/2, player.app->screen.HEIGHT-60, 750, 68};
        player.sprite_sheet->drawArea(&target, 1017, 1606, 750, 68);
        
        if (player.widget == COMBAT_WIDGET){
            SDL_SetRenderDrawColor(player, 255, 193, 7, 255);
            SDL_RenderDrawRect(player, &target);
        }
    }
}

void Runner::drawCombatActionSelect(Player& player) const{
    const auto& sprite_sheet = player.sprite_sheet;
    Target target = {player.app->screen.WIDTH/2-750/2, player.app->screen.HEIGHT-250, 750, 250};

    //draw selction line
    constexpr int radius = 45;
    const int center_x = 376;
    const int center_y = 91;
    if (player.wheel_x != 0 && player.wheel_y != 0){
        drawLine(player, target.x+center_x, target.y+center_y, target.x+center_x+player.wheel_x*radius, target.y+center_y+player.wheel_y*radius); //city middle to the wheel coords
    }


    // draw fire button
    const auto& select = player.wheel_selection[0];
    Target button_target = {target.x+275, target.y+31, 203, 43};
    if (select==0 || (select == 7 && player.wheel_x != 0) || select == 1) // if selected
        sprite_sheet->drawArea(&button_target, 1236+203, 1028, 203, 43);
    else{ //if not selected
        button_target.y += 5*cos((1/600.0)*clock+15000);
        sprite_sheet->drawArea(&button_target, 1236, 1028, 203, 43);
    }

    //draw retreat button
    button_target.y = target.y+109;
    if (select==4 || select == 5 || select == 3) // if selected
        sprite_sheet->drawArea(&button_target, 1236+203, 1071, 203, 43);
    else{ //if not selected
        button_target.y -= 5*cos((1/600.0)*clock+20000);
        sprite_sheet->drawArea(&button_target, 1236, 1071, 203, 43);
    }
}

void Runner::drawCombatTypeSelect(Player& player) const{
    const auto& sprite_sheet = player.sprite_sheet;
    Target target = {player.app->screen.WIDTH/2-750/2, player.app->screen.HEIGHT-250, 750, 250};

    //draw selction line
    constexpr int radius = 45;
    const int center_x = 376;
    const int center_y = 91;
    if (player.wheel_x != 0 && player.wheel_y != 0){
        drawLine(player, target.x+center_x, target.y+center_y, target.x+center_x+player.wheel_x*radius, target.y+center_y+player.wheel_y*radius); //city middle to the wheel coords
    }

    Target unit_class = {-1, -1, 43, 43};
    
    const auto& select = player.wheel_selection[0];
    if (player.unit_available[CLASS_A]){
        unit_class.x = target.x+353;
        unit_class.y = target.y+22 + ((select == 0)? 0 : 5*cos((1/600.0)*clock+15000));
        sprite_sheet->drawArea(&unit_class, 1642, 1028 + (select == 0)*43, 43, 43);
    }

    if (player.unit_available[CLASS_N]){
        unit_class.x = target.x+408;
        unit_class.y = target.y+76 + ((select == 2)? 0 : 5*sin((1/600.0)*clock+38470));
        sprite_sheet->drawArea(&unit_class, 1685, 1028 + (select == 2)*43, 43, 43);
    }

    if (player.unit_available[CLASS_G]){
        unit_class.x = target.x+353;
        unit_class.y = target.y+133 + ((select == 4)? 0 : 5*cos((1/600.0)*clock+204540));
        sprite_sheet->drawArea(&unit_class, 1728, 1028 + (select == 4)*43, 43, 43);
    }

    if (player.unit_available[CLASS_S]){
        unit_class.x = target.x+297;
        unit_class.y = target.y+ 76 + ((select ==6)? 0 : 5*cos((1/600.0)*clock+100));
        sprite_sheet->drawArea(&unit_class, 1771, 1028 + (select == 6)*43, 43, 43);
    }

}

void Runner::drawCombatDealHits(Player& player) const{
    //draw simple messge telling them what to do
    const string unit_name[4] = {"Air", "Naval", "Ground", "Sub"};
    const string message = "Need to apply a hit\n to a " + unit_name[target_class] + " Unit.";
    FC_DrawAlign(player.app->font1, player.app->renderer, player.app->screen.WIDTH/2,player.app->screen.HEIGHT-200, FC_ALIGN_CENTER, message.c_str());


    //highlight the currently selected unit
    const int& unit = player.popped_hit_index;
    Target highlight = {player.app->screen.WIDTH/2-750/2+(player == current_player? 15 : 545) + (unit%4)*50, player.app->screen.HEIGHT-250+15 + (unit/4)*50, 40, 40};
    SDL_SetRenderDrawColor(player, 255, 193, 7, 255);
    SDL_RenderDrawRect(player, &highlight);

}

void Runner::drawCombatRug(Player& player) const{
    const auto& sprite_sheet = player.sprite_sheet;

    Target target = {player.app->screen.WIDTH/2-750/2, player.app->screen.HEIGHT-250, 750, 250};

    
    const auto& attacker_ff = current_player->getFirstFire();
    bool defender_ff[8] = {false, false, false, false, false, false, false, false};
    if (current_battle.second != NEUTRAL){
        int i =0;
        for (const bool b : players[current_battle.second].getFirstFire())
        defender_ff[i++] = b;
    }

    uint8_t alpha = 255; //inBox(player.cursor_x+16, player.cursor_y+16, &target)? 160 : 255;

    //- Draw the container
    sprite_sheet->drawArea(&target, 1017, 1356, 750, 250, alpha);

    //- Draw all the attacker troops on the left

    //draw the rug
    Target target2 = {target.x + 10, target.y + 10, 201, 241};
    sprite_sheet->drawArea(&target2, 1236+201*current_player->getAllegiance(), 1114, 201, 241, alpha);

    int start_x = target.x+15;
    int start_y = target.y+15;
    int count = 0;

    const auto& attacker_units = current_battle.first->occupants[current_player->getAllegiance()];

    const auto& width = ZOOM_DIMENSIONS[1][0];


    bool taking_hits = (players[acting_player].combat_phase == COMBAT_CLASS_SELECT && player == acting_player && player != current_player) || (current_player->getAllegiance() == watching_player && target_class != CLASS_NULL);
    
    const UnitClass curr_select = ((int)players[acting_player].wheel_selection[0]%2 == 0) ? (UnitClass)((int)players[acting_player].wheel_selection[0]/2) : CLASS_NULL;
    for (const auto& unit : attacker_units){
        if (taking_hits && (unit->class_type == target_class || unit->class_type == curr_select)){
            drawFadeUnit(player, unit, start_x, start_y, 2, FADE_DOWN, 255, 0, 0, 200, 0, 0);

        }
        else{
            drawUnit(player, unit, start_x, start_y, 1+1, false);
        }
        start_x += width+10;
        if (++count % 4 == 0){
            start_y += width+10;
            start_x = target.x+15;
        }
    }

    //draw the first fires (215 12)
    target2 = {target.x + 215, target.y + 12, 40, 40};
    if (attacker_ff[INFANTRY]){
        sprite_sheet->drawArea(&target2, 1814+40*defender_ff[INFANTRY], 954, 40, 40, alpha);
        target2.y += 45;
    }
    if (attacker_ff[TANK]){
        sprite_sheet->drawArea(&target2, 1814+40*defender_ff[TANK], 954+120, 40, 40, alpha);
        target2.y += 45;
    }
    if (attacker_ff[FLEET]){
        sprite_sheet->drawArea(&target2, 1814+40*defender_ff[FLEET], 954+80, 40, 40, alpha);
        target2.y += 45;
    }
    if (attacker_ff[AIR]){
        sprite_sheet->drawArea(&target2, 1814+40*defender_ff[AIR], 954+40, 40, 40, alpha);
    }

    const auto& defender_units = current_battle.first->occupants[current_battle.second];

    target2 = {target.x + 540-2-40, target.y + 12, 40, 40};
    if (defender_ff[INFANTRY]){
        sprite_sheet->drawArea(&target2, 1814+40*attacker_ff[INFANTRY], 954, 40, 40, alpha);
        target2.y += 45;
    }
    if (defender_ff[TANK]){
        sprite_sheet->drawArea(&target2, 1814+40*attacker_ff[TANK], 954+120, 40, 40, alpha);
        target2.y += 45;
    }
    if (defender_ff[FLEET]){
        sprite_sheet->drawArea(&target2, 1814+40*attacker_ff[FLEET], 954+80, 40, 40, alpha);
        target2.y += 45;
    }
    if (defender_ff[AIR]){
        sprite_sheet->drawArea(&target2, 1814+40*attacker_ff[AIR], 954+40, 40, 40, alpha);
    }

    target2 = {target.x + 540, target.y + 10, 201, 241};
    sprite_sheet->drawArea(&target2, 1236+201*current_battle.second, 1114, 201, 241, alpha);

    start_x = target.x+545;
    start_y = target.y+15;
    count = 0;

    //- Draw all the defender troops on the right
    taking_hits = (players[acting_player].combat_phase == COMBAT_CLASS_SELECT && player == acting_player && player != current_battle.second) || (players[current_battle.second] == watching_player && target_class != CLASS_NULL);
    for (const auto& unit : defender_units){
        if (taking_hits && (unit->class_type == target_class || unit->class_type == curr_select)){
            drawFadeUnit(player, unit, start_x, start_y, 2, FADE_DOWN, 255, 0, 0, 200, 0, 0);
        }
        else{
            drawUnit(player, unit, start_x, start_y, 1+1, false);
        }
        start_x += width+10;

        if (++count % 4 == 0){
            start_y += width+10;
            start_x = target.x+545;
        }
    }

    //- Drawing the popped Unit and the fire order
    const auto& index = player.popped_unit_index;

    const int offset_x = target.x + 345;
    const int offset_y = target.y + 250 - 60;

    constexpr uint8_t full = 255;
    constexpr uint8_t blank = 0;
    constexpr uint8_t half = 180;


    auto draw = [&](const int& idx, const int& x_offset, const uint8_t start_a, const uint8_t end_a) {
        if (start_a != end_a) {
            drawFadeUnit(player, fire_order[idx], offset_x + x_offset, offset_y, 3, FADE_RIGHT, 97, 97, 97, start_a, end_a, 0);//second ? (left? 255: 180): (left ? 180 : 0), second? 255 : 180, 0);
        } 
        else {
            drawUnit(player, fire_order[idx], offset_x + x_offset, offset_y, 3, false);
        }
    };

    if (fire_order.empty()) { //no units to display
    
    }
    else if (fire_order.size() > 2) { //for 3+ units
        if (index == 0){ //if the first one then draw the two to the right
            draw(index, -60, blank, blank);
            draw(index+1, 0, blank, half);
            draw(index+2, 60, half, full);
        }
        else if (index == fire_order.size() - 1){ //if the last one then draw the two to the left
            draw(index-2, -60, full, half);
            draw(index-1, 0, half, blank);
            draw(index, 60, blank, blank);
        } 
        else {
            draw(index-1, -60, full, blank); //if not the end or middle then draw the surrounding units
            draw(index, 0, blank, blank);
            draw(index+1, 60, blank, full);
        }
    }
    else{ //when two or 1 units
        if (index == 0){
            draw(index, fire_order.size() > 1 ? -30 : 0, 0, 0); //highlight first
            if (fire_order.size() > 1){ //draw second if there is one
                draw(index + 1, 30, blank, full);
            }
        }
        else if (index == 1){ //if the index is 1 then there must be two units
            draw(index-1, -30, full, blank);
            draw(index, 30, blank, blank);
        }
    }    


    //- If a unit is selected for battle show this during dice roll
    if (target_class != CLASS_NULL && players[watching_player].combat_phase != COMBAT_DEAL_HITS){
        target = {target.x+750/2-21, target.y+10, 43, 43}; //todo add text to say who they are attacking
        sprite_sheet->drawArea(&target, 1642+43*target_class, 1028, 43, 43);
    }
}

//&^ Drawing Units

void Runner::drawUnit(const Player& player, const Unit* unit, const int& x, const int& y, const int& zoom, const bool secret) const{
    //- Get the sprite depending on thenationality and current CV
    SDL_Rect target {x, y, ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][1]};
    if (secret)
        player.units_sprite_z1->drawSprite(&target, 0+unit->upgrading+(unit->combat_value == 0), 35+unit->nationality, 20, 20);
    else
        player.units_sprite_z1->drawSprite(&target, unit->unit_type+7*unit->upgrading+14*unit->convoy+
        ((unit->acted)? 28 -7*unit->convoy:0), 5*unit->nationality+unit->combat_value+unit->upgrading, 20, 20);
}

void Runner::drawFadeUnit(const Player& player, const Unit* unit, const int& start_x, const int& start_y, const int& zoom, const FadeDirection& fade_direct, const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& start_opacity, const uint8_t& end_fade, const int& pixels_ignored) const{
    const int width = ZOOM_DIMENSIONS[zoom-1][0];
    const auto& renderer = player.app->renderer;

    //Draw the unit before drawing over fade
    SDL_Rect target {start_x, start_y, width, width};
    player.units_sprite_z1->drawSprite(&target, unit->unit_type+7*unit->upgrading+14*unit->convoy+ ((unit->acted)? 28 -7*unit->convoy:0), 5*unit->nationality+unit->combat_value+unit->upgrading, 20, 20);

    constexpr int x_offset_table[4] = {0, 0, +1, -1}; //FADE_UP, FADE_DOWN, FADE_RIGHT, FADE_LEFT
    constexpr int y_offset_table[4] = {+1, -1, 0, 0}; //FADE_UP, FADE_DOWN, FADE_RIGHT, FADE_LEFT

    constexpr bool x2_table[4] = {1, 1, 0, 0}; //FADE_UP, FADE_DOWN, FADE_RIGHT, FADE_LEFT
    constexpr bool y2_table[4] = {0, 0, 1, 1}; //FADE_UP, FADE_DOWN, FADE_RIGHT, FADE_LEFT

    //constexpr int start_x_table[4] = {0, 0, 0, 1}; //FADE_UP, FADE_DOWN, FADE_RIGHT, FADE_LEFT
    //constexpr int start_y_table[4] = {0, 1, 0, 0}; //FADE_UP, FADE_DOWN, FADE_RIGHT, FADE_LEFT

    int x1 = start_x + (fade_direct == FADE_LEFT)*width;
    int y1 = start_y + (fade_direct == FADE_DOWN)*width;
    int x2 = x1 + x2_table[fade_direct]*width;
    int y2 = y1 + y2_table[fade_direct]*width;

    //Get the offset (aka direction to move the line)
    const int x_offset = x_offset_table[fade_direct];
    const int y_offset = y_offset_table[fade_direct];

    //Calculate the increment to the fade
    double alpha = start_opacity;
    const double step = (start_opacity-end_fade)/(double)(width-pixels_ignored);

    for (int i = 0; i <= width; i++){
        if (i <= width-pixels_ignored){ //dont increase the opacity for the first number of pixels ignored
            SDL_SetRenderDrawColor(renderer, r, g, b, (int)alpha);
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
            alpha -= step;
        }

        x1 += x_offset;
        y1 += y_offset;
        x2 += x_offset;
        y2 += y_offset;
    }
}

void Runner::drawUnit(const Player& player, const UnitType& unit_type, const UnitCountry& nationality, const int& x, const int& y, const int& zoom, const bool invalid, const int& scale) const{
    SDL_Rect target {x, y, ZOOM_DIMENSIONS[zoom-1][0]*scale, ZOOM_DIMENSIONS[zoom-1][0]*scale};
    if (invalid){
        player.units_sprite_z1->drawSprite(&target, unit_type, 35+(MAX_CV_TABLE[nationality]==3), 20, 20);
    }
    else{
        player.units_sprite_z3->drawSprite(&target,unit_type, 44+nationality, 64, 64);
    }
}

//&^ Drawing Cities

void Runner::drawCity(Player& player, City* city, const bool resources, const bool units){
    SDL_Rect target;
    auto& sprite_sheet = player.sprite_sheet;
    target = {player.app->screen.getX(city->x), player.app->screen.getY(city->y), city->HEIGHT*player.zoom, city->WIDTH*player.zoom};
    
    //- Draw the Population type (capital, subcapital, ...)
    sprite_sheet->drawSprite(&target, 8, getCitySprite(city));

    //- Draw the ruler token (only if it doesn't equal origional)
    if (city->occupier_allegiance != city->ruler_allegiance){
        player.sprite_sheet->drawSprite(&target, 9+city->occupier_allegiance, 12+city->ruler_allegiance, 32, 32);
    }
    else if (city->ruler_allegiance != city->start_allegiance){
        player.sprite_sheet->drawSprite(&target, 9, city->ruler_allegiance*4+3, 32, 32);
    }

    //-Draw Units
    if (units)
        drawCityUnits(player, city);
}

void Runner::drawCity(Player& player, const int& x, const int& y, const PopulationType& population_type) const{
    SDL_Rect target = {player.app->screen.getX(x), player.app->screen.getY(y), 32*player.zoom, 32*player.zoom};
    player.sprite_sheet->drawSprite(&target, 8, 14+5-(int)population_type);
}

void Runner::drawCityUnits(Player& player, City* city){
    const auto& unit_ml = city->getOccupants();
    const int& num_units = unit_ml.size();

    if (num_units == 0)
        return;

    constexpr uint max_width = 4;

    const CityType& allegiance = player.getAllegiance();
    const auto& zoom = (int)player.app->screen.zoom_factor;
    const int width = ZOOM_DIMENSIONS[zoom-1][0];
    const int off = ZOOM_DIMENSIONS[zoom-1][1];
    const bool not_battling = !city->battling;

    SDL_Rect target = {player.app->screen.getX(city->x), player.app->screen.getY(city->y)+33*zoom, 0, width};

    //- Calculate offset for centering on city
    int offset = -(SDL_clamp(city->num_occupants, 0, max_width)*off)/2 + 16*zoom;
    const int org_offset = offset;
    const int org_x = target.x+offset;
    const int org_y = target.y;

    //For the closest unit to the cursor
    const int cursor_x = player.cursor_x+16;
    const int cursor_y = player.cursor_y+16;

    //- Calculating which units will be drawn
    int curr_index = (city->full_display[allegiance])? 0 : city->skip_troop[allegiance];
    const int end_index = (city->full_display[allegiance])? num_units : (num_units < max_width)? num_units : ((curr_index/max_width)+1)*max_width;

    int num_drawn = 0; //used to save how many will be drawn
    const auto& peaking_unit = player.peaked_unit.second;

    while (curr_index < num_units && curr_index < end_index){ //actually drawing the units
        const auto& unit = unit_ml[curr_index++];
        //hide_rivals = !city->battling && WEST != allegiance;
        drawUnit(player, unit, target.x+offset, target.y, zoom, unit->nationality != NEUTRAL_U && not_battling && unit->allegiance != allegiance && unit != peaking_unit);
        num_drawn++;
        offset += off;

        if (curr_index % max_width == 0){ //go next row
            offset = org_offset;
            target.y += off;
        }
    }

    target.x = org_x;
    target.y = org_y;
    target.h = width*ceil(num_drawn/(double)max_width);
    target.w = width*SDL_clamp(num_drawn, 0, max_width);

    //dev drawing hitboxes wink wink haha
    //SDL_SetRenderDrawColor(west_player->app->renderer, 0, 255, 0, 255);
    //SDL_RenderDrawRect(west_player->app->renderer, &target);

    //- Finding which unit the player's cursor is over
    if (inBox(cursor_x, cursor_y, &target)){
        //if its in divide the width by the number of units 
        //get x = (cursor_x-target.x)/width
        //get y = (cursor_y-target.y)/width
        //get num = y*max_width+x

        const int x = (cursor_x-target.x)/width;
        const int y = (cursor_y-target.y)/width;

        if (y*max_width+x < num_units){ //max sure its actually in bounds
            player.selected_unit = {city, unit_ml[y*max_width+x]};

            //draw highlight box
            Target target2 = {target.x+width*x, target.y+width*y, width, width};
            SDL_SetRenderDrawColor(player.app->renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(player.app->renderer, &target2);
        }
    }

    //- Check to update units
    const tick_t res = SDL_GetTicks();
    if (pastWait(city->last_skip[allegiance], res, 2500) && num_units > 5){
        city->skip_troop[allegiance] = ((city->skip_troop[allegiance]+max_width >= (((city->num_occupants / max_width) + 1)) * max_width) || city->num_occupants == city->skip_troop[allegiance]+max_width )? 0 : city->skip_troop[allegiance]+max_width;
        city->last_skip[allegiance] = res;
        player.selected_unit = {nullptr, nullptr};
    }
}

void Runner::drawCity(Player& player, City* city, const bool resources) const{
    SDL_Rect target;
    auto& sprite_sheet = player.sprite_sheet;
    target = {player.app->screen.getX(city->x), player.app->screen.getY(city->y), city->HEIGHT*player.zoom, city->WIDTH*player.zoom};
    
    //- Draw the Population type (capital, subcapital, ...)
    sprite_sheet->drawSprite(&target, 8, getCitySprite(city));

    //- Draw the ruler token (only if it doesn't equal origional)
    if (city->occupier_allegiance != city->ruler_allegiance){
        player.sprite_sheet->drawSprite(&target, 9+city->occupier_allegiance, 12+city->ruler_allegiance, 32, 32);
    }
    else if (city->ruler_allegiance != city->start_allegiance){
        player.sprite_sheet->drawSprite(&target, 9, city->ruler_allegiance*4+3, 32, 32);
    }
}

int Runner::getCitySprite(City* city) const{
    switch (city->population_type){
        case MAIN_CAPITAL:
            return 11 + city->start_allegiance;
        case SUB_CAPITAL:
            return 5 + city->city_nationality;
        // Cities below don't have any change in colors
        default:
            return (city->start_allegiance != WATER) + city->population_type;
    }


    return -1;
}

void Runner::drawInfluence(const Player& player) const{
    //- Draw influence at the capitals
    SDL_Rect target;
    const int& zoom = player.app->screen.zoom_factor;
    const auto& countries = map.getCountries();
    for (const auto& country : countries){
        const auto& actual_country = country.second;
        const auto& capital = actual_country->capital;
        
        //- Draw influnce level around city
        target = {player.app->screen.getX(capital->x), player.app->screen.getY(capital->y), 32*zoom, 32*zoom};
        if (actual_country->influence_level != UNALIGNED){
            player.sprite_sheet->drawSprite(&target, 9, actual_country->allegiance*4+actual_country->influence_level-1+(actual_country->influence_level == SATELLITES), 32, 32);
        }

        //- Draw any added cards
        if (actual_country->added_influence != 0){
            target.w = 23*zoom;
            target.h = target.w;
            
            for (int i = 0; i < actual_country->added_influence; i++){
                player.sprite_sheet->drawSprite(&target, 0, 33+actual_country->top_card, 23, 23);
                target.y += target.h/2;
            }
        }
        
    }
}

//&^ Extra board things

void Runner::drawConnections(const Player& player) const{
    const auto& map = getMap();
    const auto& adjacency = getMap().getAdjacency();
    for (size_t city = 0; city < adjacency.size(); city++){
        for (size_t border = 0; border < adjacency.size(); border++){
            if (adjacency[city][border] == NA) //no connection
                continue;

            City* start_city = map.getCity(city);
            City* end_city = map.getCity(border);
            drawLine(player, start_city, end_city);
        }
    }
}

void Runner::drawNumber(SDL_Renderer* renderer, int num, const int x, const int y, const float scale, const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) const{
    int digits = 0;
    bool negative = num < 0;
    num = abs(num);
    auto copy = num;
    while (copy) {
        copy /= 10;
        digits++;
    }

    (negative)? SDL_SetRenderDrawColor(renderer, 255, 0, 0, a) : SDL_SetRenderDrawColor(renderer, r, g, b, a);

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

void Runner::drawActionCard(const Player* draw_player, const ActionCard* card, const int& start_x, const int& start_y, const int& scaled_size, const uint8_t alpha) const{
    auto& sprite_sheet = draw_player->sprite_sheet;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};

    //- draw left
    sprite_sheet->drawArea(&target, 32*card->sprite_offset_left, 480, 32, 32, alpha);
    target.x += scaled_size;

    //- draw season
    sprite_sheet->drawArea(&target, 32*card->season, 512, 32, 32, alpha);

    //- draw letter
    sprite_sheet->drawArea(&target, 32*(4+card->command_priority-'A'), 512, 32, 32, alpha);

    //- draw number
    sprite_sheet->drawArea(&target, 32*(28+card->command_value), 512, 32, 32, alpha);
    target.x += scaled_size;

    //- draw right
    sprite_sheet->drawArea(&target, 32*card->sprite_offset_right, 480, 32, 32, alpha);
}

void Runner::drawActionCards(const Player* draw_player, const Player* target_player, const int& start_x, const int& start_y, const int& count, const int scale) const{
    int scaled_size = 32*scale;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};

    auto& sprite_sheet = draw_player->sprite_sheet;

    size_t i;
    for (i = draw_player->action_card_start; i < count && i < target_player->getActionSize(); i++){
        const auto& card = target_player->getActionCard(i);

        drawActionCard(draw_player, card, target.x, target.y, scaled_size);

        //is the popped card then draw select icon to the right of it
        if (draw_player->popped_action_card_index == i){
            SDL_Rect target2 = {start_x + 3*scaled_size + 3, target.y, 32,32};
            sprite_sheet->drawSprite(&target2, draw_player->widget != ACTION_HAND, 0); 
        }

        target.y += scaled_size;
        target.x = start_x;
    }

    //- Draw bought cards
    if (target_player != draw_player)
        return;

    target.w=96;
    for (size_t j = 0; j < (count-i) && j < draw_player->bought_action; j++){
        //- draw left
        sprite_sheet->drawSprite(&target, 15, 15, 96, 32, 0, -32, 0);

        target.y += scaled_size;
        target.x = start_x;
    }
}

void Runner::drawInvestCard(const Player* player, const InvestmentCard* card, const int& start_x, const int& start_y, const int& scaled_size, const uint8_t alpha) const{
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};
    auto& sprite_sheet = player->sprite_sheet;

    //- draw left
    sprite_sheet->drawArea(&target, 32*card->tech1, 448, 32, 32, alpha);

    if (&card->tech1 == player->selected_tech1 || &card->tech1 == player->selected_tech2){
        sprite_sheet->drawSprite(&target, 14, SELECTED_TECH);
    }

    target.x += scaled_size;

    //- draw base factory cost
    sprite_sheet->drawArea(&target, 32*(FACT_ONE-1+card->amount), 448, 32, 32, alpha);
    target.x += scaled_size;

    //- draw right
    sprite_sheet->drawArea(&target, 32*card->tech2, 448, 32, 32, alpha);

    if (&card->tech2 == player->selected_tech1 || &card->tech2 == player->selected_tech2){
        sprite_sheet->drawSprite(&target, 14, SELECTED_TECH);
    }
}

void Runner::drawInvestCards(const Player* player, const int& start_x, const int& start_y, const int& count, const int scale) const{
    int scaled_size = 32*scale;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};
    auto& sprite_sheet = player->sprite_sheet;

    //- Draw known cards in hands
    size_t i;
    for (i = player->invest_card_start; i < count && i < player->getInvestSize(); i++){
        const auto& card = player->getInvestCard(i);

        drawInvestCard(player, card, target.x, target.y, scaled_size);

        //is the popped card then draw select icon to the right of it
        if (player->popped_invest_card_index == i){
            SDL_Rect target2 = {target.x - 35, target.y, 32,32};
            sprite_sheet->drawSprite(&target2, player->widget != INVEST_HAND, 1);
        }

        if (player->hasSelected(card)){
            SDL_Rect target2 = {target.x, target.y, 96,32};
            sprite_sheet->drawArea(&target2, 1088, 448, 96, 32);
        }

        target.y += scaled_size;
        target.x = start_x;
    }   

    //- Draw bought cards
    target.w=96;
    for (size_t j = 0; j < (count-i) && j < player->bought_invest; j++){
        //- draw the whole card
        sprite_sheet->drawSprite(&target, 15, 15, 96, 32, 0, -32, 0);

        target.y += scaled_size;
        target.x = start_x;
    }
}

void Runner::drawAchievedTech(Player* player, const Player* target_player, const int& start_x, const int& start_y) const{
    if (target_player->getTechSize() == 0)
        return;

    SDL_Rect target = {start_x,start_y, 32, 32};
    auto& sprite_sheet = player->sprite_sheet;

    //- draw all secret cards (if the player == target_player then just draw an outline)
    int num_secret = target_player->getSecretCount();
    size_t i, count = 0;
    for (i = target_player->start_tech; i <= Y_1944 && num_secret; i++){
        if (target_player->getTech(i) != nullptr && target_player->getTech(i)->secret){ //if NOT null ptr then player does have this tech
            if (player == target_player){
                sprite_sheet->drawSprite(&target, 14, i); //draw tech and then secret outline
                sprite_sheet->drawSprite(&target, 14, SECRET_OUTLINE);
            }
            else{
                sprite_sheet->drawSprite(&target, 14, SECRET_FULL);
            }
            target.y -= 32;
            num_secret--;

            if (count++ == player->popped_tech_index){
                SDL_Rect target2 = {target.x-35, target.y+32, 32, 32};
                sprite_sheet->drawSprite(&target2, player->widget != TECH_HAND, 1);
                player->popped_tech = (player == target_player)? &target_player->getTech(i)->tech : nullptr;
            }
        }
    }

    //- draw all public cards
    int num_public = target_player->getTechSize() - target_player->getSecretCount();
    for (i = target_player->start_tech; i <= Y_1944 && num_public; i++){
        if (target_player->getTech(i) != nullptr && !target_player->getTech(i)->secret){ //if NOT null ptr then player does have this tech
            sprite_sheet->drawSprite(&target, 14, i);
            target.y -= 32;
            num_public--;
            
            if (count++ == player->popped_tech_index){
                SDL_Rect target2 = {target.x-35, target.y+32, 32, 32};
                sprite_sheet->drawSprite(&target2, player->widget != TECH_HAND, 1);
                player->popped_tech = &target_player->getTech(i)->tech;
            }
        }
    }
}

//&&& Animations

void Runner::animateCommandOrder(bool& running, const int west_start,  const int axis_start,  const int ussr_start, const int west_end,  const int axis_end,  const int ussr_end){
    //- Move the West players movement
    constexpr tick_t total_time = 5000; //Total animation time should be 5 seconds (5000 clock)

    const double progress = std::min((clock-last_tick)/(double)total_time, 1.0);
    const int y = -50+112;
    
    for (auto& player : players){
        ClearScreen(player.app->renderer);
        drawPlayerBoard(player, false);

        const int x = (player.app->screen.WIDTH-640)/2;

        const int start_x[3] = {16+x, 224+x, 432+x};
        auto& sprite_sheet = player.sprite_sheet;
        SDL_Rect target = {x, y-112, 640, 192};
        const int alpha = inBox(player.cursor_x, player.cursor_y, &target)? 100: 255;
        if (phase == 0){ //show the current state before moving
            sprite_sheet->drawArea(&target, 0, 576, 320, 96, alpha);

            if (west_player->passed){
                target = {16+x, y, 96*2, 64};
                sprite_sheet->drawArea(&target, 0, 672, 96, 32, alpha);
            }
            if (west_player->getCommandNumber() != -1){
                if (west_player->command_fake != nullptr){
                    drawInvestCard(&player,west_player->command_fake, x+16, y, 64, alpha);
                }
                else if (west_player->command_card != nullptr){
                    drawActionCard(&player, west_player->command_card, x+16, y, 64, alpha);
                }
            }

            if (axis_player->passed){
                target = {224+x, y, 96*2, 64};
                sprite_sheet->drawArea(&target, 0, 672, 96, 32, alpha);
            }
            if (axis_player->getCommandNumber() != -1){
                if (axis_player->command_fake != nullptr){
                    drawInvestCard(&player,axis_player->command_fake, x+224, y, 64, alpha);
                }
                else if (axis_player->command_card != nullptr){
                    drawActionCard(&player,axis_player->command_card, x+224, y, 64, alpha);
                }

            }

            if (ussr_player->passed){
                target = {432+x, y, 96*2, 64};
                sprite_sheet->drawArea(&target, 0, 672, 96, 32, alpha);
            }
            if (ussr_player->getCommandNumber() != -1){
                if (ussr_player->command_fake != nullptr){
                    drawInvestCard(&player, ussr_player->command_fake, x+432, y, 64, alpha);
                }
                else if (ussr_player->command_card != nullptr){
                    drawActionCard(&player, ussr_player->command_card, x+432, y, 64, alpha);
                }  
            }


            if (pastWait(last_tick, clock, 5000)){
                phase = 1;
                last_tick = clock;
                running = !(west_end == -1 && axis_end == -1 && ussr_end == -1);
            }
        }

        if (phase == 1){ //show them moving
            sprite_sheet->drawArea(&target, 320, 576, 320, 96, alpha);
            
            //draw highlights
            if (west_end != -1){
                target = {start_x[west_end]-6, y-6, 204, 76};
                sprite_sheet->drawArea(&target, 4, 629, 102, 38, alpha);
            }
            
            if (axis_end != -1){
                target = {start_x[axis_end]-6, y-6, 204, 76};
                sprite_sheet->drawArea(&target, 109, 629, 102, 38, alpha);
            }

            if (ussr_end != -1){  
                target = {start_x[ussr_end]-6, y-6, 204, 76};
                sprite_sheet->drawArea(&target, 213, 629, 102, 38, alpha);
            }

            //draw numerals
            target = {x+39*2, y+61*2-112, 44, 42};
            sprite_sheet->drawArea(&target, 320, 672, 22, 21, alpha == 255? 255 : 150);

            target = {x+151*2, y+61*2-112, 44, 42};
            sprite_sheet->drawArea(&target, 342, 672, 22, 21, alpha == 255? 255 : 150);

            target = {x+254*2, y+61*2-112, 44, 42};
            sprite_sheet->drawArea(&target, 364, 672, 27, 21, alpha == 255? 255 : 150);

            // calculate its current pos to its determined one 0->where_ever
            if (west_end != -1){
                drawActionCard(&player, west_player->command_card, start_x[0] + (start_x[west_end] - start_x[0])*progress, y, 64, alpha);
            }

            if (axis_end != -1){
                drawActionCard(&player, axis_player->command_card, start_x[1] + (start_x[axis_end] - start_x[1])*progress, y, 64, alpha);
            }

            if (ussr_end != -1){
                drawActionCard(&player, ussr_player->command_card, start_x[2] + (start_x[ussr_end] - start_x[2])*progress, y, 64, alpha);
            }
        }
        //cout << start_x[ussr_start] + (start_x[ussr_end] - start_x[ussr_start])/((clock-last_tick)/(double)total_time) << endl;

        SDL_RenderPresent(player.app->renderer);
    }    

    if (progress == 1.0){
        turn_order[0] = temp_order[0];
        turn_order[1] = temp_order[1];
        turn_order[2] = temp_order[2];
        season = SPRING;
        west_player->passed = false;
        axis_player->passed = false;
        ussr_player->passed = false;
    }
}

void Runner::animateMessage(Player& player, PublicMessage& message){
    SDL_Rect target;
    if (message.beside_action)
        target = {108, player.app->screen.HEIGHT-35, message.width, message.height};
    else
        target = {player.app->screen.getCenterX()-(message.width/2), 3, message.width, message.height};

    const int current_frame = (message.flicker)? (clock-message.start_tick)%message.tpf >= message.tpf/(2.0*((clock-message.start_tick)/(double)message.life_time))
    
    
    : (clock-message.start_tick)/message.tpf;
    player.message_animation_sheets->drawSprite(&target, message.message, current_frame, message.width, message.height, 0, message.offset);

    if (message.flicker? clock-message.start_tick > message.life_time : current_frame >= message.frames){ //if animation is done remove from vector
        public_messages.erase(std::find(public_messages.begin(), public_messages.end(), message));
    }
}

void Runner::animateReshuffle(bool& running, const size_t& action_size, const size_t& invest_sizes){
    //- Draw all boards (will draw things over it)
    for (auto& player : players){
        ClearScreen(player.app->renderer);
        drawPlayerBoard(player, false);
        
        SDL_Rect target = {0, 0, player.app->screen.WIDTH, player.app->screen.HEIGHT};
        player.sprite_sheet->drawArea(&target, 0, 288, 1, 1, 180);

        SDL_RenderPresent(player.app->renderer);
    }
    running = false;
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

//DEV MICHAEL IN THE MORNING REMEMBER TO ADD A CALL BACK FUNCTION TO THE DICE ROLL ANIMATION THAT ADDS A NEW ANIMATION WITH THE ACTUAL DIE RESULT AND THEN THAT ANIMATION WILL HAVE THE HIT CHECK CALLBACK Good luck :)

//& Title Screen
void Runner::drawTitle(Player& player, const uint8_t& alpha){
    bool over_start=false, over_house=false, over_credits=false;
    
    ClearScreen(player.app->renderer);

    const int& width=player.app->screen.WIDTH, height=player.app->screen.HEIGHT;
    const auto& sprite_sheet = player.sprite_sheet;

    //- Init targets
    SDL_Rect map_target = {0, 0, width, height},
    title_target = {width/2-533,93, 1067,90},
    house_target = {width/2-206, height/2-72/2, 412,72}, // 90
    start_target = {width/2-206, house_target.y-90, 412,72},
    credits_target = {width/2-206, house_target.y+90, 412,72}, // 90
    rule_target = {width-350, height-22-420, 320, 420},
    west_target = {22, height-21-176, 176, 176},
    axis_target = {226, height-21-176, 176, 176},
    ussr_target = {430, height-21-176, 176, 176};

    for (auto& cursor : players) {
        int adjusted_x = (int)(cursor.cursor_x) + 16;
        int adjusted_y = (int)(cursor.cursor_y) + 16;

        cursor.in_start = inBox(adjusted_x, adjusted_y, &start_target);
        over_start = over_start || cursor.in_start;
        if (cursor.in_start) 
            continue;

        cursor.in_house = inBox(adjusted_x, adjusted_y, &house_target);
        over_house = over_house || cursor.in_house;
        if (cursor.in_house) 
            continue;

        cursor.in_credits = inBox(adjusted_x, adjusted_y, &credits_target);
        over_credits = over_credits || cursor.in_credits;
    }

    //- Draw the Background
    player.map_sprite->drawArea(&map_target, 0, 982, 1512, 982, alpha);

    //- Draw Title (TnT)
    sprite_sheet->drawArea(&title_target, 0, 1024, 1067, 90,alpha);

    //- Draw Start Button
    if (!over_start)
        start_target.y += 5*cos((1/600.0)*clock+90000);
    sprite_sheet->drawArea(&start_target, 0, 1114, 412, 72,alpha);

    //- Draw House Rule Button
    if (!over_house)
        house_target.y += 5*cos((1/600.0)*clock+46000);
    sprite_sheet->drawArea(&house_target, 412, 1114, 412, 72,alpha);

    //- Draw Credits Button
    if (!over_credits)
        credits_target.y += 5*cos((1/600.0)*clock+15000);
    sprite_sheet->drawArea(&credits_target, 824, 1114, 412, 72,alpha);

    //- Draw Rule Book
    rule_target.y += 5*cos((1/700.0)*clock);
    sprite_sheet->drawArea(&rule_target, 526, 1186, 320, 420,alpha);

    //- Draw West Dock
    west_target.x += 2*sin((1/400.0)*clock);
    sprite_sheet->drawArea(&west_target, 0, 1186, 176, 176,alpha);

    //- Draw Axis Dock
    axis_target.x += 2*sin((1/400.0)*clock+40000);
    sprite_sheet->drawArea(&axis_target, 174, 1186, 176, 176,alpha);

    //- Draw USSR Dock
    ussr_target.x += 2*sin((1/400.0)*clock+25000);
    sprite_sheet->drawArea(&ussr_target, 350, 1186, 176, 176,alpha);

    //- Draw Connected Controllers
    Target controller_target = {31, 754, 162, 126};
    if (controllers[WEST]){
        sprite_sheet->drawArea(&controller_target, 0, 1362, 162, 126,alpha);
    }

    controller_target.x = 235;
    if (controllers[AXIS]){
        sprite_sheet->drawArea(&controller_target, 0, 1362, 162, 126,alpha);
    }

    controller_target.x = 439;
    if (controllers[USSR]){
        sprite_sheet->drawArea(&controller_target, 0, 1362, 162, 126,alpha);
    }
    

    //- Draw all cursor's
    for (const auto& cursor : players){
        SDL_Rect cursor_target;
        cursor_target = {(int)cursor.cursor_x, (int)cursor.cursor_y, 32, 32};
        sprite_sheet->drawSprite(&cursor_target, 0, 11+cursor.getAllegiance(), 32, 32);
    }

    SDL_RenderPresent(player.app->renderer);

}

void Runner::animatePoem(Player& player) const{
    ClearScreen(player.app->renderer);
    FC_DrawAlign(player.app->font1, player.app->renderer, player.app->screen.WIDTH/2,player.app->screen.HEIGHT/3, FC_ALIGN_CENTER, "What we have feared\nassumes dimension and a name;\nthe long shadow emerges from the wall;\nthe smoke is flame.\n\nSo wind we heard in elm tree branches\nis a voice after all;\nso corners wake,\nand stairways speak,\nand the twisted stick becomes the snake.\n\nM. Jean Prussin");
    //FC_Draw(player.app->font1, player.app->renderer, player.app->screen.WIDTH/2-612, player.app->screen.HEIGHT*0, "What we have feared\nassumes dimension and a name;\nthe long shadow emerges from the wall;\nthe smoke is flame.\n\nSo wind we heard in elm tree branches\nis a voice after all;\nso corners wake,\nand stairways speak,\nand the twisted stick becomes the snake.\n\n   M. Jean Prussin");

    SDL_RenderPresent(player.app->renderer);
}