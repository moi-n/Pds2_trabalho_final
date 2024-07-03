#include <iostream>
#include <string>
#include "casa.hpp"

Casa::Casa() {

    this->estadoOcupado = 0;
    this->conteudo = " ";
}

void Casa::setConteudo(std::string escolha) {

    this->conteudo = escolha;
}

std::string Casa::getConteudo() {

    return this->conteudo;
}