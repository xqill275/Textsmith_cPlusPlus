#pragma once
#include <string>


class Player {
    public:
    Player();

    void setPlayerName(std::string newName);
    void setRoomID(int newID);
    int getRoomID();
    std::string getPlayerName();



    std::string PlayerName;
    int CurrentRoomID = 0;
};