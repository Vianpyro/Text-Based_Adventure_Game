// Copyright 2024 Vianney Veremme
#include "../include/main.h"

#include <iostream>

#include "../include/Game.h"

int main() {
    Game game;

    // Show welcome message
    game.initialize();

    // Game loop
    while (!game.isGameOver()) {
        game.update();
        game.displayMenu();
        game.processInput();
    }

    return 0;
}
