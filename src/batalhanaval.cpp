#include "batalhanaval.hpp"

BatalhaNaval::BatalhaNaval() : Tabuleiro() {}

BatalhaNaval::BatalhaNaval(int _num_linhas, int _num_colunas) : Tabuleiro(_num_linhas, _num_colunas) {

    matriz_tabuleiro_2 = std::vector<std::vector<Casa>>(this->num_linhas, std::vector<Casa>(this->num_colunas, Casa()));
    vetor_tabuleiros.push_back(matriz_tabuleiro);
    vetor_tabuleiros.push_back(matriz_tabuleiro_2);
    fase_jogo = 1;

    int aux = 1;
    std::vector<int> tamanho_barcos = {2, 3, 2, 1};

    for (int k = 0; k < 2; k++) {
        std::vector<Barco> barcos;
        for (int i = tamanho_barcos.size(); i > 0; i--) {
            for(int j = 0; j < tamanho_barcos[i - 1]; j++) {
                barcos.push_back(Barco(i, aux));
                aux++;
            }
        }
        vetor_barcos.push_back(barcos);
    }
}

BatalhaNaval::~BatalhaNaval() {}

int BatalhaNaval::inverteJogador() {
    return ((this->jogador == 1) ? 2 : 1);
}

void BatalhaNaval::setFaseJogo(int n) {
    this->fase_jogo = n;
}

int BatalhaNaval::getFaseJogo() {
    return this->fase_jogo;
}

