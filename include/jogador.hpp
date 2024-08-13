#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Jogador    {
    private:
        std::string apelido;
        std::string nome;
        static int posJogo(std::string jogo);
        static std::string checaJogador(std::string apelido);
    public:
        Jogador(std::string apelido);
        void addResultado(std::string jogo, std::string resultado);
        static void setJogador(std::string apelido, std::string nome);
        static void removeJogador(std::string apelido);
        static void getJogadores(std::string ordenar);
};

#endif