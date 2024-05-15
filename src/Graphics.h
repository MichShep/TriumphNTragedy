#include "Runner.h"

// Game Object

//SDL Routines



bool Runner::InitSDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

//Graphics Routine
;
void Runner::ClearScreen(){
    SDL_SetRenderDrawColor(app.renderer, 216, 216, 216, 255);
    SDL_RenderClear(app.renderer);

}

void Runner::drawCity(City* city){
    //FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY
    SDL_Rect target;

    //- Draw the City
    target.x = city->x;
    target.y = city->y;
    target.h = city->HEIGHT;
    target.w = city->WIDTH;

    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/CityTypes.png";

    Spritesheet cities(path.c_str(), app.renderer);
    cities.selectSprite(getCitySprite(city));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

    cities.drawSelectedSprite(app.renderer, &target);

    //- Draw the Population type (capital, subcapital, ...)


    //- Draw all the units in there
    float scale = 1;
    int offset = city->HEIGHT;
    for (auto unit :city->occupants[0]){ //west
        (this->*draw[unit->unit_type])(unit, city->x, city->y+offset, scale);
        offset += 32*scale;
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[1]){ //axis
        (this->*draw[unit->unit_type])(unit, city->x+32*scale, city->y+offset, scale);
        offset += 32*scale;
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[2]){ //ussr
        (this->*draw[unit->unit_type])(unit, city->x+32*2*scale, city->y+offset, scale);
        offset += 32*scale;
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[3]){ //neutral
        (this->*draw[unit->unit_type])(unit, city->x+32*3*scale, city->y+offset, scale);
        offset += 32*scale;
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
        }
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

    SDL_Quit();
}

