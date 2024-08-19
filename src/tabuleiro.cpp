#include <iostream>
#include <string>
#include <stdexcept>
#include "casa.hpp"
#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro() : Tabuleiro(0, 0) {}

Tabuleiro::Tabuleiro(int _num_linhas, int _num_colunas) : num_linhas(_num_linhas), num_colunas(_num_colunas) {

    // inicia com o primeiro jogador (1)
    this->jogador = 1; 
    // inicia com 0, termina com vencedor sendo (1) ou (2)
    this->vencedor = 0;
    matriz_tabuleiro = std::vector<std::vector<Casa>>(this->num_linhas, std::vector<Casa>(this->num_colunas, Casa()));
}

Tabuleiro::~Tabuleiro(){}

const char* Tabuleiro::saidaSistema::what() const throw() {
    return "Saida do sistema";
}

std::vector<std::vector<Casa>>& Tabuleiro::getTabuleiro(){
    return matriz_tabuleiro;
}

int Tabuleiro::getJogador() {
    return this->jogador;
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
        if (j > 9){
            std::cout << "/ " << j+1;
        }
        else{
        std::cout << " / " << j+1;
        }
    }
    std::cout << " / ";
    std::cout << std::endl;
}

void Tabuleiro::trocaConteudoCasa(int linha, int coluna) {

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
    if (!checaVitoria()) { 
        this->jogador = (this->jogador == 1) ? 2 : 1;
    }
}

int Tabuleiro::trataJogada(std::string jogada)    {
    if(jogada=="FS"||jogada=="fs")
        throw Tabuleiro::saidaSistema();

    for(auto i : jogada)    
        if(i-'0'<0 || i-'0'>9)
            throw std::invalid_argument("Erro: jogada invalida");
    return std::stoi(jogada);
}

void Tabuleiro::pegaJogada() {

    int linha, coluna;
    std::string jogada;

    while(true) {
        std::cout << "Jogador " << jogador << ", digite sua jogada, linha [SPACE] coluna: "; 
        
        try {
            std::cin >> jogada;
            linha = trataJogada(jogada);
            std::cin >> jogada;
            coluna = trataJogada(jogada);

            if(!std::cin)
                throw std::invalid_argument("Erro: formato incorreto");
            else if (linha > num_linhas || coluna > num_colunas || linha < 1 || coluna < 1) {
                throw std::out_of_range("ERRO: jogada invalida");
            } else if (matriz_tabuleiro[linha - 1][coluna - 1].getEstado()) {
                throw std::invalid_argument("ERRO: jogada invalida");
            }
            break;
        } catch(Tabuleiro::saidaSistema &e)   {
            std::cout << e.what() << std::endl;
            throw;    
        } catch(std::exception &e) {
            getline(std::cin, jogada);
            std::cout << e.what() << std::endl;
        } catch(...) {
            std::cout << "Excecao desconhecida" << std::endl;
        }
    }
    trocaConteudoCasa(linha, coluna);
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