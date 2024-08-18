#ifndef TABULEIROFILEIRA_HPP
#define TABULEIROFILEIRA_HPP

#include "tabuleiro.hpp"

/**
 * \brief \class TabuleiroFileira
 * 
 * Classe herdeira do Tabuleiro que possui o intuito de armazenar as funções checaLinha, checaColuna e checaDiagonal para facilitar a 
 * implementação dos jogos Lig4, Jogo da Velha e Gomoku.
 */
class TabuleiroFileira : public Tabuleiro {

    public:
        /*!
        * \brief Construtor default da classe TabuleiroFileira. 
        * \details É feita a chamada do construtor default da classe Tabuleiro.
        */
        TabuleiroFileira();
        /*!
        * \brief Construtor com parâmetros da classe TabuleiroFileira.
        * \details Recebe os parâmetros do número de linhas e colunas do usuário e faz a chamada do construtor 
        * da classe Tabuleiro.
        * \param num_linhas Número de linhas do tabuleiro.
        * \param num_colunas Número de colunas do tabuleiro.
        */
        TabuleiroFileira(int num_linhas, int num_colunas);
        /*!
        * \brief Destrutor da classe TabuleiroFileira.
        */
        virtual ~TabuleiroFileira();
        virtual int checaLinha(int linha) = 0;
        virtual int checaColuna(int coluna) = 0;
        virtual int checaDiagonal() = 0;
};

#endif