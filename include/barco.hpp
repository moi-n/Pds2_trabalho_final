#ifndef BARCO_HPP
#define BARCO_HPP

#include <string>
#include <vector>
#include "ponto.hpp"

class Barco {

    protected:

        int tamanho;
        int id;
        char direcao;
        bool posicionado;
        std::string tipo;
        std::string nome;
        std::vector<Ponto> coordenadas;
        std::vector<Ponto> extremidades;
        std::vector<bool> partesAtingidas;

    public:
        Barco();
        Barco(int, int);

        void setCoordenada(Ponto);
        std::vector<Ponto> getCoordenadas();

        void adicionaExtremidade(int, int);
        void descobreDirecao();
        std::vector<Ponto> getExtremidades();

        Ponto getExtremidade(int);

        int getTamanho();
        int getId();
        char getDirecao();
        void setDirecao(char);

        std::vector<bool> getPartesAtingidas();
        void setPartesAtingidas(int);

        void preencheCoordenadas();
        std::string getNome();

        int checaEspacoBarco(int, int);
        
        bool getPosicionado();
        void setPosicionado(bool);

};

#endif