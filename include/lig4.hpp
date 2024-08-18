#ifndef LIG4_H
#define LIG4_H

#include <iostream>
#include <string>
#include <vector>
#include "tabuleiro.hpp"

class Lig4 : public TabuleiroFileira{

    public:
        Lig4(int _num_linhas, int _num_colunas);
        ~Lig4();

        void pegaJogada() override;

        int checaLinha(int linha) override; 
        int checaColuna(int coluna) override;
        int checaDiagonal() override;
        int checaVitoria() override;

    private: 

};

#endif