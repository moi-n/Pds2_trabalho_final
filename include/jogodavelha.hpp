#ifndef TABULEIROJV_H
#define TABULEIROJV_H

#include <iostream>
#include "tabuleirofileira.hpp"

/*!
 * \brief \class JogodaVelha
 *
 * Classe herdeira da classe base Tabuleiro, que possui a função de implementar o jogo Jogo da Velha.
 */
class JogodaVelha : public TabuleiroFileira {

    public:
        /*!
        * \brief Construtor default da classe JogodaVelha.
        * \details Faz a chamada do construtor default da classe Tabuleiro.
        */
        JogodaVelha();
        /*!
        * \brief Construtor com parâmetros da classe JogodaVelha.
        * \details Faz a chamada do construtor com parâmetros da classe Tabuleiro, possuindo dois inteiros,
        * linha e coluna, como parâmetros de entrada definidos pelo usuário.
        * \param num_linhas Número de linhas do tabuleiro.
        * \param num_colunas Número de colunas do tabuleiro.
        */
        JogodaVelha(int num_linhas, int num_colunas);
        /*!
        * \brief Destrutor da classe JogodaVelha.
        */
        virtual ~JogodaVelha();
        /*!
        * \brief Método que checa se alguma linha está totalmente ocupada pelo conteúdo do jogador atual.
        * \details Um inteiro que representa a linha escolhida é recebido pelo método. Assim, varia-se as colunas
        * mantendo a linha constante para checar se a linha está totalmente ocupada pelo conteúdo do jogador. Se estiver
        * totalmente ocupada, retorna 1, se não, retorna 0.
        * \param linha Número da linha onde será feita a checagem.
        */
        int checaLinha(int linha) override; 
        /*!
        * \brief Método que checa se alguma coluna está totalmente ocupada pelo conteúdo do jogador atual.
        * \details Um inteiro que representa a coluna escolhida é recebido pelo método. Assim, varia-se as linhas
        * mantendo a coluna constante para checar se a coluna está totalmente ocupada pelo conteúdo do jogador. Se estiver
        * totalmente ocupada, retorna 1, se não, retorna 0.
        * \param coluna Número da coluna onde será feita a checagem.
        */
        int checaColuna(int coluna) override;
        /*!
        * \brief Checa se alguma das duas diagonais do tabuleiro está ocupada pelo conteúdo do jogador atual.
        * \details Como o tabuleiro do Jogo da Velha possui três linhas e três colunas, existe somente duas diagonais em todo
        * o tabuleiro. Assim, é feita a checagem do conteúdo de cada uma delas, se alguma estiver totalmente ocupada, retorna 1, 
        * se não, retorna 0.
        */
        int checaDiagonal() override;
        /*!
        * \brief Método que faz a checagem das condições de vitória do jogador.
        * \details Faz a chamada dos métodos checaLinha(), checaColuna() e checaDiagonal(). Se algum deles é 1,
        * o jogador atual vence, já que há alguma linha, coluna ou diagonal totalmente ocupada pelo jogador.
        */
        int checaVitoria() override;
};

#endif