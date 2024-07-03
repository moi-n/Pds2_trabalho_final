#include <iostream>
#include <string>
#include <vector>
#include "casa.hpp"
#include "tabuleiro.hpp"

int main() {

    Tabuleiro t = Tabuleiro();
    int jogadas = 0;

    while(jogadas < 9) {

        t.imprimeTabuleiro();
        t.pegaJogada();
        jogadas++;
    }
    return 0;
}