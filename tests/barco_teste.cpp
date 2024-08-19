#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "ponto.hpp"
#include "barco.hpp"
#include <vector>

TEST_CASE("Verificando getTamanho, getId e getNome") {

    for(int i = 1; i <= 4; i++) {
        Barco barco_aux(i, i);
        CHECK(barco_aux.getTamanho() == i);
        CHECK(barco_aux.getId() == i);
        if (barco_aux.getTamanho() == 1) CHECK(barco_aux.getNome() == "Bote");
        else if(barco_aux.getTamanho() == 2) CHECK(barco_aux.getNome() == "Contratorpedeiro");
        else if(barco_aux.getTamanho() == 3) CHECK(barco_aux.getNome() == "Submarino");
        else CHECK(barco_aux.getNome() == "Porta-Avioes");
    }
}

TEST_CASE("Verificando descobreDirecao") {

    std::vector<Barco> vetor_aux;
    for(int i = 1; i <= 3; i++) {
        vetor_aux.push_back(Barco(i, i));
    }

    vetor_aux[0].adicionaExtremidade(0, 0);
    vetor_aux[0].descobreDirecao();
    CHECK(vetor_aux[0].getDirecao() == 'h');

    vetor_aux[1].adicionaExtremidade(5, 5);
    vetor_aux[1].adicionaExtremidade(5, 6);
    vetor_aux[1].descobreDirecao();
    CHECK(vetor_aux[1].getDirecao() == 'h');

    vetor_aux[2].adicionaExtremidade(5, 5);
    vetor_aux[2].adicionaExtremidade(7, 5);
    vetor_aux[2].descobreDirecao();
    CHECK(vetor_aux[2].getDirecao() == 'v');
}

TEST_CASE("Verificando preencheCoordenadas") {

    Barco barco_aux_1(4, 1);
    Barco barco_aux_2(4, 1);
    std::vector<Ponto> vetor_aux_1;
    std::vector<Ponto> vetor_aux_2;

    for (int i = 1; i <= 4; i++) {
        vetor_aux_1.push_back(Ponto(i, 1));
        vetor_aux_2.push_back(Ponto(1, i));
    }
    barco_aux_1.adicionaExtremidade(1, 1);
    barco_aux_1.adicionaExtremidade(1, 4);
    barco_aux_1.descobreDirecao();
    barco_aux_1.preencheCoordenadas();

    barco_aux_2.adicionaExtremidade(1, 1);
    barco_aux_2.adicionaExtremidade(4, 1);
    barco_aux_2.descobreDirecao();
    barco_aux_2.preencheCoordenadas();

    int aux = 0;
    for (int i = 0; i < (int)vetor_aux_1.size(); i++) {
        if(barco_aux_1.getCoordenadas()[i].getX() == vetor_aux_1[i].getX() && 
        barco_aux_1.getCoordenadas()[i].getY() == vetor_aux_1[i].getY() &&
        barco_aux_2.getCoordenadas()[i].getX() == vetor_aux_2[i].getX() &&
        barco_aux_2.getCoordenadas()[i].getY() == vetor_aux_2[i].getY()) aux++;
    }
    CHECK(aux == (int)vetor_aux_1.size());
}

TEST_CASE("Verificando checaEspacoBarco") {

    Barco barco_aux(4, 1);  
    Barco barco_aux_2(3, 1);  
    barco_aux.adicionaExtremidade(1, 1);
    barco_aux_2.adicionaExtremidade(5, 2);

    CHECK(barco_aux.checaEspacoBarco(1, 5) == 1);
    CHECK(barco_aux_2.checaEspacoBarco(7, 2) == 0);
}