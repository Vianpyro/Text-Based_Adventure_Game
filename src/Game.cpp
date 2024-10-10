// Copyright 2024 Vianney Veremme
#include "../include/Game.h"

#include <fstream>
#include <iostream>
#include <limits>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

const char* GAME_TITLE = "Shattered Kingdom";

void Game::endGame() {
    // Show goodbye message
    std::cout << "Thanks for playing " << GAME_TITLE << "!" << std::endl;

    // Set game state
    isRunning = false;
}

void Game::initialize() {
    // Show welcome message
    std::cout << "Welcome to " << GAME_TITLE << "!" << std::endl;

    // Set game state
    isRunning = true;
}

bool Game::isGameOver() {
    return !isRunning;
}

void Game::displayMenu() {
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Quit" << std::endl;
}

void Game::loadStory() {
    std::ifstream file("assets/quests/plot.json");
    json storyData;
    file >> storyData;

    for (auto& [id, segment] : storyData.items()) {
        StorySegment storySegment;
        storySegment.description = segment["description"];

        for (auto& [choiceId, choiceText] : segment["choices"].items()) {
            storySegment.choices[std::stoi(choiceId)] = choiceText;
        }

        for (auto& [choiceId, nextId] : segment["nextSegmentIds"].items()) {
            storySegment.nextSegmentIds[std::stoi(choiceId)] = nextId;
        }

        storySegments[std::stoi(id)] = storySegment;
    }

    // Tell the user the story has been loaded
    std::cout << "Story loaded!" << std::endl;
}

void Game::printStory() {
    for (const auto& [id, segment] : storySegments) {
        std::cout << "Segment ID: " << id << std::endl;
        std::cout << "Description: " << segment.description << std::endl;

        std::cout << "Choices:" << std::endl;
        for (const auto& [choiceId, choiceText] : segment.choices) {
            std::cout << "  Choice ID: " << choiceId << " - " << choiceText << std::endl;
        }

        std::cout << "Next Segment IDs:" << std::endl;
        for (const auto& [choiceId, nextId] : segment.nextSegmentIds) {
            std::cout << "  Choice ID: " << choiceId << " -> Next Segment ID: " << nextId << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
}

void Game::processInput() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number." << std::endl;
        return;
    }

    switch (choice) {
        case 1:
            std::cout << "Starting game..." << std::endl;
            loadStory();
            break;
        case 2:
            std::cout << "Quitting game..." << std::endl;
            endGame();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void Game::update() {
    printStory();
}
