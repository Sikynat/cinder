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

    if (window == nullptr) {
        std::cout << "Erro: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 10, 10, 20, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
    SDL_Rect retangulo = {100, 100, 200, 80};
    SDL_RenderFillRect(renderer, &retangulo);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect retangulo02 = {100, 300, 200, 80};
    SDL_RenderFillRect(renderer, &retangulo02);

    SDL_RenderPresent(renderer);

    SDL_Event event;
    bool rodando = true;

    while (rodando) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}