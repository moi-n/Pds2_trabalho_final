#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "reversi.hpp"

TEST_CASE("Testando o verificaLinha")   {
    Reversi tabuleiro;
    for(int i=1;i<7;i++)    {
        tabuleiro.getTabuleiro()[0][i].setEstado(2);
    }
    tabuleiro.getTabuleiro()[0][7].setEstado(1);
    CHECK(tabuleiro.verificaLinha(1,1,1)==true);
    for(int i=0; i<8; i++)  {
        CHECK(tabuleiro.getTabuleiro()[0][i].getEstado()==1);
    }

}

TEST_CASE("Testando o verificaColuna")  {
    Reversi tabuleiro;
    for(int i=1;i<7;i++)    {
        tabuleiro.getTabuleiro()[i][0].setEstado(2);
    }
    tabuleiro.getTabuleiro()[7][0].setEstado(1);
    CHECK(tabuleiro.verificaColuna(1,1,1)==true);
    for(int i=0; i<8; i++)  {
        CHECK(tabuleiro.getTabuleiro()[i][0].getEstado()==1);
    }
}

//testando se o método funciona para as duas diagonais principais
TEST_CASE("Testando o verificaDiagonal")    {
    Reversi tabuleiro;
    for(int i=1;i<7;i++)    {
        tabuleiro.getTabuleiro()[i][i].setEstado(2);
        tabuleiro.getTabuleiro()[i][7-i].setEstado(2);
    }
    tabuleiro.getTabuleiro()[7][0].setEstado(1);
    tabuleiro.getTabuleiro()[7][7].setEstado(1);

    CHECK(tabuleiro.verificaDiagonal(1,8,1)==true);
    CHECK(tabuleiro.verificaDiagonal(1,1,1)==true);
    for(int i=0; i<8; i++)  {
        CHECK(tabuleiro.getTabuleiro()[i][i].getEstado()==1);
        CHECK(tabuleiro.getTabuleiro()[i][7-i].getEstado()==1);
    }
}

TEST_CASE("Testando o checaVitoria e o jogadaPossivel") {
    Reversi  tabuleiro;
    for(int i=0; i<4;i++)   {
        for(int j=0; j<8; j++)  {
            tabuleiro.getTabuleiro()[i][j].setEstado(1);
            tabuleiro.getTabuleiro()[i+4][j].setEstado(2);
        }
    }
    CHECK(tabuleiro.checaVitoria()==1);
    CHECK(tabuleiro.getVencedor()==0);
    CHECK(tabuleiro.jogadaPossivel()==0);

    tabuleiro.getTabuleiro()[5][4].setEstado(0);
    CHECK(tabuleiro.jogadaPossivel()==1);
}