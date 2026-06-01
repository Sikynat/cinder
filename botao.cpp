#include "botao.h"

void desenhar_botao(
    SDL_Renderer* renderer,
    TTF_Font* fonte,
    int x, int y,
    int largura, int altura,
    std::string texto,
    bool hover
) {
    SDL_Rect botao = {x, y, largura, altura};

    if (hover) {
        SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
    }

    SDL_RenderFillRect(renderer, &botao);

    SDL_Color cor_texto = {255, 255, 255, 255};
    SDL_Surface* superficie = TTF_RenderText_Blended(fonte, texto.c_str(), cor_texto);
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);

    int text_w, text_h;
    SDL_QueryTexture(textura, NULL, NULL, &text_w, &text_h);

    SDL_Rect dest = {
        x + (largura - text_w) / 2,
        y + (altura - text_h) / 2,
        text_w,
        text_h
    };

    SDL_RenderCopy(renderer, textura, NULL, &dest);
    SDL_FreeSurface(superficie);
    SDL_DestroyTexture(textura);
}