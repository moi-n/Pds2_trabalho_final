#ifndef GOMOKU_H
#define GOMOKU_H

#include <iostream>
#include <string>
#include <vector>
#include "tabuleiro.hpp"

class Gomoku : public Tabuleiro{

    public:
        Gomoku(int linha_, int coluna_);
        virtual ~Gomoku();

        // funções virtuais da classe pai Tabuleiro
        int checaLinha(int linha) override; // retorna 1 se jogador 1 ganho, 2 same, 0 se nenhum
        int checaColuna(int coluna) override;// retorna 1 se jogador 1 ganho, 2 same, 0 se nenhum
        int checaDiagonal() override;// retorna 1 se jogador 1 ganho, 2 same, 0 se nenhum
        int checaVitoria() override;

    private: 

};

#endif