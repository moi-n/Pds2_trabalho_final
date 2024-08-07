#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"

class Tabuleiro {

    protected:

        int num_linhas;
        int num_colunas;
        int jogador;        
        int vencedor;
        std::vector<std::vector<Casa>> matriz_tabuleiro;

        std::vector<std::vector<Casa>>& getTabuleiro();

    public:
        Tabuleiro(int _num_linhas, int _num_colunas);
        virtual ~Tabuleiro();
        //
        void imprimeTabuleiro();
        virtual void trocaConteudoCasa(int linha, int coluna, int jogador);
        virtual void pegaJogada(int jogador);

        // pegar/mudar jogador e vencedor 
        void setJogador(int _jogador);
        int getJogador();
        void setVencedor(int _vencedor);
        int getVencedor();
        

        // checa formas de ganhar
        virtual int checaLinha(int linha) = 0;
        virtual int checaColuna(int coluna) = 0;
        virtual int checaDiagonal() = 0;
        
        //checa se ganhou
        virtual int checaVitoria() = 0;

        // checa se o tabuleiro foi totalmente preenchido
        int checaOcupacaoTotal();

};      

#endif
