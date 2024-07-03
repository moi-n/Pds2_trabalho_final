#include <iostream>
#include <string>
#include "casa.hpp"
#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro() {

    this->jogador = 1;
    this-> tam = 3;

    m_tabuleiro = std::vector<std::vector<Casa>>(this->tam, std::vector<Casa>(tam, Casa()));
}

void Tabuleiro::setJogador(int jogador) {

    this->jogador = jogador*(-1);
}

void Tabuleiro::imprimeTabuleiro() {

    std::cout << std::endl;
    for (int i = 0; i < m_tabuleiro.size(); i++) {
        std::cout << "| ";
        for (int j = 0; j < m_tabuleiro[i].size(); j++) {
        
            std::cout << m_tabuleiro[i][j].getConteudo() << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Tabuleiro::trocaConteudoCasa(int linha, int coluna, int jogador) {

    if (jogador == 1){
        m_tabuleiro[linha][coluna].setConteudo("X");
    }
    else {
        m_tabuleiro[linha][coluna].setConteudo("O");
    }
}

void Tabuleiro::pegaJogada() {

    std::string jogada;
    int linha, coluna;
    
    std::cout << "Jogador " << this->jogador << ", digite sua jogada: ";
    while(1) {

        std::getline(std::cin, jogada);

        linha = (int)(jogada[1] - '0') - 1;
        coluna = (int)(jogada[0] - 'a');

        if (jogada.size() > 2 || coluna > 2 || linha > 2) {
            
            std::cout << "Jogada inválida, digite novamente: ";
            continue;
        }
        else {
            break;
        }
    }

    trocaConteudoCasa(linha, coluna, this->jogador);
    setJogador(this->jogador);
}