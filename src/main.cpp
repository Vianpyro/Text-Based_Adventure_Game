#include "main.h"

#include <iostream>

// Function to display the welcome message
void displayWelcomeMessage() {
    std::cout << "Welcome to " << GAME_TITLE << "!" << std::endl;
}

// Function to display the goodbye message
void displayGoodbyeMessage() {
    std::cout << "Thank you for playing " << GAME_TITLE << "!" << std::endl;
}

int main() {
    // Show welcome message
    displayWelcomeMessage();

    // // Create the game object
    // Game game;
    // game.initialize();

    // // Main game loop
    // while (!game.isGameOver())
    // {
    //     game.displayMenu();  // Show menu
    //     game.processInput(); // Handle player input
    //     game.update();       // Update game state
    // }

    // Show goodbye message
    displayGoodbyeMessage();
    return 0;
}
