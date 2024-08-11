#include <iostream>
#include <string>
#include "casa.hpp"
#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro(int _num_linhas, int _num_colunas) : num_linhas(_num_linhas), num_colunas(_num_colunas) {

    // inicia com o primeiro jogador (1)
    this->jogador = 1; 
    // inicia com 0, termina com vencedor sendo (1) ou (2)
    this->vencedor = 0;
    matriz_tabuleiro = std::vector<std::vector<Casa>>(this->num_linhas, std::vector<Casa>(this->num_colunas, Casa()));
}

Tabuleiro::~Tabuleiro(){}

std::vector<std::vector<Casa>>& Tabuleiro::getTabuleiro(){
    return matriz_tabuleiro;
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
    for (int i = 0; i < this->num_linhas; i++) {
        if (i < 9){
            std::cout << 0 << i+1 << "  _" << "| ";
        }
        else{
        std::cout << i+1 << "  _" << "| ";
        }
        
        for (int j = 0; j < this->num_colunas; j++) {
            std::cout << matriz_tabuleiro[i][j].getConteudo() << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (int j = 0; j < this->num_colunas; j++) {
        std::cout << " / " << j+1;
    }
    std::cout << " / ";
    std::cout << std::endl;
    
        
}


void Tabuleiro::trocaConteudoCasa(int linha, int coluna, int jogador) {

    if (jogador == 1){
        matriz_tabuleiro[linha-1][coluna-1].setConteudo("X");
        matriz_tabuleiro[linha-1][coluna-1].setEstado(1); // define a casa como 1 = preenchida pelo jogador1, 0 = vazia
    }

    else if (jogador == 2) {
        matriz_tabuleiro[linha-1][coluna-1].setConteudo("O");
        matriz_tabuleiro[linha-1][coluna-1].setEstado(2); // define a casa como 2 = preenchida pelo jogador2, 0 = vazia
    }

    else{
        std::cout << "Jogador Inválido!" << std::endl;
    }
}

void Tabuleiro::pegaJogada(int jogador) {

    int linha, coluna;
    
    std::cout << "Jogador " << jogador << ", digite sua jogada, linha [SPACE] coluna: ";
    while(1) {

        std::cin >> linha >> coluna;

        if (linha <= 0 || coluna <= 0 || (linha) > num_linhas || (coluna) > num_colunas ||
         matriz_tabuleiro[linha-1][coluna-1].getEstado() != 0) {
            
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
    for (int i = 0; i < num_linhas; ++i) {
        for (int j = 0; j < num_colunas; ++j) {
            if (matriz_tabuleiro[i][j].getEstado() == 0) {
                return 0; 
            }
        }
    }
    return 1; 
}
