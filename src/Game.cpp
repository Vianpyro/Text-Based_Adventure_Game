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
    story.loadStory("0-plentiful_valley");
    gameState = GameState::MainMenu;
}

bool Game::isGameOver() {
    return gameState == GameState::GameOver;
}

void Game::displayMainMenu() {
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Quit" << std::endl;
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
        case 1:
            std::cout << "Starting game..." << std::endl;
            gameState = GameState::InGame;
            story.printSegment();
            break;
        case 2:
            std::cout << "Quitting game..." << std::endl;
            gameState = GameState::GameOver;
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
            story.printSegment();
            break;
        case GameState::GameOver:
            break;
    }
}

void Game::showMainMenu() {
    displayMainMenu();
    processMainMenuInput();
}
