#include "barco.hpp"
#include <cmath>

Barco::Barco() : Barco(0, 0){}

Barco::Barco(int tam, int _id) : tamanho(tam), id(_id), posicionado(false) {

    if (tam == 4) nome = "Porta-Avioes";
    else if (tam == 3) nome = "Submarino";
    else if (tam == 2) nome = "Contratorpedeiro";
    else if (tam == 1) nome = "Bote";

    for(int i = 0; i < tam; i++) {
        partesAtingidas.push_back(false);
    }
}

void Barco::adicionaExtremidade(int linha, int coluna) {
    Ponto aux(coluna, linha);
    extremidades.push_back(aux);
}

Ponto Barco::getExtremidade(int i) {
    return extremidades[i];
}

std::vector<Ponto> Barco::getExtremidades() {
    return extremidades;
}

void Barco::setCoordenada(Ponto xy){
    coordenadas.push_back(xy);
}

std::vector<Ponto> Barco::getCoordenadas(){
    return this->coordenadas;
}

int Barco::getTamanho(){
    return this->tamanho;
}

int Barco::getId(){
    return this->id;
}

char Barco::getDirecao(){
    return this->direcao;
}

void Barco::setDirecao(char _direcao) {
    this->direcao = _direcao;
}

std::vector<bool> Barco::getPartesAtingidas() {
    return partesAtingidas;
} 
void Barco::setPartesAtingidas(int i) {
    partesAtingidas[i] = true;
}

void Barco::descobreDirecao() {

    if (tamanho > 1) {
    if(extremidades[0].getX() == extremidades[1].getX()) {setDirecao('v');}
    else {setDirecao('h');}
    }
    else setDirecao('h');
}

std::string Barco::getNome() {
    return this->nome;
}

void Barco::preencheCoordenadas() {

    if (tamanho > 1) {
        
        if(direcao == 'v') {

            int y1 = extremidades[0].getY();
            int y2 = extremidades[1].getY();
            int x = extremidades[0].getX();

            if (y1 < y2) {

                for(int i = y1; i <= y2; i++) {

                    Ponto p_aux(x, i);
                    coordenadas.push_back(p_aux);
                }
            }
            else if (y1 > y2) {

                for(int i = y2; i <= y1; i++) {

                    Ponto p_aux(x, i);
                    coordenadas.push_back(p_aux);
                }
            }
        }
        if (direcao == 'h') {

            int x1 = extremidades[0].getX();
            int x2 = extremidades[1].getX();
            int y = extremidades[0].getY();

            if (x1 < x2) {

                for(int i = x1; i <= x2; i++) {

                    Ponto p_aux(i, y);
                    coordenadas.push_back(p_aux);
                }
            }
            else if (x1 > x2) {

                for(int i = x2; i <= x1; i++) {

                    Ponto p_aux(i, y);
                    coordenadas.push_back(p_aux);
                }
            }
        }
    }

    else {
        coordenadas = extremidades;
    }
}

int Barco::checaEspacoBarco(int linha, int coluna) {

    if(linha == extremidades[0].getY()) {

        int diff = coluna - extremidades[0].getX();
        if (abs(diff) != tamanho - 1) {
            return 1;
        }
    }
    else if(coluna == extremidades[0].getX()) {

        int diff = linha - extremidades[0].getY();
        if (abs(diff) != tamanho - 1) {
            return 1;
        }
    }
    return 0;
}

bool Barco::getPosicionado() {

    return posicionado;

}
void Barco::setPosicionado(bool a) {

    this->posicionado = a;
}