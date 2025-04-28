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

void Room::setDirectionArray(std::vector<Room> newDirectionArray) {
    DirectionArray = newDirectionArray;
}

void Room::insertDirectionArray(int index, Room& room) {
    DirectionArray[index] = room;
}
std::vector<Room> Room::getDirectionArray() {
    return DirectionArray;
}


