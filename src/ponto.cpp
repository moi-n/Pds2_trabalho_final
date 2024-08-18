#include "ponto.hpp"

Ponto::Ponto() : Ponto(0, 0) {}
Ponto::Ponto(int _x, int _y) : x(_x), y(_y) {}

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