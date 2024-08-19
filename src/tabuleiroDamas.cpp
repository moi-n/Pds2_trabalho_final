#ifndef TABULEIRO_DAMAS_H
#define TABULEIRO_DAMAS_H

#include <iostream>
#include <string>
#include <vector>
#include "tabuleiroDamas.hpp"
#include "casa.hpp"
#include "tabuleiro.hpp"

TabuleiroDamas::TabuleiroDamas() : TabuleiroDamas(0, 0) {}

TabuleiroDamas::TabuleiroDamas(int linhas, int colunas) : tabuleiro(linhas, colunas){
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      if ((i + j)%2 != 0) {
        if(i < 3){
          matriz_tabuleiro[i][j].setConteudo("x");
          matriz_tabuleiro[i][j].setEstado(1);
          this->pecas1.push_back(posicao(i, j));
          m++
        }
        else if(i > 4){
          matriz_tabuleiro[i][j].setConteudo("o");
          matriz_tabuleiro[i][j].setEstado(2);
        }
      }
    }
  }
}

TabuleiroDamas::~TabuleiroDamas(){}

//checa se a peca escolhida pode comer alguma peça adversaria nas 4 direçoes possiveis
int TabuleiroDamas::verificaCaptura(int linha_peca, int coluna_peca){
  for(int i = 0; i<this->num_linhas; i++){
    for(int j = 0; j<this->num_colunas; j++){
      //checa se é uma peça normal do jogador 1
      if(matriz_tabuleiro[linha_peca -1][coluna_peca-1].getEstado() == 1 && 
      matriz_tabuleiro[i][j] == "x"){
        //direçãosuperior esquerda
        if(i > 1 && j > 1){
          if(matriz_tabuleiro[i - 1][j - 1].getEstado() == 2 &&
            matriz_tabuleiro[i - 2][j - 2].getEstado() == 0){
            return 1;
          }
        }
        //direção superior direita
        else if(i > 1 && j < this->num_colunas){
          if(matriz_tabuleiro[i - 1][j + 1].getEstado() == 2 &&
          matriz_tabuleiro[i - 2][j + 2].getEstado() == 0){
            return 1;
          }
        }
        //direção inferior esquerda
        else if(i < this->num_linhas && j > 1){
          if(matriz_tabuleiro[i + 1][j - 1].getEstado() == 2 &&
          matriz_tabuleiro[i + 2][j - 2].getEstado() == 0){
            return 1;
          }
        }
        //direção inferior esquerda
        else if(i < this->num_linhas && j < this->num_colunas){
          if(matriz_tabuleiro[i + 1][j + 1].getEstado() == 2 &&
          matriz_tabuleiro[i + 2][j + 2].getEstado() ==0){
            return 1;
          }
        }
      }
      //checa se é um dama do jogador 1
      else if(matriz_tabuleiro[linha_peca -1][coluna_peca-1].getEstado()==1 &&
        matriz[i][j]== "X"){
        //direção superior esquerda
        for(int m = 1; i-m>0 && j-m>0; m++){
          if(matriz_tabuleiro[i-m][j-m].getEstado()){
            if(matriz_tabuleiro[i-m][j-m].getEstado()==2 && matriz_tabuleiro[i-m-1][j-m-1].getEstado() ==0){
              return 1;
            }
          }
        }
        //direção superior direita
        for(int m = 1; i-m>0 && j+m<this->num_colunas-1; m++){
          if(matriz_tabuleiro[i-m][j+m].getEstado())){
            if(matriz_tabuleiro[i - m][j + m].getEstado() == 2 && matriz_tabuleiro[i-m-1][j+m+1].getEstado()==0){
              return 1;
            }
          }
        }
        //direção inferior esquerda
        for(int m = 1; i+m<this->num_linhas-1 && j-m>0; m++){
          if(matriz_tabuleiro[i+m][j-m].getEstado()){
            if(matriz_tabuleiro[i+m][j-m].getEstado()==2 && matriz_tabuleiro[i+m+1][j-m-1].getEstado()==0){
              return 1;
            }
          }
        }
        //direção inferior direita
        for(int m = 1; i+m<this->num_linhas-1 && j+m<this->num_colunas-1; m++){
          if(matriz_tabuleiro[i+m][j+m].getEstado()){
            if(matriz_tabuleiro[i+m][j+m].getEstado()==2 && matriz_tabuleiro[i+m+1][j+m+1].getEstado()==0){
              return 1;
            }
          }
        }
      }
      //checa se é uma peça normal do jogador 2
      else if(matriz_tabuleiro[linha_peca -1][coluna_peca-1].getEstado() == 2 &&
      matriz_tabuleiro[i][j] == "o"){
        //direção superior esquerda
          if(i > 1 && j > 1){ 
            if(matriz_tabuleiro[i - 1]j - 1].getEstado() == 1 &&
              matriz_tabuleiro[i - 2][j - 2].getEstado() == 0){
              return 1;
            }
          }
        //direção superior direita
          else if(i > 1 && j < this->num_colunas){
            if(matriz_tabuleiro[i - 1][j + 1].getEstado() == 1 &&
            matriz_tabuleiro[i-2][j+2].getEstado() == 0){
              return 1;
            }
          }
        //direção inferior esquerda
          else if(i < this->num_linhas && j > 1){
            if(matriz_tabuleiro[i+1][j-1].getEstado() == 1 &&
            matriz_tabuleiro[i+2][j+2].getEstado() == 0){
              return 1;
            }
          }
        //direção inferior direita
          else if(i < this->num_linhas && j < this->num_colunas){
            if(matriz_tabuleiro[i+1][j+1].getEstado() == 1 &&
            matriz_tabuleiro[i+2][j+2].getEstado() ==0){
              return 1;
            }
          }
      }
      //checa se é um dama do jogador 2
      else if(matriz_tabuleiro[linha_peca -1][coluna_peca-1].getEstado()==2 &&
        matriz[i][j]== "O"){
        //direção superior esquerda
        for(int m = 1; i-m>0 && j-m>0; m++){
          if(matriz_tabuleiro[i-m][j-m].getEstado()){
            if(matriz_tabuleiro[i-m][j-m].getEstado()==1 && matriz_tabuleiro[i-m-1][j-m-1].getEstado() ==0){
              return 1;
            }
          }
        }
        //direção superior direita
        for(int m = 1; i-m>0 && j+m<this->num_colunas-1; m++){
          if(matriz_tabuleiro[i-m][j+m].getEstado()){
            if(matriz_tabuleiro[i - m][j + m].getEstado() == 1 && matriz_tabuleiro[i-m-1][j+m+1].getEstado()==0){
              return 1;
            }
          }
        }
        //direção inferior esquerda
        for(int m = 1; i+m<this->num_linhas-1 && j-m>0; m++){
          if(matriz_tabuleiro[i+m][j-m].getEstado()){
            if(matriz_tabuleiro[i+m][j-m].getEstado()==1 && matriz_tabuleiro[i+m+1][j-m-1].getEstado()==0){
              return 1;
            }
          }
        }
        //direção inferior direita
        for(int m = 1; i+m<this->num_linhas-1 && j+m<this->num_colunas-1; m++){
          if(matriz_tabuleiro[i+m][j+m].getEstado()){
            if(matriz_tabuleiro[i+m][j+m].getEstado()==1 && matriz_tabuleiro[i+m+1][j+m+1].getEstado()==0){
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

void TabuleiroDamas::verificaJogada(int linha_peca, int coluna_peca, 
  int linha_destino, int coluna_destino, int capturaObrigatoria){
  switch(matriz_tabuleiro[linha_peca -1][coluna_peca-1].getConteudo()){
    case "x":
      // captura
      if (linha_peca == linha_destino -2 || linha_peca == linha_destino +2){
        int linha_meio = (linha_destino + linha_peca)/2;
        int coluna_meio = (coluna_destino + coluna_peca)/2;

        if(matriz_tabuleiro[linha_meio][coluna_meio].getEstado() == 2){
          trocaConteudoCasa(linha_destino, coluna_destino, "x");
          limpaConteudoCasa(linha_peca, coluna_peca);
          limpaConteudoCasa(linha_meio, coluna_meio);
          return;
        }
      }
      else if(capturaObrigatoria){
        throw std::invalid_argument("Jogada inválida. Captura obrigatória");
      }
      //mover normal
      else if (linha_destino != linha_peca +1 || 
        (coluna_destino != coluna_peca +1 && coluna_destino != coluna_peca -1) ){
        throw std::invalid_argument("ERRO: jogada invalida");
      }
      else{
        trocaConteudoCasa(linha_destino, coluna_destino, "x");
        limpaConteudoCasa(linha_peca, coluna_peca);
        this->jogador = (this->jogador == 1) ? 2 : 1;
        return;
      }
      break;
    case "X":
      //verificar a direção da jogada:
      //se é subindo para a esquerda
      if(linha_peca > linha_destino && coluna_peca > coluna_destino){
        for(int i=1; linha_peca-i>linha_destino && coluna_peca-i>coluna_destino; i++){
          if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1-i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1-i].getEstado() == 1){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca-2-i != linha_destino || coluna_peca-2-i != coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      //se é subindo para a direita
      else if(linha_peca > linha_destino && coluna_peca < coluna_destino){
        for(int i=1; linha_peca-i>linha_destino && coluna_peca+i<coluna_destino; i++){
          if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1+i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1+i].getEstado() == 1){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca-2-i != linha_destino || coluna_peca+i!=coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      //se é descendo para a esquerda
      else if(linha_peca < linha_destino && coluna_peca > coluna_destino){
        for(int i=1; linha_peca+i<linha_destino && coluna_peca-i>coluna_destino; i++){
          if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1-i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1-i].getEstado()==1){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca+i != linha_destino || coluna_peca-2-i != coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      //se é descendo para a direita
      else if(linha_peca < linha_destino && coluna_peca < coluna_destino){
        for(int i=1; linha_peca+i<linha_destino && coluna_peca+1<coluna_destino;i++){
          if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1+i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1+i].getEstado()==1){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca+i != linha_destino || coluna_peca+i!=coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      trocaConteudoCasa(linha_destino, coluna_destino, "X");
      limpaConteudoCasa(linha_peca, coluna_peca);
      limpaConteudoCasa(linha_destino-1, coluna_destino-1);
      if(!capturaObrigatoria){
        this->jogador = (this->jogador == 1) ? 2 : 1;
      }
      return;
      break;
    case "o":
      //capturar
      if (linha_peca == linha_destino -2 || linha_peca == linha_destino +2){
        int linha_meio = (linha_destino + linha_peca)/2;
        int coluna_meio = (coluna_destino + coluna_peca)/2;
        if(matriz_tabuleiro[linha_meio][coluna_meio].getEstado() == 2){
          trocaConteudoCasa(linha_destino, coluna_destino, "o");
          limpaConteudoCasa(linha_peca, coluna_peca);
          limpaConteudoCasa(linha_meio, coluna_meio);
          return;
        }
      }
      else if(capturaObrigatoria){
        throw std::invalid_argument("Jogada inválida. Captura obrigatória");
      }
      //mover normal
      else if ( linha_destino != linha_peca -1 ||
      (coluna_destino != coluna_peca +1 && coluna_destino != coluna_peca -1) ){
        throw std::invalid_argument("ERRO: jogada invalida");
      }
      else {
        trocaConteudoCasa(linha_destino, coluna_destino, "o");
        limpaConteudoCasa(linha_peca, coluna_peca);
        this->jogador = (this->jogador == 1) ? 2 : 1;
        return;
      }
      break;
    case "O":
      //verificar a direção da jogada:
      //se é subindo para a esquerda
      if(linha_peca > linha_destino && coluna_peca > coluna_destino){
        for(int i=1; linha_peca-i>linha_destino && coluna_peca-i>coluna_destino; i++){
          if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1-i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1-i].getEstado() == 2){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca-2-i != linha_destino || coluna_peca-2-i != coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      //se é subindo para a direita
      else if(linha_peca > linha_destino && coluna_peca < coluna_destino){
        for(int i=1; linha_peca-i>linha_destino && coluna_peca+i<coluna_destino; i++){
          if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1+i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1-i][coluna_peca-1+i].getEstado() == 2){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca-2-i != linha_destino || coluna_peca+i!=coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      //se é descendo para a esquerda
      else if(linha_peca < linha_destino && coluna_peca > coluna_destino){
        for(int i=1; linha_peca+i<linha_destino && coluna_peca-i>coluna_destino; i++){
          if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1-i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1-i].getEstado()==2){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca+i != linha_destino || coluna_peca-2-i != coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      //se é descendo para a direita
      else if(linha_peca < linha_destino && coluna_peca < coluna_destino){
        for(int i=1; linha_peca+i<linha_destino && coluna_peca+1<coluna_destino;i++){
          if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1+i].getEstado()){
            if(matriz_tabuleiro[linha_peca-1+i][coluna_peca-1+i].getEstado()==2){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
            else if(linha_peca+i != linha_destino || coluna_peca+i!=coluna_destino){
              throw std::invalid_argument("ERRO: jogada invalida");
            }
          }
        }
      }
      trocaConteudoCasa(linha_destino, coluna_destino, "O");
      limpaConteudoCasa(linha_peca, coluna_peca);
      limpaConteudoCasa(linha_destino-1, coluna_destino-1);
      if(!capturaObrigatoria){
        this->jogador = (this->jogador == 1) ? 2 : 1;
      }
      return;
      break;
  }
}

void TabuleiroDamas::pegaJogada(){
  int linha_peca, coluna_peca, linha_destino, coluna_destino;
  std::string jogada;

  //pega a peca que vai mexer
  while(true) {
    std::cout << "Jogador " << jogador << ",  escolha uma peça para mover, linha [SPACE] coluna: "; 

    try {
      std::cin >> jogada;
      linha_peca = trataJogada(jogada);
      std::cin >> jogada;
      coluna_peca = trataJogada(jogada);

      if(!std::cin){
        throw std::invalid_argument("Erro: formato incorreto");
      }
      else if (linha_peca > num_linhas || coluna_peca > num_colunas || 
      linha_peca < 1 || coluna_peca < 1) {
        throw std::out_of_range("ERRO: jogada invalida");
      } 
      else if (matriz_tabuleiro[linha_peca - 1][coluna_peca - 1].getEstado() != jogador) {
        throw std::invalid_argument("ERRO: não é sua peça");
      }
      break;
    }
    catch(std::exception &e) {
      getline(std::cin, jogada);
      std::cout << e.what() << std::endl;
    } 
    catch(...) {
      std::cout << "Excecao desconhecida" << std::endl;
    }
  }

  //pega a posicao do destino da peca
  while(true) {
    std::cout << "Jogador " << jogador << ", digite onde mover a peça, linha [SPACE] coluna: "; 

    try {
      std::cin >> jogada;
      linha_destino = trataJogada(jogada);
      std::cin >> jogada;
      coluna_destino = trataJogada(jogada);

      if(!std::cin){
        throw std::invalid_argument("Erro: formato incorreto");
      }
      else if (linha_destino > num_linhas || coluna_destino > num_colunas || linha_destino < 1 ||             coluna_destino < 1) {
        throw std::out_of_range("ERRO: jogada invalida");
      }
      else if(matriz_tabuleiro[linha_destino -1][coluna_destino -1].getEstado() != 0){
        throw std::invalid_argument("ERRO: posição ocupada");
      }
      
      verificaJogada(linha_peca, coluna_peca, linha_destino, coluna_destino, verificaCaptura(linha_peca, coluna_peca));
      
      break;
    }
    catch(std::exception &e) {
      getline(std::cin, jogada);
      std::cout << e.what() << std::endl;
      break;
    }
    catch(...) {
      std::cout << "Excecao desconhecida" << std::endl;
      break;
    }
  }
}

void TabuleiroDamas::trocaConteudoCasa(int linha, int coluna, std::string conteudoAntigo){
  if (jogador == 1){
    if(linha!=num_linhas){
      matriz_tabuleiro[linha-1][coluna-1].setConteudo(conteudoAntigo);
    }
    else{
      matriz_tabuleiro[linha-1][coluna-1].setConteudo("X");
    }
  
    matriz_tabuleiro[linha-1][coluna-1].setEstado(1);
  }

  else if (jogador == 2) {

    if(linha!=1){
      matriz_tabuleiro[linha-1][coluna-1].setConteudo(conteudoAntigo);
    }
    else{
      matriz_tabuleiro[linha-1][coluna-1].setConteudo("O");
    }
    matriz_tabuleiro[linha-1][coluna-1].setEstado(2); 
    // define a casa como 2 = preenchida pelo jogador2, 0 = vazia
  }

  else{
    std::cout << "Jogador Inválido!" << std::endl;
  }
}

void TabuleiroDamas::limpaConteudoCasa(int linha, int coluna){
  matriz_tabuleiro[linha-1][coluna-1].setConteudo(" ");
  matriz_tabuleiro[linha-1][coluna-1].setEstado(0);
}

int TabuleiroDamas::checaVitoria(){
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      if ((i + j)%2 != 0){
        if(matriz_tabuleiro[i][j].getEstado() != jogador && 
        matriz_tabuleiro[i][j].getEstado() != 0){
          return 0;
        }
      }
    }
  }
  this->vencedor = jogador;
  return 1;
}
#endif