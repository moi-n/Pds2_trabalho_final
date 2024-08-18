#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include\doctest.h"
#include "include\gomoku.hpp"

TEST_CASE("Testando o método checaLinha") {
  Gomoku tabuleiro(15, 15);

  SUBCASE("Testando linha vazia") { CHECK(tabuleiro.checaLinha(0) == 0); }

  SUBCASE("Testando sequência de 5 'X' em linha") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[0][i].setConteudo("X");
    }
    CHECK(tabuleiro.checaLinha(0) == 1);
  }

  SUBCASE("Testando sequência de 5 'O' em linha") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[1][i].setConteudo("O");
    }
    CHECK(tabuleiro.checaLinha(1) == 2);
  }
}

TEST_CASE("Testando a função checaColuna") {
  Gomoku tabuleiro(15, 15);

  SUBCASE("Testando coluna vazia") { CHECK(tabuleiro.checaColuna(0) == 0); }

  SUBCASE("Testando sequência de 5 'X' em coluna") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][0].setConteudo("X");
    }
    CHECK(tabuleiro.checaColuna(0) == 1);
  }

  SUBCASE("Testando sequência de 5 'O' em coluna") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][1].setConteudo("O");
    }
    CHECK(tabuleiro.checaColuna(1) == 2);
  }
}

TEST_CASE("Testando a função checaDiagonal") {
  Gomoku tabuleiro(15, 15);

  SUBCASE("Testando diagonal sem vencedor") {
    CHECK(tabuleiro.checaDiagonal() == 0);
  }

  SUBCASE("Testando diagonal descendente com uma sequência de 5 'X'") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][i].setConteudo("X");
    }
    CHECK(tabuleiro.checaDiagonal() == 1);
  }

  SUBCASE("Testando diagonal descendente com uma sequência de 5 'O'") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][i].setConteudo("O");
    }
    CHECK(tabuleiro.checaDiagonal() == 2);
  }

  SUBCASE("Testando diagonal ascendente com uma sequência de 5 'X'") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][4 - i].setConteudo("X");
    }
    CHECK(tabuleiro.checaDiagonal() == 1);
  }

  SUBCASE("Testando diagonal ascendente com uma sequência de 5 'O'") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][4 - i].setConteudo("O");
    }
    CHECK(tabuleiro.checaDiagonal() == 2);
  }
}

TEST_CASE("Testando a função checaVitoria") {
  Gomoku tabuleiro(15, 15);

  SUBCASE("Testando sem vencedor") { CHECK(tabuleiro.checaVitoria() == 0); }

  // testando vitória do jogador
  SUBCASE("Verificando vitória em uma linha") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[0][i].setConteudo("X");
    }
    CHECK(tabuleiro.checaVitoria() == 1);
  }

  SUBCASE("Testando vitória em uma coluna") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][0].setConteudo("X");
    }
    CHECK(tabuleiro.checaVitoria() == 1);
  }

  SUBCASE("Testando vitória em uma diagonal") {
    for (int i = 0; i < 5; i++) {
      tabuleiro.getTabuleiro()[i][i].setConteudo("X");
    }
    CHECK(tabuleiro.checaVitoria() == 1);
  }
}
