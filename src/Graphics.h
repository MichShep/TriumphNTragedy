#include "Runner.h"


//& SDL Routines
bool Runner::InitSDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

//Graphics Routine

void Runner::ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 216, 216, 216, 255);
    if (SDL_RenderClear(renderer) < 0){
        cout << "SDL_RenderClear failed with error: " << SDL_GetError() << endl;
    }

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

    SDL_Quit();
    exit(0);
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

    //- Init west app
    powers_app[WEST].window = SDL_CreateWindow(
        "West Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        960,
        576, 
        SDL_WINDOW_OPENGL
    );

    //- Init axis app
    powers_app[AXIS].window = SDL_CreateWindow(
        "Axis Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        960,
        576, 
        SDL_WINDOW_OPENGL
    );

    //- Init ussr app
    powers_app[USSR].window = SDL_CreateWindow(
        "USSR Player",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        960,
        576, 
        SDL_WINDOW_OPENGL
    );

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

        if (!(a.renderer = SDL_CreateRenderer(a.window, -1, SDL_RENDERER_PRESENTVSYNC))){
            cout << "Unable to create main renderer. Error: "<< SDL_GetError() << endl;
            ShutdownApplication();
        }
    }

    return true;
}

void Runner::drawCity(City* city){
    SDL_Rect target = {city->x, city->y, city->HEIGHT, city->WIDTH};

    //- Draw the Population type (capital, subcapital, ...)
    sprite_map.drawSprite(app.renderer, &target, 8, getCitySprite(city));

    //- Draw all the units in there
    float scale = 1;
    int offset = city->HEIGHT;
    for (auto unit :city->occupants[0]){ //west
        drawUnit(app.renderer, unit, city->x, city->y+offset, scale);
        offset += 32*scale;
    }

    for (auto unit :city->occupants[1]){ //axis
        drawUnit(app.renderer, unit, city->x, city->y+offset, scale);
        offset += 32*scale;
    }

    for (auto unit :city->occupants[2]){ //ussr
        drawUnit(app.renderer, unit, city->x, city->y+offset, scale);
        offset += 32*scale;
    }

    for (auto unit :city->occupants[3]){ //neutral
        drawUnit(app.renderer, unit, city->x, city->y+offset, scale);
        offset += 32*scale;
    }

    //- Draw the resources
    if (city->blockcade == true){
        target = {city->x, city->y-(int)(scale*32), city->HEIGHT, city->WIDTH};
        if (city->resource_type != TRANS_ATLANTIC){
            (city->blockcade)? sprite_map.drawSprite(app.renderer, &target, 17, 0) : sprite_map.drawSprite(app.renderer, &target, 17, 1+city->resource);
        }
        else{ //transadental
            target.x -= (int)(scale*16);
            sprite_map.drawSprite(app.renderer, &target, 17, 1+(city->resource/2));
            sprite_map.drawSprite(app.renderer, &target, 17, 4+(city->resource/2), (int)(scale*32));
        }
    }
}

void Runner::drawCity(int x, int y, PopulationType population_type){
    SDL_Rect target = {x, y, 32, 32};
    sprite_map.drawSprite(app.renderer, &target, 8, 13+5-(int)population_type);
}

