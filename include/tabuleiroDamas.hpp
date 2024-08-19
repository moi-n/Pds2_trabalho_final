#ifndef TABULEIRO_DAMAS_H
#define TABULEIRO_DAMAS_H

#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"
#include "tabuleiro.hpp"

/**
 * \brief \class TabuleiroDamas
 *
 * Classe herdeira da classe base Tabuleiro, com a função de implementar o jogo de Damas.
 */
class TabuleiroDamas : public Tabuleiro {

  public:
    /**
     * \brief Construtor default do tabuleiro de Damas
     * 
     * Cria um tabuleiro de Damas 8x8 por padrão, colocando as peças dos jogadores intercaladas com espaços vazios.
     */
    TabuleiroDamas();

    /**
     * \brief Construtor das Damas
     *
     * Cria um tabuleiro de Damas com a quantidade de linhas e colunas recebidas.
     * \param linhas Número de linhas do tabuleiro.
     * \param colunas Número de colunas do tabuleiro.
     */
    TabuleiroDamas(int linhas, int colunas);
     /**
     * \brief Destrutor do tabuleiro de Damas.
     */
    virtual ~TabuleiroDamas();

     /**
     * \brief Método que verifica uma possível captura
     * 
     * Recebe a localização da peça escolhida para verificar qual o jogador da vez e percorre o tabuleiro procurando
     * as peças do mesmo e verifica se elas possui uma jogada de captura disponível.
     * \param linha_peca Linha da peça escolhida pelo jogador da vez
     * \param coluna_peca Coluna da peça escolhida pelo jogador da vez.
     * \return 1 caso seja identifica um jogada de captura disponível e 0 caso contrário
     */
    int verificaCaptura(int linha_peca, int coluna_peca);

     /**
     * \brief Verifica a jogada escolhida pelo jogador
     *
     * Recebe os endereçoes da peça escolhida para mover, assim como seu destino e se há a existência de uma jogada de 
     * captura disponível. Após isso verifica a validade da jogada e, caso ela seja um jogada de captura 
     * ou caso não seja uma jogada de captura e não tenha uma jogada de captura disponível, realiza a jogada, mudando 
     * o jogador da vez caso nescessário. Do contrário, realiza um "throw" com o erro específico.
     * \param linha_peca Linha da peça escolhida para mover.
     * \param coluna_peca Coluna da peça escolhida para mover.
     * \param linha_destino Linha da posição escolhida para mover a peça.
     * \param coluna_destino Coluna da posição escolhida para mover a peça.
     * \param capturaObrigatoria Valor que define a existência de um jogada de captura disponível.
     */
    void verificaJogada(int linha_peca, int coluna_peca, int linha_destino, int coluna_destino, int capturaObrigatoria);

     /**
     * \brief Função que recebe a jogada do jogador.
     *
     * Lê as entradas do jogador no terminal e, após verificar brevemente a validade dela, manda os valores para a função
     * "verificaJogada".
     */
    void pegaJogada() override;

     /**
     *\brief Muda o valor da casa.
     *
     * Recebe um endereço do tabuleiro e muda seu conteúdo e estado de acordo com o conteúdo passado.
     * \param linha Linha da casa para mudar o conteúdo.
     * \param coluna Colunda da casa para mudar o conteúdo.
     * \param conteudo Conteúdo escolhido para colocar na casa.
     */
    void mudaConteudoCasa(int linha, int coluna, std::string conteudo);

     /**
     * \brief Limpa o conteúdo de uma casa
     *
     * Recebe a linha e a coluna de uma casa e redefine deu conteúdo para um espaço vazio e seu estado para 0.
     * \param linha Linha da casa escolhida.
     * \param coluna Coluna da casa escolhida.
     */
    void limpaConteudoCasa(int linha, int coluna);

     /**
     * \brief Verifica se houve um ganhador na partida
     *
     * A função percorre o tabuleiro procurando alguma peça que não pertença ao jogador da vez e, caso não ache uma,
     * define o jogador como o vencedor.
     */
    int checaVitoria() override;
  
};

#endif
