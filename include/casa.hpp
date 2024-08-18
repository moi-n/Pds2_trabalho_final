#ifndef CASA_H
#define CASA_H

#include <iostream>
#include <string>

/*!
 * \brief \class Casa
 * 
 * Define uma casa de um Tabuleiro.
 */
class Casa {

    private:

        int estado; //!< Estado da casa. É zero se está desocupado e um inteiro positivo se está ocupado.
        std::string conteudo; //!< Conteúdo da casa. Define o que será impresso no Tabuleiro.

    public:
        /*!
        * \brief Construtor default da classe Casa.
        * \details Inicializa o atributo estado como 0 (desocupado) e o conteúdo como uma string com espaço " "
        * para representar o estado desocupado.
        */
        Casa();
        /*!
        * \brief Destrutor da classe Casa.
        */
        virtual ~Casa();
        /*!
        * \brief Método que retorna o estado da casa.
        */
        int getEstado();
        /*!
        * \brief Método que altera o estado da casa.
        * \param estado Parâmetro dado pelo jogador para modificar o estado da casa.
        */
        void setEstado(int estado);
        /*!
        * \brief Método que retorna o conteúdo da casa.
        */
        std::string getConteudo();
        /*!
        * \brief Método que altera o conteúdo da casa.
        * \details Altera o conteúdo dacasa dependendo da escolha do usuário.
        * \param escolha Parâmetro dado pelo jogador para mudar o conteúdo da casa.
        */
        void setConteudo(std::string escolha);
};

#endif