#include <iostream>
#include <string>
#include "casa.hpp"
#include "tabuleiro.hpp"
#include "jogodavelha.hpp"

JogodaVelha::JogodaVelha() : TabuleiroFileira(0, 0) {}

JogodaVelha::JogodaVelha(int _num_linhas, int _num_colunas) : TabuleiroFileira(_num_linhas, _num_linhas) {}

JogodaVelha::~JogodaVelha() {} 

int JogodaVelha::checaLinha(int linha) {

    int soma = 1;
    if(matriz_tabuleiro[linha][0].getConteudo() != " ") {
        for(int j = 1; j < matriz_tabuleiro[linha].size(); j++) {

            if (matriz_tabuleiro[linha][0].getConteudo() == matriz_tabuleiro[linha][j].getConteudo()) {

                soma++;
            }
        }
    }
    if (soma == this->num_colunas){
       return 1;
    }
    else { 
        return 0;
    }
}

int JogodaVelha::checaColuna(int coluna) {

    int soma = 1;
    if(matriz_tabuleiro[0][coluna].getConteudo() != " ") {

        for(int i = 1; i < matriz_tabuleiro[coluna].size(); i++) {

            if (matriz_tabuleiro[0][coluna].getConteudo() == matriz_tabuleiro[i][coluna].getConteudo()) {

                soma++;
            }
        }
    }
    if (soma == this->num_colunas){
       return 1;
    }
    else { 
        return 0;
    }
}

int JogodaVelha::checaDiagonal() {

    int soma1 = 1;
    int soma2 = 1;

    if(matriz_tabuleiro[0][0].getConteudo() != " ") {

        if(matriz_tabuleiro[0][0].getConteudo() == matriz_tabuleiro[1][1].getConteudo()) {
            if(matriz_tabuleiro[0][0].getConteudo() == matriz_tabuleiro[2][2].getConteudo()) {
                return 1;
            }
        }
    }

    if(matriz_tabuleiro[2][0].getConteudo() != " ") {

        if(matriz_tabuleiro[2][0].getConteudo() == matriz_tabuleiro[1][1].getConteudo()) {
            if(matriz_tabuleiro[2][0].getConteudo() == matriz_tabuleiro[0][2].getConteudo()) {
                return 1;
            }
        }
    }
    
    return 0;
}

int JogodaVelha::checaVitoria() {

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
    return 0;
}
