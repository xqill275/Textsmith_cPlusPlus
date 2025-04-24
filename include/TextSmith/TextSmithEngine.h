#pragma once
#include <TextSmith/Room.h>
#include <TextSmith/Player.h>
#include <string>
#include <vector>
#include <map>

class TextSmithEngine {
  public:
  TextSmithEngine(std::string GameName);
  void init();
  void startStopGame();
  void setUpRooms(const std::vector<Room>& RoomArray);
  void assignPlayer(Player& playerObject);
  
  std::string GameName;
  bool IsRunning;

  std::vector<Room> RoomIdArray;

  Player assignedPlayer;
};



