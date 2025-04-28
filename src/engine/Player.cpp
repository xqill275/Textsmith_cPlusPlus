#include <TextSmith/Player.h>

Player::Player() {}

void Player::setPlayerName(std::string newName) {
    this -> PlayerName = newName;
}

std::string Player::getPlayerName() {
    return PlayerName;
}

void Player::setRoomID(int RoomID) {
    CurrentRoomID = RoomID;
}

int Player::getRoomID() {
    return CurrentRoomID;
}

