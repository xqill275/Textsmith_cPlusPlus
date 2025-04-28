#pragma once

#include <string>

class Item {
    public:
    Item(std::string itemName, std::string itemDescription, int worth);

    std::string getName() const;
    std::string getDescription() const;
    private:
    std::string itemName;
    std::string itemDescription;
    int worth;
};