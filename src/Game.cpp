// Copyright 2024 Vianney Veremme
#include "../include/Game.h"

#include <fstream>
#include <iostream>

const char* GAME_TITLE = "Shattered Kingdom";

void Game::chooseCharacter() {
    bool validChoice = false;

    while (!validChoice) {
        std::cout << "Choose your character class:" << std::endl
                  << "1. Mage" << std::endl
                  << "2. Rogue" << std::endl
                  << "3. Warrior" << std::endl;

        int choice = getValidatedChoice();  // Get validated integer input

        switch (choice) {
            case 1:
                character = std::make_unique<Mage>("PlayerMage");
                validChoice = true;
                break;
            case 2:
                character = std::make_unique<Rogue>("PlayerRogue");
                validChoice = true;
                break;
            case 3:
                character = std::make_unique<Warrior>("PlayerWarrior");
                validChoice = true;
                break;
            default:
                std::cout << "Invalid choice." << std::endl
                          << "Please select a valid character class."
                          << std::endl;
                break;
        }
    }
}

void Game::displayMainMenu() {
    std::cout << "Main Menu" << std::endl
              << "1. Start Game" << std::endl
              << "2. New Character" << std::endl
              << "3. Load Character" << std::endl
              << "0. Quit" << std::endl;
}

void Game::endGame() {
    std::cout << "Thanks for playing " << GAME_TITLE << "!" << std::endl;
    gameState = GameState::GameOver;
}

void Game::initialize() {
    std::cout << "Welcome to " << GAME_TITLE << "!" << std::endl;
    story.loadStory("0-plentiful_valley");
    gameState = GameState::MainMenu;
}

bool Game::isGameOver() const {
    return gameState == GameState::GameOver;
}

void Game::loadNextStory() {
    std::string nextStory = story.getNextStoryName();

    if (nextStory.empty()) {
        endGame();
        return;
    }

    story.unloadStory();
    story.loadStory(nextStory);
    story.printSegment();
}

void Game::processInput() {
    int choice = getValidatedChoice();

    if (choice == 0) {
        gameState = GameState::MainMenu;
        return;
    }

    story.nextSegment(choice);
}

void Game::processMainMenuInput() {
    int choice = getValidatedChoice();

    switch (choice) {
        case 0:
            std::cout << "Quitting game..." << std::endl;
            gameState = GameState::GameOver;
            break;
        case 1:
            std::cout << "Starting game..." << std::endl;
            gameState = GameState::InGame;
            story.printSegment();
            break;
        case 2:
            chooseCharacter();
            break;
        case 3:
            std::cout << "Loading character..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void Game::update() {
    switch (gameState) {
        case GameState::MainMenu:
            showMainMenu();
            break;
        case GameState::InGame:
            if (!story.printSegment()) {
                loadNextStory();
            }
            break;
        case GameState::GameOver:
            break;
    }
}

void Game::showMainMenu() {
    displayMainMenu();
    processMainMenuInput();
}
