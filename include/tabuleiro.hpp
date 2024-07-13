#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"

class Tabuleiro {

    private:

        int tam_linha;
        int tam_coluna;
        int jogador;        
        std::vector<std::vector<Casa>> m_tabuleiro;
        int vencedor;

    public:

        Tabuleiro(int _tam_linha, int _tam_coluna);
        virtual ~Tabuleiro();
        //
        void imprimeTabuleiro();
        void trocaConteudoCasa(int linha, int coluna, int jogador);
        void pegaJogada(int jogador);

        // pegar/mudar jogador e vencedor 
        void setJogador(int _jogador);
        int getJogador();
        void setVencedor(int _vencedor);
        int getVencedor();
        

        // checa formas de ganhar
        virtual int checaLinha(int linha);
        virtual int checaColuna(int coluna);
        virtual int checaDiagonal();
        
        //checa se ganhou
        virtual int checaVitoria();

        // checa se o tabuleiro foi totalmente preenchido
        int checaOcupacaoTotal();

};      

#endif
