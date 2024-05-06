#include "/opt/homebrew/Cellar/sdl2/2.30.2/include/SDL2/SDL.h"

#include "Runner.h"

#define SDL_MAIN_HANDELED



//Colors
namespace Colors{
    const SDL_Color BLACK = {0, 0, 0, 255};
    const SDL_Color GREEN = {0, 255, 0, 255};
}

//Graphics
namespace Graphics{
    struct Screen{
        const int WIDTH = 1024;
        const int HEIGHT = 568;

        const int center_x = WIDTH /2;
        const int center_y = HEIGHT /2;
    };
};

// Game Object

// Application
struct App{
    SDL_Window* window;
    SDL_Renderer* renderer;

    Graphics::Screen screen;

} app;

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

void DrawCity(City* city){
    SDL_Rect target;

    target.x = city->x - (city->WIDTH/2);
    target.y = city->y - (city->HEIGHT/2);
    target.h = city->HEIGHT;
    target.w = city->WIDTH;

    SDL_SetRenderDrawColor(app.renderer, city->color[0], city->color[1], city->color[2], 255);

    SDL_RenderFillRect(app.renderer, &target);
}

void DrawConnections(const Runner& runner){
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
static void ShutdownApplication(){
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

bool InitApplication(){
    if (InitSDL() == false){
        ShutdownApplication();
        return false;
    }


    app.window = SDL_CreateWindow(
        "SDL Create Window (512x284)",
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

int main(int argc, char* argv[]){
    if (InitApplication() == false){
        ShutdownApplication();
        return EXIT_FAILURE;
    }

    SDL_Event event;
    bool running = true;

    Runner runner(0);

    auto cities = runner.getMap().getCities();

    while (running){
        ClearScreen(app.renderer);

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

        //Draw the connections
        DrawConnections(runner);

        //Draw the cities and troops
        for (auto city : cities){
            //printf("%d %d\n", city.second->x, city.second->y);
            DrawCity(city.second);
        }

        SDL_RenderPresent(app.renderer);
    }
    
    
    runner.freeMemory();

    printf("Memory was deleted\n");
    //!!    

    ShutdownApplication();
    return EXIT_SUCCESS;
}