#include "reversi.hpp"
#include "tabuleiro.hpp"

Reversi::Reversi() : Tabuleiro(8,8), pulaJogada(0){
    matriz_tabuleiro[3][3].setEstado(2);
    matriz_tabuleiro[3][3].setConteudo("2");
    matriz_tabuleiro[3][4].setEstado(1);
    matriz_tabuleiro[3][4].setConteudo("1");
    matriz_tabuleiro[4][3].setEstado(1);
    matriz_tabuleiro[4][3].setConteudo("1");
    matriz_tabuleiro[4][4].setEstado(2);
    matriz_tabuleiro[4][4].setConteudo("2");
};

Reversi::~Reversi() {};

int Reversi::checaVitoria() {
    if(checaOcupacaoTotal()||pulaJogada==2)    {
        int casasJogador1=0, casasJogador2=0;

        for(int i=0; i<num_linhas; i++) {
            for(int j=0; j<num_colunas; j++)    {
                if(matriz_tabuleiro[i][j].getEstado()==1)
                    casasJogador1++;
                else if(matriz_tabuleiro[i][j].getEstado()==2)
                    casasJogador2++;
            }
        }

        if(casasJogador1>casasJogador2)  
            vencedor=1;
        else if(casasJogador1<casasJogador2)
            vencedor=2;
        return 1;
    }
    return 0;
}


bool Reversi::verificaLinha(int linha, int coluna, bool jogada)   {
    bool direita = true, esquerda = true;
    linha-=1; coluna-=1;
    int count=0;

    
    for(int i=1; i<num_linhas; i++)  {
        if(esquerda && coluna-i>=0){
            if(matriz_tabuleiro[linha][coluna-i].getEstado()==0 || matriz_tabuleiro[linha][coluna-1].getEstado()==jogador)    {
                esquerda=false;
            }  else if(matriz_tabuleiro[linha][coluna-i].getEstado()==jogador) {
                if(jogada)  {completaCasas(linha, coluna, linha, coluna-i);}
                esquerda=false;
                count++;
            }
        } 

        if(direita && coluna+i<=7) {
            if(matriz_tabuleiro[linha][coluna+i].getEstado()==0 || matriz_tabuleiro[linha][coluna+1].getEstado()==jogador)    {
                direita=false;
            } else if(matriz_tabuleiro[linha][coluna+i].getEstado()==jogador)  {
                if(jogada)  {completaCasas(linha, coluna+i, linha, coluna);}
                direita=false;
                count++;
            }
        } 

    }
    return count;
}

bool Reversi::verificaColuna(int linha, int coluna, bool jogada)  {
    bool cima = true, baixo = true;
    linha-=1; coluna-=1;
    int count=0;

    for(int j=1; j<num_colunas; j++)  {
        if(cima && linha-j>=0)  {
            if(matriz_tabuleiro[linha-j][coluna].getEstado()==0 || matriz_tabuleiro[linha-1][coluna].getEstado()==jogador)    {
                cima=false;
            } else if(matriz_tabuleiro[linha-j][coluna].getEstado()==jogador) {
                if(jogada)  {completaCasas(linha, coluna, linha-j, coluna);}
                cima=false;
                count++;
            }
        } 

        if(baixo && linha+j<=7)  {
            if(matriz_tabuleiro[linha+j][coluna].getEstado()==0 || matriz_tabuleiro[linha+1][coluna].getEstado()==jogador)    {
                baixo=false;
            } else if(matriz_tabuleiro[linha+j][coluna].getEstado()==jogador) {
                if(jogada)  {completaCasas(linha+j, coluna, linha, coluna);}
                baixo=false;
                count++;
            }
        } 

    }
    return count;
}

