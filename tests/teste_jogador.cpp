#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "jogador.hpp"

TEST_CASE("Testando as exceções de jogador") {
    CHECK_THROWS_AS(Jogador::setJogador("", ""),std::invalid_argument);
    CHECK_THROWS_AS(Jogador teste("testeunitario"), std::invalid_argument);
    
    Jogador::setJogador("teste", "unitario");
    Jogador teste("teste");
    CHECK(teste.getApelido()=="teste");
    CHECK(teste.getNome()=="unitario");
    Jogador::removeJogador("teste");
}
