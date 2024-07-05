#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"
#include "tabuleiro.hpp"

int main() {

    Tabuleiro t = Tabuleiro();
    int jogadas = 0;
    t.imprimeTabuleiro();
    int vitoria = 0;

    while(!t.checaOcupacaoTotal()) {

        t.pegaJogada();
        t.setJogador(t.getJogador());
        t.imprimeTabuleiro();
        
        vitoria = t.checaVitoria();
        if (vitoria) {
            break;
        }
    }
    
    std::cout << "Fim de jogo" << std::endl;
    
    if (vitoria) {
        std::cout << "Vitória do jogador " << t.getJogador()*-1 << std::endl;
    }
    else {
        std::cout << "Empate: deu velha!" << std::endl;
    }

    return 0;
}