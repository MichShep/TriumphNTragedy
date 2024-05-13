#include "Runner.h"

// Game Object

//SDL Routines

bool InitSDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

//Graphics Routine
void ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, Colors::BLACK.r, Colors::BLACK.g, Colors::BLACK.b, Colors::BLACK.a);
    SDL_RenderClear(renderer);

}

void DrawCity(App& app, City* city){
    SDL_Rect target;

    target.x = city->x - (city->WIDTH/2);
    target.y = city->y - (city->HEIGHT/2);
    target.h = city->HEIGHT;
    target.w = city->WIDTH;

    SDL_SetRenderDrawColor(app.renderer, city->color[0], city->color[1], city->color[2], 255);

    SDL_RenderFillRect(app.renderer, &target);

    //Draw all the units in there
    int offset = city->HEIGHT;
    for (auto unit :city->occupants[0]){ //west
        SDL_Rect target_unit;
        target_unit.x = city->x - (city->WIDTH/2);
        target_unit.y = city->y - (city->HEIGHT/2) + offset;
        offset += 5;
        target_unit.h = 5;
        target_unit.w = 5;

        SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[(size_t)unit->unit_type][0], UNIT_COLOR[(size_t)unit->unit_type][1], UNIT_COLOR[(size_t)unit->unit_type][2], 255);

        SDL_RenderFillRect(app.renderer, &target_unit);
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[1]){ //axis
        SDL_Rect target_unit;
        target_unit.x = city->x - (city->WIDTH/2)+10;
        target_unit.y = city->y - (city->HEIGHT/2) + offset;
        offset += 5;
        target_unit.h = 5;
        target_unit.w = 5;

        SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[(size_t)unit->unit_type][0], UNIT_COLOR[(size_t)unit->unit_type][1], UNIT_COLOR[(size_t)unit->unit_type][2], 255);

        SDL_RenderFillRect(app.renderer, &target_unit);
    }

    offset = city->HEIGHT;
    for (auto unit :city->occupants[2]){ //ussr
        SDL_Rect target_unit;
        target_unit.x = city->x - (city->WIDTH/2)+20;
        target_unit.y = city->y - (city->HEIGHT/2) + offset;
        offset += 5;
        target_unit.h = 5;
        target_unit.w = 5;

        SDL_SetRenderDrawColor(app.renderer, UNIT_COLOR[(size_t)unit->unit_type][0], UNIT_COLOR[(size_t)unit->unit_type][1], UNIT_COLOR[(size_t)unit->unit_type][2], 255);
    
        SDL_RenderFillRect(app.renderer, &target_unit);
    }
}

void DrawConnections(App& app, const Runner& runner){
    auto& map = runner.getMap();
    auto& adjacency = runner.getMap().getAdjacency();
    for (size_t city=0; city < adjacency.size(); city++){
        for (size_t border=0; border < adjacency.size(); border++){
            if (adjacency[city][border] == 0) //no connection
                continue;

            auto& temp = adjacency[city][border];

            SDL_SetRenderDrawColor(app.renderer, BORDER_COLOR[temp][0], BORDER_COLOR[temp][1], BORDER_COLOR[temp][2], 255);

            SDL_RenderDrawLine(app.renderer, map.getCity(city)->x, map.getCity(city)->y, map.getCity(border)->x, map.getCity(border)->y);
        }
    }
}

// Application Routine
static void ShutdownApplication(App& app){
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

bool InitApplication(App& app){
    if (InitSDL() == false){
        ShutdownApplication(app);
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
        ShutdownApplication(app);
        return false;
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}