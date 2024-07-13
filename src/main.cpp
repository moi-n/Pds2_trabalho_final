#include <iostream>
#include <string>
#include "tabuleiro.hpp"


int main(){

    // jogo da velha pra teste 
    Tabuleiro tabuleiro(3,3);
    
    int currentJogador = 1;
    
    while (true){
        tabuleiro.imprimeTabuleiro();

        if (tabuleiro.checaOcupacaoTotal() == 1){
            break;
        }

        tabuleiro.pegaJogada(currentJogador);

        currentJogador = (currentJogador == 1) ? 2 : 1; 
    }

    tabuleiro.imprimeTabuleiro();
    return 0;
}
