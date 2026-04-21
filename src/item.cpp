#include "item.h"

// Default constructor
Item::Item()
    : itemType(ItemType::POTION), grade(0), name(""), hpEffect(0), atkEffect(0), defEffect(0), price(0) {}

// Initialize item with type and grade (set stats, name, price based on type and grade)
void Item::initItem(ItemType type, int grade) {
    itemType = type;
    this->grade = grade;

    // Set effects and price based on item type and grade
    switch (type) {
        case ItemType::POTION:
            name = "Potion_" + std::to_string(grade);
            hpEffect = ITEM_EFFECT_POTION * (grade + 1);
            atkEffect = 0;
            defEffect = 0;
            price = ITEM_PRICE_POTION * (grade + 1);
            break;

        case ItemType::SWORD:
            name = "Sword_" + std::to_string(grade);
            hpEffect = 0;
            atkEffect = ITEM_EFFECT_SWORD * (grade + 1);
            defEffect = 0;
            price = ITEM_PRICE_SWORD * (grade + 1);
            break;

        case ItemType::ARMOR:
            name = "Armor_" + std::to_string(grade);
            hpEffect = 0;
            atkEffect = 0;
            defEffect = ITEM_EFFECT_ARMOR * (grade + 1);
            price = ITEM_PRICE_ARMOR * (grade + 1);
            break;
    }
}

// Apply item effects to player (heal HP, increase ATK/DEF)
void Item::applyEffect(Player& player) {
    // Potion: restore health
    if (itemType == ItemType::POTION) {
        player.change_HP(hpEffect);
    }

    // Sword: increase attack
    if (itemType == ItemType::SWORD) {
        player.change_ATK(atkEffect);
    }

    // Armor: increase defense
    if (itemType == ItemType::ARMOR) {
        player.change_DEF(defEffect);
    }
}

// Getter functions
std::string Item::getName() const { return name; }
ItemType Item::getType() const { return itemType; }
int Item::getGrade() const { return grade; }
int Item::getHpEffect() const { return hpEffect; }
int Item::getAtkEffect() const { return atkEffect; }
int Item::getDefEffect() const { return defEffect; }
int Item::getPrice() const { return price; }
