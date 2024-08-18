#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/**
 * \brief Classe Jogador
 * 
 * Classe que implementa o cadastro/manutenção dos jogadores dos jogos.
 */
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
         * \brief Método responsável por retornar o nome do jogador. 
         * \return nome
         */ 
        std::string getNome();

        /**
         * \brief Método responsável por retornar o apelido do jogador.
         * \return apelido
         */
        std::string getApelido();
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