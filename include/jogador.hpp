#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/**
 * @param apelido Apelido de um jogador, é único.
 * @param nome Nome de um jogador.
 */
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

/*
bool entradaExcessiva() {
    return (!std::cin) ? true : false;
}

std::cout<<"Bem vindo ao salão de jogos!"<<std::endl;
std::cout << "------------------------------------------------" << std::endl; 
std::cout<<"Jogos: Reversi - Lig4 - Jogo da Velha - Gomoku - Batalha Naval - Damas" << std::endl;
std::cout<<"------------------------------------------------" << std::endl;
std::cout<<"Comandos:" << std::endl;
std::cout<<"Cadastrar jogador: CJ <Apelido> <Nome>"<<std::endl;
std::cout<<"Remover jogador: RJ <Apelido>" <<std::endl;
std::cout<<"Listar jogador (ordenar por nome-apelido='[N|A]' ou ordenar por apelido-nome='[A|N]'): LJ <ordenar>" << std::endl;
std::cout<<"Iniciar partida ("JV"="Jogo da Velha" e "BN"="Batalha Naval"): <Jogo> <Apelido jogador 1> <Apelido jogador 2>" << std::endl;
std::cout<<"------------------------------------------------"<<std::endl

Jogador *jogador1, *jogador2;
while(true) {
    try   {
        char comando[];
        std::string parametro1, parametro2;
        std::string jogos[]={"reversi", "lig4", "jv", "gomoku", "bn", "damas"};
        
        std::cin >> comando;
        
        if(comando=="CJ")   {
            std::cin >> parametro1 >> parametro2;
            if(entradaExcessiva()) throw std::invalid_argument("Erro: dados invalidos");
            Jogador::setJogador(parametro1, parametro2);
        } else if(comando=="RJ")    {
            std::cin >> parametro1;
            if(entradaExcessiva()) throw std::invalid_argument("Erro: dados invalidos");
            Jogador::removeJogador(parametro1);
        } else if(comando=="LJ")    {
            std::cin >> parametro1;
            if(entradaExcessiva()) throw std::invalid_argument("Erro: dados invalidos");
            Jogador::getJogadores(parametro1);
        } else if(jogos.indexOf(tolower(comando))!=-1)  {
            std::cin >> parametro1 >> parametro2;
            Jogador1 = new Jogador(parametro1);
            Jogador2 = new Jogador(parametro2);
        }

    } catch (std::invalid_argument &e)  {
        std::cout << e.what() << std::endl;
    } catch (std::ifstream::failure &e) {
        std::ofstream arq_out("jogadores.txt", std::ios::app);
        arq_out << "apelido nome reversi lig4 jogodavelha gomoku batalhanaval dama";
        std::cout << "Insira o comando novamente" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}*/
