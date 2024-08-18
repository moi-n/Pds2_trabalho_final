#include <fstream>
#include <sstream> 
#include "jogador.hpp"

#define NUM_JOGOS 6

Jogador::Jogador(std::string apelido)    {
    std::string linha = Jogador::checaJogador(apelido);
    std::stringstream info(linha);
    info >> this->apelido;
    info >> this->nome;

}

std::string Jogador::getNome()  {
    return this->nome;
}

std::string Jogador::getApelido()   {
    return this->apelido;
}

std::string Jogador::checaJogador(std::string apelido)   {
    if(apelido.find(" ")!=std::string::npos)
        throw std::invalid_argument("Erro: dados incorretos.");

    std::ifstream arq("jogadores.txt");  
    if(!arq.is_open())
        throw std::ifstream::failure("Erro: arquivo inexistente.");
    if(arq.peek()==EOF)
        throw std::ifstream::failure("Erro: arquivo vazio.");
    
    std::string linha;
    for(int i=0; i<(int)apelido.length(); i++)
            if(apelido[i]>=65 && apelido[i]<=90)
                apelido[i]+=32;
    while(!arq.eof())  {
        getline(arq,linha);
        if(linha.substr(0,linha.find(" "))==apelido) {
            return linha;
        }
    }
    arq.close();
    throw std::invalid_argument("Erro: jogador inexistente.");
}

void Jogador::setJogador(std::string apelido, std::string nome)  {
    try {
        if(!Jogador::checaJogador(apelido).empty()) {
            throw std::logic_error("Erro: jogador ja existente.");
        }   
    }catch(std::invalid_argument &e)   {}

    std::ofstream arq_out("jogadores.txt", std::ios::app);

    for(int i=0; i<(int)apelido.length(); i++)
        if(apelido[i]>=65 && apelido[i]<=90)
            apelido[i]+=32;
    for(int i=0; i<(int)nome.length(); i++)
        if(nome[i]>=65 && nome[i]<=90)
            nome[i]+=32;

    arq_out << std::endl << apelido << " " << nome;
    for(int i=0; i<NUM_JOGOS;i++) 
        arq_out << " 0|0|0";
    arq_out.close();

}

void Jogador::removeJogador(std::string apelido) {
    Jogador::checaJogador(apelido);

    std::ifstream arq_in("jogadores.txt");
    std::string linha; 
    std::string out;

    for(int i=0; i<(int)apelido.length(); i++)
        if(apelido[i]>=65 && apelido[i]<=90)
            apelido[i]+=32;

    while(!arq_in.eof())   {
        getline(arq_in, linha);
        if(linha.substr(0, linha.find(" "))==apelido)
            continue;
        else 
            out += linha+'\n';
    }
    out.pop_back();
    arq_in.close();
    std::ofstream arq_out("jogadores.txt");
    arq_out << out;
    arq_out.close();

}

int Jogador::posJogo(std::string jogo)   {
    std::string linha = Jogador::checaJogador("apelido");
    std::stringstream info(linha);
    std::string aux;
    int i;
    for(i = 0; aux!=jogo;i++) {
        info>>aux;
    }
    return i;
}

void Jogador::addResultado(std::string jogo,std::string resultado)    {
    std::ifstream arq_in("jogadores.txt");

    if(!arq_in.is_open())
        throw std::ifstream::failure("Erro: arquivo inexistente.");
    if(arq_in.eof())
        throw std::ifstream::failure("Erro: arquivo vazio.");
    
    std::string linha;
    std::string out;
    while(!arq_in.eof())   {
        getline(arq_in,linha);
        if(linha.substr(0,linha.find(" "))==this->apelido)   {
            int npos = linha.find(" ");
            int pos = posJogo(jogo)-1;
            
            for(int i=1;i<pos;i++)  {
                npos = linha.find(" ", npos+1);
            }
            if(resultado=="vitoria")   {
                std::string numString = linha.substr(npos+1, linha.find("|", npos)-(npos+1));
                int num = std::stoi(numString);
                linha.replace(npos+1, numString.size(), std::to_string(num+1));
            } else if(resultado=="derrota")   {
                npos = linha.find("|",npos+1);
                std::string numString = linha.substr(npos+1, linha.find("|", npos+1)-(npos+1));
                int num = std::stoi(numString);
                linha.replace(npos+1, numString.size(), std::to_string(num+1));
            } else if(resultado=="empate")   {
                npos = linha.find("|", npos+1);
                npos = linha.find("|", npos+1);
                std::string numString = linha.substr(npos+1, linha.find(" ", npos+1)-(npos+1));
                int num = std::stoi(numString);
                linha.replace(npos+1, numString.size(), std::to_string(num+1));
            } else  {
                std::cout << "Resultado da partida invalido." << std::endl; 
            }
        }
        out+=linha+"\n";
    }
    out.pop_back();
    arq_in.close();
    std::ofstream arq_out("jogadores.txt");
    arq_out << out;
    arq_out.close();
}

