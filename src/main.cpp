#include <iostream>
#include <string>
#include "jogodavelha.hpp"

int main() {
    // jogo da velha pra teste 

    JogodaVelha tabuleiro = JogodaVelha(3, 3);
    int jogador_atual = 1;
    int vitoria = 0;
    tabuleiro.imprimeTabuleiro();

    while(!tabuleiro.checaOcupacaoTotal()) {

        tabuleiro.pegaJogada(jogador_atual);
        tabuleiro.imprimeTabuleiro();

        if(tabuleiro.checaVitoria()) {
            vitoria = 1;
            break;
        }
        jogador_atual = (jogador_atual == 1) ? 2 : 1;
    }

    tabuleiro.imprimeTabuleiro();
    std::cout << "Fim de jogo!" << std::endl;

    if(vitoria) std::cout << "Parabéns jogador " << jogador_atual << "! Você GANHOU!" << std::endl;
    
    else std::cout << "EMPATE: deu velha!" << std::endl;

    return 0;
}