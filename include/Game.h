// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <unordered_map>

#include "Story.h"
#include "Utility.h"

// Game constants
extern const char* GAME_TITLE;

class Game {
 public:
    bool isRunning;

    void endGame();
    void initialize();
    bool isGameOver();
    void displayMenu();
    void processInput();
    void update();
    void showMainMenu();

 private:
    int currentSegmentId;
    GameState gameState;
    Story story;

    void displayMainMenu();
    void processMainMenuInput();
};

#endif  // INCLUDE_GAME_H_
