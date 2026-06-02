#include "texto.h"

void desenhar_texto(SDL_Renderer* renderer, 
    TTF_Font* fonte,
     std::string texto, 
     int x, int y, SDL_Color cor) 
     
     { 
        // Envia para a memoria
        SDL_Surface* superficie = TTF_RenderText_Blended(fonte, texto.c_str(), cor);
        // Envia para a GPU
        SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);
        // Pega o tamanho do texto
        int text_w, text_h;
        SDL_QueryTexture(textura, NULL, NULL, &text_w, &text_h);
        // Onde vai aparecer na tela
        SDL_Rect dest = {x, y, text_w, text_h};
        //Desenhar na tela
        SDL_RenderCopy(renderer, textura, NULL, &dest);
        SDL_FreeSurface(superficie);
        //Liberar memoria
        SDL_DestroyTexture(textura);
        
}


     