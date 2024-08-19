#include "jogodavelha.hpp"
#include "lig4.hpp"
#include "reversi.hpp"
#include "gomoku.hpp"
#include "batalhanaval.hpp"
#include "jogador.hpp"
// #include "tabuleiroDamas.hpp"
#include <fstream>

std::string paraMinusculo(std::string palavra)  {
    for(int i=0; i<=(int)palavra.length(); i++)
        if(palavra[i]>=65 && palavra[i]<=90)
            palavra[i] = palavra[i]+32;
        else
            palavra[i] = palavra[i]; 
    return palavra;
}

std::string jogoCorrespondente(int num) {
    if(num==1) return "reversi";
    else if(num==2) return "lig4";
    else if(num==3) return "jogodavelha";
    else if(num==4) return "gomoku";
    else if(num==5) return "batalhanaval";
    else if(num==6) return "damas";
    else return "";
}

int menu(std::string &jogador1, std::string &jogador2)  {

    std::cout<<"Bem vindo ao salao de jogos!"<<std::endl;
    std::cout <<"-------------------------------------------------------------------------------------------" << std::endl; 
    std::cout<<"Jogos: 1-> Reversi | 2-> Lig4 | 3-> Jogo da Velha | 4-> Gomoku | 5-> Batalha Naval | 6-> Damas" << std::endl;
    std::cout<< "-------------------------------------------------------------------------------------------" << std::endl;
    std::cout<<"Comandos:" << std::endl;
    std::cout<<"Cadastrar jogador: 'CJ <Apelido> <Nome>'"<<std::endl;
    std::cout<<"Remover jogador: 'RJ <Apelido>'" <<std::endl;
    std::cout<<"Listar jogadores (ordenar por nome-apelido='[N|A]' ou ordenar por apelido-nome='[A|N]'): 'LJ <ordenar>'" << std::endl;
    std::cout<<"Iniciar partida: '<Numero do Jogo> <Apelido jogador 1> <Apelido jogador 2>'" << std::endl;
    std::cout<<"Finalizar sistema: 'FS'" << std::endl;
    std::cout<< "-------------------------------------------------------------------------------------------"<<std::endl;

    while(true) {
        std::string comando;
        std::string parametro1, parametro2;
            
        try   {
            std::cin >> comando;    
            comando = paraMinusculo(comando);
            
            if(comando=="cj")   {
                std::cin >> parametro1 >> parametro2;
                if(!std::cin) throw std::invalid_argument("Erro: dados invalidos");
                Jogador::setJogador(parametro1, parametro2);
                std::cout << "Jogador "<< parametro1 <<" cadastrado com sucesso" << std::endl;
            } else if(comando=="rj")    {
                std::cin >> parametro1;
                if(!std::cin) throw std::invalid_argument("Erro: dados invalidos");
                Jogador::removeJogador(parametro1);
                std::cout << "Jogador "<< parametro1 << "removido com sucesso" << std::endl;
            } else if(comando=="lj")    {
                std::cin >> parametro1;
                if(!std::cin) throw std::invalid_argument("Erro: dados invalidos");
                Jogador::getJogadores(parametro1);
            } else if(comando[0]-'0' <=6 && comando[0]-'0'>=1 && (int)comando.length()==1)  {
                std::cin >> parametro1 >> parametro2;
                Jogador teste1(parametro1);
                Jogador teste2(parametro2);
                jogador1=parametro1;
                jogador2=parametro2;
                return comando[0]-'0';
            } else if(comando=="fs")   {
                std::exit(0);
            } else  {
                std::cout << "Comando invalido." << std::endl;
            }

        } catch (std::invalid_argument &e)  {
            std::cout << e.what() << std::endl;
            getline(std::cin, comando);
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
    
    std::cout << "----- Iniciando jogo -----" << std::endl;
    Tabuleiro *jogo;
    //para os jogos que requerem alguma configuração inicial é possível por uma chamada de função dentro desses if's
    //antes de alocar a memória do tabuleiro.
    if(num_jogo==1)   {
        jogo = new Reversi();
    } else if(num_jogo==2)   {
        jogo = new Lig4(6,7);
    } else if(num_jogo==3)  {
        jogo = new JogodaVelha(3,3);
    } else if(num_jogo==4)  {
        jogo = new Gomoku(15,15);
    } else if(num_jogo==5)  {
        jogo = new BatalhaNaval(10,10);
    // } else if(num_jogo==6)  {
    //     jogo = new TabuleiroDamas(8,8);
    }

    while(1) {  
        jogo->imprimeTabuleiro();
        try 
        {jogo->pegaJogada();}

        catch(Tabuleiro::saidaSistema &e)  {
            delete jogo;
            std::exit(0);
        }

        if(jogo->checaVitoria())
            break;
    }

    jogo->imprimeTabuleiro();
    std::cout << "Fim de jogo!" << std::endl;

    if(jogo->getVencedor()==1) {
        std::cout << "O jogador 1 venceu! Parabens, " << jogador1.getApelido() << std::endl;
        jogador1.addResultado(jogoCorrespondente(num_jogo), "vitoria");
        jogador2.addResultado(jogoCorrespondente(num_jogo), "derrota");

    } else if(jogo->getVencedor()==2)    {
        std::cout << "O jogador 2 venceu! Parabens, " << jogador2.getApelido() << std::endl;
        jogador1.addResultado(jogoCorrespondente(num_jogo), "derrota");
        jogador2.addResultado(jogoCorrespondente(num_jogo), "vitoria");
    } else  {
        std::cout << "Empate!" << std::endl;
        jogador1.addResultado(jogoCorrespondente(num_jogo), "empate");
        jogador2.addResultado(jogoCorrespondente(num_jogo), "empate");

    }
    delete jogo;
    return 0;
}
