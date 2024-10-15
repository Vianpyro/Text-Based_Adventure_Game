// Copyright 2024 Vianney Veremme
#include "../include/main.h"

#include <iostream>

#include "../include/Game.h"

int main() {
    Game game;

    // Show the main menu message
    game.showMainMenu();

    // Game loop
    while (true) {
        game.update();

        if (game.isGameOver()) {
            break;
        }

        game.processInput();
    }

    return 0;
}
