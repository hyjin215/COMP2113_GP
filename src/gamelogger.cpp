#include "gamelogger.h"
#include <iostream>
#include <fstream>

// Static instance
GameLogger& GameLogger::getInstance() {
    static GameLogger instance;
    return instance;
}

// Constructor: open log file
GameLogger::GameLogger() {
    logFile.open("transaction_log.txt", std::ios::app);
}

// Destructor: close file
GameLogger::~GameLogger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Log message to file
void GameLogger::log(const std::string& message) {
    if (logFile.is_open()) {
        logFile << "[LOG] " << message << std::endl;
    }
}
