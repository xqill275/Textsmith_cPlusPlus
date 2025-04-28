#pragma once
#include <TextSmith/Room.h>
#include <TextSmith/Player.h>
#include <TextSmith/InputHandler.h>
#include <string>
#include <vector>
#include <map>
#include <functional>

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
    InputHandler inputHandler;  // Keep if you want InputHandler


    std::map<std::string, void (TextSmithEngine::*)()> allowedCommands;
    void parseCommand(std::string command);
    void help();
    void move();
    void look();
    void exit();


    //hooks
    // Hooks
    std::function<void()> onStart;
    std::function<void()> onFinish;
    
    // New helper functions
    void triggerOnStart();
    void triggerOnFinish();

};




