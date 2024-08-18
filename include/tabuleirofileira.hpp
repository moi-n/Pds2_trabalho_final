#ifndef TABULEIROFILEIRA_HPP
#define TABULEIROFILEIRA_HPP

#include "tabuleiro.hpp"

/**
 * \brief Classe abstrata herdeira do Tabuleiro
 * 
 * Classe herdeira do Tabuleiro que possui o intuito de armazenar as funções checaLinha, checaColuna e checaDiagonal para facilitar a 
 * implementação dos jogos lig4, jogo da velha e gomoku.
 */
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