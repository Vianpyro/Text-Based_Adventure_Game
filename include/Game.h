// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <string>

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
};

#endif  // INCLUDE_GAME_H_
