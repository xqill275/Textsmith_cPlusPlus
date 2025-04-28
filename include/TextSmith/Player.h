#pragma once
#include <string>
#include <vector>
#include <TextSmith/Item.h>

class Player {
public:
    Player();

    // Player properties
    void setPlayerName(std::string newName);
    std::string getPlayerName();
    void setRoomID(int newID);
    int getRoomID();

    // Inventory management
    std::vector<Item> getInventory() const;  // Return a copy of the inventory
    void addToInventory(const Item& item);  // Add an item by const reference
    bool removeFromInventory(int index);   // Return success status (true if removed)
    void sortInventory();  // Sort the inventory items

private:
    std::string PlayerName;
    int CurrentRoomID = 0;
    std::vector<Item> Inventory;  // Use std::vector<Item> instead of std::vector<Item&>
};
