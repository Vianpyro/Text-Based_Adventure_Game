// Copyright 2024 Vianney Veremme
#include "../include/Game.h"

#include <fstream>
#include <iostream>
#include <limits>

const char* GAME_TITLE = "Shattered Kingdom";

void Game::endGame() {
    std::cout << "Thanks for playing " << GAME_TITLE << "!" << std::endl;
    gameState = GameState::GameOver;
}

int Game::getValidatedChoice() {
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
    story.printStory();
}

void Game::showMainMenu() {
    displayMainMenu();
    processMainMenuInput();
}
