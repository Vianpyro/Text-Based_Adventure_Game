// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <string>
#include <unordered_map>

// Game constants
extern const char* GAME_TITLE;

struct StorySegment {
    std::string description;
    std::unordered_map<int, std::string> choices;
    std::unordered_map<int, int> nextSegmentIds;
};

class Game {
 public:
    bool isRunning;

    void endGame();
    void initialize();
    bool isGameOver();
    void displayMenu();
    void loadStory();
    void processInput();
    void update();

 private:
    std::unordered_map<int, StorySegment> storySegments;
    int currentSegmentId;
};

#endif  // INCLUDE_GAME_H_
