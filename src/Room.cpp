#include <TextSmith/Room.h>
#include <string>

Room::Room(std::string RoomName, std::string RoomDescription) {
    this -> Name = RoomName;
    this -> description = RoomDescription;
}

std::string Room::getDescription() {
    return this -> description;
}

std::string Room::getName() {
    return this -> Name;
}


