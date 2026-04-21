#include "gamelogger.h"
#include <iostream>
#include <ctime>

// Constructor
GameLogger::GameLogger() {
    logPath = "transaction_log.txt";
}

// Destructor
GameLogger::~GameLogger() {
    if (logFile.is_open())
        logFile.close();
}

// Initialize log file
void GameLogger::initLogFile() {
    logFile.open(logPath, std::ios::app);
}

// Log transaction with timestamp
void GameLogger::log(const std::string& playerName, const std::string& action, const std::string& itemName, int goldChange) {}

// Close log file
void GameLogger::closeLog() {}
