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
void Runner::ClearScreen(){
    SDL_SetRenderDrawColor(app.renderer, 216, 216, 216, 255);
    SDL_RenderClear(app.renderer);

}

void Runner::DrawCity(City* city){
    //FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY
    SDL_Rect target;

    target.x = city->x;
    target.y = city->y;
    target.h = city->HEIGHT;
    target.w = city->WIDTH;

    SDL_SetRenderDrawColor(app.renderer, city->color[0], city->color[1], city->color[2], 255);

    SDL_RenderFillRect(app.renderer, &target);

    //Draw all the units in there
    float scale = 5;
    int offset = city->HEIGHT;
    for (auto unit :city->occupants[0]){ //west
        (this->*draw[unit->unit_type])(unit, city->x, city->y+offset, scale);
        offset += 5*scale;
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[1]){ //axis
        (this->*draw[unit->unit_type])(unit, city->x+6*scale, city->y+offset, scale);
        offset += 5*scale;
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[2]){ //ussr
        (this->*draw[unit->unit_type])(unit, city->x+12*scale, city->y+offset, scale);
        offset += 5*scale;
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[3]){ //neutral
        (this->*draw[unit->unit_type])(unit, city->x+18*scale, city->y+offset, scale);
        offset += 5*scale;
    }
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
    //- Create base square
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = (int)(5*scale);
    target.w = target.h;
    target.x = (float)x;
    target.y = (float)y;

    SDL_RenderFillRect(app.renderer, &target);

    //- Draw inner rect
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

    target.h = (int)(3*scale);
    target.w = target.h;
    target.x = (float)x+1*scale;
    target.y = (float)y+1*scale;

    SDL_SetRenderDrawColor(app.renderer, 70, 68, 62, 255);

    SDL_RenderFillRect(app.renderer, &target);

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+0*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+0*scale;
        target.y = (float)y+2*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+4*scale;
        target.y = (float)y+2*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+4*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }


}

void Runner::drawAir(Unit* unit, const int x, const int y, const float scale) const{
    //- Create long cross sectinon
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = 1*scale;
    target.w = 5*scale;
    target.x = (float)x;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create mid section
    target.h = 1*scale;
    target.w = 3*scale;
    target.x = (float)x+1*scale;
    target.y = (float)y+2*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create vertical bar
    target.h = 5*scale;
    target.w = 1*scale;
    target.x = (float)x+2*scale;
    target.y = (float)y+0*scale;
    SDL_RenderFillRect(app.renderer, &target);
    

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

}

void Runner::drawCarrier(Unit* unit, const int x, const int y, const float scale) const{
    //- Create first long cross section
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = 1*scale;
    target.w = 5*scale;
    target.x = (float)x;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create second long cross section
    target.h = 1*scale;
    target.w = 5*scale;
    target.x = (float)x;
    target.y = (float)y+3*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create bar going down
    target.h = 4*scale;
    target.w = 1*scale;
    target.x = (float)x+2*scale;
    target.y = (float)y+0;
    SDL_RenderFillRect(app.renderer, &target);


    //- Create the two little bits at the bottem
    target.h = 1*scale;
    target.w = 1*scale;
    target.x = (float)x+1*scale;
    target.y = (float)y+4*scale;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 1*scale;
    target.w = 1*scale;
    target.x = (float)x+3*scale;
    target.y = (float)y+4*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }
}

void Runner::drawSub(Unit* unit, const int x, const int y, const float scale) const{
    //- Create bottom left
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = 2*scale;
    target.w = 3*scale;
    target.x = (float)x;
    target.y = (float)y+3*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create middle section
    target.h = 2*scale;
    target.w = 2*scale;
    target.x = (float)x+1*scale;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create top right
    target.h = 3*scale;
    target.w = 2*scale;
    target.x = (float)x+3*scale;
    target.y = (float)y+0;
    SDL_RenderFillRect(app.renderer, &target);


    //- Create the two little bits at the bottem
    target.h = 1*scale;
    target.w = 1*scale;
    target.x = (float)x+1*scale;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 1*scale;
    target.w = 1*scale;
    target.x = (float)x+4*scale;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }
}

void Runner::drawFleet(Unit* unit, const int x, const int y, const float scale) const{
    //- Create first long cross section
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = 5*scale;
    target.w = 1*scale;
    target.x = (float)x+2*scale;
    target.y = (float)y;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create second long cross section
    target.h = 1*scale;
    target.w = 5*scale;
    target.x = (float)x;
    target.y = (float)y+3*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create bar going down
    target.h = 5*scale;
    target.w = 1*scale;
    target.x = (float)x+2*scale;
    target.y = (float)y+0;
    SDL_RenderFillRect(app.renderer, &target);


    //- Create the two little bits at the bottem
    target.h = 1*scale;
    target.w = 1*scale;
    target.x = (float)x+0*scale;
    target.y = (float)y+4*scale;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 1*scale;
    target.w = 1*scale;
    target.x = (float)x+4*scale;
    target.y = (float)y+4*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+0*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+4*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }
}

void Runner::drawTank(Unit* unit, const int x, const int y, const float scale) const{
    //- Draw the main rectangles
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = (int)(5*scale);
    target.w = (int)(3*scale);
    target.x = (float)x+1*scale;
    target.y = (float)y;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = (int)(3*scale);
    target.w = (int)(5*scale);
    target.x = (float)x;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+2*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+2*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

}

void Runner::drawInfantry(Unit* unit, const int x, const int y, const float scale) const{
    //- Create the 4 spikes
    SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[unit->nationality][0], UNIT_COLOR[unit->nationality][1], UNIT_COLOR[unit->nationality][2], 255);
    SDL_Rect target;
    target.h = 2*scale;
    target.w = 1*scale;
    target.x = (float)x;
    target.y = (float)y;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 2*scale;
    target.w = 1*scale;
    target.x = (float)x+4*scale;
    target.y = (float)y;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 2*scale;
    target.w = 1*scale;
    target.x = (float)x;
    target.y = (float)y+3*scale;
    SDL_RenderFillRect(app.renderer, &target);

    target.h = 2*scale;
    target.w = 1*scale;
    target.x = (float)x+4*scale;
    target.y = (float)y+3*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Create middle section
    target.h = 3*scale;
    target.w = 3*scale;
    target.x = (float)x+1*scale;
    target.y = (float)y+1*scale;
    SDL_RenderFillRect(app.renderer, &target);

    //- Draw the pips
    if (unit->max_combat_value >= 1){
        (1 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+1*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 2){
        (2 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+1*scale;
        target.y = (float)y+2*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 3){
        (3 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+3*scale;
        target.y = (float)y+2*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }

    if (unit->max_combat_value >= 4){
        (4 <= unit->combat_value)? SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255) : SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        target.h = 1*scale;
        target.w = target.h;
        target.x = (float)x+2*scale;
        target.y = (float)y+3*scale;
        SDL_RenderFillRect(app.renderer, &target);
    }
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
