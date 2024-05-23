#include "Graphics.h"

#define SDL_MAIN_HANDELED


int main(int argc, char* argv[]){
    App app;
    Runner runner(1);

    return runner.run();
}