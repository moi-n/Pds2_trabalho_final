#include <iostream>
#include <string>
#include <vector>
#include "gomoku.hpp"
#include "tabuleiro.hpp"

Gomoku::Gomoku(int linha_, int coluna_) : TabuleiroFileira(linha_, coluna_) {}

Gomoku::~Gomoku() {}

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

int Gomoku::checaDiagonal(){
    auto& tabuleiro = getTabuleiro();
    //x representando cada linha, y/j cada coluna, z a area final 

    // checa descendo para direita 
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
    
    // checa descendo para esquerda
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

int Gomoku::checaVitoria(){
    for (int i = 0; i < num_linhas; i++){
        int vencedor = checaLinha(i);
        if (vencedor) return vencedor;
    }

    for (int j = 0; j < num_colunas; j++){
        int vencedor = checaColuna(j);
        if (vencedor) return vencedor;
    }

    return checaDiagonal();
}