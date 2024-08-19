#include <iostream>
#include <string>
#include <vector>
#include "lig4.hpp"
#include "tabuleiro.hpp"
#include "tabuleirofileira.hpp"
////////////////////////// Lig4() //////////////////////////

Lig4::Lig4(int linha_, int coluna_) : TabuleiroFileira(linha_, coluna_) {}

Lig4::~Lig4() {}

void Lig4::pegaJogada(){
    int linha, coluna;
    std::string jogada;

    while(true) {
        std::cout << "Jogador " << jogador << ", escolha uma coluna: "; 
        
        try {
            std::cin >> jogada;
            coluna = trataJogada(jogada);

            if(!std::cin)
                throw std::invalid_argument("Erro: formato incorreto");
            else if (coluna > num_colunas || coluna < 1) {
                throw std::out_of_range("ERRO: jogada invalida");
            }

            ////////////////////////// checa se a coluna esta cheia //////////////////////////
            for (int i = num_linhas-1; i >= 0; i--){
                if (matriz_tabuleiro[i][coluna-1].getEstado() == 0){
                    linha = i;
                    break;
                }
                else linha = -1;   
            }
            ////////////////////////// checa validade da entrada //////////////////////////
            if (coluna <= 0 || coluna > num_colunas || linha == -1){
                std::cout << "Jogada invalida, digite novamente: ";
                continue;
            } else  {
                trocaConteudoCasa(linha+1, coluna);
                break;
            }

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
}

////////////////////////// checaLinha() //////////////////////////

int Lig4::checaLinha(int linha){  
    auto& tabuleiro = getTabuleiro();
    int count = 0;

    for (int i =0; i <= num_colunas - 4 ; i++){
        std::string conteudo = tabuleiro[linha][i].getConteudo();
        if (conteudo == " "){
            count = 0;
            continue;
        }
                
        for(int k = 0; k < 4; k++){
            if(tabuleiro[linha][i+k].getConteudo() == conteudo) count++;
            else{
                count = 0;
                continue;
            }

            if (count == 4){
                if(conteudo == "X") return 1;
                else return 2;
            }
        }        
    }
    return 0;
}

////////////////////////// checaColuna() //////////////////////////

int Lig4::checaColuna(int coluna){
    auto& tabuleiro = getTabuleiro();
    int count = 0;

    for (int i = num_linhas-1; i > num_linhas - 4; i--){
        std::string conteudo = tabuleiro[i][coluna].getConteudo();
        if (conteudo == " ") {
            count = 0;
            continue;
        }
        
        for(int k = 0; k < 4; k++){
            if(tabuleiro[i-k][coluna].getConteudo() == conteudo) count++;
            else{
                count = 0;
                continue;
            }

            if (count == 4){
                if(conteudo == "X") return 1;
                else return 2;
            }
        }        
    }
    return 0;
}

////////////////////////// checaDiagonal() //////////////////////////

int Lig4::checaDiagonal(){
    auto& tabuleiro = getTabuleiro();
    int count = 0;

    ////////////////////////// crescente //////////////////////////
    for (int i = num_linhas-1; i > num_linhas - 4 ; i--){
        for(int j = 0; j <= num_colunas - 4; j++){
            std::string conteudo = tabuleiro[i][j].getConteudo();
            if (conteudo == " ") continue;

            for(int k = 0; k < 4; k++){
                if(tabuleiro[i-k][j+k].getConteudo() == conteudo) count++;
                else{
                    count = 0;
                    continue;
                }
            }

            if (count == 4)
            {
                if(conteudo == "X") return 1;
                else return 2;
            }
        }
    }
    ////////////////////////// decrescente //////////////////////////
    for (int i = num_linhas-1; i > num_linhas - 4 ; i--){
        for(int j = num_colunas - 4; j < num_colunas; j++){
            std::string conteudo = tabuleiro[i][j].getConteudo();
            if (conteudo == " "){
                count = 0;
                continue;
            }

             for(int k = 0; k < 4; k++){
                if(tabuleiro[i-k][j-k].getConteudo() == conteudo) count++;
                else{
                    count = 0;
                    continue;
                }
            }

            if (count == 4)
            {
                if(conteudo == "X") return 1;
                else return 2;
            }

        }
    }
    return 0;
}

////////////////////////// checaVitoria() //////////////////////////

int Lig4::checaVitoria(){
    for (int i = 0; i < num_linhas; i++){
        vencedor = checaLinha(i);
        if(vencedor != 0) return vencedor;
    }

    for (int i = 0; i < num_colunas; i++){
        vencedor = checaColuna(i);
        if(vencedor !=0) return vencedor;
    }

    vencedor = checaDiagonal();
    if(vencedor != 0) return vencedor;
    vencedor=0;
    return 0;
}