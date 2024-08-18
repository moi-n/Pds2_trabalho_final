#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "lig4.hpp"

TEST_CASE("Testando o checaLinhas")     {
    Lig4 tabuleiro(6,7);
    for(int i=0;i<4;i++)    
        tabuleiro.getTabuleiro()[5][i].setConteudo("X");
    
    CHECK(tabuleiro.checaLinha(5)==1);
    CHECK(tabuleiro.checaLinha(4)==0);
}

TEST_CASE("Testando o checaColunas")    {
    Lig4 tabuleiro(6,7);
    for(int i=0; i<4; i++)  
        tabuleiro.getTabuleiro()[i][0].setConteudo("X");
    
    CHECK(tabuleiro.checaColuna(0)==1);
    CHECK(tabuleiro.checaColuna(1)==0);
}

TEST_CASE("Testando o checaDiagonal")   {
    Lig4 tabuleiro(6,7);

    for(int i=0; i<4;i++)   
        tabuleiro.getTabuleiro()[i][i].setConteudo("X");
    
    CHECK(tabuleiro.checaDiagonal()==1);
    for(int i=0; i<4;i++)   {
        tabuleiro.getTabuleiro()[i][i].setConteudo(" ");
        tabuleiro.getTabuleiro()[5-i][i].setConteudo("O");
    }
    CHECK(tabuleiro.checaDiagonal()==2);
}

TEST_CASE("Teste de fim de jogo")   {
    Lig4 tabuleiro(6,7);

    for(int i=0; i<4; i++) 
        tabuleiro.getTabuleiro()[5][i].setConteudo("X");
    CHECK(tabuleiro.checaVitoria()==1);

    for(int i=0; i<4; i++)
        tabuleiro.getTabuleiro()[0][i].setConteudo("O");
    CHECK(tabuleiro.checaVitoria()==2);
}