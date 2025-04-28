#include <iostream>
#include <TextSmith/TextSmith.h>
#include <vector>
#include <thread>
#include <chrono>

void setupRooms(TextSmithEngine& engine){
    Room testRoom("Test Room", "this is a room to test some things");
    Room testRoom2("Test room 2", "this is too see if i can do mutiple rooms");
    std::vector<Room> testRoomDirectionArray = {testRoom2};  // 0 = north 1=east 2 =south 3 = west
    testRoom.setDirectionArray(testRoomDirectionArray);
    std::vector<Room> RoomArray = {testRoom, testRoom2};
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

    engine.onStart = []() {
        int count = 10;
        for (int i = 0; i < count; i++) {
            std::cout << "==== on start hook ==== \n";
        }
    };

    engine.onFinish = []() {
        std::cout << "==== on finish hook ==== \n";
    };

    engine.startStopGame(); // This sets IsRunning to true

    while (engine.IsRunning) {
        std::cout << "please enter a command! \n";
        std::string command = engine.inputHandler.getInput<std::string>("Command: ");
        engine.parseCommand(command);
    }

    std::cout << "Game loop ended." << std::endl;
    return 0;
}
