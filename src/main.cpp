#include <iostream>
#include <TextSmith/TextSmith.h>
#include <vector>
#include <thread>
#include <chrono>

void setupRooms(TextSmithEngine& engine){
    Room testRoom("Test Room", "this is a room to test some things");
    std::vector<Room> RoomArray = {testRoom};
    engine.setUpRooms(RoomArray);
}

int main() {
    int gameLoopTest = 0;
    TextSmithEngine engine("TestGame");
    Player p1;
    engine.init();
    setupRooms(engine);
    engine.assignPlayer(p1);
    std::cout << "Initial state: " << engine.IsRunning << std::endl;
    engine.startStopGame(); // This sets IsRunning to true

    while (engine.IsRunning) {
        if (!engine.RoomIdArray.empty()) {
            std::cout << "Room Name: " << engine.RoomIdArray[0].getName() << std::endl;
        } else {
            std::cout << "No rooms available!" << std::endl;
        }
        
        std::cout << "Game: " << engine.GameName << " | Loop: " << gameLoopTest << std::endl;

        if (gameLoopTest == 10) {
            engine.startStopGame(); // This sets IsRunning to false, breaking the loop
        }
        gameLoopTest += 1;
    }

    std::cout << "Game loop ended." << std::endl;
    return 0;
}
