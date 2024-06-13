#include "Runner.h"


//& SDL Routines

bool Runner::InitSDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;

    
    }
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_GameControllerEventState(SDL_ENABLE);
    const char* mapping_string = "030000000d0f0000f600000001000000,Lic Pro Controller,a:b0,b:b1,x:b2,y:b3,back:b8,guide:b12,start:b9,leftshoulder:b4,rightshoulder:b5,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,lefttrigger:b6,righttrigger:b7,platform:Mac OS X";

    cout << SDL_GameControllerAddMapping(mapping_string) << endl;
                                        //030000000d0f0000f600000001000000,Lic Pro Controller,a:b0,b:b1,x:b2,y:b3,back:b8,guide:b12,start:b9,leftshoulder:b4,rightshoulder:b5,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,lefttrigger:b6,righttrigger:b7,platform:Mac OS X
    for (int i = 0; i < SDL_NumJoysticks(); i++){
        if (SDL_IsGameController(i)){
            west_controller = SDL_GameControllerOpen(0);
            controllers[0] = west_controller;
            break;
        }
    }
    if (controllers[0] == nullptr){
        cout << "West controller not connected" << endl;
        exit(1);
    }

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

// Application Routine
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

//!!! Drawing Player board

void Runner::drawPlayerBoard(const Player& player, SDL_Renderer* renderer, const int bought_action, const int bought_invest){
    //- Draw the map and the cities
    drawMap(player, true, true, true, false, false);

    auto& sprite_sheet = powers_sprite_map[player.getAllegiance()];
    
    //- Draw the current state of the 
    int y = powers_app[player.getAllegiance()].screen.HEIGHT-105;
    SDL_Rect target = {3, y, 102, 102};
    if (player.show_action){ //draw all the action cards
        if (player.getActionSize() > 0){
            //- Draw the opening icon
            sprite_sheet.drawSprite(&target, 6, 1, 102, 102);

            //- calcualte how many cards need to be shown and draw background (max amount will be 12)
            target = {3, y-(int)(32*player.getActionSize()), 102, (int)(32*player.getActionSize())};
            sprite_sheet.drawSprite(&target, 6, 2, 102, 102);
            target = {3, y-(int)(32*player.getActionSize()), 102, 102};
            sprite_sheet.drawSprite(&target, 6, 2, 102, 102);

            //- Draw the cards
            drawActionCards(&player, 6, y-(int)(32*player.getActionSize())+3, 15);
        }
        else{
            target.y = 875-102/2;
            sprite_sheet.drawSprite(&target, 6, 2, 102, 102);

            target.y = 875;
            sprite_sheet.drawSprite(&target, 6, 1, 102, 102);
        }
    }
    else{ //draw just the icon
        sprite_sheet.drawSprite(&target, 6, 0, 102, 102);
    }

    target = {powers_app[player.getAllegiance()].screen.WIDTH-105, y, 102, 102};
    const int x = target.x;
    if (player.show_invest){ //draw all the invest cards
        if (player.getInvestSize() > 0){
            //- Draw the opening icon
            sprite_sheet.drawSprite(&target, 6, 4, 102, 102);

            //- calcualte how many cards need to be shown and draw background (max amount will be 12)
            target = {x, y-(int)(32*player.getInvestSize()), 102, (int)(32*player.getInvestSize())};
            sprite_sheet.drawSprite(&target, 6, 5, 102, 102);
            target = {x, y-(int)(32*player.getInvestSize()), 102, 102};
            sprite_sheet.drawSprite(&target, 6, 5, 102, 102);

            //- Draw the cards
            drawInvestCards(&player, x+3, y-(int)(32*player.getInvestSize())+3, 15);
        }
        else{
            target.y = 875-102/2;
            sprite_sheet.drawSprite(&target, 6, 5, 102, 102);

            target.y = 875;
            sprite_sheet.drawSprite(&target, 6, 4, 102, 102);
        }
    }
    else{
        sprite_sheet.drawSprite(&target, 6, 3, 102, 102);
    }


    //- Draw the production left
    drawNumber(powers_app[player.getAllegiance()].renderer, player.getCurrentProduction()-player.production_actions.size(), 50, 0, 5, 255, 255, 255);

    //- Draw the cursor
    target = {(int)player.cursor_x, (int)player.cursor_y, 32, 32};
    sprite_sheet.drawSprite(&target, 0, 11+player.getAllegiance(), 32, 32);

    SDL_RenderPresent(powers_app[player.getAllegiance()].renderer);
}

