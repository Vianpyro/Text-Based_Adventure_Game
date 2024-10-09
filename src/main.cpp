// Copyright 2024 Vianney Veremme
#include "../include/main.h"
#include "../include/Game.h"

#include <iostream>

int main() {
    Game game;

    // Show welcome message
    game.initialize();

    // Game loop
    while (!game.isGameOver()) {
        game.displayMenu();
        game.processInput();
        game.update();
    }

    return 0;
}
