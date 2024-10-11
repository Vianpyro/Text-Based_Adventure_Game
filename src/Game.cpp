// Copyright 2024 Vianney Veremme
#include "../include/Game.h"

#include <iostream>

const char* GAME_TITLE = "Shattered Kingdom";

void Game::endGame() {
    // Show goodbye message
    std::cout << "Thanks for playing " << GAME_TITLE << "!" << std::endl;

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
        // Placeholder for game update logic
    }
