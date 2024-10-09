// Copyright 2024 Vianney Veremme
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

    // Show goodbye message
    displayGoodbyeMessage();
    return 0;
}
