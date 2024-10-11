// Copyright 2024 Vianney Veremme
#include "../include/main.h"

#include <iostream>

#include "../include/Game.h"

int main() {
    Game game;

    // Show welcome message
    game.displayMainMenu();

    // Game loop
    while (!game.isGameOver()) {
        game.processInput();
        game.update();
    }

    game.endGame();

    return 0;
}