bool Runner::InitApplication(){
    if (InitSDL() == false){
        ShutdownApplication();
        return false;
    }


    app.window = SDL_CreateWindow(
        "SDL Create Window (Triumph And Tragedy)",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app.screen.WIDTH,
        app.screen.HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    if (app.window == nullptr){
        cout << "Unable to create window. Error: "<< SDL_GetError() << endl;
        ShutdownApplication();
        return false;
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}

//& Drawing units
void Runner::drawFortress(Unit* unit, int x, int y, float scale) const{
    //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Fortress/"+NATIONALITY_STRING[unit->nationality] +"-FORT.png";

    Spritesheet tank(path.c_str(), app.renderer);
    tank.selectSprite(unit->combat_value);

    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;

    tank.drawSelectedSprite(app.renderer, &target);

}

void Runner::drawAir(Unit* unit, const int x, const int y, const float scale) const{
    //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Air/"+NATIONALITY_STRING[unit->nationality] +"-AIR.png";

   Spritesheet tank(path.c_str(), app.renderer);
   tank.selectSprite(unit->combat_value);


    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;

    tank.drawSelectedSprite(app.renderer, &target);

}

void Runner::drawCarrier(Unit* unit, const int x, const int y, const float scale) const{
     //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Carrier/"+NATIONALITY_STRING[unit->nationality] +"-CARRIER.png";

   Spritesheet tank(path.c_str(), app.renderer);
   tank.selectSprite(unit->combat_value);


    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;

    tank.drawSelectedSprite(app.renderer, &target);
}

void Runner::drawSub(Unit* unit, const int x, const int y, const float scale) const{
     //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Tank/"+NATIONALITY_STRING[unit->nationality] +"-TANK.png";

   Spritesheet tank(path.c_str(), app.renderer);
   tank.selectSprite(unit->combat_value);


    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;

    tank.drawSelectedSprite(app.renderer, &target);
}

void Runner::drawFleet(Unit* unit, const int x, const int y, const float scale) const{
     //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Fleet/"+NATIONALITY_STRING[unit->nationality] +"-FLEET.png";

   Spritesheet tank(path.c_str(), app.renderer);
   tank.selectSprite(unit->combat_value);


    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;

    tank.drawSelectedSprite(app.renderer, &target);
}

void Runner::drawTank(Unit* unit, const int x, const int y, const float scale) const{
    //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Tank/"+NATIONALITY_STRING[unit->nationality] +"-TANK.png";

   Spritesheet tank(path.c_str(), app.renderer);
   tank.selectSprite(unit->combat_value);


    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;

    tank.drawSelectedSprite(app.renderer, &target);
}

void Runner::drawInfantry(Unit* unit, const int x, const int y, const float scale) const{
    //- Get the sprite depending on thenationality and current CV
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/Infantry/"+NATIONALITY_STRING[unit->nationality] +"-INFA.png";

    Spritesheet tank(path.c_str(), app.renderer);
    tank.selectSprite(unit->combat_value);


    SDL_Rect target;
    target.x = x;
    target.y = y;
    target.h = 32 * scale;
    target.w = 32 * scale;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

    tank.drawSelectedSprite(app.renderer, &target);
}

void Runner::drawConvoy(Unit* unit, const int x, const int y,const float scale) const{

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
    drawNumber(year, 0, app.screen.HEIGHT - 3*5*14, 5);

    //- Draw End Year
    drawNumber(end_year, 0, app.screen.HEIGHT - 2*5*13, 5);

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
        drawNumber(year-1941, 153+5*5, dot_start+15, 2.5, 255, 255, 255);
           
    }
}

void Runner::drawPlayerStats(Player& player){
    //- Get the sprite depending on the power
    string path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/PlayerStats.png";

    Spritesheet board(path.c_str(), app.renderer, 96, 64);
    board.selectSprite(player.getAllegiance());

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

    board.drawSelectedSprite(app.renderer, &target);

    //- Draw the stats onto the spots
    //(16,20) for pop, (40,20) for res (64,20) for ind (82,20) for ind_cost
    drawNumber(player.getPopulation(), x+(int)(scale*16)+7*scale/2, (int)(scale*20), 3); //pop

    drawNumber(player.getResource(), x+(int)(scale*40)+7*scale/2, (int)(scale*20), 3); //res

    drawNumber(player.getIndustry(), x+(int)(scale*64)+7*scale/2, (int)(scale*20), 3); //ind

    drawNumber(player.getIndustryCost(), x+(int)(scale*82)+7*scale/2, (int)(scale*20), 1.5); //ind_cost

    path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/DoWs.png";

    Spritesheet treaties(path.c_str(), app.renderer, 19, 19);

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
                treaties.selectSprite(3);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal peace size
                treaties.selectSprite(2);
                treaties.drawSelectedSprite(app.renderer, &target);
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
                treaties.selectSprite(5);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal peace size
                treaties.selectSprite(4);
                treaties.drawSelectedSprite(app.renderer, &target);
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
                treaties.selectSprite(7);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal neutral size
                treaties.selectSprite(6);
                treaties.drawSelectedSprite(app.renderer, &target);
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
                treaties.selectSprite(3);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal peace size
                treaties.selectSprite(2);
                treaties.drawSelectedSprite(app.renderer, &target);
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
                treaties.selectSprite(1);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal peace size
                treaties.selectSprite(0);
                treaties.drawSelectedSprite(app.renderer, &target);
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
                treaties.selectSprite(5);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal peace size
                treaties.selectSprite(4);
                treaties.drawSelectedSprite(app.renderer, &target);
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
                treaties.selectSprite(1);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            case PEACE:
                //draw normal peace size
                treaties.selectSprite(0);
                treaties.drawSelectedSprite(app.renderer, &target);
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }

    //- Draw chits
    path = "/Users/michshep/Desktop/TriumphNTragedy/sprites/PeaceChit.png";

    Spritesheet peace(path.c_str(), app.renderer);
    peace.selectSprite(0);

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
        peace.drawSelectedSprite(app.renderer, &target);
        
    }
}


void Runner::drawNumber(const int num, const int x, const int y, const float scale, const uint8_t r, const uint8_t g, const uint8_t b) const{
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

        (num == end_year)?  SDL_SetRenderDrawColor(app.renderer, 248, 194, 46, 255) : SDL_SetRenderDrawColor(app.renderer, r, g, b, 255);

        SDL_Rect target;
        if (SEVEN_SEGMENT_DISPLAY[digit][0]){ //A
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y;
            SDL_RenderFillRect(app.renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][1]){ //B
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+6*scale+offset;
            target.y = y+1*scale;
            SDL_RenderFillRect(app.renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][2]){ //C
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+6*scale+offset;
            target.y = y+7*scale;
            SDL_RenderFillRect(app.renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][3]){ //D
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y+12*scale;
            SDL_RenderFillRect(app.renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][4]){ //E
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+0*scale+offset;
            target.y = y+7*scale;
            SDL_RenderFillRect(app.renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][5]){ //F
            target.h = 5*scale;
            target.w = 1*scale;
            target.x = x+0*scale+offset;
            target.y = y+1*scale;
            SDL_RenderFillRect(app.renderer, &target);
        }
        if (SEVEN_SEGMENT_DISPLAY[digit][6]){ //G
            target.h = 1*scale;
            target.w = 5*scale;
            target.x = x+1*scale+offset;
            target.y = y+6*scale;
            SDL_RenderFillRect(app.renderer, &target);
        }
    }


}
