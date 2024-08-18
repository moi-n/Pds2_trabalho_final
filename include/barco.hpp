#ifndef BARCO_HPP
#define BARCO_HPP

#include <string>
#include <vector>
#include "ponto.hpp"

/*!
 * \brief \class Barco
 * 
 * Define um barco qualquer utilizado no jogo Batalha Naval. É composta pela classe Ponto.
 */
class Barco {

    protected:

        int tamanho; //!< Tamanho do barco
        int id; //!< Número de identificação único do barco.
        char direcao; //!< Direção de disposição do barco: vertical (v) ou horizontal (h).
        bool posicionado; //!< Variável booleana que indica se o barco foi posicionado (true) ou não (false).
        std::string nome; //!< Nome do barco.
        std::vector<Ponto> coordenadas; //!< Vetor da classe Ponto que guarda as coordenadas de todas as partes do barco.
        std::vector<Ponto> extremidades; //!< Vetor da classe Ponto que guarda as coordenadas das duas extremidades do barco.
        std::vector<bool> partesAtingidas; //!< Vetor de bools que indica quais partes do barco foram atingidas.

    public:
        /*!
        * \brief Construtor default da classe Barco.
        * \details Inicializa um barco de tamanho zero e com id zero.
        */
        Barco();
        /*!
        * \brief Construtor com parâmetros da classe Barco.
        * \details Inicializa um barco de tamanho e id dados pelo usuário. A variável posicionado é iniciada como false.
        * Dentro do corpo do método, o nome do barco é definido dependendo do seu tamanho. Todas as partes do vetor partes
        * Atingidas são inicializadas como false.
        * \param tamanho Tamanho do barco entrado pelo usuário.
        * \param id Número de identificação entrado pelo usuário.
        */
        Barco(int tamanho, int id);
        /*!
        * \brief Destrutor da classe Barco.
        * \details É definido como virtual para que classes herdeiras possam redefinir seus destrutores.
        */
        virtual ~Barco();
        /*!
        * \brief Método que define as coordenadas do barco.
        * \details Recebe um parâmetro da classe Ponto dado pelo jogador e 
        * adiciona-o no vetor coordenadas da classe Barco.
        * \param xy Coordenada da classe Ponto, que define a posição de uma parte do barco no tabuleiro.
        */
        void setCoordenada(Ponto xy);
        /*!
        * \brief Método que retorna o vetor de coordenadas do barco.
        */
        std::vector<Ponto> getCoordenadas();
        /*!
        * \brief Método que adiciona a coordenada de uma extremidade do barco ao vetor extremidades.
        * \details A partir de dois inteiros linha e coluna, que representam a coordenada de uma das extremidades 
        * do barco, é criado um objeto da classe Ponto com os parâmetros dados pelo usuário e, assim, esse ponto 
        * é adicionado ao vetor extremidades.
        * \param linha Parâmetro que representa a posição y da extremidade do barco.
        * \param coluna Parâmetro que representa a posição x da extremidade do barco.
        */
        void adicionaExtremidade(int linha, int coluna);
        /*!
        * \brief Método que retorna o vetor de extremidades do barco.
        */
        std::vector<Ponto> getExtremidades();
        /*!
        * \brief Método que retorna um objeto da classe Ponto do vetor extremidades.
        * \details Recebe um inteiro i, que pode ser 0 ou 1, e acessa uma posição do vetor extremidades,
        * retornando um objeto Ponto que representa as coordenadas de uma das pontas do barco.
        */
        Ponto getExtremidade(int i);
        /*!
        * \brief Método que descobre a direção em que o barco está posicionado.
        * \details Como o usuário não informa a direção em que posicionará o barco, mas a coordenada da suas duas extremidades,
        * o método, a partir dos dois elementos do vetor de extremidades, define se a orientação do barco é vertical ou horizontal.
        * Para barcos de tamanho maior que 1, se a coordenada x das duas pontas do barco é a mesma, quer dizer que estão na mesma
        * coluna, ou seja, na posição vertical. Se não, a direção é definida como horizontal. Por definição, a direção de um barco
        * de tamanho 1 é definida como horizontal.
        */
        void descobreDirecao();
        /*!
        * \brief Método que retorna a direção do barco, vertical (v) ou horizontal (h).
        */
        char getDirecao();
        /*!
        * \brief Método que altera a direção do barco a partir de um parâmetro dado pelo usuário.
        * \param direcao Parâmetro para o qual o atributo direcao da classe Barco será redefinido.
        */
        void setDirecao(char direcao);
        /*!
        * \brief Método que retorna o tamanho do barco, que pode variar de 1 a 4.
        */
        int getTamanho();
        /*!
        * \brief Método que retorna o número de identificação do barco, que pode variar de 1 até a quantidade de barcos disponível.
        * É único para cada barco e não é redefinido depois da sua criação.
        */
        int getId();
        /*!
        * \brief Método que retorna o nome do barco.
        * Os barcos disponível são: porta-aviões, de tamanho 4; submarino, de tamanho 3; contratorpedeiro, de tamanho 2 e bote, 
        * de tamanho 1. Não é alterado após sua definição no construtor.
        */
        std::string getNome();
        /*!
        * \brief Método que altera o estado booleano numa posição i do vetor partesAtingidas.
        * \details Faz a mudança de false para true na posição i, dada pelo usuário, no vetor partesAtingidas. Notar que as 
        * posições do vetor partesAtingidas e coordenadas são correspondentes, ou seja, se o barco na posição 0 do vetor de
        * coordenadas foi atingido, é feita a chamada do método setPartesAtingidas(0).
        * \param i Posição do vetor partesAtingidas que terá seu estado alterado.
        */
        void setPartesAtingidas(int i);
        /*!
        * \brief Método que retorna o vetor partesAtingidas.
        */
        std::vector<bool> getPartesAtingidas();
        /*!
        * \brief Método que adiciona as coordenadas entre as duas extremidades ao vetor coordenadas.
        * \details Como o usuário entra somente com as coordenadas das duas extremidades do barco, é necessário saber, também,
        * as coordenadas das partes entre as duas pontas do barco. Assim, o método navega o vetor extremidades e encontra as 
        * coordenadas de todas as partes do barco, fazendo de uma maneira diferente se o barco estiver na direção vertical ou
        * horizontal. Se o barco tiver tamanho 1, o vetor extremidades é o próprio vetor coordenadas.
        */
        void preencheCoordenadas();
        /*!
        * \brief Método que checa se a segunda extremidade está numa distância válida da primeira.
        * \details Tem o intuito de checar se uma coordenada para a segunda extremidade, representada por dois inteiros linha e coluna, 
        * está numa distância válida da primeira extremidade do barco, ou seja, se a distância entre elas é igual ao tamanho do barco - 1. 
        * Esse método só é chamado após já ter a informação da primeira coordenada.
        * \param linha Parâmetro que representa a posição y da extremidade do barco.
        * \param coluna Parâmetro que representa a posição x da extremidade do barco.
        */
        int checaEspacoBarco(int linha, int coluna);
        /*!
        * \brief Método que mostra se o barco já foi posicionado no tabuleiro ou não.
        * \details Todo barco tem o atributo posicionado iniciado como false no construtor. Assim, essa função retorna true se já foi posicionado
        * e false se ainda não foi.
        */
        bool getPosicionado();
        /*!
        * \brief Método que altera o estado posicionado do barco.
        * \details A partir do parâmetro a inserido pelo jogador, o atributo posicionado da classe Barco é alterado.
        * \param a Variável booleana que altera o estado do barco no tabuleiro.
        */
        void setPosicionado(bool a);
};

#endif