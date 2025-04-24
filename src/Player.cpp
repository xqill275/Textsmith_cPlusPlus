#include <TextSmith/Player.h>

Player::Player() {}

void Player::setPlayerName(std::string newName) {
    this -> PlayerName = newName;
}

std::string Player::getPlayerName() {
    return PlayerName;
}

