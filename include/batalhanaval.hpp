#ifndef BATALHANAVAL_HPP
#define BATALHANAVAL_HPP

#include "tabuleiro.hpp"
#include "casa.hpp"
#include "barco.hpp"

class BatalhaNaval : public Tabuleiro {

    protected:

        std::vector<std::vector<Casa>> matriz_tabuleiro_2;
        std::vector<std::vector<std::vector<Casa>>> vetor_tabuleiros;
        std::vector<std::vector<Barco>> vetor_barcos;
        int fase_jogo;
    public:

        BatalhaNaval(); 
        BatalhaNaval(int, int);
        virtual ~BatalhaNaval() {}

        void imprimeTabuleiro() override;
        void imprimeTabuleiroAdversario();
        void pegaJogada() override;
        int inverteJogador();
        void reiniciaConteudoTabuleiro();

        void posicionaBarcos();
        void pegaPosicaoBarcos(Barco &);
        void trocaConteudoCasa(int, int);
        void trocaConteudoVizinhaca(Barco &);

        int checaVizinhaca(int, int, int);
        Barco& encontraBarco(int, int, int);

        int checaVitoria() override;

        void setFaseJogo(int);
        int getFaseJogo();
};

#endif