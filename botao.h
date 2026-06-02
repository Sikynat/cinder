#pragma once
#include "/opt/homebrew/opt/sdl2/include/SDL2/SDL.h"
#include "/opt/homebrew/opt/sdl2_ttf/include/SDL2/SDL_ttf.h"
#include <string>

void desenhar_botao(
    SDL_Renderer* renderer,
    TTF_Font* fonte,
    int x, int y,
    int largura, int altura,
    std::string texto,
    bool hover,
    SDL_Color cor_normal,
    SDL_Color cor_hover
);