bool Reversi::verificaDiagonal(int linha, int coluna, bool jogada)    {
    bool diagonalCima = true, diagonalBaixo = true;
    linha-=1; coluna-=1;
    int count=0;
    
    //Verificando a diagonal principal 
    for(int k=1; k<num_linhas; k++)   {

        if(diagonalCima && linha-k>=0 && coluna-k>=0)   {
            if(matriz_tabuleiro[linha-k][coluna-k].getEstado()==0 || matriz_tabuleiro[linha-1][coluna-1].getEstado()==jogador)  {
                diagonalCima=false;
            } else if(matriz_tabuleiro[linha-k][coluna-k].getEstado()==jogador) {
                if(jogada)  {completaCasas(linha, coluna, linha-k, coluna-k);}
                diagonalCima=false;
                count++;
            }
        } 

        if(diagonalBaixo && linha+k<=7 && coluna+k<=7)   {
            if(matriz_tabuleiro[linha+k][coluna+k].getEstado()==0 || matriz_tabuleiro[linha+1][coluna+1].getEstado()==jogador)  {
                diagonalBaixo=false;
            } else if(matriz_tabuleiro[linha+k][coluna+k].getEstado()==jogador) {
                if(jogada)  {completaCasas(linha+k,coluna+k, linha, coluna);}
                diagonalBaixo=false;
                count++;
            }
        } 

    }

    diagonalCima=true; diagonalBaixo=true;
    //verificando a diagonal secundária
    for(int k=1; k<num_linhas; k++)  {
        
        if(diagonalCima && linha-k>=0 && coluna+k<=7)   {
            if(matriz_tabuleiro[linha-k][coluna+k].getEstado()==0 || matriz_tabuleiro[linha-1][coluna+1].getEstado()==jogador)  {
                diagonalCima=false;
            } else if(matriz_tabuleiro[linha-k][coluna+k].getEstado()==jogador)   {
                if(jogada)  {completaCasas(linha, coluna, linha-k, coluna+k);}
                diagonalCima=false;   
                count++;             
            }
        } 

        if(diagonalBaixo && linha+k<=7 && coluna-k>=0)   {
            if(matriz_tabuleiro[linha+k][coluna-k].getEstado()==0 || matriz_tabuleiro[linha+1][coluna-1].getEstado()==jogador)  {
                diagonalBaixo=false;
            } else if(matriz_tabuleiro[linha+k][coluna-k].getEstado()==jogador)    {
                if(jogada)  {completaCasas(linha+k, coluna-k, linha, coluna);}
                diagonalBaixo=false;
                count++;
            }
        } 
        
    }
    return count;
}

void Reversi::trocaConteudoCasa(int linha, int coluna) {

    if (jogador == 1){
        matriz_tabuleiro[linha][coluna].setConteudo("1");
        matriz_tabuleiro[linha][coluna].setEstado(1); // define a casa como 1 = preenchida pelo jogador1, 0 = vazia
    }

    else if (jogador == 2) {
        matriz_tabuleiro[linha][coluna].setConteudo("2");
        matriz_tabuleiro[linha][coluna].setEstado(2); // define a casa como 2 = preenchida pelo jogador2, 0 = vazia 
    }
}

void Reversi::completaCasas(int linhaMaior, int colunaMaior, int linhaMenor, int colunaMenor)    {
    int difLinha = linhaMaior-linhaMenor, difColuna = colunaMaior-colunaMenor;
    if(difLinha==0) { 
        for(int j=0; j<=(difColuna); j++) {
            trocaConteudoCasa(linhaMenor, colunaMenor+j);
        }
    } else if(difColuna==0) {
        for(int i=0; i<=(difLinha); i++)   {
            trocaConteudoCasa(linhaMenor+i,colunaMenor);
        }
    } else if(difColuna<0)  {
        for(int k=0; k<=(difLinha); k++) {
            trocaConteudoCasa(linhaMenor+k,colunaMenor-k);
        }
    } else  {
        for(int k=0; k<=(difLinha); k++)   {
            trocaConteudoCasa(linhaMenor+k,colunaMenor+k);
        }
    }
}

bool Reversi::jogadaPossivel()   {
    for(int i=1; i<=num_linhas; i++) {
        for(int j=1; j<=num_colunas; j++)    {  
            if(!matriz_tabuleiro[i-1][j-1].getEstado())  
                if(verificaLinha(i,j,false)||verificaColuna(i,j,false)||verificaDiagonal(i,j,false))    {
                    pulaJogada=0;
                    return true;
                }
        }
    }
    pulaJogada++;
    return false;
}

void Reversi::pegaJogada()   {
    int linha, coluna;
    bool casaInvalida;
    std::string jogada;
    while(true) {
        std::cout << "Jogador " << jogador << ", digite sua jogada, linha [SPACE] coluna: ";
        try {

            if(!jogadaPossivel())  
                break;

            std::cin >> jogada;
            linha = Tabuleiro::trataJogada(jogada);
            std::cin >> jogada;
            coluna = Tabuleiro::trataJogada(jogada);

            if(!std::cin)
                throw std::invalid_argument("Erro: formato incorreto");
            else if (linha > num_linhas || coluna > num_colunas || linha < 1 || coluna < 1) {
                    throw std::out_of_range("ERRO: jogada invalida");
            } else if (matriz_tabuleiro[linha - 1][coluna - 1].getEstado()) {
                    throw std::invalid_argument("ERRO: jogada invalida");
            }

            casaInvalida = !verificaLinha(linha,coluna,true);
            casaInvalida = !verificaColuna(linha,coluna,true) && casaInvalida;
            casaInvalida = !verificaDiagonal(linha,coluna,true) && casaInvalida;
            if(casaInvalida)
                throw std::invalid_argument("Erro: jogada invalida");
            
            break;
        } catch(Tabuleiro::saidaSistema &e)   {
            std::cout << e.what() << std::endl;
            throw;
        } catch(std::exception &e) {
            getline(std::cin, jogada);
            std::cout << e.what() << std::endl;
        } catch(...) {
            std::cout << "Excecao desconhecida" << std::endl;
        } 
    }
    jogador = (jogador == 1) ? 2 : 1;
}