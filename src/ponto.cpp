#include "ponto.hpp"

Ponto::Ponto() : Ponto(0, 0) {}
Ponto::Ponto(int x, int y) : x(x), y(y) {}
Ponto::~Ponto() {}

int Ponto::getX() {
    return this->x;
}

int Ponto::getY() {
    return this->y;
}

void Ponto::setX(int n) {
    this->x = n;    
}

void Ponto::setY(int n) {
    this->y = n;
}