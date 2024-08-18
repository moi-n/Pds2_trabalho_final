#ifndef LIG4_H
#define LIG4_H

#include <iostream>
#include <string>
#include <vector>
#include "tabuleiro.hpp"
#include "tabuleirofileira.hpp"

/**
 * \brief \class Classe Lig4
 * 
 * Classe herdeira da classe tabuleiro, que possui a função de implementar o jogo lig4. 
 */

class Lig4 : public TabuleiroFileira {

    public:
        /**
         * \brief Construtor do Lig4
         * 
         * Chama o construtor da classe Tabuleiro com o valor de linhas e colunas definidos por
         * _num_linhas e _num_colunas, respectivamente.
         * @param _num_linhas Número de linhas do tabuleiro.
         * @param _num_colunas Número de colunas do tabuleiro.
         */
        Lig4(int _num_linhas, int _num_colunas);

        /**
         * \brief Destrutor do Lig4
         */
        ~Lig4();

        /**
         * \brief Método responsável por pegar e realizar a jogada de um jogador.
         * 
         * Averigua se há alguma jogada possível para o jogador atual, se sim verifica se o jogador digitou um valor de coluna válido.
         * Caso verdadeiro a jogada será feita e a vez será trocada, caso falso será indicado que a jogada é inválida.
         */
        void pegaJogada() override;

        /**
         * \brief Método responsável pela checagem de linhas
         * 
         * Verifica se a linha recebida pelo parâmetro linha foi completada, isto é, se algum jogador colocou 4 peças em sequência na linha.
         * @param linha A linha escolhida para checagem.
         * \return 1 caso quem tenha completado a linha tenha sido o jogador 1, 2 caso tenha sido o jogador 2, 0 caso nenhum.
         */
        int checaLinha(int linha) override; 
        
        /**
         * \brief Método responsável pela checagem de colunas
         * 
         * Verifica se a coluna recebida pelo parâmetro coluna foi completada, isto é, se algum jogador colocou 4 peças em sequência na coluna.
         * @param coluna A coluna escolhida para checagem.
         * \return 1 caso quem tenha completado a coluna tenha sido o jogador 1, 2 caso tenha sido o jogador 2, 0 caso nenhum.
         */
        int checaColuna(int coluna) override;

        /**
         * \brief Método responsável pela checagem de diagonais
         * 
         * Verifica se alguma diagonal foi completada, isto é, se algum jogador colocou 4 peças em sequência na diagonal.
         * \return 1 caso quem tenha completado a linha tenha sido o jogador 1, 2 caso tenha sido o jogador 2, 0 caso nenhum.
         */
        int checaDiagonal() override;

        /**
         * \brief Método responsável pela verificação de vitória
         * 
         * Verifica se alguma linha, coluna ou diagonal foi completada, caso verdadeiro define a variável vencedor como o jogador que completou a ação. 
         * Caso o tabuleiro esteja completo por peças retorna 0.
         * \return 1 caso o jogo tenha terminado, 0 caso não.
         */
        int checaVitoria() override;

    private: 

};

#endif