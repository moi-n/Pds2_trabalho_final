#include <iostream>
#include <string>
#include <vector>
#include "gomoku.hpp"
#include "tabuleiro.hpp"

// \brief \class é responsável pelos métodos para realizar o jogo Gomoku

Gomoku::Gomoku(int linha_, int coluna_) : TabuleiroFileira(linha_, coluna_) {}

Gomoku::~Gomoku() {}

/* \brief \class Método para checar a vitória dos jogadores no formato 5 em uma linha.
Retorna o valor "1" caso o primeiro jogador tenha vencido, "2" caso o segundo jogador
tenha vencido, e retorna 0 caso nenhum dos jogadores tenha vencido a partida.
*/ 
int Gomoku::checaLinha(int linha){
    auto& tabuleiro = getTabuleiro();

    for (int i = 0; i <= num_linhas-5; i++){
        bool venceu = true;
        std::string conteudo = tabuleiro[linha][i].getConteudo();

        if (conteudo == " ") continue;
        for (int j = 1; j < 5; j++){
            if (tabuleiro[linha][i+j].getConteudo() != conteudo){
                venceu = false;
                break;
            }
        }
        if (venceu) return (conteudo == "X") ? 1 : 2;
    }
    return 0;
}

/* \brief \class Método para checar a vitória dos jogadores no formato 5 em uma coluna.
Retorna o valor "1" caso o primeiro jogador tenha vencido, "2" caso o segundo jogador
tenha vencido, e retorna 0 caso nenhum dos jogadores tenha vencido a partida.
*/
int Gomoku::checaColuna(int coluna){
    auto& tabuleiro = getTabuleiro();

    for (int m = 0; m <= num_colunas-5; m++){
        bool venceu = true;
        std::string conteudo = tabuleiro[m][coluna].getConteudo();

        if (conteudo == " ") continue;
        for (int n = 1; n < 5; n++){
            if (tabuleiro[m+n][coluna].getConteudo() != conteudo){
                venceu = false;
                break;
            }
        }
        if (venceu) return (conteudo == "X") ? 1 : 2;
    }
    return 0;
}

/* \brief \class Método para checar a vitória dos jogadores no formato 5 em uma diagonal.
Retorna o valor "1" caso o primeiro jogador tenha vencido, "2" caso o segundo jogador
tenha vencido, e retorna 0 caso nenhum dos jogadores tenha vencido a partida.
*/
int Gomoku::checaDiagonal(){
    auto& tabuleiro = getTabuleiro();
    
    // \brief \details checa a vitória em diagonal descendente para direita, sem ultrapassar o limite lateral direito
    for (int x = 0; x <= num_linhas-5; x++ ){
        for (int y = 0; y <= 10; y++){
            bool venceu = true;
            std::string conteudo = tabuleiro[x][y].getConteudo();

            if (conteudo == " ") continue;
            for (int z = 1; z < 5; z++){
                if(tabuleiro[x+z][y+z].getConteudo() != conteudo){
                    venceu = false;
                    break;
                }
            }
            if (venceu) return (conteudo == "X") ? 1 : 2;
        }
    }
    
    // \brief \details checa a vitória em diagonal descendente para esquerda, sem ultrapassar o limite lateral esquerdo
    for (int x = 0; x <= num_colunas-5; x++){
        for (int j = 4; j < num_colunas; j++){
            bool venceu = true;
            std::string conteudo = tabuleiro[x][j].getConteudo();

            if (conteudo == " ") continue;
            for (int z = 1; z < 5; z++){
                if (tabuleiro[x+z][j-z].getConteudo() != conteudo){
                    venceu = false;
                    break;
                }
            }
            if (venceu) return (conteudo == "X") ? 1 : 2;
        }
    }

    return 0;
}

/* \brief \class Método auxiliar para checar a vitória de forma geral, utilizando como base os métodos anteriores:
checaColuna(int coluna);
checaLinha(int linha);
checaDiagonal();
*/
int Gomoku::checaVitoria(){
    int coluna = 0; int linha = 0; int diagonal = 0;

    for(int i = 0; i < num_linhas; i++) {
        
        coluna = checaColuna(i);
        linha = checaLinha(i);
        diagonal = checaDiagonal();
    
        if (coluna || linha || diagonal) {
            if(jogador==1)
                vencedor=1;
            else if(jogador==2)
                vencedor=2;
            return 1;
        }
    }
     if(checaOcupacaoTotal()) 
        return 1;
    return 0;
}