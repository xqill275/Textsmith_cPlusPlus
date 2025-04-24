#include <TextSmith/TextSmithEngine.h>
#include <TextSmith/Room.h>
#include <string>
#include <iostream>

TextSmithEngine::TextSmithEngine(std::string gameName) {
    this->GameName = gameName;
    this->IsRunning = false;
}

void TextSmithEngine::init() {
    std::cout << "we are now a libary \n";
}

void TextSmithEngine::startStopGame() {
    IsRunning = !IsRunning;
}

void TextSmithEngine::setUpRooms(const std::vector<Room>& RoomArray) {
    RoomIdArray = RoomArray;
}

void TextSmithEngine::assignPlayer(Player& PlayerObject) {
    assignedPlayer = PlayerObject;
}