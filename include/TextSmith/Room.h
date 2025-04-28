#pragma once

#include <string>
#include <vector>

class Room {
 public:
 Room(std::string RoomName, std::string RoomDescription);

 std::string getName();
 std::string getDescription();

 void setDirectionArray(std::vector<Room> DirectionArray);
 void insertDirectionArray(int index, Room& room);
 std::vector<Room> getDirectionArray();

 private:
 std::string Name;
 std::string description;
 std::vector<Room> DirectionArray = {}; // 0 = north 1=east 2 =south 3 = west

};