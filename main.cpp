#include "/opt/homebrew/opt/sdl2/include/SDL2/SDL.h"
#include <iostream>
#include "/opt/homebrew/opt/sdl2_ttf/include/SDL2/SDL_ttf.h"

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


    // Posição do botao
    SDL_Rect botao = {100, 100, 200, 80};

    SDL_Event event;

    bool rodando = true;
    bool hover = false;

    while (rodando) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    rodando = false;
                }

                if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                if (hover) {
                // clicou no botão
                std::cout << "clicou!" << std::endl;
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

        if (hover) {
            SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
        }

        SDL_RenderFillRect(renderer, &botao);

        SDL_Color cor_texto = {255, 255, 255, 255};

        SDL_Surface* superficie = TTF_RenderText_Blended(fonte, "Clique aqui", cor_texto);
        SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);

        int text_w, text_h;
        SDL_QueryTexture(textura, NULL, NULL, &text_w, &text_h);

        SDL_Rect dest = {
            botao.x + (botao.w - text_w) / 2,
            botao.y + (botao.h - text_h) / 2,
            text_w,
            text_h
        };

        SDL_RenderCopy(renderer, textura, NULL, &dest);
        SDL_FreeSurface(superficie);
        SDL_DestroyTexture(textura);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_CloseFont(fonte);
    TTF_Quit();
    return 0;
}