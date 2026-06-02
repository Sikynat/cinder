#include "/opt/homebrew/opt/sdl2/include/SDL2/SDL.h"
#include "/opt/homebrew/opt/sdl2_ttf/include/SDL2/SDL_ttf.h"
#include <iostream>
#include "botao.h"
#include "texto.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    TTF_Font* fonte = TTF_OpenFont("/Library/Fonts/Arial Unicode.ttf", 24);

    SDL_Window* window = SDL_CreateWindow(
        "Cinder",
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
    bool hover = false;

    SDL_Rect botao2 = {100, 250, 200, 80};
    bool hover2 = false;

    SDL_Rect sair = {100, 350, 200, 80};
    bool hover3 = false;

    SDL_Color vermelho = {244, 33, 0, 255};
    SDL_Color vermelho_hover = {255, 80, 50, 255};
    SDL_Color laranja = {255, 100, 0, 255};
    SDL_Color laranja_hover = {255, 200, 0, 255};
    SDL_Color branco = {255, 255, 255, 255};

    while (rodando) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (hover) {
                        std::cout << "clicou!" << std::endl;
                    }

                    if (hover3) {
                        rodando = false;
                    }
                }
            }
        }

       

        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        SDL_Point mouse = {mouse_x, mouse_y};
        hover = SDL_PointInRect(&mouse, &botao);

        
       

        SDL_SetRenderDrawColor(renderer, 10, 10, 20, 255);
        SDL_RenderClear(renderer);

        desenhar_texto(renderer, fonte, "Cinder Engine", 100, 30, branco);

        desenhar_botao(renderer, fonte, 100, 100, 200, 80, "Clique aqui", hover, laranja, laranja_hover);

        hover2 = SDL_PointInRect(&mouse, &botao2);
        desenhar_botao(renderer, fonte, 100, 250, 200, 80, "Outro botao", hover2, laranja, laranja_hover);

        hover3 = SDL_PointInRect(&mouse, &sair);
        desenhar_botao(renderer, fonte, 100, 350, 200, 80, "Sair", hover3, vermelho, vermelho_hover);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(fonte);
    TTF_Quit();
    SDL_Quit();
    return 0;

}