void Runner::drawMap(const Player& player, const bool cities, const bool influence, const bool resources, const bool connections, const bool clear, const int& fps){
    ClearScreen(player.app->renderer);
    int width, height;
    SDL_GetWindowSize(player.app->window, &width, &height);
    SDL_Rect tar = {player.app->screen.zoom_x*(player.app->screen.zoom_x<0), player.app->screen.zoom_y*(player.app->screen.zoom_y>0), width, height};
    player.map_sprite->drawSprite(&tar, 0, 0, (int)(1512/player.app->screen.zoom_factor), (int)(982/player.app->screen.zoom_factor), 0, player.app->screen.zoom_x*(player.app->screen.zoom_x>0), player.app->screen.zoom_y*(player.app->screen.zoom_x>0));

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
}

void Runner::drawCityUnits(const Player& player, City* city){
    if (city->full_display){
        drawFullCityUnits(player, city);
        return;
    }

    const CityType& allegiance = player.getAllegiance();
    const auto& zoom_scale = player.app->screen.zoom_factor;
    const auto& zoom = (int)player.app->screen.zoom_factor;
    const int off = ZOOM_DIMENSIONS[zoom-1][1];

    //Most units in a shown row can be 5
    SDL_Rect target = {0, 0, 20, 20};

    int unit_count = 0;
    int skipped = 0;
    target = {(int)(city->x*zoom_scale*player.app->screen.WIDTH/1512)+8, (int)(city->y*zoom_scale*player.app->screen.HEIGHT/982)+33, 20, 20};
    int offset = -(((city->num_occupants <= 5)? city->num_occupants : 5)/2*20);


    bool hide_rivals = !city->isConflict() && WEST != allegiance; //if there is no conflict then rival units are placed 'face up' and not viewable by rivals
    for (const auto& unit : city->occupants[0]){ //west units
        if (unit_count == 5)
            break;
        if (skipped < city->skip_troop[allegiance]){
            skipped++;
            continue;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
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
        offset += off; unit_count++;
        if (unit_count == 5)
            break;
    }
    Uint32 res = SDL_GetTicks();
    if (res - city->last_skip[allegiance] >= 2500 && city->num_occupants > 5){
        city->skip_troop[allegiance] = (city->skip_troop[allegiance]+5 >= (((city->num_occupants / 5) + 1)) * 5)? 0 : city->skip_troop[allegiance]+5;
        city->last_skip[allegiance] = res;
    }
}

void Runner::drawFullCityUnits(const Player& player, City* city){
    const CityType& allegiance = player.getAllegiance();
    const auto& zoom_scale = player.app->screen.zoom_factor;
    const auto& zoom = (int)player.app->screen.zoom_factor;
    const int off = ZOOM_DIMENSIONS[zoom-1][1];

    SDL_Rect target = {(int)(city->x*zoom_scale*player.app->screen.WIDTH/1512)+8, (int)(city->y*zoom_scale*player.app->screen.HEIGHT/982)+33-off, 20, 20};
    int offset =-(((city->num_occupants <= 5)? city->num_occupants : 5)/2*20);
    const int og_offset = offset;
    int unit_count = 0;

    bool hide_rivals = !city->isConflict() && WEST != allegiance; //if there is no conflict then rival units are placed 'face up' and not viewable by rivals
    for (const auto& unit : city->occupants[0]){ //west units
        if (unit_count % 5 == 0){
            target.y += off;
            offset = og_offset;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
        offset += off;  unit_count++;
    }

    hide_rivals = !city->isConflict() && AXIS != allegiance;
    for (const auto& unit : city->occupants[1]){ //axis units
        if (unit_count % 5 == 0){
            target.y += off;
            offset = og_offset;
        }
        drawUnit(player, unit, target.x+offset, target.y, zoom, hide_rivals);
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

void Runner::drawCity(const Player& player, City* city, const bool resources){
    const auto& x_scale = player.app->screen.getScaleX();
    const auto& y_scale = player.app->screen.getScaleY();
    SDL_Rect target = {(int)(city->x*x_scale), (int)(city->y*y_scale), city->HEIGHT, city->WIDTH};
    auto& sprite_sheet = player.sprite_sheet;
    //- Draw the Population type (capital, subcapital, ...)
    sprite_sheet->drawSprite(&target, 8, getCitySprite(city));
    int scale = 1;
    //- Draw the resources
    if (resources){
        target = {(int)(city->res_x*x_scale), (int)(city->res_y*y_scale),23*scale , 23*scale};
        if (city->resource > 0){ //can blockade even with no resources
            sprite_sheet->drawSprite(&target, 0, (city->blockcade)? 25 : 25 + (city->resource)/((city->resource_type == TRANS_ATLANTIC)? 2 : 1), 23, 23);
            if (city->resource_type == TRANS_ATLANTIC){
                target.x +=24;
                sprite_sheet->drawSprite(&target, 0, (city->med_blockcade)? 29 : 29 + (city->resource/2), 23, 23);
            }
        }
    }
    //-Draw Units
    drawCityUnits(player, city);
}

void Runner::drawCity(int x, int y, PopulationType population_type){
    SDL_Rect target = {x, y, 32, 32};
    sprite_map.drawSprite(&target, 8, 13+5-(int)population_type);
}

void Runner::drawInfluence(const Player& player){
    //- Draw influence at the capitals
    SDL_Rect target;

    float scale = 1;
    for (const auto& country : map.getCountries()){
        target = {(int)(map.getCity(country.second->capital)->x*player.app->screen.zoom_factor*player.app->screen.WIDTH/1512+ 32*scale), (int)(map.getCity(country.second->capital)->y*player.app->screen.zoom_factor*player.app->screen.HEIGHT/982), (int)(32*scale), (int)(32*scale)};

        if (country.second->influence_level == SATELLITES){ //draw one big token
            player.sprite_sheet->drawSprite(&target, 13, country.second->allegiance*2);
        }
        else{ //draw how many influnece token it has
            for (size_t i = 0; i < country.second->influence; i++){
                player.sprite_sheet->drawSprite(&target, 13, country.second->allegiance*2+1, 32, 32, (int)(16*scale));
            }
        }
    }
}

int Runner::getCitySprite(City* city){
    switch (city->population_type){
        case MAIN_CAPITAL:
            switch (city->city_type){
                case WEST:
                    return 1;
                case AXIS:
                    return 2;
                case USSR:
                    return 0;
                default:
                    return -1;;
            }
        case SUB_CAPITAL:
            switch (city->nationality){
                case BRITIAN_U:
                    return 6;
                case FRANCE_U:
                    return 7;
                case USA_U:
                    return 8;
                case GERMANY_U:
                    return 4;
                case ITALY_U:
                    return 5;
                case USSR_U:
                    return 3;
                default:
                    return -1;;
            }
        // Cities below don't have any change in colors
        case CAPITAL_CITY:
            return 9;
        case CITY:
            return 10;
        case TOWN:
            return 11;
        case EMPTY:
            return 12;        
        default:
            return -1;
    }


    return -1;
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

void Runner::drawUnit(const Player& player, const Unit* unit, const int x, const int y, const int zoom, const bool secret){
    //- Get the sprite depending on thenationality and current CV

    SDL_Rect target {x, y, ZOOM_DIMENSIONS[zoom-1][0], ZOOM_DIMENSIONS[zoom-1][0]};
    if (zoom <= 2){
        if (secret)
            player.units_sprite_z1->drawSprite(&target, 0, 35+unit->nationality, 20, 20);
        else
            player.units_sprite_z1->drawSprite(&target, (int)unit->unit_type+7*unit->upgrading, 5*unit->nationality+unit->combat_value+unit->upgrading, 20, 20);
    }
    if (zoom == 3)
        player.units_sprite_z3->drawSprite(&target, (int)unit->unit_type+7*unit->upgrading, 5*unit->nationality+unit->combat_value+unit->upgrading, 64, 64);
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

//&&& Animations

void Runner::reshuffleAnimation(const size_t& action_size, const size_t& invest_size){
    bool running = true;
    SDL_Event event;
    int action_offset = 0;
    int invest_offset = 0;
    int scale = 5;
    int scaled_size = (5*32);
    int delta_time = rand() % (8 - 4 + 1) + 4;
    bool state = true;
    SDL_Rect target;
    while (running){
        ClearScreen(app.renderer);
        if (state){ //move cards

            target = {(app.screen.WIDTH/2-(scale*96)/2), (app.screen.HEIGHT/2-(scale*64)/2), (scale*96), (scale*64)};

            sprite_map.drawSprite(&target, 5, 7, 96, 64);

            sprite_map.selectSprite(7, 0, 32, 32);
            for (int i = 0; i < invest_size; i++){
                if (invest_offset - i*16 >= app.screen.WIDTH/2-(scale*96)/2+(9*scale))
                    target = {app.screen.WIDTH/2-(scale*96)/2+(9*scale), (app.screen.HEIGHT/2-(scale*64)/2)+(15*scale) , scaled_size, scaled_size};
                else
                    target = {invest_offset - i*16,                      (app.screen.HEIGHT/2-(scale*64)/2)+(15*scale), scaled_size, scaled_size};
                sprite_map.drawSelectedSprite(&target);

            }
            invest_offset += delta_time;

            for (int i = 0; i < action_size; i++){
                if (app.screen.WIDTH + action_offset + i*16 <= app.screen.WIDTH/2-(scale*96)/2+(57*scale))
                    target = {app.screen.WIDTH/2-(scale*96)/2+(57*scale), (app.screen.HEIGHT/2-(scale*64)/2)+(15*scale) , scaled_size, scaled_size};
                else
                    target = {app.screen.WIDTH + action_offset + i*16, (app.screen.HEIGHT/2-(scale*64)/2)+(15*scale), scaled_size, scaled_size};
                sprite_map.drawSelectedSprite(&target);

            }
            action_offset -= delta_time;
            SDL_RenderPresent(app.renderer);
        }
        else{ //finish sign
            for (int i = 0; i < 6; i++){
                ClearScreen(app.renderer);
                sprite_map.drawSprite(&target, 5, 3, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(50);

                ClearScreen(app.renderer);
                sprite_map.drawSprite(&target, 5, 4, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(50);

                ClearScreen(app.renderer);
                sprite_map.drawSprite(&target, 5, 5, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(50);

                ClearScreen(app.renderer);
                sprite_map.drawSprite(&target, 5, 6, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(100);

                ClearScreen(app.renderer);
            }

            return;
        }

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

        //- Check to see if animation is done
        if ((app.screen.WIDTH + action_offset + (action_size-1)*16    <= app.screen.WIDTH/2-(scale*96)/2+(57*scale)) &&
            (invest_offset                           >= app.screen.WIDTH/2-(scale*96)/2+(9*scale))){
            target = {app.screen.WIDTH/2-(scale*96)/2, (app.screen.HEIGHT/2-(scale*64)/2) ,(scale*96), (scale*64)};
            state = false;
            SDL_Delay(100);
        }
    }
}

void Runner::drawActionCards(const Player* player, int start_x, int start_y, int count, int scale){
    int scaled_size = 32*scale;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};

    auto& sprite_sheet = powers_sprite_map[player->getAllegiance()];

    for (size_t i = player->action_card_start; i < count && i < player->getActionSize(); i++){ //TODO have it so the seasons are already imprinted on the back for one less call
        auto card = player->getActionCard(i);
        //- draw left
        sprite_sheet.drawSprite(&target, 15, card->sprite_offset_left, 32, 32, 0);

        //- draw base middle
        sprite_sheet.drawSprite( &target, 16, 0, 32, 32, scaled_size);

        //- draw season
        sprite_sheet.drawSprite( &target, 16, card->season-1, 32, 32);

        //- draw letter
        sprite_sheet.drawSprite( &target, 16, 4+card->letter-'A', 32, 32);

        //- draw number
        sprite_sheet.drawSprite(  &target, 16, 28+card->number, 32, 32);

        //- draw right
        sprite_sheet.drawSprite( &target, 15, card->sprite_offset_right, 32, 32, scaled_size);

        target.y += scaled_size;
        target.x = start_x;
    }
}

void Runner::drawInvestCards(const Player* player, int start_x, int start_y, int count, int scale){
    int scaled_size = 32*scale;
    SDL_Rect target = {start_x,start_y,scaled_size,scaled_size};

    auto& sprite_sheet = powers_sprite_map[player->getAllegiance()];

    for (size_t i = player->invest_card_start; i < count && i < player->getInvestSize(); i++){ //TODO have it so the seasons are already imprinted on the back for one less call
        auto card = player->getInvestCard(i);
        //- draw left
        sprite_sheet.drawSprite(&target, 14, card->sprite_offset_left, 32, 32, 0);

        //- draw base factory cost
        sprite_sheet.drawSprite(&target, 14, 24+card->amount, 32, 32, scaled_size);

        //- draw right
        sprite_sheet.drawSprite(&target, 14, card->sprite_offset_right, 32, 32, scaled_size);

        target.y += scaled_size;
        target.x = start_x;
    }
}

void Runner::drawMemoResolution(const vector<std::array<size_t, 6>>& memo, vector<City*> unblocked){    
    for (const auto& city : unblocked){
        drawMap(players[WEST], true, true, false, false, false);
        size_t city_indx = city->ID;
        City* city_obj = map.getCity(city_indx);
        //printf("To link %s to the capital go: ", city->name.c_str());
        SDL_SetRenderDrawColor(powers_app[WEST].renderer, 225, 194, 20, 255);
        while (memo[city_indx][1] != 0){ //1 is previous
            //printf("%s [land:%d sea %d]to ", map.getCity(city_indx)->name.c_str(), (int)memo[city_indx][4], (int)memo[city_indx][5]);
            const int& oldx=city_obj->x, oldy=city_obj->y;
            drawCity(oldx, oldy, city_obj->population_type);
            city_indx = memo[city_indx][1];
            city_obj = map.getCity(city_indx);
            SDL_RenderDrawLine(powers_app[WEST].renderer,oldx + 16, oldy+ 16,        city_obj->x+ 16,city_obj->y+ 16);
            SDL_RenderDrawLine(powers_app[WEST].renderer, oldx-1 + 16, oldy+1+ 16,   city_obj->x-1+ 16,city_obj->y+1+ 16);
            SDL_RenderDrawLine(powers_app[WEST].renderer, oldx + 16, oldy+1+ 16,     city_obj->x+ 16, city_obj->y+1+ 16);
        }
        drawCity(city_obj->x, city_obj->y, city_obj->population_type);
        //printf("%s .\n", map.getCity(city_indx)->name.c_str());
        SDL_RenderPresent(powers_app[WEST].renderer);
        SDL_Delay(1600);

    }
    
}

//TODO fix goofy ahhh lines

void Runner::drawMemoResolution(const Player& player, const vector<std::array<size_t, 4>>& memo){
    //- Draw Map
    drawMap(player, true, true, false, false, false);
    SDL_SetRenderDrawColor(player.app->renderer, 225, 194, 20, 255);
    
    const int scale_x = player.app->screen.getScaleX();
    const int scale_y = player.app->screen.getScaleY();
    

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