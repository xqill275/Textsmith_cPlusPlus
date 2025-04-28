#include <TextSmith/Player.h>
#include <iostream>
#include <algorithm>

Player::Player() {}

void Player::setPlayerName(std::string newName) {
    PlayerName = newName;
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

// Inventory Methods

std::vector<Item> Player::getInventory() const {
    return Inventory;  // Return a copy of the inventory
}

void Player::addToInventory(const Item& item) {
    Inventory.push_back(item);  // Adds a copy of the item
}

bool Player::removeFromInventory(int index) {
    if (index >= 0 && index < Inventory.size()) {
        Inventory.erase(Inventory.begin() + index);
        return true;  // Successfully removed
    } else {
        std::cout << "Error: Invalid index, unable to remove item.\n";
        return false;  // Invalid index
    }
}

void Player::sortInventory() {
    std::sort(Inventory.begin(), Inventory.end(), [](const Item& a, const Item& b) {
        return a.getName() < b.getName();  // Assuming Item has a getName() method
    });
}