void Runner::drawInfluence(){
    //- Draw influence at the capitals
    SDL_Rect target;

    float scale = 1;
    for (const auto& country : map.getCountries()){
        target = {map.getCity(country.second->capital)->x+(int)(32*scale), map.getCity(country.second->capital)->y, (int)(32*scale), (int)(32*scale)};

        if (country.second->influence_level == SATELLITES){ //draw one big token
            sprite_map.drawSprite(app.renderer, &target, 13, country.second->allegiance*2);
        }
        else{ //draw how many influnece token it has
            for (size_t i = 0; i < country.second->influence; i++){
                sprite_map.drawSprite(app.renderer, &target, 13, country.second->allegiance*2+1, 32, 32, (int)(16*scale));
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

void Runner::DrawConnections(){
    auto& map = getMap();
    auto& adjacency = getMap().getAdjacency();
    for (size_t city=0; city < adjacency.size(); city++){
        for (size_t border=0; border < adjacency.size(); border++){
            if (adjacency[city][border] == 0) //no connection
                continue;

            auto& temp = adjacency[city][border];

            SDL_SetRenderDrawColor(app.renderer, BORDER_COLOR[temp][0], BORDER_COLOR[temp][1], BORDER_COLOR[temp][2], 255);

            City* start_city = map.getCity(city);
            City* end_city = map.getCity(border);
            SDL_RenderDrawLine(app.renderer, start_city->x + start_city->WIDTH/2, start_city->y+ start_city->HEIGHT/2, end_city->x+ end_city->WIDTH/2, end_city->y+ end_city->HEIGHT/2);
            SDL_RenderDrawLine(app.renderer, start_city->x-1 + start_city->WIDTH/2, start_city->y+1+ start_city->HEIGHT/2, end_city->x-1+ end_city->WIDTH/2, end_city->y+1+ end_city->HEIGHT/2);
            SDL_RenderDrawLine(app.renderer, start_city->x + start_city->WIDTH/2, start_city->y+1+ start_city->HEIGHT/2, end_city->x+ end_city->WIDTH/2, end_city->y+1+ end_city->HEIGHT/2);
        }
    }
}

//& Drawing units
void Runner::drawUnit(SDL_Renderer* renderer, Unit* unit, int x, int y, float scale){
    //- Get the sprite depending on thenationality and current CV

    SDL_Rect target {x, y, (int)(32 * scale), (int)(32 * scale)};

    sprite_map.drawSprite(renderer, &target, 1 + (int)unit->unit_type, UNIT_SPRITE_OFFSET[unit->nationality]+unit->combat_value);
}

void Runner::DrawTimeTrack(){
    //- Draw Outline
    SDL_Rect target;

    target.h = 155;
    target.w = 145*1.5;
    target.x = 0;
    target.y = app.screen.HEIGHT - 150*1.5+5;

    //outer box
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 150;
    target.w = 140*1.5;
    target.x = 0;
    target.y = app.screen.HEIGHT - target.h*1.5+10;
    auto dot_start = app.screen.HEIGHT - target.h*1.5+10;

    //inner box
    SDL_SetRenderDrawColor(app.renderer, 125, 125, 125, 255);
    SDL_RenderFillRect(app.renderer, &target);

    //- Draw dash line
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    target.h = 5;
    target.w = 18;
    target.x = 0;
    target.y = app.screen.HEIGHT - 2*5*14;
    for (size_t i = 0; i < 5; i++){
        target.x += 5;
        SDL_RenderFillRect(app.renderer, &target);
        target.x += 23;
    }

    target.h = 25;
    target.w = 5;
    target.x = 5*7*4;
    target.y = dot_start-5;
    for (size_t i = 0; i < 5; i++){
        target.y += 7;
        SDL_RenderFillRect(app.renderer, &target);
        target.y += 25;
    }

    //- Draw Start Year
    drawNumber(app.renderer, year, 0, app.screen.HEIGHT - 3*5*14, 5);

    //- Draw End Year
    drawNumber(app.renderer, end_year, 0, app.screen.HEIGHT - 2*5*13, 5);

    //- Draw American Flag from 1941 to 1944
    if (year >= 1941 && year <= 1944){
        SDL_SetRenderDrawColor(app.renderer, 0, 0, 255, 255);
        target.h = 120;
        target.w = 50;
        target.x = 153;
        target.y = dot_start+10;

        SDL_RenderFillRect(app.renderer, &target);

        for (int i = 0; i < 5; i++){
            SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
            target.h = 80;
            target.w = 5;
            target.y = dot_start+50;

            SDL_RenderFillRect(app.renderer, &target);

            target.x += 5;

            SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);

            SDL_RenderFillRect(app.renderer, &target);

            target.x += 5;
        }

        //- Draw what level the US is at
        drawNumber(app.renderer,year-1941, 153+5*5, dot_start+15, 2.5, 255, 255, 255);
           
    }
}

//TODO optomize
void Runner::drawPlayerStats(Player& player){
    //- Get the sprite depending on the power

    float scale = 3;

    int x;

    switch (player.getAllegiance()){
        case WEST:
            x = 0;
            break;

        case AXIS:
            x = app.screen.WIDTH/2-(int)(96*scale)/2;
            break;
        case USSR:
            x = app.screen.WIDTH-(int)(96*scale);
            break;
        
        default:
            x = -1;
            break;
    }

    //- Draw the Board
    SDL_Rect target = {x, 0, (int)(96*scale), (int)(64*scale)};

    sprite_map.drawSprite(app.renderer, &target, 5, player.getAllegiance(), 96, 64);

    //- Draw the stats onto the spots
    //(16,20) for pop, (40,20) for res (64,20) for ind (82,20) for ind_cost
    drawNumber(app.renderer, player.getPopulation(), x+(int)(scale*16)+7*scale/2, (int)(scale*20), 3); //pop

    drawNumber(app.renderer,player.getResource(), x+(int)(scale*40)+7*scale/2, (int)(scale*20), 3); //res

    drawNumber(app.renderer, player.getIndustry(), x+(int)(scale*64)+7*scale/2, (int)(scale*20), 3); //ind

    drawNumber(app.renderer, player.getIndustryCost(), x+(int)(scale*82)+7*scale/2, (int)(scale*20), 1.5); //ind_cost


    switch (player.getAllegiance()){
        case WEST:{
            //check USSR DoW
            target = {(int)(x+14*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getUssrDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped size
                sprite_map.drawSprite(app.renderer, &target, 0, 3, 19, 19);
                break;
            
            case PEACE:
                //draw normal peace size
                sprite_map.drawSprite(app.renderer, &target, 0, 2, 19, 19);
                break;
            
            default:
                break;
            }
            
            //check Axis DoW
            target = {(int)(x+38*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getAxisDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped size
                sprite_map.drawSprite(app.renderer, &target, 0, 5, 19, 19);
                break;
            
            case PEACE:
                //draw normal peace size
                sprite_map.drawSprite(app.renderer, &target, 0, 4, 19, 19);
                break;
            
            default:
                break;
            }

            //check USA invlovement
            target = {(int)(x+62*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getAxisDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped at war size
                sprite_map.drawSprite(app.renderer, &target, 0, 7, 19, 19);
                break;
            
            case PEACE:
                //draw normal neutral size
                sprite_map.drawSprite(app.renderer, &target, 0, 6, 19, 19);
                break;
            
            default:
                break;
            }
        }
        break;
        case AXIS:
            //check USSR DoW
            target = {(int)(x+26*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getUssrDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped size
                sprite_map.drawSprite(app.renderer, &target, 0, 3, 19, 19);
                break;
            
            case PEACE:
                //draw normal peace size
                sprite_map.drawSprite(app.renderer, &target, 0, 2, 19, 19);
                break;
            
            default:
                break;
            }
            
            //check West DoW
            target = {(int)(x+50*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getWestDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped size
                sprite_map.drawSprite(app.renderer, &target, 0, 1, 19, 19);
                break;
            
            case PEACE:
                //draw normal peace size
                sprite_map.drawSprite(app.renderer, &target, 0, 0, 19, 19);

                break;
            
            default:
                break;
            }
            break;
        case USSR:
            //check AXis DoW
            target = {(int)(x+26*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getAxisDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped size
                sprite_map.drawSprite(app.renderer, &target, 5, 2, 19, 19);
                break;
            
            case PEACE:
                //draw normal peace size
                sprite_map.drawSprite(app.renderer, &target, 0, 4, 19, 19);
                break;
            
            default:
                break;
            }
            
            //check West DoW
            target = {(int)(x+50*scale), (int)(41*scale), (int)(19*scale), (int)(19*scale)};
            switch (player.getWestDow()){
            case VICTIM:
                //dont draw anything
                break;

            case DECLARED:
                //draw flipped size
                sprite_map.drawSprite(app.renderer, &target, 0, 1, 19, 19);

                break;
            
            case PEACE:
                //draw normal peace size
                sprite_map.drawSprite(app.renderer, &target, 0, 0, 19, 19);
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }

    //- Draw chits

    target = {(int)(x+79*scale), (int)(6*scale), (int)(8*scale), (int)(8*scale)};

    for (size_t i = 0; i < player.getPeaceDividendSize(); i++){
        auto& chit = player.getPeaceDividend(i);

        if (chit.y == 0){
            chit.y = target.y + rand() % (4 - -4 + 1) + -4;
        }
        if (chit.x == 0){
            chit.x = target.x + rand() % (4 - -4 + 1) + -4;
        }
        target.y = chit.y;
        target.x = chit.x;
        sprite_map.drawSprite(app.renderer, &target, 9, 0);
        
    }
}


void Runner::drawNumber(SDL_Renderer* renderer, const int num, const int x, const int y, const float scale, const uint8_t r, const uint8_t g, const uint8_t b) const{
    int digits = 0;
    auto copy = num;
    while (copy) {
        copy /= 10;
        digits++;
    }
    if  (num == 0)
        digits = 1;

    int offset = -(7*scale)/2;
    copy = num;
    for (int i = 1; i <= digits; i++, offset += 8*scale){
        auto f = pow(10, digits-1);
        int digit = copy/f;
        copy -= digit * f;
        copy *= 10;

        (num == end_year)?  SDL_SetRenderDrawColor(renderer, 248, 194, 46, 255) : SDL_SetRenderDrawColor(renderer, r, g, b, 255);

        SDL_Rect target;
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

void Runner::reshuffleAnimation(const size_t& action_size, const size_t& invest_size){
    bool running = true;
    SDL_Event event;
    int action_offset = 0;
    int invest_offset = 0;
    float scale = 3;
    int delta_time = rand() % (8 - 4 + 1) + 4;
    bool state = true;
    SDL_Rect target;
    while (running){
        ClearScreen(app.renderer);
        if (state){ //move cards

            target = {app.screen.WIDTH/2-(int)(scale*96)/2, app.screen.HEIGHT/2-(int)(scale*64) ,(int)(scale*96), (int)(scale*64)};

            sprite_map.drawSprite(app.renderer, &target, 5, 7, 96, 64);

            sprite_map.selectSprite(7, 0, 32, 32);
            for (int i = 0; i < invest_size; i++){
                if (invest_offset - i*16 >= app.screen.WIDTH/2-(int)(scale*96)/2+(int)(9*scale))
                    target = {app.screen.WIDTH/2-(int)(scale*96)/2+(int)(9*scale), app.screen.HEIGHT/2-(int)(scale*64)+(int)(15*scale) , (int)(scale*32), (int)(scale*32)};
                else
                    target = {invest_offset - i*16, app.screen.HEIGHT/2-(int)(scale*64)+(int)(15*scale), (int)(scale*32), (int)(scale*32)};
                sprite_map.drawSelectedSprite(app.renderer, &target);

            }
            invest_offset += delta_time;

            for (int i = 0; i < action_size; i++){
                if (app.screen.WIDTH + action_offset + i*16 <= app.screen.WIDTH/2-(int)(scale*96)/2+(int)(57*scale))
                    target = {app.screen.WIDTH/2-(int)(scale*96)/2+(int)(57*scale), app.screen.HEIGHT/2-(int)(scale*64)+(int)(15*scale) , (int)(scale*32), (int)(scale*32)};
                else
                    target = {app.screen.WIDTH + action_offset + i*16, app.screen.HEIGHT/2-(int)(scale*64)+(int)(15*scale), (int)(scale*32), (int)(scale*32)};
                sprite_map.drawSelectedSprite(app.renderer, &target);

            }
            action_offset -= delta_time;
            SDL_RenderPresent(app.renderer);
        }
        else{ //finish sign
            for (int i = 0; i < 6; i++){
                ClearScreen(app.renderer);
                sprite_map.drawSprite(app.renderer, &target, 5, 3, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(50);

                ClearScreen(app.renderer);
                sprite_map.drawSprite(app.renderer, &target, 5, 4, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(50);

                ClearScreen(app.renderer);
                sprite_map.drawSprite(app.renderer, &target, 5, 5, 96, 64);
                SDL_RenderPresent(app.renderer);
                SDL_Delay(50);

                ClearScreen(app.renderer);
                sprite_map.drawSprite(app.renderer, &target, 5, 6, 96, 64);
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
        if ((app.screen.WIDTH + action_offset + (action_size-1)*16    <= app.screen.WIDTH/2-(int)(scale*96)/2+(int)(57*scale)) &&
            (invest_offset                           >= app.screen.WIDTH/2-(int)(scale*96)/2+(int)(9*scale))){
            target = {app.screen.WIDTH/2-(int)(scale*96)/2, app.screen.HEIGHT/2-(int)(scale*64) ,(int)(scale*96), (int)(scale*64)};
            state = false;
            SDL_Delay(100);
        }
    }
}

void Runner::drawPlayerBoard(const Player& player, SDL_Renderer* renderer, const int bought_action, const int bought_invest){
    switch (player.state){
        case (HOME_BOARD):
            drawHomeBoard(player, renderer);
            break;
        case (PRODUCTION_BOARD):
            drawProductionBoard(player, renderer, bought_action, bought_invest);
            break;
        
        default:
            break;
    }
}

void Runner::drawProductionBoard(const Player& player, SDL_Renderer* renderer, const int bought_action, const int bought_invest){
    ClearScreen(renderer);

    int scale = 3;
    int scaled_size = (int)(scale*32);
    CityType allegiance = player.getAllegiance();

    //- Draw the Board
    SDL_Rect target = {0,0,960,576}, target2={0,0,32,32}, target3;
    powers_sprite_map[allegiance].drawSprite(renderer, &target, 3, 3+allegiance, 320, 192);

    //- Draw all controlled cities
    target = {20*3-scaled_size, 38*3, scaled_size, scaled_size};
    auto cities_begin = player.getControlledCitiesBegin(); //only units that are legible ot be upgrade is when they are in a frindly (controlled) undisputed area
    const auto& cities_end = player.getControlledCitiesEnd();

    for (int i = 0, count = 0; i < player.getControlledSize() && cities_begin != cities_end && count < 6; cities_begin++, i++){
        if (i < player.controlled_cities_start)
            continue;

        count++;

        //- Draw the cities where this player's units are present or where its a home territory
        const auto& city = (cities_begin)->second;

        if (!city->isConflict()){ //since we know all cities are controlled by the player we juse need to check if theres a conflict 
            powers_map_sprite[allegiance].drawSprite(renderer, &target, (city->y/128), (city->x/128), 128, 128, scaled_size+9);
            target2.x = ((city->x - (city->x/128)*128) + target.x)-32;
            target2.y = ((city->y - (city->y/128)*128) + target.y)-32;

            powers_sprite_map[allegiance].drawSprite(renderer, &target2, 8, getCitySprite(city), 32, 32);
        }
        //- Draw all units there
        int offset = 32 + 32*(city->occupants[allegiance].size() <= 3);
        target3 = {target.x, target.y+scaled_size, offset, offset};
        for (const auto& unit : city->occupants[allegiance]){
            powers_sprite_map[allegiance].drawSprite(renderer, &target3, 1 + (int)unit->unit_type, UNIT_SPRITE_OFFSET[unit->nationality]+unit->combat_value);
            if ((target3.x += offset) >= target.x + scaled_size){
                target3.x = target.x;
                target3.y += offset;
            }
        }
    }
    //256 39

    //- Draw all the cards that have been bought
    int offset = (32*scale/4);
    target = {250*scale, 39*scale, scaled_size, scaled_size};
    for (int i = 0; i < bought_action; i++){
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 0, 6, 32, 32);
        target.y += offset; 
    }
    for (int i = 0; i < bought_invest; i++){
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 0, 5, 32, 32); 
        target.y += offset;
    }

    SDL_RenderPresent(renderer);
}  

void Runner::drawHomeBoard(const Player& player, SDL_Renderer* renderer){
    ClearScreen(renderer);

    float scale = 3;
    int scaled_size = (int)(scale*32);
    CityType allegiance = player.getAllegiance();

    SDL_Rect target = {0,0,960,576};
    powers_sprite_map[allegiance].drawSprite(renderer, &target, 3, allegiance, 320, 192);

    //- Draw all Action Cards
    target = {64*3,38*3,scaled_size,scaled_size};

    for (size_t i = player.action_card_start; i < player.getActionSize(); i++){ //TODO have it so the seasons are already imprinted on the back for one less call
        auto card = player.getActionCard(i);
        //- draw left
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 15, card->sprite_offset_left, 32, 32, 0);

        //- draw base middle
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 16, 0, 32, 32, scaled_size);

        //- draw season
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 16, card->season, 32, 32);

        //- draw letter
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 16, 4+card->letter-'A', 32, 32);

        //- draw number
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 16, 28+card->number, 32, 32);

        //- draw right
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 15, card->sprite_offset_right, 32, 32, scaled_size);

        target.x += scaled_size;
        if (target.x + 3*scaled_size >= 260*3){
            break;
        }

    }

    // - Draw Industry cards
    target = {64*3,78*3,scaled_size,scaled_size};
    for (size_t i = player.invest_card_start; i < player.getInvestSize(); i++){
        auto card = player.getInvestCard(i);
        //- draw left
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 14, card->sprite_offset_left, 32, 32, 0);

        //- draw base factory cost
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 14, 24+card->amount, 32, 32, scaled_size);

        //- draw right
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 14, card->sprite_offset_right, 32, 32, scaled_size);

        target.x += scaled_size;
        if (target.x + 3*scaled_size >= 260*3){
            break;
        }
    }

    //- Draw Achieved Tech
    target = {80*3,119*3,scaled_size,scaled_size};
    for (size_t i = player.tech_card_start; i < player.getTechSize(); i++){
        powers_sprite_map[allegiance].drawSprite(renderer, &target, 14, player.getTech(i).tech, 32, 32, 0);
        if(player.getTech(i).secret){
            powers_sprite_map[allegiance].drawSprite(renderer, &target, 14, 30, 32, 32, 0);
        }

        target.x += scaled_size;
        if (target.x >= 238*3){
            break;
        }
    }

    //- Draw res/pop/ind/ind_cost/VP
    drawNumber(powers_app[allegiance].renderer,players[allegiance].getPopulation(),  292*3, 20*3, 5); //pop

    drawNumber(powers_app[allegiance].renderer,players[allegiance].getResource(),  292*3, 74*3, 5); //pop

    drawNumber(powers_app[allegiance].renderer, players[allegiance].getIndustry(),  292*3, 127*3, 5); //pop

    drawNumber(powers_app[allegiance].renderer, players[allegiance].getIndustryCost(),  303*3, 158*3, 3); //pop

    drawNumber(powers_app[allegiance].renderer, players[allegiance].getVP(),  153*3, 163*3, 4, 0, 0, 0); //pop


    SDL_RenderPresent(renderer);

}

void Runner::drawMemoResolution(const size_t memo[][6], vector<City*> unblocked){
    SDL_Rect target = {0,0,1512,912};
    
    for (const auto& city : unblocked){
        ClearScreen(app.renderer);
        map_sprite.drawSprite(app.renderer, &target, 0, 0, 1512, 912);
        size_t city_indx = city->ID;
        City* city_obj = map.getCity(city_indx);
        //printf("To link %s to the capital go: ", city->name.c_str());
        SDL_SetRenderDrawColor(app.renderer, 225, 194, 20, 255);
        while (memo[city_indx][1] != 0){ //1 is previous
            //printf("%s [land:%d sea %d]to ", map.getCity(city_indx)->name.c_str(), (int)memo[city_indx][4], (int)memo[city_indx][5]);
            const int& oldx=city_obj->x, oldy=city_obj->y;
            drawCity(oldx, oldy, city_obj->population_type);
            city_indx = memo[city_indx][1];
            city_obj = map.getCity(city_indx);
            SDL_RenderDrawLine(app.renderer,oldx + 16, oldy+ 16,        city_obj->x+ 16,city_obj->y+ 16);
            SDL_RenderDrawLine(app.renderer, oldx-1 + 16, oldy+1+ 16,   city_obj->x-1+ 16,city_obj->y+1+ 16);
            SDL_RenderDrawLine(app.renderer, oldx + 16, oldy+1+ 16,     city_obj->x+ 16, city_obj->y+1+ 16);
        }
        drawCity(city_obj->x, city_obj->y, city_obj->population_type);
        //printf("%s .\n", map.getCity(city_indx)->name.c_str());
        SDL_RenderPresent(app.renderer);
        SDL_Delay(800);

    }
    
}

void Runner::drawTurnRoll(const int& result){
    int scale = 5;
    int scaled_size = scale*32;
    SDL_Rect target = {app.screen.WIDTH/2-scaled_size/2, app.screen.HEIGHT/2-scaled_size/2, scaled_size, scaled_size};
    for (int i = 0; i < 50; i ++){
        ClearScreen(app.renderer);
        sprite_map.drawSprite(app.renderer, &target, 12, i%6);
        SDL_RenderPresent(app.renderer);
        SDL_Delay(50);
    }
    
    ClearScreen(app.renderer);
    sprite_map.drawSprite(app.renderer, &target, 12, result-1);
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    target = {app.screen.WIDTH/2-(scale*96)/2, app.screen.HEIGHT/2-(scale*64)/2, (scale*96),(scale*64)};
    SDL_Rect target2 = {(target.x+5*scale), target.y+22*scale, scaled_size, scaled_size};
    SDL_Rect target3 = {target.x+38*scale, target.y+22*scale, scaled_size, scaled_size};
    SDL_Rect target4 = {target.x+71*scale, target.y+22*scale, scaled_size, scaled_size};

    //blank
    ClearScreen(app.renderer);
    sprite_map.drawSprite(app.renderer, &target, 5, 8, 96, 64);
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    //add first
    ClearScreen(app.renderer);
    sprite_map.drawSprite(app.renderer, &target, 5, 9, 96, 64);
    sprite_map.drawSprite(app.renderer, &target2, 0, 8+turn_order[0]->getAllegiance());
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    ClearScreen(app.renderer);
    sprite_map.drawSprite(app.renderer, &target, 5, 10, 96, 64);
    sprite_map.drawSprite(app.renderer, &target2, 0, 8+turn_order[0]->getAllegiance());
    sprite_map.drawSprite(app.renderer, &target3, 0, 8+turn_order[1]->getAllegiance());
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    ClearScreen(app.renderer);
    sprite_map.drawSprite(app.renderer, &target, 5, 11, 96, 64);
    sprite_map.drawSprite(app.renderer, &target2, 0, 8+turn_order[0]->getAllegiance());
    sprite_map.drawSprite(app.renderer, &target3, 0, 8+turn_order[1]->getAllegiance());
    sprite_map.drawSprite(app.renderer, &target4, 0, 8+turn_order[2]->getAllegiance());
    SDL_RenderPresent(app.renderer);
    SDL_Delay(400);

    for (int i = 0; i < 12; i++){
        ClearScreen(app.renderer);
        sprite_map.drawSprite(app.renderer, &target, 5, 8+i%4, 96, 64);
        sprite_map.drawSprite(app.renderer, &target2, 0, 8+turn_order[0]->getAllegiance());
        sprite_map.drawSprite(app.renderer, &target3, 0, 8+turn_order[1]->getAllegiance());
        sprite_map.drawSprite(app.renderer, &target4, 0, 8+turn_order[2]->getAllegiance());
        SDL_RenderPresent(app.renderer);
        SDL_Delay(200);
    }

    ClearScreen(app.renderer);

}

