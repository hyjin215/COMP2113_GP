#include "merchant.h"

// Default constructor
Merchant::Merchant() {
    maxStockPerItem = MAX_STOCK;
    isAvailable = false;
    currentDiff = Difficulty::EASY;
}

// Destructor
Merchant::~Merchant() {}

// Initialize merchant goods and availability
void Merchant::initMerchant(Difficulty diff) {
    currentDiff = diff;
    isAvailable = true;

    for (int grade = 0; grade < 3; grade++) {
        Item potion;
        potion.initItem(ItemType::POTION, grade);
        goods[ItemType::POTION][grade] = potion;

        Item sword;
        sword.initItem(ItemType::SWORD, grade);
        goods[ItemType::SWORD][grade] = sword;

        Item armor;
        armor.initItem(ItemType::ARMOR, grade);
        goods[ItemType::ARMOR][grade] = armor;
    }
}

// Check if the item exists in stock
bool Merchant::hasItem(ItemType type, int grade) {
    return goods[type][grade].getGrade() == grade;
}

// Get the specified item from inventory
Item Merchant::getItem(ItemType type, int grade) {
    return goods[type][grade];
}

// Show all goods provided by the merchant
std::string Merchant::showGoodsList() {
    return "=== Merchant Goods ===\nPotions (Lv0-2)\nSwords (Lv0-2)\nArmors (Lv0-2)";
}

// Check merchant availability
bool Merchant::getIsAvailable() const {
    return isAvailable;
}

// Set merchant availability status
void Merchant::setIsAvailable(bool status) {
    isAvailable = status;
}

// Get current game difficulty
Difficulty Merchant::getCurrentDiff() const {
    return currentDiff;
}
