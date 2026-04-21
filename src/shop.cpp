#include "shop.h"

// Default constructor
Shop::Shop() {

}

// Destructor
Shop::~Shop() {

}

// Initialize shop with merchant, player and inventory
void Shop::initShop(Merchant* m, Player* p, Inventory* inv) {
    merchant = m;
    player = p;
    inventory = inv;
    isShopOpen = false;
    sellDiscount = SELL_DISCOUNT;
}

// Purchase item from merchant
bool Shop::buyItem(ItemType type, int grade) {
    if (!merchant->hasItem(type, grade)) {
        return false;
    }
    return true;
}

// Sell item back to shop
bool Shop::sellItem(ItemType type, int grade) {
    return true;
}

// Calculate discounted sell price
int Shop::calculateSellPrice(const Item& item) {
    return static_cast<int>(item.getOriginalPurchasePrice() * sellDiscount);
}

// Show shop UI text
std::string Shop::showShopUI() {
    return "=== Shop Menu ===\n1. Buy Item\n2. Sell Item\n3. Exit";
}

// Close shop interface
void Shop::closeShop() {
    isShopOpen = false;
}

// Check if shop is open
bool Shop::get_isShopOpen() const {
    return isShopOpen;
}

// Get sell discount rate
float Shop::get_sellDiscount() const {
    return sellDiscount;
}
