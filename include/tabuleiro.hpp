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
        int vencedor;

    public:

        Tabuleiro();
        void setJogador(int);
        int getJogador();
        void setVencedor(int);
        int getVencedor();
        void imprimeTabuleiro();
        void trocaConteudoCasa(int, int, int);
        void pegaJogada();

        // checa formas de ganhar
        int checaLinha(int);
        int checaColuna(int);
        int checaDiagonal();
        
        // checa se ganhou
        int checaVitoria();

        // checa empate
        int checaOcupacaoTotal();

};      

#endif