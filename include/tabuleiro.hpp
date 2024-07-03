#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"

class Tabuleiro {

    private:

        int tam;
        int jogador;        
        std::vector<std::vector<Casa>> m_tabuleiro;

    public:

        Tabuleiro();
        void setJogador(int);
        void imprimeTabuleiro();
        void trocaConteudoCasa(int, int, int);
        void pegaJogada();
};

#endif