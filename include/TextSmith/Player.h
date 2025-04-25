#pragma once
#include <string>


class Player {
    public:
    Player();

    void setPlayerName(std::string newName);
    std::string getPlayerName();


    std::string PlayerName;

};