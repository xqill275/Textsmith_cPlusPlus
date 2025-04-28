#include <TextSmith/TextSmithEngine.h>
#include <TextSmith/Room.h>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

TextSmithEngine::TextSmithEngine(std::string gameName) {
    this->GameName = gameName;
    this->IsRunning = false;
    allowedCommands["help"] = &TextSmithEngine::help;
    allowedCommands["move"] = &TextSmithEngine::move;
    allowedCommands["look"] = &TextSmithEngine::look;
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

void TextSmithEngine::parseCommand(std::string command) {
    auto it = allowedCommands.find(command);
    if (it != allowedCommands.end()) {
        (this->*(it->second))();
    } else {
        std::cout << "unknow command" << command << "\n";
    }
}

void TextSmithEngine::help() {
    std::cout << "Available commands:\n";
    for (const auto& cmd : allowedCommands) {
        std::cout << "- " << cmd.first << "\n";
    }
}

void TextSmithEngine::move() {
    std::vector<std::string> directionLabels = {"north", "east", "south", "west"};
    int currentPlayerLocation = this->assignedPlayer.getRoomID();
    std::vector<Room> directionArray = this->RoomIdArray[currentPlayerLocation].getDirectionArray();
    
    for (int i = 0; i < directionArray.size(); i++) {
        std::cout << directionLabels[i] << ": " << directionArray[i].getName() << "\n";
    }

    std::string directionChoice = this->inputHandler.getInput<std::string>("Enter a location (north, south, etc ..): ");
    auto it = std::find(directionLabels.begin(), directionLabels.end(), directionChoice);

    if (it != directionLabels.end()) {
        int directionIndex = std::distance(directionLabels.begin(), it);

        if (directionIndex < directionArray.size()) {
            Room RoomTarget = directionArray[directionIndex];

            int RoomIndex = -1;
            for (int i = 0; i < RoomIdArray.size(); ++i) {
                if (RoomIdArray[i].getName() == RoomTarget.getName()) {
                    RoomIndex = i;
                    break;
                }
            }

            if (RoomIndex != -1) {
                this->assignedPlayer.setRoomID(RoomIndex);
                std::cout << "You moved to " << RoomTarget.getName() << "!\n";
            } else {
                std::cout << "Error: Destination room not found!\n";
            }

        } else {
            std::cout << "That direction is blocked.\n";
        }
    } else {
        std::cout << "That is not a valid location.\n";
    }
}

void TextSmithEngine::look() {
    int playerLocation = this->assignedPlayer.getRoomID();
    std::string description = this->RoomIdArray[playerLocation].getDescription();
    std::cout << description;
}
