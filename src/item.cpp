#include "item.h"

// Default constructor
Item::Item() {}

// Destructor
Item::~Item() {}

// Initialize item attributes based on type and grade
void Item::initItem(ItemType type, int grade) {
    this->type = type;
    this->grade = grade;

    if (type == ItemType::POTION) {
        isConsumable = true;
        name = "Potion";
        effectValue = ITEM_EFFECT_POTION[grade];
        price = ITEM_PRICE_POTION[grade];
    }
    else if (type == ItemType::SWORD) {
        isConsumable = false;
        name = "Sword";
        effectValue = ITEM_EFFECT_SWORD[grade];
        price = ITEM_PRICE_SWORD[grade];
    }
    else if (type == ItemType::ARMOR) {
        isConsumable = false;
        name = "Armor";
        effectValue = ITEM_EFFECT_ARMOR[grade];
        price = ITEM_PRICE_ARMOR[grade];
    }
    originalPurchasePrice = price;
}

// Get item type
ItemType Item::getType() const {
    return type;
}

// Get item grade
int Item::getGrade() const {
    return grade;
}

// Get item name
std::string Item::getName() const {
    return name;
}

// Get item effect value
int Item::getEffectValue() const {
    return effectValue;
}

// Get item price
int Item::getPrice() const {
    return price;
}

// Get original purchase price
int Item::getOriginalPurchasePrice() const {
    return originalPurchasePrice;
}

// Check if item is consumable
bool Item::isConsumableItem() const {
    return isConsumable;
}

// Set original purchase price
void Item::setOriginalPurchasePrice(int price) {
    originalPurchasePrice = price;
}

// Apply item effect to player
void Item::applyEffect(Player& player) {}
