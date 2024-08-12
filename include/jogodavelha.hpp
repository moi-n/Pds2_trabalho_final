#ifndef TABULEIROJV_H
#define TABULEIROJV_H

#include <iostream>
#include "tabuleirofileira.hpp"


class JogodaVelha : public TabuleiroFileira {

    public:

        JogodaVelha();
        JogodaVelha(int, int);
        virtual ~JogodaVelha();

        int checaLinha(int) override; 
        int checaColuna(int) override;
        int checaDiagonal() override;
        
        int checaVitoria() override;
};

#endif