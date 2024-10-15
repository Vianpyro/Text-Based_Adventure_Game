// Copyright 2024 Vianney Veremme
#include "../include/Game.h"

#include <fstream>
#include <iostream>

const char* GAME_TITLE = "Shattered Kingdom";

void Game::endGame() {
    std::cout << "Thanks for playing " << GAME_TITLE << "!" << std::endl;
    gameState = GameState::GameOver;
}

void Game::initialize() {
    std::cout << "Welcome to " << GAME_TITLE << "!" << std::endl;
    story.loadStory();
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

void Game::processInput() {
    int choice = getValidatedChoice();

    std::cout << "You chose: " << choice << std::endl;

    if (story.isChoiceValid(choice)) {
        story.setCurrentSegment(choice);
    } else {
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
    story.printSegment();
}

void Game::showMainMenu() {
    displayMainMenu();
    processMainMenuInput();
}
