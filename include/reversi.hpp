#ifndef REVERSI_HPP
#define REVERSI_HPP
#include "tabuleiro.hpp"

class Reversi : public Tabuleiro    {
    private:
        /**
         *Parâmetro responsável por monitorar a quantidade de vezes que os jogadores pularam a vez.
         */
        int pulaJogada;
    public:    
        /**
         * \brief Construtor do Reversi.
         * 
         * Cria um Tabuleiro com 8x8 casas e inicializa as quatro casas centrais com peças dos dois jogadores.
         */
        Reversi();

        /**
         * \brief Destrutor do Reversi.
         */
        ~Reversi();

        /**
         * \brief Método que verifica se a casa escolhida tem alguma ação na sua linha.
         * 
         * Recebe uma casa delimitada pelos parâmetros linha e coluna e verifica se há uma jogada possível na respectiva
         * linha, caso o parâmetro jogada seja verdadeiro a jogada será realizada, caso não apenas será retornado que a jogada
         * é possível.
         * @param linha A linha da casa escolhida.
         * @param coluna A coluna da casa escolhida.
         * @param jogada A condição da verificação, caso true será efetivada uma jogada, caso false apenas a possibilidade da jogada é testada.
         * \return true caso a jogada foi possível na linha, false caso não.
         */
        bool verificaLinha(int linha, int coluna, bool jogada);

        /**
         * \brief Método que verifica se a casa escolhida tem alguma ação na sua coluna.
         * 
         * Recebe uma casa delimitada pelos parâmetros linha e coluna e verifica se há uma jogada possível na respectiva
         * coluna, caso o parâmetro jogada seja verdadeiro a jogada será realizada, caso não apenas será retornado que a jogada
         * é possível.
         * @param linha A linha da casa escolhida.
         * @param coluna A coluna da casa escolhida.
         * @param jogada A condição da verificação, caso true será efetivada uma jogada, caso false apenas a possibilidade da jogada é testada.
         * \return true caso a jogada foi possível na coluna, false caso não.
         */
        bool verificaColuna(int linha, int coluna, bool jogada);

        /**
         * \brief Método que verifica se a casa escolhida tem alguma ação nas duas diagonais.
         * 
         * Recebe uma casa delimitada pelos parâmetros linha e coluna e verifica se há uma jogada possível nas respectivas
         * diagonais, caso o parâmetro jogada seja verdadeiro a jogada será realizada, caso não apenas será retornado que a jogada
         * é possível.
         * @param linha A linha da casa escolhida.
         * @param coluna A coluna da casa escolhida.
         * @param jogada A condição da verificação, caso true será efetivada uma jogada, caso false apenas a possibilidade da jogada é testada.
         * \return true caso a jogada foi possível nas diagonais, false caso não.
         */
        bool verificaDiagonal(int linha, int coluna, bool jogada);
        
        /**
         * \brief Método responsável por mudar um conjunto de casas de acordo com uma jogada aplicada.
         * 
         * Recebe duas casas e chama o método trocaConteudoCasa() para todas as casas no intervalo que corresponde às duas.
         * 
         * A diferenciação entre maior e menor casa utiliza a seguinte lógica:
         * 
         * Casas na mesma linha: a casa mais à direita é a maior.
         * 
         * Casas na mesma coluna: a casa mais abaixo é a maior.
         * 
         * Casas na mesma diagonal principal: A casa mais abaixo e à direita é a maior.
         * 
         * Casas na mesma diagonal secundária: A casa mais abaixo e à esquerda é a maior
         * @param linhaMaior A linha respectiva da casa que ocupa a maior posição.
         * @param colunaMaior A coluna respectiva da casa que ocupa a maior posição.
         * @param linhaMenor A linha respectiva da casa que ocupa a menor posição.
         * @param colunaMenor A linha respectiva da casa que ocupa a menor posição.
         */
        void completaCasas(int linhaMaior, int colunaMaior, int linhaMenor, int colunaMenor);

        /**
         * \brief Método responsável por verificar se há alguma jogada possível no tabuleiro.
         * 
         * Verifica cada casa no tabuleiro a procura de jogada possível.
         * 
         * \return true caso haja jogada possível, false caso não.
         */
        bool jogadaPossivel();
        
        /**
         * \brief Método responsável por pegar e realizar a jogada de um jogador.
         * 
         * Averigua se há alguma jogada possível para o jogador atual, se sim verifica se o jogador digitou uma jogada no formato: <linha> <coluna>.
         * Caso verdadeiro a jogada será feita e a vez será trocada, caso falso será indicado que a jogada é inválida.
         */
        void pegaJogada() override;
        
        /**
         * \brief Método que verifica se houve um resultado para a partida.
         * 
         * Verifica se a partida acabou checando se todas as casas foram ocupadas ou se os dois jogadores pularam sua vez,
         * caso positivo compara a quantidade de casas dominadas pelos jogadores. Define a variável vencedor como 1 caso o jogador 1 tenha vencido, 
         * 2 caso o jogador 2 tenha vencido e 0 caso empate. 
         * \return 1 caso algum jogador tenha vencido ou houve empate, 0 caso a partida não tenha chegado ao fim.
        */
        int checaVitoria() override;

        /**
         * @brief Método responsável por trocar o conteúdo de uma casa.
         * 
         * Substitui o conteúdo e o estado da casa escolhida por "1" caso seja o jogador 1 ou "2" caso seja o jogador 2.
         * @param linha A linha da casa escolhida.
         * @param coluna A coluna da casa escolhida.
         */
        void trocaConteudoCasa(int linha, int coluna) override;
};

#endif