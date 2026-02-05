#include "engine.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include "render.h"

void engine_init() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    initRenderer();
    SDL_StartTextInput();
}

void engine_shutdown() {
    SDL_StopTextInput();
    destroyRenderer();
    TTF_Quit();
    SDL_Quit();
}
