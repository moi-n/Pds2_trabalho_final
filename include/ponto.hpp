#ifndef PONTO_HPP
#define PONTO_HPP

/**
 * \brief Classe Ponto
 * 
 * A classe descreve uma coordenada (x, y) qualquer. Foi utilizada para o jogo Batalha Naval.
 */

class Ponto {

    protected:

        int x; //!< Posição x de um objeto.
        int y; //!< Posição y de um objeto.
    public:

        /*!
         * \brief Construtor default da classe Ponto.
        */
        Ponto();
        /*!
         * \brief Construtor com parâmetros da classe Ponto.
         * \param x Inteiro que inicializa o parâmetro x da classe.
         * \param y Inteiro que inicializa o parâmetro y da classe.
        */
        Ponto(int x, int y);
        /*! 
        * \brief Destrutor da classe Ponto.
        * \details É colocado como virtual para que não haja problemas futuros se a classe for herdada.
        */
        virtual ~Ponto();

        /*!
         * \brief Método responsável por retornar o valor do parâmetro x da classe.
        */
        int getX();
        /*!
         * \brief Método responsável por retornar o valor do parâmetro y da classe.
        */
        int getY();
        /*!
         * \brief Método responsável por alterar o valor x da classe por um inteiro n.
         * \param n Inteiro utilizado para alterar o valor do parâmetro x.
        */
        void setX(int n);
        /*!
         * \brief Método responsável por alterar o valor y da classe por um inteiro n.
         * \param n Inteiro utilizado para alterar o valor do parâmetro y.
        */
        void setY(int n);
};

#endif
