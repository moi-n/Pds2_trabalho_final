#ifndef BATALHANAVAL_HPP
#define BATALHANAVAL_HPP

#include "tabuleiro.hpp"
#include "casa.hpp"
#include "barco.hpp"

/*!
 * \brief \class BatalhaNaval
 *
 * Classe herdeira da classe Tabuleiro, que possui a função de implementar o jogo Batalha Naval.
 */
class BatalhaNaval : public Tabuleiro {

    protected:

        std::vector<std::vector<Casa>> matriz_tabuleiro_2; //!< A matriz correspondente ao tabuleiro do segundo jogador. A matriz do primeiro jogador está presente na classe Tabuleiro.
        std::vector<std::vector<std::vector<Casa>>> vetor_tabuleiros; //!< Vetor de matrizes do jogador 1 e 2 para facilitar a alternância entre ambos.
        std::vector<std::vector<Barco>> vetor_barcos; //!< Vetor de barcos que serão posicionados pelo jogador 1 e 2.
        int fase_jogo; //!< Inteiro que indica a fase atual do jogo. É 1 na fase de posicionamento de barcos e 2 na fase de ataque. 

    public:
        /*!
        * \brief Construtor default da classe BatalhaNaval.
        * \details Faz chamada do construtor default da classe Tabuleiro.
        */
        BatalhaNaval(); 
        /*!
        * \brief Construtor com parâmetros da classe BatalhaNaval.
        * \details Inicializa o tabuleiro com um número de linhas e colunas passados por parâmetro pelo usuário chamando o construtor da classe Tabuleiro.
        * Inicializa também o tabuleiro do jogador 2, adicionando-a ao vetor_tabuleiros, assim como o tabuleiro do
        * jogador 1. Além disso, os barcos disponíveis para cada jogador são adicionados ao vetor_barcos e a a fase 
        * do jogo é definida para 1.
        * \param num_linhas Número de linhas do tabuleiro.
        * \param num_colunas Número de colunas do tabuleiro.
        */
        BatalhaNaval(int num_linhas, int num_colunas);
        /*!
        * \brief Destrutor da classe Batalha Naval.
        */
        virtual ~BatalhaNaval();
        /*!
        * \brief Método responsável por imprimir o tabuleiro dos dois jogadores.
        */
        void imprimeTabuleiro() override;
        /*!
        * \brief Método responsável por pegar e realizar a jogada de um jogador.
        * \details Na fase 1 do jogo, chama a função posicionaBarcos para que os barcos de cada jogador possam ser
        * posicionados. Na fase 2 do jogo, verifica se o jogador digitou uma jogada no formato: <linha> <coluna>. 
        * Caso verdadeiro, a jogada será feita chamando o método trocaConteudoCasa. Caso falso, será indicado que a 
        * jogada é inválida. 
        */
        void pegaJogada() override;
        /*!
        * \brief Método que alterna o atributo jogador da superclasse Tabuleiro.
        * \details Se o jogador atual é 1, é modificado para 2 e vice-versa.
        */
        int inverteJogador();
        /*!
        * \brief Método que reinicia o conteúdo dos tabuleiros.
        * \details Itera sobre as matrizes de tabuleiro de ambos jogadores, modificando o conteúdo de cada casa 
        * para a string " ", que representa um espaço vazio.
        */
        void reiniciaConteudoTabuleiro();
        /*!
        * \brief Método que posiciona os barcos de cada jogador.
        * \details Para cada barco do vetor de tabuleiros na posição jogador - 1, é chamado o método pegaPosicaoBarco.
        * Ao final, após todos os barcos serem posicionados corretamente, o atributo fase_jogo é modificado para 2, e
        * o conteúdo dos dois tabuleiros é reiniciado com a chamada do método reiniciaConteudoTabuleiro.
        */
        void posicionaBarcos();
        /*!
        * \brief Método utilizado para pegar a posição de um barco
        * \details Recebe uma referência para um barco e verifica se o jogador digitou uma posição válida para as 
        * extremidades do barco. Caso verdadeiro, chama os métodos da classe Barco: descobreDirecao, preencheCoordenadas, 
        * setPosicionado, chamando, ao final, o método trocaConteudoCasa para todas as casas ocupadas por todas as partes 
        * do barco. Caso contrário, será indicado uma mensagem com o tipo de erro.
        * \param barco Objeto da classe Barco passado por referência.
        */
        void pegaPosicaoBarcos(Barco & barco);
        /*!
        * \brief Método responsável por trocar o conteúdo de uma casa. 
        * \details Na fase 1 do jogo, substitiu o estado da casa e o conteúdo para "O" onde um barco foi posicionado. 
        * Na fase 2, substitui o conteúdo e o estado da casa escolhida por "X", se um barco foi atingido e "-", se 
        * não havia nenhum barco.
        * \param linha Parâmetro que representa a posição y da extremidade do barco.
        * \param coluna Parâmetro que representa a posição x da extremidade do barco. 
        */
        void trocaConteudoCasa(int linha, int coluna);
        /*!
        * \brief Método que troca o conteúdo da vizinhança de um barco totalmente destruído.
        * \details Recebe um objeto da classe Barco passado por referência. O método é chamado caso um barco tenha sido totalmente atingido, 
        * assim, o conteúdo das casas na sua vizinhança é alterado para "-". É feito 18 verificações diferentes para os casos de contorno, 
        * como quinas e cordas do tabuleiro e para casos gerais. Funciona para barcos na vertical e horizontal.
        * \param barco Objeto da classe Barco que teve todas suas partes atingidas.
        */
        void trocaConteudoVizinhaca(Barco & barco);
        /*!
        * \brief Método que checa se existe barco na vizinhaça de uma posição <linha | coluna>
        * \details Recebe uma coordenada definida pelos inteiros linha e coluna e o id do barco que será colocado nessa
        * posição. Assim, verifica todos os 9 casos de contorno e gerais dependendo de onde for essa posição no tabuleiro
        * e retorna 1 se encontrar algum barco na vizinhança. Caso não encontre, retorna 0;
        * \param linha Parâmetro que representa a posição y da extremidade do barco.
        * \param coluna Parâmetro que representa a posição x da extremidade do barco.
        * \param id Número de identificação do barco a ser colocado na posição <linha | coluna>
        */
        int checaVizinhaca(int linha, int coluna, int id);
        /*!
        * \brief Método que encontra um barco dado uma posição <linha | coluna> no tabuleiro.
        * \details Recebe uma coordenada definida pelos inteiros linha e coluna e um inteiro jogador que correponde ao
        * jogador dono do barco. Assim, retorna a referência do barco do jogador que se encontra naquela posição.
        * \param linha Parâmetro que representa a posição y da extremidade do barco.
        * \param coluna Parâmetro que representa a posição x da extremidade do barco.
        * \param jogador Parâmetro referente ao jogador dono do barco que deve ser encontrado.
        */
        Barco& encontraBarco(int linha, int coluna, int jogador);
        /*!
        * \brief Método que faz checagem da condição de vitória para o jogador atual
        * \details Para que um jogador vença no Batalha Naval, é necessário ter afundado todos os barcos no 
        * tabuleiro do jogador adversário. Dessa forma, o método itera pelo tabuleiro do jogador adversário 
        * procurando algum barco vivo. Se existe algum barco vivo no tabuleiro do jogador adversário, é retornado 
        * 0, se não, é retornado 1.
        */
        int checaVitoria() override;
        /*!
        * \brief Método que altera o atributo fase_jogo
        * \details O atributo da classe é alterado a partir de um valor n fornecido pelo usuário.
        * \param n Inteiro utilizado para alterar a fase do jogo.
        */
        void setFaseJogo(int n);
        /*!
        * \brief Método que retorna o atributo fase_jogo
        */
        int getFaseJogo();
        /*!
        * \brief Método que retorna uma referência para o atributo matriz_tabuleiro_2.
        */
        std::vector<std::vector<Casa>>& getTabuleiro2();
};

#endif