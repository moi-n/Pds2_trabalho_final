#include <fstream>
#include <sstream> 
#include "player.hpp"

#define NUM_GAMES 3

Player::Player(std::string nickname)
{
    std::string linha = Player::checkPlayer(nickname);
    if(linha=="")    {
        std::cout << "Jogador inexistente." << std::endl;
        this->nickname = "";
        this->name = "";
    } else  {
        std::stringstream info(linha);
        info >> this->nickname;
        info >> this->name;
    }
}

std::string Player::checkPlayer(std::string nickname)   {
    std::ifstream file("jogadores.txt");
    std::string line;
    while(!file.eof())  {
        getline(file,line);
        if(line.substr(0,line.find(" "))==nickname) {
            return line;
        }
    }
    file.close();
    return {};
}

void Player::setPlayer(std::string nickname, std::string name)  {
    if(!Player::checkPlayer(nickname).empty())   {
        std::cout << "Jogador ja cadastrado." << std::endl; 
    } else  {
        std::ofstream file("jogadores.txt", std::ios::app);
        file << std::endl << nickname << " " << name;
        for(int i=0; i<NUM_GAMES;i++) 
            file << " 0|0";
        file.close();
    }
}

void Player::removePlayer(std::string nickname) {
    if(Player::checkPlayer(nickname).empty())   {
        std::cout << "Jogador inexistente." << std::endl;
    } else {
        std::ifstream file_in("jogadores.txt");
        std::string line; 
        std::string out;
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
                std::string numString = line.substr(npos+1, line.find(" ", npos+1)-(npos+1));
                int num = std::stoi(numString);
                line.replace(npos+1, numString.size(), std::to_string(num+1));
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