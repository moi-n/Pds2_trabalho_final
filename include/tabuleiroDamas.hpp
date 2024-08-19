#ifndef TABULEIRO_DAMAS_H
#define TABULEIRO_DAMAS_H

#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"
#include "tabuleiro.hpp"

class TabuleiroDamas : public Tabuleiro {

  public:
    //inicializadores e destrutores
    TabuleiroDamas();
    TabuleiroDamas(int linhas, int colunas);
    virtual ~TabuleiroDamas();

    //getters e setters

    //métodos
    int verificaCaptura(int linha_peca, int coluna_peca);
    void verificaJogada(int linha_peca, int coluna_peca, int linha_destino, int coluna_destino, int capturaObrigatoria);
    void pegaJogada() override;
    void mudaConteudoCasa(int linha, int coluna, std::string conteudo);
    void limpaConteudoCasa(int linha, int coluna);
    int checaVitoria() override;
  
};

#endif
