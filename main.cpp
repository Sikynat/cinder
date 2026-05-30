#include "/opt/homebrew/opt/sdl2/include/SDL2/SDL.h"
#include <iostream>

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Dadonas Solutions",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Rect botao = {100, 100, 200, 80};

    SDL_Event event;
    bool rodando = true;

    while (rodando) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
        }

        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        SDL_Point mouse = {mouse_x, mouse_y};
        bool hover = SDL_PointInRect(&mouse, &botao);

        SDL_SetRenderDrawColor(renderer, 10, 10, 20, 255);
        SDL_RenderClear(renderer);

        if (hover) {
            SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
        }

        SDL_RenderFillRect(renderer, &botao);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}