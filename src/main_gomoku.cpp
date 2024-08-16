#include <iostream>
#include <string>
#include "gomoku.hpp"
#include "jogador.hpp"


int main(){

    
    std::string nome1, nome2;
    // registro
    std::cout << "Digite o nome do Jogador 1: " << std::endl;
    std::cin >> nome1;
    std::cout << "Digite o nome do Jogador 2: " << std::endl;
    std::cin >> nome2;
    Jogador::setJogador(nome1, nome1);
    Jogador::setJogador(nome2, nome2);
    Jogador jogador1(nome1);
    Jogador jogador2(nome2);
    

    // inicio meu tabuleiro de tamanho fixo 15x15
    Gomoku tabuleiro(15,15);
    // alterna entre o jogador 1 e jogador 2
    int currentJogador = 1;
    // inicia em 0 para empate,assume 1 para ganhador = jogador 1, o mesmo para 2
    int ganhador = 0;
     
    
    // loop do jogo gomoku
    while (true){
        tabuleiro.imprimeTabuleiro();

        tabuleiro.pegaJogada(); 
        
        ganhador = tabuleiro.checaVitoria();
        
        // condiçao para caso tenha um vencedor
        if (ganhador != 0){
            tabuleiro.imprimeTabuleiro();
            std::cout << "Vencedor e\' o jogador: " << ganhador << std::endl;
            break;
        }
        
        // condição para caso o jogo termine e não tenha ganhador
        if (tabuleiro.checaOcupacaoTotal() == 1 && ganhador == 0 ){
            tabuleiro.imprimeTabuleiro();
            std::cout << "O jogo terminou empatado!" << std::endl;
            break;
        }

        // altera o jogador para o próximo loop 
        currentJogador = (currentJogador == 1) ? 2 : 1;
    }


    if (ganhador == 1){
        jogador1.addResultado("gomoku", "vitoria");
        jogador2.addResultado("gomoku", "derrota");
    }
    else if (ganhador == 2){
        jogador1.addResultado("gomoku", "derrota");
        jogador2.addResultado("gomoku", "vitoria");
    }
    else if (ganhador == 0){
        jogador1.addResultado("gomoku", "empate");
        jogador2.addResultado("gomoku", "empate");
    }

    return 0;
}
