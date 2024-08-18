#include <iostream>
#include <string>
#include "casa.hpp"

Casa::Casa() {

    this->estado = 0;
    this->conteudo = " ";
}

Casa::~Casa() {}

void Casa::setConteudo(std::string escolha) {

    this->conteudo = escolha;
}

std::string Casa::getConteudo() {

    return this->conteudo;
}

int Casa::getEstado() {

    return this->estado;
}

void Casa::setEstado(int estado) {

    this->estado = estado;
    
}