void Jogador::getJogadores(std::string ordenar)   {
    if(ordenar!="[A|N]" && ordenar!="[N|A]")
        throw std::invalid_argument("Erro: dados invalidos.");

    std::vector<std::string> linhas;
    std::string aux;
    std::ifstream arq("jogadores.txt");

    if(!arq.is_open())
        throw std::ifstream::failure("Erro: arquivo inexistente.");
    if(arq.peek()==EOF)
        throw std::ifstream::failure("Erro: arquivo vazio.");
    while(!arq.eof())  {
        getline(arq,aux);
        linhas.push_back(aux);
    }
        
    //Ordenando nas duas formas possíveis:    
    if(ordenar=="[N|A]")   {
        std::vector<std::pair<std::string, std::string>> jogadores;
        for(int i=1; i<(int)linhas.size(); i++)   {
            int _pos = linhas[i].find(" ");
            std::string apelido = linhas[i].substr(0, _pos);
            std::string nome = linhas[i].substr(_pos+1, linhas[i].find(" ", _pos+1)-(_pos+1));
            jogadores.push_back({nome,apelido});
        }
        sort(jogadores.begin(), jogadores.end());
        int count = 1;
        for(auto &it : jogadores)  {
            for(int i=1; i<(int)linhas.size(); i++)   {
                std::string apelido = linhas[i].substr(0, linhas[i].find(" "));
                if(apelido==it.second) {
                    std::string aux = linhas[i];
                    linhas[i]=linhas[count];
                    linhas[count] = aux;
                }
            }
            count += 1;
        }
    } else if(ordenar=="[A|N]")    {
        sort(linhas.begin()+1,linhas.end());
    }
    
    for(int i=1; i<(int)linhas.size(); i++)   {
        int _pos = linhas[i].find(" ");
        int pos_jogo = linhas[0].find(" ");
        if(ordenar=="[A|N]")
            std::cout << linhas[i].substr(0, _pos) << " " <<linhas[i].substr(_pos+1, linhas[i].find(" ", _pos+1)-(_pos+1)) << std::endl;
        else
            std::cout << linhas[i].substr(_pos+1, linhas[i].find(" ", _pos+1)-(_pos+1)) << " " << linhas[i].substr(0, _pos) << std::endl;
        
        std::cout << "------------------------------------------------" << std::endl;
        for(int j=0; j<NUM_JOGOS; j++)  {
            _pos = linhas[i].find(" ", _pos+1);
            pos_jogo = linhas[0].find(" ", pos_jogo+1);
            std::cout << linhas[0].substr(pos_jogo+1, linhas[0].find(" ", pos_jogo+1)-(pos_jogo+1)) << " - ";
            std::cout << "V: " << linhas[i].substr(_pos+1, linhas[i].find("|", _pos)-(_pos+1));
            _pos = linhas[i].find("|", _pos+1);
            std::cout << " D: " << linhas[i].substr(_pos+1, linhas[i].find("|", _pos+1)-(_pos+1));
            _pos = linhas[i].find("|", _pos+1);
            std::cout << " E: " << linhas[i].substr(_pos+1, linhas[i].find(" ", _pos+1)-(_pos+1)) << std::endl;
        }
        std::cout << std::endl;
    }
}
