#include <iostream>
#include <string>
#include "casa.hpp"
#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro(int _tam_linha, int _tam_coluna) : tam_linha(_tam_linha), tam_coluna(_tam_coluna) {

    // inicia com o primeiro jogador (1)
    this->jogador = 1; 
    // inicia com 0, termina com vencedor sendo (1) ou (2)
    this->vencedor = 0;
    m_tabuleiro = std::vector<std::vector<Casa>>(this->tam_linha, std::vector<Casa>(this->tam_coluna, Casa()));
}

Tabuleiro::~Tabuleiro(){}

std::vector<std::vector<Casa>>& Tabuleiro::getTabuleiro(){
    return m_tabuleiro;
}

void Tabuleiro::setJogador(int _jogador) {
    // alterna entre o jogador (1) e jogador (2)
    this->jogador = _jogador;
}

int Tabuleiro::getJogador() {
    return this->jogador;
}

void Tabuleiro::setVencedor(int jogador) {
    // vitoria do jogador (1) ou (2)
    this->vencedor = jogador;
}

int Tabuleiro::getVencedor() {
    return this->vencedor;
}

void Tabuleiro::imprimeTabuleiro() {

    std::cout << std::endl;
    for (int i = 0; i < this->tam_linha; i++) {
        std::cout << "| ";
        for (int j = 0; j < this->tam_coluna; j++) {
            std::cout << m_tabuleiro[i][j].getConteudo() << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Tabuleiro::trocaConteudoCasa(int linha, int coluna, int jogador) {

    if (jogador == 1){
        m_tabuleiro[linha-1][coluna-1].setConteudo("X");
        m_tabuleiro[linha-1][coluna-1].setEstado(1); // define a casa como 1 = preenchida pelo jogador1, 0 = vazia
    }

    else if (jogador == 2) {
        m_tabuleiro[linha-1][coluna-1].setConteudo("O");
        m_tabuleiro[linha-1][coluna-1].setEstado(2); // define a casa como 2 = preenchida pelo jogador2, 0 = vazia
    }

    else{
        std::cout << "Jogador Inválido!" << std::endl;
    }
}

void Tabuleiro::pegaJogada(int jogador) {

    int linha, coluna;
    
    std::cout << "Jogador " << jogador << ", digite sua jogada, linha e coluna: ";
    while(1) {

        std::cin >> linha >> coluna;

        if ((linha) > tam_linha || (coluna) > tam_coluna || m_tabuleiro[linha-1][coluna-1].getEstado() != 0) {
            
            std::cout << "Jogada inválida, digite novamente: ";
            continue;
        }

        else {
            trocaConteudoCasa(linha, coluna, jogador);
            break;
        }
    }
}

int Tabuleiro::checaOcupacaoTotal() { // retorna 1 se tiver totalmente ocupado 
    for (int i = 0; i < tam_linha; ++i) {
        for (int j = 0; j < tam_coluna; ++j) {
            if (m_tabuleiro[i][j].getEstado() == 0) {
                return 0; 
            }
        }
    }
    return 1; 
}
// classes a serem redefinidas nas classes filhas de acordo com cada regra de jogo

int Tabuleiro::checaLinha(int linha) {}

int Tabuleiro::checaColuna(int coluna) {}

int Tabuleiro::checaDiagonal() {}

int Tabuleiro::checaVitoria() {}
