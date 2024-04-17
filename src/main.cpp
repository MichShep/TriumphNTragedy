#include "/opt/homebrew/Cellar/sdl2/2.30.2/include/SDL2/SDL.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cout;
using std::string;

int main(){
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0){
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    string greetings = "Hello SDL2";
    cout << greetings << endl;

    SDL_Quit(); //prevent memorty leak

    return EXIT_SUCCESS;
}