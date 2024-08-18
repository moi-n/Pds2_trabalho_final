#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"

/**
 * \brief \class Tabuleiro
 * 
 * É a classe base utilizada para criar todos os jogos. É composta pela classe Casa.
 */
class Tabuleiro {
 
    protected:
        /**
         *Número de linhas do tabuleiro.
         */
        int num_linhas; 
        
        /**
         *Número de colunas do tabuleiro. 
         */
        int num_colunas;
        
        /**
         *Jogador correspondente à jogada atual.
         */
        int jogador;        
        /**
         *Jogador vencedor.
         */
        int vencedor;

        /**
         *A matriz num_linhas x num_colunas correspondente ao tabuleiro do jogo.
         */
        std::vector<std::vector<Casa>> matriz_tabuleiro;

        
        /**
         * \brief Método responsável por receber uma jogada e verificar se há caracteres não numéricos compondo-a.
         * \return O inteiro associado à jogada, caso seja encontrado um caractere não numérico uma excessão é lançada.
         */

        int trataJogada(std::string);

    public:
        /**
         * \brief Construtor default do Tabuleiro, cria um tabuleiro de tamanho 0.
         */
        Tabuleiro();
        
        /**
         * \brief Construtor do Tabuleiro, cria um tabuleiro de acordo com o tamanho passado pelos parâmetros
         * _num_linha e _num_coluna.
         * @param _num_linhas Número de linhas do tabuleiro construído.
         * @param _num_colunas Número de colunas do tabuleiro construído.
         */
        Tabuleiro(int _num_linhas, int _num_colunas);
        
        
        /**
         * \brief Destrutor do tabuleiro.
         */
        virtual ~Tabuleiro();
        
        /**
         * \brief Método responsável por retornar a variável matriz_tabuleiro.
         * \return matriz_tabuleiro
         */
        std::vector<std::vector<Casa>>& getTabuleiro();

        /**
         * \brief Método responsável por imprimir o tabuleiro.
         */
        virtual void imprimeTabuleiro();

        /**
         * \brief Método responsável por trocar o conteúdo de uma casa.
         * 
         * Substitui o conteúdo e o estado da casa escolhida por "X" caso seja o jogador 1 ou "O" caso seja o jogador 2.
         * @param linha A linha correspondente da casa escolhida.
         * @param coluna A coluna correspondente da casa escolhida.
         */
        virtual void trocaConteudoCasa(int linha, int coluna);

        /**
         * \brief Método responsável por pegar e realizar a jogada de um jogador.
         * 
         * Averigua se há alguma jogada possível para o jogador atual, se sim verifica se o jogador digitou uma jogada no formato: <linha> <coluna>.
         * Caso verdadeiro a jogada será feita e a vez será trocada, caso falso será indicado que a jogada é inválida.
         */
        virtual void pegaJogada();
        
        /**
         * \brief Método responsável por retornar quem foi o vencedor da partida.
         * 
         * \return vencedor
         */
        int getVencedor();

        /**
         * \brief Método responsável por retornar o jogador atual.
         * \return jogador
         */
        int getJogador();

        /**
         * \brief Método abstrato responsável por checar a condição de vitória.
         */
        virtual int checaVitoria() = 0;

        /**
         * \brief Método responsável por indicar se o tabuleiro foi completamente preenchido.
         * \return 1 caso completamente preenchido, 0 caso não.
         */
        int checaOcupacaoTotal();

};      

#endif
