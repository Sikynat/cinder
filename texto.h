#pragma once
#include "/opt/homebrew/opt/sdl2/include/SDL2/SDL.h"
#include "/opt/homebrew/opt/sdl2_ttf/include/SDL2/SDL_ttf.h"
#include <string>

void desenhar_texto(
    SDL_Renderer* renderer, 
    TTF_Font* fonte, 
    std::string texto, 
    int x, int y, 
    SDL_Color cor
);
