#ifndef TABULEIROFILEIRA_HPP
#define TABULEIROFILEIRA_HPP

#include "tabuleiro.hpp"

class TabuleiroFileira : public Tabuleiro {

    public:

        TabuleiroFileira();
        TabuleiroFileira(int, int);
        virtual ~TabuleiroFileira();

        virtual int checaLinha(int linha) = 0;
        virtual int checaColuna(int coluna) = 0;
        virtual int checaDiagonal() = 0;

};

#endif