#ifndef GOMOKU_H
#define GOMOKU_H

#include <iostream>
#include <string>
#include <vector>
#include "tabuleirofileira.hpp"

class Gomoku : public TabuleiroFileira{

    public:
        Gomoku(int linha_, int coluna_);
        virtual ~Gomoku();

        // funções virtuais da classe pai Tabuleiro
        int checaLinha(int linha) override; 
        int checaColuna(int coluna) override;
        int checaDiagonal() override;
        
        int checaVitoria() override;
};

#endif
