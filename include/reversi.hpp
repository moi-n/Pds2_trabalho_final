#ifndef REVERSI_HPP
#define REVERSI_HPP
#include "tabuleiro.hpp"

class Reversi : public Tabuleiro    {
    private:
        /**
         * @param pulaJogada Parâmetro responsável por monitorar a quantidade de vezes que os jogadores pularam a vez.
         */
        int pulaJogada;
    public:
        Reversi();
        ~Reversi();
        
        //parâmetro jogada indica se o método está sendo chamado por uma jogada ou para verificar se há uma jogada possível restante.
        bool verificaLinha(int linha, int coluna, bool jogada);
        bool verificaColuna(int linha, int coluna, bool jogada);
        bool verificaDiagonal(int linha, int coluna, bool jogada);
        
        void completaCasas(int X1, int X2, int Y1, int Y2);
        bool jogadaPossivel();
        
        void pegaJogada() override;
        int checaVitoria() override;
        void trocaConteudoCasa(int linha, int coluna) override;
};

#endif