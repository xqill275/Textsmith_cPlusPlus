#pragma once

#include <string>

class Room {
 public:
 Room(std::string RoomName, std::string RoomDescription);

 std::string getName();
 std::string getDescription();

 private:
 std::string Name;
 std::string description;

};