void BatalhaNaval::imprimeTabuleiro() {

    int jogador_aux = 0;
    if (getFaseJogo() == 2) {jogador_aux = inverteJogador();}
    else {jogador_aux = jogador;}

    std::cout << std::endl;
    std::cout << "/////////////////////////// TABULEIRO DO JOGADOR (" << jogador_aux << ") ////////////////////////////" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < this->num_linhas; i++) {
        if (i < 9){
            std::cout << 0 << i+1 << "  _" << "| ";
        }
        else{
        std::cout << i+1 << "  _" << "| ";
        }
        
        for (int j = 0; j < this->num_colunas; j++) {
            std::cout << vetor_tabuleiros[jogador_aux - 1][i][j].getConteudo() << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (int j = 0; j < this->num_colunas; j++) {
        if (j > 9){
            std::cout << "/ " << j+1;
        }
        else{
        std::cout << " / " << j+1;
        }
    }
    std::cout << " / ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "/////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
}

void BatalhaNaval::reiniciaConteudoTabuleiro() {

    for (int i = 0; i < (int)vetor_tabuleiros.size(); i++) {
        for (int j = 0; j < num_linhas; j++) {
            for (int k = 0; k < num_colunas; k++) {
                vetor_tabuleiros[i][j][k].setConteudo(" ");
            }
        }
    }
}

void BatalhaNaval::posicionaBarcos() {

    std::cout << std::endl;
    std::cout << "/////////////////////// FASE 1: POSICIONAMENTO DOS BARCOS ///////////////////////" << std::endl;

    int aux = 0;
    imprimeTabuleiro();
    while(aux < 2) {

        std::cout << "//////////////////// POSICIONAMENTO DE BARCOS DO JOGADOR (" << jogador << ") ////////////////////" << std::endl << std::endl;

        for (int i = 0; i < (int)vetor_barcos[jogador - 1].size(); i++) {
                pegaPosicaoBarcos(vetor_barcos[jogador - 1][i]);
                imprimeTabuleiro();
        }
        imprimeTabuleiro();
        this->jogador = inverteJogador();
        aux++;
    }
    std::cout << "////////////////////////// FASE 2: ATAQUE SEU INIMIGO! //////////////////////////" << std::endl << std::endl;

    setFaseJogo(2);
    reiniciaConteudoTabuleiro();
}

void BatalhaNaval::trocaConteudoCasa(int linha, int coluna) {

    bool atingido = false;

    if (fase_jogo == 1) {

        vetor_tabuleiros[jogador - 1][linha][coluna].setConteudo("O");
        vetor_tabuleiros[jogador - 1][linha][coluna].setEstado(2);
    }

    else if (fase_jogo == 2) {

        int jogador_contrario = inverteJogador();

        if(vetor_tabuleiros[jogador_contrario - 1][linha - 1][coluna - 1].getEstado() == 0) {

            vetor_tabuleiros[jogador_contrario - 1][linha - 1][coluna - 1].setConteudo("-");
            vetor_tabuleiros[jogador_contrario - 1][linha - 1][coluna - 1].setEstado(1);
        }
        else if(vetor_tabuleiros[jogador_contrario - 1][linha - 1][coluna - 1].getEstado() == 2) {

            atingido = true;
            vetor_tabuleiros[jogador_contrario - 1][linha - 1][coluna - 1].setConteudo("X");
            vetor_tabuleiros[jogador_contrario - 1][linha - 1][coluna - 1].setEstado(3);

            std::cout << std::endl << "Barco atingido na coordenada: (" << linha << ", " << coluna << ")"<< std::endl;

            Barco &barco = encontraBarco(linha - 1, coluna - 1, inverteJogador());
            std::vector<Ponto> aux = barco.getCoordenadas();
            for(int i = 0; i < (int)aux.size();i++) {
                if(aux[i].getX() == coluna - 1 && aux[i].getY() == linha - 1){
                    barco.setPartesAtingidas(i);
                }
            }
            int contagemPartesMortas = 0;
            for(int i = 0; i < (int)barco.getPartesAtingidas().size(); i++) {
                if(barco.getPartesAtingidas()[i] == true) {
                    contagemPartesMortas++;
                }
            }
            if (contagemPartesMortas == barco.getTamanho()) {
                trocaConteudoVizinhaca(barco);
            }
        }
    }
    if (!checaVitoria() && getFaseJogo() == 2 && !atingido) { 
        this->jogador = inverteJogador();
    }
}

void BatalhaNaval::pegaPosicaoBarcos(Barco &barco) {

    int linha, coluna;
    std::string jogada;
    int aux = 0;

    while(aux < 2) {

        if (barco.getTamanho() != 1) {
            if (aux == 0) {
                std::cout << "JOGADOR (" << jogador << "): digite a posicao da primeira extremidade do barco " << barco.getNome() << " de tamanho (" << barco.getTamanho() << "): ";
            }
            else {std::cout << "JOGADOR (" << jogador << "): digite a posicao da segunda extremidade do barco " << barco.getNome() << " de tamanho (" << barco.getTamanho() << "): ";}
        }
        else {std::cout << "JOGADOR (" << jogador << "): digite a posicao do barco " <<  barco.getNome() <<" de tamanho (" << barco.getTamanho() << "): ";}
        
        try {
            std::cin >> jogada;
            linha = trataJogada(jogada);
            std::cin >> jogada;
            coluna = trataJogada(jogada);

            if(!std::cin)
                throw std::invalid_argument("Erro: formato incorreto");
            else if (linha > num_linhas || coluna > num_colunas || linha < 1 || coluna < 1) {
                    throw std::out_of_range("ERRO: jogada invalida");
            }
            else if (vetor_tabuleiros[jogador - 1][linha - 1][coluna - 1].getEstado() == 2) {
                    throw std::invalid_argument("ERRO: ja existe um barco nessa posicao!");
            }
            else if(aux == 1 && barco.getTamanho() != 1) {
                if(barco.checaEspacoBarco(linha - 1, coluna - 1)) {
                    throw std::invalid_argument("ERRO: a extremidade deve seguir o tamanho do barco!");
                }
            } 
            checaVizinhaca(linha, coluna, barco.getId());
            
            if (aux > 0) {
                if (barco.getExtremidade(0).getY() == linha - 1 && barco.getExtremidade(0).getX() == coluna - 1) {
                    throw std::invalid_argument("ERRO: nao e possivel colocar duas extremidades no mesmo lugar!");
                }
                Ponto ponto_aux = barco.getExtremidade(0);
                if (ponto_aux.getY() != linha - 1 && ponto_aux.getX() != coluna - 1) {
                    throw std::invalid_argument("ERRO: nao e possivel colocar barcos na diagonal!");
                }
            }
            barco.adicionaExtremidade(linha - 1, coluna - 1);
            if (barco.getTamanho() == 1) break;
            aux++;
        }catch(Tabuleiro::saidaSistema &e)   {
            std::cout << e.what() << std::endl;
            throw;    
        } catch(std::exception &e) {
            getline(std::cin, jogada);
            std::cout << e.what() << std::endl << std::endl;
        } catch(...) {
            std::cout << "Excecao desconhecida" << std::endl << std::endl;
        }
    }

    barco.descobreDirecao();
    barco.preencheCoordenadas();
    barco.setPosicionado(true);
    std::vector<Ponto> coord = barco.getCoordenadas();

    for (int i = 0; i < barco.getTamanho(); i++) {
    
        trocaConteudoCasa(coord[i].getY(), coord[i].getX());
    }
}

void BatalhaNaval::pegaJogada() {

    if (fase_jogo == 1) {posicionaBarcos();}

    else {
    int linha, coluna;
    std::string jogada;

    while(true) {

        std::cout << "JOGADOR (" << jogador << "): digite sua jogada, linha e coluna: "; 
        try {
            std::cin >> jogada;
            linha = trataJogada(jogada);
            std::cin >> jogada;
            coluna = trataJogada(jogada);

            if(!std::cin)
                throw std::invalid_argument("Erro: formato incorreto");
            else if (linha > num_linhas || coluna > num_colunas || linha < 1 || coluna < 1) {
                    throw std::out_of_range("ERRO: jogada invalida!");
            } else if (vetor_tabuleiros[inverteJogador() - 1][linha - 1][coluna - 1].getEstado() == 1 || 
                        vetor_tabuleiros[inverteJogador() - 1][linha - 1][coluna - 1].getEstado() == 3) {
                    throw std::invalid_argument("ERRO: uma jogada ja foi feita nessa posicao!");
            }
            break;
        } catch(std::exception &e) {
            getline(std::cin, jogada);
            std::cout << e.what() << std::endl << std::endl;
        } catch(...) {
            std::cout << "Excecao desconhecida" << std::endl << std::endl;
        }
    }
    trocaConteudoCasa(linha, coluna);
    }
}

int BatalhaNaval::checaVitoria() {

    for (int j = 0; j < num_linhas; j++) {
        for (int k = 0; k < num_colunas; k++) {
            if (vetor_tabuleiros[inverteJogador() - 1][j][k].getEstado() == 2) {
                    return 0;
                }
            }
        }
    this->vencedor = jogador;
    return 1;
}

Barco& BatalhaNaval::encontraBarco(int linha, int coluna, int jogador) {

    for(int k = 0; k < (int)vetor_barcos[jogador - 1].size(); k++) {
        if (vetor_barcos[jogador - 1][k].getPosicionado()) {
            std::vector<Ponto> aux = vetor_barcos[jogador - 1][k].getCoordenadas(); 
            for(int i = 0; i < (int)aux.size(); i++) {
                if(aux[i].getX() == coluna && aux[i].getY() == linha) {
                    return vetor_barcos[jogador - 1][k];
                }
            }
        }
    }
}

void BatalhaNaval::trocaConteudoVizinhaca(Barco &barco) {

    int jogador_contrario = inverteJogador();
    if (barco.getDirecao() == 'h') {
        if (barco.getCoordenadas()[0].getY() == 0) {
            if (barco.getCoordenadas()[0].getX() == 0) {
                for(int i = barco.getCoordenadas()[0].getY(); i <= barco.getCoordenadas()[0].getY() + 1; i++) {
                    for (int j = barco.getCoordenadas()[0].getX(); j <= barco.getCoordenadas()[0].getX() + barco.getTamanho(); j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
            
            if(barco.getCoordenadas()[barco.getTamanho() - 1].getX() == num_colunas - 1) {
                for(int i = barco.getCoordenadas()[0].getY(); i <= barco.getCoordenadas()[0].getY() + 1; i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + barco.getTamanho() - 1; j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            } 
            else {
                for(int i = barco.getCoordenadas()[0].getY(); i <= barco.getCoordenadas()[0].getY() + 1; i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + barco.getTamanho(); j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
        }
        
        else if (barco.getCoordenadas()[0].getY() == num_linhas - 1) {
            if(barco.getCoordenadas()[0].getX() == 0) {
                for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY(); i++) {
                    for (int j = barco.getCoordenadas()[0].getX(); j <= barco.getCoordenadas()[0].getX() + barco.getTamanho(); j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
            else if(barco.getCoordenadas()[barco.getTamanho() - 1].getX() == num_colunas - 1) {
                for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY(); i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + barco.getTamanho() - 1; j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
            else {
                for(int i = barco.getCoordenadas()[0].getY() -  1; i <= barco.getCoordenadas()[0].getY(); i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + barco.getTamanho(); j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
        }
        
        else if (barco.getCoordenadas()[0].getX() == 0) {
            for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + 1; i++) {
                for (int j = barco.getCoordenadas()[0].getX(); j <= barco.getCoordenadas()[0].getX() + barco.getTamanho(); j++) {
                    if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                    }
                }
            }
        }
        else if (barco.getCoordenadas()[barco.getTamanho() - 1].getX() == num_colunas - 1) {
            for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + 1; i++) {
                for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + barco.getTamanho() - 1; j++) {
                    if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                    }
                }
            }
        }
        else {
            for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + 1; i++) {
                for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + barco.getTamanho(); j++) {
                    if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                    }
                }
            }
        }
    
    }
    else { 
        
        if (barco.getCoordenadas()[0].getY() == 0) {
            if (barco.getCoordenadas()[0].getX() == 0) {
                for(int i = barco.getCoordenadas()[0].getY(); i <= barco.getCoordenadas()[0].getY() + barco.getTamanho(); i++) {
                    for (int j = barco.getCoordenadas()[0].getX(); j <= barco.getCoordenadas()[0].getX() + 1; j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
            else if(barco.getCoordenadas()[0].getX() == num_colunas - 1) {
                for(int i = barco.getCoordenadas()[0].getY(); i <= barco.getCoordenadas()[0].getY() + barco.getTamanho(); i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX(); j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }   
            }
            else {
                for(int i = barco.getCoordenadas()[0].getY(); i <= barco.getCoordenadas()[0].getY() + barco.getTamanho(); i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + 1 ; j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                } 
            }
        }
        else if (barco.getCoordenadas()[barco.getTamanho() - 1].getY() == num_linhas - 1) {
            
            if(barco.getCoordenadas()[barco.getTamanho() - 1].getX() == 0) {
                for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + barco.getTamanho() - 1; i++) {
                    for (int j = barco.getCoordenadas()[0].getX(); j <= barco.getCoordenadas()[0].getX() + 1 ; j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
            else if(barco.getCoordenadas()[barco.getTamanho() - 1].getX() == num_colunas - 1) {
                for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + barco.getTamanho() - 1; i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX(); j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
                
            }
            else {
                for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + barco.getTamanho() - 1; i++) {
                    for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + 1 ; j++) {
                        if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                            vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                        }
                    }
                }
            }
        }
        else if (barco.getCoordenadas()[0].getX() == 0) {
            for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + barco.getTamanho(); i++) {
                for (int j = barco.getCoordenadas()[0].getX(); j <= barco.getCoordenadas()[0].getX() + 1; j++) {
                    if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                    }
                }
            }
        }
        else if (barco.getCoordenadas()[barco.getTamanho() - 1].getX() == num_colunas - 1) {
            for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + barco.getTamanho(); i++) {
                for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX(); j++) {
                    if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                    }
                }
            }
        }
        else {
            for(int i = barco.getCoordenadas()[0].getY() - 1; i <= barco.getCoordenadas()[0].getY() + barco.getTamanho(); i++) {
                for (int j = barco.getCoordenadas()[0].getX() - 1; j <= barco.getCoordenadas()[0].getX() + 1; j++) {
                    if(vetor_tabuleiros[jogador_contrario - 1][i][j].getEstado() == 0) {
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setConteudo("-");
                        vetor_tabuleiros[jogador_contrario - 1][i][j].setEstado(1);
                    }
                }
            }
        }
    }
}

int BatalhaNaval::checaVizinhaca(int linha, int coluna, int id) {
    
    if (linha - 1 == 0) {
        //checa borda 00
        if (coluna - 1 == 0) {
            for (int i = linha - 1; i <= linha; i++) {
                for (int j = coluna - 1; j <= coluna; j++) {
                    if (i == linha - 1 && j == coluna - 1) {
                        continue;
                    }
                    else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                        if(encontraBarco(i, j, jogador).getId() != id) {
                            throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                        }
                    }
                }
            }
        }
        //checa borda [0][num_colunas - 1]
        else if (coluna == num_colunas) {
            for (int i = linha - 1; i <= linha; i++) {
                for (int j = coluna - 2; j <= coluna - 1; j++) {
                    if (i == linha - 1 && j == coluna - 1) {
                        continue;
                    }
                    else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                        if(encontraBarco(i, j, jogador).getId() != id) {
                            throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                        }
                    }
                }
            }
        }
        // checa casa na primeira linha porem nao esta na borda
        else {
            for (int i = linha - 1; i <= linha; i++) {
                for (int j = coluna - 2; j <= coluna; j++) {
                    if (i == linha - 1 && j == coluna - 1) {
                        continue;
                    }
                    else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                        if(encontraBarco(i, j, jogador).getId() != id) {
                            throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                        }
                    }
                }
            }
        }
    }
    else if (linha == num_linhas) {
        if (coluna - 1 == 0) {
            for (int i = linha - 2; i <= linha - 1; i++) {
                for (int j = coluna - 1; j <= coluna; j++) {
                    if (i == linha - 1 && j == coluna - 1) {
                        continue;
                    }
                    else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                        if(encontraBarco(i, j, jogador).getId() != id) {
                            throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                        }
                    }
                }
            }
        }
        else if (coluna == num_colunas) {
            for (int i = linha - 2; i <= linha - 1; i++) {
                for (int j = coluna - 2; j <= coluna - 1; j++) {
                    if (i == linha - 1 && j == coluna - 1) {
                        continue;
                    }
                    else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                        if(encontraBarco(i, j, jogador).getId() != id) {
                            throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                        }
                    }
                }
            }
        }
        else {
            for (int i = linha - 2; i <= linha - 1; i++) {
                for (int j = coluna - 2; j <= coluna; j++) {
                    if (i == linha - 1 && j == coluna - 1) {
                        continue;
                    }
                    else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                        if(encontraBarco(i, j, jogador).getId() != id) {
                            throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                        }
                    }
                }
            }
        }
    }
    else if (coluna - 1 == 0) {
        for(int i = coluna - 1; i <= coluna; i++) {
            for (int j = linha - 2; j <= linha; j++) {
                if (i == coluna - 1 && j == linha - 1) {
                    continue;
                }
                else if (vetor_tabuleiros[jogador - 1][j][i].getEstado() == 2) {
                    if(encontraBarco(j, i, jogador).getId() != id) {
                        throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                    }
                }
            }
        }
    }
    else if (coluna == num_colunas) {
        for(int i = coluna - 2; i <= coluna - 1; i++) {
            for (int j = linha - 2; j <= linha; j++) {
                if (i == coluna - 1 && j == coluna - 1) {
                    continue;
                }
                else if (vetor_tabuleiros[jogador - 1][j][i].getEstado() == 2) {
                    if(encontraBarco(j, i, jogador).getId() != id) {
                        throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                    }
                }
            }
        }
    }
    else {
        for (int i = linha - 2; i <= linha; i++) {
            for (int j = coluna - 2; j <= coluna; j++) {
                if (i == linha - 1 && j == coluna - 1) {
                    continue;
                }
                else if (vetor_tabuleiros[jogador - 1][i][j].getEstado() == 2) {
                    if(encontraBarco(i, j, jogador).getId() != id) {
                        throw std::invalid_argument("ERRO: barcos nao podem se encostar!");
                    }
                }
            }
        }
    }
    return 0;
}
