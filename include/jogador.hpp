#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Jogador    {
    private:

        /**
         * Apelido de um jogador, é único para cada usuário.
         */
        std::string apelido;

        /**
         * Nome de um jogador.
         */
        std::string nome;

        /**
         * \brief  responsável por retornar a ordem de um determinado jogo no arquivo "jogadores.txt".
         * @param jogo Jogo que deseja-se procurar a posição.
         * \return A ordem do jogo no arquivo "jogadores.txt".
         */
        static int posJogo(std::string jogo);

        /**
         * \brief Método responsável por checar se um jogador encontra-se no arquivo "jogadores.txt".
         * @param apelido Apelido do jogador deseja-se procurar.
         * \return As informações do jogador encontrado, gera uma excessão caso o jogador não seja encontrado.
         */
        static std::string checaJogador(std::string apelido);
    public:

        /**
         * \brief Construtor do Jogador.
         * @param apelido Apelido do jogador que será atribuído à variável.
         */
        Jogador(std::string apelido);

        /**
         * \brief Método para adicionar o resultado da partida no arquivo "jogadores.txt".
         * @param jogo Nome do jogo.
         * @param resultado Valores possíveis aceitos: "vitoria", "derrota" e "empate".
         */
        void addResultado(std::string jogo, std::string resultado);

        /**
         *\brief Método estático para cadastrar um jogador.
         *O apelido para um jogador deve ser único.
         *@param apelido Apelido do jogador.
         *@param nome Nome do jogador.  
         */
        static void setJogador(std::string apelido, std::string nome);

        /**
         * \brief Método estático para remover um jogador.
         *@param apelido Apelido do jogador que deseja-se remover.
         */
        static void removeJogador(std::string apelido);

        /**
         * \brief Imprime todos os jogadores ordenando por nome ou apelido.
         * @param ordenar Valores possíveis aceitos: "[A|N]"" e "[N|A]".
         */
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
