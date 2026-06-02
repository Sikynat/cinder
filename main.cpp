#include "/opt/homebrew/opt/sdl2/include/SDL2/SDL.h"
#include "/opt/homebrew/opt/sdl2_ttf/include/SDL2/SDL_ttf.h"
#include <iostream>
#include "botao.h"
#include "texto.h"

int main() {
    // Inicia o subsistema de video do SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Inicia a biblioteca de fontes
    TTF_Init();

    // Carrega a fonte Arial com tamanho 24
    TTF_Font* fonte = TTF_OpenFont("/Library/Fonts/Arial Unicode.ttf", 24);

    // Cria a janela centralizada com resolucao 800x600
    SDL_Window* window = SDL_CreateWindow(
        "Cinder",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    // Cria o renderer responsavel por desenhar dentro da janela
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Define as areas clicaveis dos botoes (x, y, largura, altura)
    SDL_Rect clique_aqui = {100, 100, 200, 80};
    SDL_Rect outro_botao = {100, 250, 200, 80};
    SDL_Rect abrir = {350, 100, 200, 80};
    SDL_Rect sair = {100, 350, 200, 80};

    // Variavel de controle do loop principal
    SDL_Event event;
    bool rodando = true;

    // Estado de hover de cada botao
    bool clique_aqui_hover = false;
    bool outro_botao_hover = false;
    bool abrir_hover = false;
    bool sair_hover = false;
   

    // Paleta de cores usada nos botoes
    SDL_Color vermelho = {244, 33, 0, 255};
    SDL_Color vermelho_hover = {255, 80, 50, 255};
    SDL_Color laranja = {255, 100, 0, 255};
    SDL_Color laranja_hover = {255, 200, 0, 255};
    SDL_Color verde = {127, 255, 0, 255};
    SDL_Color verde_hover = {0, 128, 0, 255};
    SDL_Color branco = {255, 255, 255, 255};

    // Loop principal — mantém o app rodando ate o usuario fechar
    while (rodando) {

        // Captura eventos do sistema (fechar janela, cliques, teclado)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rodando = false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (clique_aqui_hover) {
                        std::cout << "clicou!" << std::endl;
                    }
                    // Botao sair encerra o loop
                    if (sair_hover) {
                        rodando = false;
                    }
                }
            }
        }

        // Atualiza a posicao do mouse a cada frame
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_Point mouse = {mouse_x, mouse_y};

        // Verifica se o mouse esta sobre cada botao
        clique_aqui_hover = SDL_PointInRect(&mouse, &clique_aqui);
        outro_botao_hover = SDL_PointInRect(&mouse, &outro_botao);
        sair_hover = SDL_PointInRect(&mouse, &sair);
        abrir_hover = SDL_PointInRect(&mouse, &abrir);
      
        // Limpa a tela com a cor de fundo
        SDL_SetRenderDrawColor(renderer, 10, 10, 20, 255);
        SDL_RenderClear(renderer);

        // Desenha o titulo e os botoes
        desenhar_texto(renderer, fonte, "Cinder Engine", 100, 30, branco);
        desenhar_texto(renderer, fonte, "Versao: 0.0.1", 400, 30, branco);
        desenhar_botao(renderer, fonte, 100, 100, 200, 80, "Clique aqui", clique_aqui_hover, laranja, laranja_hover);
        desenhar_botao(renderer, fonte, 100, 250, 200, 80, "Outro botao", outro_botao_hover, laranja, laranja_hover);
        desenhar_botao(renderer, fonte, 100, 350, 200, 80, "Sair", sair_hover, vermelho, vermelho_hover);
        desenhar_botao(renderer, fonte, 350, 100, 200, 80, "Abrir", abrir_hover, verde, verde_hover);

        // Envia o frame renderizado para a tela
        SDL_RenderPresent(renderer);
    }

    // Libera todos os recursos na ordem inversa da criacao
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(fonte);
    TTF_Quit();
    SDL_Quit();

    return 0;
}