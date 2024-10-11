// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <string>
#include <unordered_map>

// Game constants
extern const char* GAME_TITLE;

enum class GameState {
    MainMenu,
    InGame,
    GameOver
};

struct StorySegment {
    std::string description;
    std::unordered_map<int, std::string> choices;
    std::unordered_map<int, int> nextSegmentIds;
};

class Game {
 public:
    void endGame();
    void initialize();
    bool isGameOver();
    void printStory();
    void processInput();
    void update();
    void showMainMenu();

 private:
    int currentSegmentId;
    GameState gameState;
    std::unordered_map<int, StorySegment> storySegments;

    void displayMainMenu();
    int getValidatedChoice();
    void loadStory();
    void processMainMenuInput();
};

#endif  // INCLUDE_GAME_H_
