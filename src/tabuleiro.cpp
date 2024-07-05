#include <iostream>
#include <string>
#include "casa.hpp"
#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro() {

    this->jogador = 1;
    this-> tam = 3;
    this->vencedor = 0;

    m_tabuleiro = std::vector<std::vector<Casa>>(this->tam, std::vector<Casa>(tam, Casa()));
}

void Tabuleiro::setJogador(int jogador) {

    this->jogador = jogador*(-1);
}

int Tabuleiro::getJogador() {

    return this->jogador;
}
void Tabuleiro::setVencedor(int jogador) {

    this->vencedor = jogador;
}
int Tabuleiro::getVencedor() {

    return this->vencedor;
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

        if (jogada.size() > 2 || coluna > 2 || linha > 2 || m_tabuleiro[linha][coluna].getEstado()) {
            
            std::cout << "Jogada inválida, digite novamente: ";
            continue;
        }
        else {
            break;
        }
    }

    trocaConteudoCasa(linha, coluna, this->jogador);
    m_tabuleiro[linha][coluna].setEstado(1);
}

int Tabuleiro::checaOcupacaoTotal() {

    for(int i = 0; i < m_tabuleiro.size(); i++) {
        for(int j = 0; j < m_tabuleiro[i].size(); j++) {

            if(m_tabuleiro[i][j].getEstado() == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int Tabuleiro::checaLinha(int linha) {

    int soma = 1;
    if(m_tabuleiro[linha][0].getConteudo() != " ") {
        for(int j = 1; j < m_tabuleiro[linha].size(); j++) {

            if (m_tabuleiro[linha][0].getConteudo() == m_tabuleiro[linha][j].getConteudo()) {

                soma++;
            }
        }
    }
    if (soma == this->tam){
       return 1;
    }
    else { 
        return 0;
    }
}

int Tabuleiro::checaColuna(int coluna) {

    int soma = 1;
    if(m_tabuleiro[0][coluna].getConteudo() != " ") {

        for(int i = 1; i < m_tabuleiro[coluna].size(); i++) {

            if (m_tabuleiro[0][coluna].getConteudo() == m_tabuleiro[i][coluna].getConteudo()) {

                soma++;
            }
        }
    }
    if (soma == this->tam){
       return 1;
    }
    else { 
        return 0;
    }
}

int Tabuleiro::checaDiagonal() {

    int soma1 = 1;
    int soma2 = 1;

    if(m_tabuleiro[0][0].getConteudo() != " ") {

        if(m_tabuleiro[0][0].getConteudo() == m_tabuleiro[1][1].getConteudo()) {
            if(m_tabuleiro[0][0].getConteudo() == m_tabuleiro[2][2].getConteudo()) {
                return 1;
            }
        }
    }

    if(m_tabuleiro[2][0].getConteudo() != " ") {

        if(m_tabuleiro[2][0].getConteudo() == m_tabuleiro[1][1].getConteudo()) {
            if(m_tabuleiro[2][0].getConteudo() == m_tabuleiro[0][2].getConteudo()) {
                return 1;
            }
        }
    }
    
    return 0;
}

int Tabuleiro::checaVitoria() {

    int coluna = 0; int linha = 0; int diagonal = 0;

    for(int i = 0; i < m_tabuleiro[0].size(); i++) {
        
        coluna = checaColuna(i);
        linha = checaLinha(i);
        diagonal = checaDiagonal();
    
        if (coluna || linha || diagonal) {
            return 1;
        }
    }
    return 0;
}
