#ifndef GOMOKU_H
#define GOMOKU_H

#include <iostream>
#include <string>
#include <vector>
#include "tabuleirofileira.hpp"

/*!
 * \brief \class Gomoku
 *
 * Classe herdeira da classe base Tabuleiro, que possui a função de implementar o jogo Gomoku.
 */

class Gomoku : public TabuleiroFileira{

    public:
        /*!
        * \brief Construtor com parâmetros da classe Gomoku.
        * \details Faz a chamada do construtor com parâmetros da classe Tabuleiro, possuindo dois inteiros,
        * linha e coluna, como parâmetros de entrada definidos pelo usuário.
        * \param linha_ Número de linhas do tabuleiro.
        * \param coluna_ Número de colunas do tabuleiro.
        */
        Gomoku(int linha_, int coluna_);
        /*!
        * \brief Destrutor da classe Gomoku.
        */
        virtual ~Gomoku();
        /*! 
        * \brief  Método para checar a vitória dos jogadores no formato 5 em uma linha.
        * \details Retorna o valor "1" caso o primeiro jogador tenha vencido, "2" caso o segundo jogador
        * tenha vencido, e retorna 0 caso nenhum dos jogadores tenha vencido a partida.
        * \param linha Número da linha onde será feita a checagem.
        */ 
        int checaLinha(int linha) override; 
        /*! 
        * \brief  Método para checar a vitória dos jogadores no formato 5 em uma coluna.
        * \details Retorna o valor "1" caso o primeiro jogador tenha vencido, "2" caso o segundo jogador
        * tenha vencido, e retorna 0 caso nenhum dos jogadores tenha vencido a partida.
        * \param coluna Número da coluna onde será feita a checagem.
        */ 
        int checaColuna(int coluna) override;
        /*! 
        * \brief  Método para checar a vitória dos jogadores no formato 5 em uma diagonal.
        * \details Retorna o valor "1" caso o primeiro jogador tenha vencido, "2" caso o segundo jogador
        * tenha vencido, e retorna 0 caso nenhum dos jogadores tenha vencido a partida.
        */ 
        int checaDiagonal() override;
        /*!
        * \brief Método que faz a checagem das condições de vitória do jogador.
        * \details Faz a chamada dos métodos checaLinha(), checaColuna() e checaDiagonal(). Se algum deles é diferente de 0,
        * o jogador atual vence, já que há alguma linha, coluna ou diagonal totalmente ocupada pelo jogador.
        */ 
        int checaVitoria() override;
};

#endif
