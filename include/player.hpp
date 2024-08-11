#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Player    {
    private:
        std::string nickname;
        std::string name;
        static int posGame(std::string game);
        static std::string checkPlayer(std::string nickname);
    public:
        Player(std::string nickname);
        void addResult(std::string game, std::string result);
        static void setPlayer(std::string nickname, std::string name);
        static void removePlayer(std::string nickname);
        static void getPlayers(std::string sort);
};

#endif