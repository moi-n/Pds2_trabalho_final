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
        int trataJogada(std::string);

    public:

        Tabuleiro();
        Tabuleiro(int _num_linhas, int _num_colunas);
        std::vector<std::vector<Casa>>& getTabuleiro();

        virtual ~Tabuleiro();
        
        virtual void imprimeTabuleiro();
        virtual void trocaConteudoCasa(int linha, int coluna);
        virtual void pegaJogada();

        // pegar/mudar jogador e vencedor 
        void setJogador(int _jogador);
        int getJogador();
        void setVencedor(int _vencedor);
        int getVencedor();
        
        //
        
        //checa se ganhou
        virtual int checaVitoria() = 0;

        // checa se o tabuleiro foi totalmente preenchido
        int checaOcupacaoTotal();

};      

#endif
