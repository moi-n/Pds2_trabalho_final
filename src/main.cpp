#include "jogodavelha.hpp"
#include "lig4.hpp"
#include "reversi.hpp"
#include "gomoku.hpp"
#include "jogador.hpp" 
#include <fstream>

bool entradaExcessiva() {
    return (!std::cin) ? true : false;
}

std::string paraMinusculo(std::string palavra)  {
    std::string aux;
    for(auto i : palavra)
        aux = tolower(i);
    return aux;
}

std::string jogoCorrespondente(int num) {
    if(num==1) return "reversi";
    else if(num==2) return "lig4";
    else if(num==3) return "jogodavelha";
    else if(num==4) return "gomoku";
    else if(num==5) return "batalhanaval";
    else if(num==6) return "damas";
}

int menu(std::string &jogador1, std::string &jogador2)  {

    std::cout<<"Bem vindo ao salão de jogos!"<<std::endl;
    std::cout << "------------------------------------------------" << std::endl; 
    std::cout<<"Jogos: 1->Reversi | 2->Lig4 | 3-> Jogo da Velha | 4-> Gomoku | 5-> Batalha Naval | 6-> Damas" << std::endl;
    std::cout<<"------------------------------------------------" << std::endl;
    std::cout<<"Comandos:" << std::endl;
    std::cout<<"Cadastrar jogador: CJ <Apelido> <Nome>"<<std::endl;
    std::cout<<"Remover jogador: RJ <Apelido>" <<std::endl;
    std::cout<<"Listar jogador (ordenar por nome-apelido='[N|A]' ou ordenar por apelido-nome='[A|N]'): LJ <ordenar>" << std::endl;
    std::cout<<"Iniciar partida: <Numero do Jogo> <Apelido jogador 1> <Apelido jogador 2>" << std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;

    while(true) {
        try   {
            std::string comando;
            std::string parametro1, parametro2;
            
            std::cin >> comando;
            comando = paraMinusculo(comando);
            
            if(comando=="cj")   {
                std::cin >> parametro1 >> parametro2;
                if(entradaExcessiva()) throw std::invalid_argument("Erro: dados invalidos");
                Jogador::setJogador(parametro1, parametro2);
            } else if(comando=="rj")    {
                std::cin >> parametro1;
                if(entradaExcessiva()) throw std::invalid_argument("Erro: dados invalidos");
                Jogador::removeJogador(parametro1);
            } else if(comando=="lj")    {
                std::cin >> parametro1;
                if(entradaExcessiva()) throw std::invalid_argument("Erro: dados invalidos");
                Jogador::getJogadores(parametro1);
            } else if(std::stoi(comando) <=6 && std::stoi(comando)>=1)  {
                std::cin >> parametro1 >> parametro2;
                Jogador teste1(parametro1);
                Jogador teste2(parametro2);
                jogador1=parametro1;
                jogador2=parametro2;
                return std::stoi(comando);
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
    }
}

int main() {
    std::string apelido_J1, apelido_J2;

    int num_jogo = menu(apelido_J1, apelido_J2);
    Jogador jogador1(apelido_J1), jogador2(apelido_J2);
    
    Tabuleiro *jogo;
    //para os jogos que requerem alguma configuração inicial é possível por uma chamada de função dentro desses if's
    //antes de alocar a memória do tabuleiro.
    if(num_jogo==1)   {
        jogo = new Reversi();
    } else if(num_jogo==2)   {
        jogo = new Lig4();
    } else if(num_jogo==3)  {
        jogo = new JogodaVelha();
    } else if(num_jogo==4)  {
        jogo = new Gomoku();
    } else if(num_jogo==5)  {
        jogo = new BatalhaNaval();
    } else if(num_jogo==6)  {
        jogo = new Damas();
    }

    while(1) {

        jogo->pegaJogada();
        jogo->imprimeTabuleiro();

        if(jogo->checaVitoria())
            break;
    }

    jogo->imprimeTabuleiro();
    std::cout << "Fim de jogo!" << std::endl;

    if(jogo->getVencedor()==1) {
        jogador1.addResultado(jogoCorrespondente(num_jogo), "vitoria");
        jogador2.addResultado(jogoCorrespondente(num_jogo), "derrota");

    } else if(jogo->getVencedor()==2)    {
        jogador1.addResultado(jogoCorrespondente(num_jogo), "derrota");
        jogador2.addResultado(jogoCorrespondente(num_jogo), "vitoria");
    } else  {
        jogador1.addResultado(jogoCorrespondente(num_jogo), "empate");
        jogador2.addResultado(jogoCorrespondente(num_jogo), "empate");

    }
    return 0;
}