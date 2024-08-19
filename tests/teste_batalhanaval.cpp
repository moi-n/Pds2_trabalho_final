#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "ponto.hpp"
#include "barco.hpp"
#include "batalhanaval.hpp"
#include <vector>

TEST_CASE("Verificando condição de Vitória") {

    BatalhaNaval tabuleiro_aux(10, 10);

    // jogador atual é o jogador 1, logo, mudando o estado
    // do tabuleiro do jogador 2, é possível checar a vitória
    tabuleiro_aux.getTabuleiro2()[1][1].setEstado(2);
    CHECK(tabuleiro_aux.checaVitoria() == 0);

    tabuleiro_aux.getTabuleiro2()[1][1].setEstado(1);
    CHECK(tabuleiro_aux.checaVitoria() == 1);
}