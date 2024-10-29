// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <memory>
#include <unordered_map>

#include "Character.h"
#include "Mage.h"
#include "Rogue.h"
#include "Story.h"
#include "Utility.h"
#include "Warrior.h"

// Game constants
extern const char* GAME_TITLE;

enum class GameState {
    MainMenu,
    InGame,
    GameOver
};

class Game {
 public:
    void endGame();
    void initialize();
    bool isGameOver() const;
    void processInput();
    void update();
    void showMainMenu();

 private:
    int currentSegmentId;
    GameState gameState;
    Story story;

    std::unique_ptr<Character> character;
    void chooseCharacter();
    void displayMainMenu();
    void loadNextStory();
    void processMainMenuInput();
};

#endif  // INCLUDE_GAME_H_
