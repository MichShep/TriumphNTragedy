#include "Graphics.h"

#define SDL_MAIN_HANDELED


int main(int argc, char* argv[]){
    App app;

    if (InitApplication(app) == false){
        ShutdownApplication(app);
        return EXIT_FAILURE;
    }

    SDL_Event event;
    bool running = true;

    Runner runner(app, 0);
    runner.test();

    auto cities = runner.getMap().getCities();

    while (running){
        ClearScreen(app.renderer);

        //Draw the connections
        DrawConnections(app, runner);

        //Draw the cities and troops
        for (auto city : cities){
            //printf("%d %d\n", city.second->x, city.second->y);
            DrawCity(app, city.second);
        }

        if (SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_KEYDOWN:{
                    running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;

                    if (event.key.keysym.scancode == SDL_SCANCODE_M){
                        runner.test1();
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


        

        SDL_RenderPresent(app.renderer);
    }
    
    
    runner.freeMemory();

    printf("Memory was deleted\n");
    //!!    

    ShutdownApplication(app);
    return EXIT_SUCCESS;
}