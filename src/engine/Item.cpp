#include <TextSmith/Item.h>

Item::Item(std::string itemName, std::string itemDescription, int worth) {
    this->itemName = itemName;
    this->itemDescription = itemDescription;
    this->worth = worth;
}

std::string Item::getName() const {
    return itemName;
}

std::string Item::getDescription() const {
    return itemDescription;
}