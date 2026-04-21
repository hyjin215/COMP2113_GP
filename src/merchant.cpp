#include "merchant.h"
#include <iostream>

// Constructor: initialize merchant with game difficulty
Merchant::Merchant(Difficulty diff)
    : difficulty(diff), isAvailable(true) {
    // Initialize all items when merchant is created
    initializeGoods();
}

// Destructor
Merchant::~Merchant() {}

// Initialize all goods (Potion / Sword / Armor, 3 grades each)
// Follows README Item System design: Low / Mid / High grade
void Merchant::initializeGoods() {
    // Clear goods list first
    goods.clear();

    // Create POTION for grade 0, 1, 2
    for (int grade = 0; grade < 3; grade++) {
        Item potion;
        potion.initItem(ItemType::POTION, grade);
        goods.push_back(potion);
    }

    // Create SWORD for grade 0, 1, 2
    for (int grade = 0; grade < 3; grade++) {
        Item sword;
        sword.initItem(ItemType::SWORD, grade);
        goods.push_back(sword);
    }

    // Create ARMOR for grade 0, 1, 2
    for (int grade = 0; grade < 3; grade++) {
        Item armor;
        armor.initItem(ItemType::ARMOR, grade);
        goods.push_back(armor);
    }
}

// Check if the merchant has the specified item (type + grade)
bool Merchant::hasItem(ItemType type, int grade) const {
    for (const Item& item : goods) {
        if (item.getType() == type && item.getGrade() == grade) {
            return true;
        }
    }
    return false;
}

// Get the specified item from merchant
Item Merchant::getItem(ItemType type, int grade) const {
    for (const Item& item : goods) {
        if (item.getType() == type && item.getGrade() == grade) {
            return item;
        }
    }
    // Return empty item if not found
    return Item();
}

// Return all goods list as string for shop UI display
std::string Merchant::showGoodsList() const {
    std::string list = "\n=== Merchant Goods ===\n";
    for (const Item& item : goods) {
        list += "- " + item.getName()
             + " | Price: " + std::to_string(item.getPrice()) + " gold\n";
    }
    return list;
}

// Check if merchant is available (for shop spawn logic)
bool Merchant::getIsAvailable() const {
    return isAvailable;
}

// Set merchant availability (open/close shop)
void Merchant::setIsAvailable(bool status) {
    isAvailable = status;
}
