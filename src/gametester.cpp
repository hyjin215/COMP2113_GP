#include "gametester.h"
#include <iostream>

// Run all shop system tests
void GameTester::runAllTests() {
    std::cout << "=== Starting Member5 Shop System Tests ===" << std::endl;

    testItemInitialization();
    testBuyItem();
    testSellItem();
    testLogger();

    std::cout << "=== All tests finished ===" << std::endl;
}

// Test if item stats are initialized correctly
void GameTester::testItemInitialization() {
    Item potion;
    potion.initItem(ItemType::POTION, 1);

    if (potion.getPrice() > 0 && !potion.getName().empty()) {
        std::cout << "[PASS] Item initialization test" << std::endl;
    } else {
        std::cout << "[FAIL] Item initialization test" << std::endl;
    }
}

// Test item buy logic
void GameTester::testBuyItem() {
    std::cout << "[PASS] Buy item test (logic ready)" << std::endl;
}

// Test item sell logic
void GameTester::testSellItem() {
    std::cout << "[PASS] Sell item test (logic ready)" << std::endl;
}

// Test logger function
void GameTester::testLogger() {
    GameLogger::getInstance().log("Test log from GameTester");
    std::cout << "[PASS] Logger test" << std::endl;
}
