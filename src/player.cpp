#include <fstream>
#include <sstream> 
#include "player.hpp"

#define NUM_GAMES 5

Player::Player(std::string nickname)    {
    std::string linha = Player::checkPlayer(nickname);
    std::stringstream info(linha);
    info >> this->nickname;
    info >> this->name;

}

std::string Player::checkPlayer(std::string nickname)   {
    if(nickname.find(" ")!=std::string::npos)
        throw std::logic_error("Erro: dados incorretos.");

    std::ifstream file("jogadores.txt");  
    if(!file.is_open())
        throw std::ifstream::failure("Erro: arquivo inexistente.");
    if(file.peek()==EOF)
        throw std::ifstream::failure("Erro: arquivo vazio.");
    
    std::string line;
    for(int i=0; i<(int)nickname.length(); i++)
            if(nickname[i]>=65 && nickname[i]<=90)
                nickname[i]+=32;
    while(!file.eof())  {
        getline(file,line);
        if(line.substr(0,line.find(" "))==nickname) {
            return line;
        }
    }
    file.close();
    throw std::logic_error("Erro: jogador inexistente.");
}

void Player::setPlayer(std::string nickname, std::string name)  {
    try {
        if(!Player::checkPlayer(nickname).empty()) {
            return;
        }   
    } catch(std::logic_error &e)    {}

    std::ofstream file("jogadores.txt", std::ios::app);

    for(int i=0; i<(int)nickname.length(); i++)
        if(nickname[i]>=65 && nickname[i]<=90)
            nickname[i]+=32;
    for(int i=0; i<(int)name.length(); i++)
        if(name[i]>=65 && name[i]<=90)
            name[i]+=32;

    file << std::endl << nickname << " " << name;
    for(int i=0; i<NUM_GAMES;i++) 
        file << " 0|0|0";
    file.close();

}

void Player::removePlayer(std::string nickname) {
    Player::checkPlayer(nickname);

    std::ifstream file_in("jogadores.txt");
    std::string line; 
    std::string out;

    for(int i=0; i<(int)nickname.length(); i++)
        if(nickname[i]>=65 && nickname[i]<=90)
            nickname[i]+=32;

    while(!file_in.eof())   {
        getline(file_in, line);
        if(line.substr(0, line.find(" "))==nickname)
            continue;
        else 
            out += line+'\n';
    }
    out.pop_back();
    file_in.close();
    std::ofstream file_out("jogadores.txt");
    file_out << out;
    file_out.close();

}

int Player::posGame(std::string game)   {
    std::string line = Player::checkPlayer("nickname");
    std::stringstream info(line);
    std::string aux;
    int i;
    for(i = 0; aux!=game;i++) {
        info>>aux;
    }
    return i;
}

void Player::addResult(std::string game,std::string result)    {
    std::ifstream file_in("jogadores.txt");

    if(!file_in.is_open())
        throw std::ifstream::failure("Erro: arquivo inexistente.");
    if(file_in.eof())
        throw std::ifstream::failure("Erro: arquivo vazio.");
    
    std::string line;
    std::string out;
    while(!file_in.eof())   {
        getline(file_in,line);
        if(line.substr(0,line.find(" "))==this->nickname)   {
            int npos = line.find(" ");
            int pos = posGame(game)-1;
            
            for(int i=1;i<pos;i++)  {
                npos = line.find(" ", npos+1);
            }
            if(result=="win")   {
                std::string numString = line.substr(npos+1, line.find("|", npos)-(npos+1));
                int num = std::stoi(numString);
                line.replace(npos+1, numString.size(), std::to_string(num+1));
            } else if(result=="lost")   {
                npos = line.find("|",npos+1);
                std::string numString = line.substr(npos+1, line.find("|", npos+1)-(npos+1));
                int num = std::stoi(numString);
                line.replace(npos+1, numString.size(), std::to_string(num+1));
            } else if(result=="draw")   {
                npos = line.find("|", npos+1);
                npos = line.find("|", npos+1);
                std::string numString = line.substr(npos+1, line.find(" ", npos+1)-(npos+1));
                int num = std::stoi(numString);
                line.replace(npos+1, numString.size(), std::to_string(num+1));
            } else  {
                std::cout << "Resultado da partida invalido." << std::endl; 
            }
        }
        out+=line+"\n";
    }
    out.pop_back();
    file_in.close();
    std::ofstream file_out("jogadores.txt");
    file_out << out;
    file_out.close();
}

void Player::getPlayers(std::string sorting)   {
    if(sorting!="[A|N]" && sorting!="[N|A]")
        throw std::logic_error("Erro: dados invalidos.");

    std::vector<std::string> lines;
    std::string aux;
    std::ifstream file("jogadores.txt");

    if(!file.is_open())
        throw std::ifstream::failure("Erro: arquivo inexistente.");
    if(file.peek()==EOF)
        throw std::ifstream::failure("Erro: arquivo vazio.");
    while(!file.eof())  {
        getline(file,aux);
        lines.push_back(aux);
    }
        
    //Ordenando nas duas formas possíveis:    
    if(sorting=="[N|A]")   {
        std::vector<std::pair<std::string, std::string>> players;
        for(int i=1; i<(int)lines.size(); i++)   {
            int _pos = lines[i].find(" ");
            std::string nickname = lines[i].substr(0, _pos);
            std::string name = lines[i].substr(_pos+1, lines[i].find(" ", _pos+1)-(_pos+1));
            players.push_back({name,nickname});
        }
        sort(players.begin(), players.end());
        int count = 1;
        for(auto &it : players)  {
            for(int i=1; i<(int)lines.size(); i++)   {
                std::string nickname = lines[i].substr(0, lines[i].find(" "));
                if(nickname==it.second) {
                    std::string aux = lines[i];
                    lines[i]=lines[count];
                    lines[count] = aux;
                }
            }
            count += 1;
        }
    } else if(sorting=="[A|N]")    {
        sort(lines.begin()+1,lines.end());
    }
    
    for(int i=1; i<(int)lines.size(); i++)   {
        int _pos = lines[i].find(" ");
        int pos_game = lines[0].find(" ");
        if(sorting=="[A|N]")
            std::cout << lines[i].substr(0, _pos) << " " <<lines[i].substr(_pos+1, lines[i].find(" ", _pos+1)-(_pos+1)) << std::endl;
        else
            std::cout << lines[i].substr(_pos+1, lines[i].find(" ", _pos+1)-(_pos+1)) << " " << lines[i].substr(0, _pos) << std::endl;
        for(int j=0; j<NUM_GAMES; j++)  {
            _pos = lines[i].find(" ", _pos+1);
            pos_game = lines[0].find(" ", pos_game+1);
            std::cout << lines[0].substr(pos_game+1, lines[0].find(" ", pos_game+1)-(pos_game+1)) << " - ";
            std::cout << "V: " << lines[i].substr(_pos+1, lines[i].find("|", _pos)-(_pos+1));
            _pos = lines[i].find("|", _pos+1);
            std::cout << " D: " << lines[i].substr(_pos+1, lines[i].find("|", _pos+1)-(_pos+1));
            _pos = lines[i].find("|", _pos+1);
            std::cout << " E: " << lines[i].substr(_pos+1, lines[i].find(" ", _pos+1)-(_pos+1)) << std::endl;
        }
        std::cout << std::endl;
    }
}