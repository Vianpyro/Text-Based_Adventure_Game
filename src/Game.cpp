// Copyright 2024 Vianney Veremme
#include "../include/Game.h"

#include <fstream>
#include <iostream>
#include <limits>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

const char* GAME_TITLE = "Shattered Kingdom";

void Game::endGame() {
    std::cout << "Thanks for playing " << GAME_TITLE << "!" << std::endl;
    gameState = GameState::GameOver;
}

int getValidatedChoice() {
    int choice;
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

void Game::initialize() {
    std::cout << "Welcome to " << GAME_TITLE << "!" << std::endl;
    loadStory();
    gameState = GameState::InGame;
}

bool Game::isGameOver() {
    return gameState == GameState::GameOver;
}

void Game::displayMainMenu() {
    gameState = GameState::MainMenu;
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Quit" << std::endl;
}

void Game::loadStory() {
    std::ifstream file("assets/quests/plot.json");

    // Check if file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open plot.json file!" << std::endl;
        return;
    }

    // Try to parse the JSON data
    json storyData;
    try {
        file >> storyData;
    } catch (const std::exception& e) {
        std::cerr << "Error: Failed to parse JSON data - " << e.what() << std::endl;
        return;
    }

    // Iterate over story data
    for (auto& [id, segment] : storyData.items()) {
        StorySegment storySegment;

        // Check if "description" exists
        if (segment.contains("description")) {
            storySegment.description = segment["description"];
        } else {
            std::cerr << "Warning: Missing 'description' for story segment " << id << std::endl;
            continue;  // Skip this segment if essential data is missing
        }

        // Parse choices if they exist
        if (segment.contains("choices")) {
            for (auto& [choiceId, choiceText] : segment["choices"].items()) {
                storySegment.choices[std::stoi(choiceId)] = choiceText;
            }
        } else {
            std::cerr << "Warning: Missing 'choices' for story segment " << id << std::endl;
        }

        // Parse next segment IDs if they exist
        if (segment.contains("nextSegmentIds")) {
            for (auto& [choiceId, nextId] : segment["nextSegmentIds"].items()) {
                storySegment.nextSegmentIds[std::stoi(choiceId)] = nextId;
            }
        } else {
            std::cerr << "Warning: Missing 'nextSegmentIds' for story segment " << id << std::endl;
        }

        storySegments[std::stoi(id)] = storySegment;
    }

    // Indicate the story has been loaded successfully
    std::cout << "Story loaded! Total segments: " << storySegments.size() << std::endl;
}

void Game::printStory() {
    for (const auto& [id, segment] : storySegments) {
        std::cout << "Segment ID: " << id << std::endl;
        std::cout << "Description: " << segment.description << std::endl;

        std::cout << "Choices:" << std::endl;
        for (const auto& [choiceId, choiceText] : segment.choices) {
            std::cout << "  Choice ID: " << choiceId
                      << " - " << choiceText << std::endl;
        }

        std::cout << "Next Segment IDs:" << std::endl;
        for (const auto& [choiceId, nextId] : segment.nextSegmentIds) {
            std::cout << "  Choice ID: " << choiceId
                      << " -> Next Segment ID: " << nextId << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
}

void Game::processInput() {
    int choice = getValidatedChoice();

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

void Game::processMainMenuInput() {
    int choice = getValidatedChoice();

    switch (choice) {
        case 1:
            std::cout << "Starting game..." << std::endl;
            initialize();
            gameState = GameState::InGame;
            break;
        case 2:
            std::cout << "Quitting game..." << std::endl;
            endGame();
            gameState = GameState::GameOver;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void Game::update() {
    printStory();
}
