#include "shop.h"
#include "gamelogger.h"

// Constructor: initialize discount and pointers
Shop::Shop()
    : merchant(nullptr), player(nullptr), inventory(nullptr), sellDiscount(SELL_DISCOUNT) {}

// Link merchant, player, and inventory to the shop
void Shop::initShop(Merchant* m, Player* p, Inventory* inv) {
    merchant = m;
    player = p;
    inventory = inv;
}

// Buy item from shop: check gold, deduct gold, add to inventory
bool Shop::buyItem(ItemType type, int grade) {
    // Check if merchant has the item
    if (!merchant->hasItem(type, grade)) {
        return false;
    }

    Item item = merchant->getItem(type, grade);
    int price = item.getPrice();

    // Check if player has enough gold
    if (player->getMoney() < price) {
        return false;
    }

    // Deduct gold and add item to inventory
    player->changeMoney(-price);
    inventory->addItem(item.getName());

    // Log transaction
    GameLogger::getInstance().log("Bought " + item.getName() + " for " + std::to_string(price) + " gold");
    return true;
}

// Sell item to shop: remove from inventory, add gold (with discount)
bool Shop::sellItem(ItemType type, int grade) {
    Item tempItem;
    tempItem.initItem(type, grade);
    std::string itemName = tempItem.getName();

    // Check if inventory has the item
    if (!inventory->hasItem(itemName)) {
        return false;
    }

    // Calculate sell price
    int sellPrice = calculateSellPrice(tempItem);

    // Remove item and give gold to player
    inventory->removeItem(itemName);
    player->changeMoney(sellPrice);

    // Log transaction
    GameLogger::getInstance().getInstance().log("Sold " + itemName + " for " + std::to_string(sellPrice) + " gold");
    return true;
}

// Calculate selling price: original price * discount
int Shop::calculateSellPrice(const Item& item) const {
    return static_cast<int>(item.getPrice() * sellDiscount);
}
