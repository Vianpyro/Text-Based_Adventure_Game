#include <cassert>

#include "../include/Game.h"

void test_initialize_game() {
    Game game;
    game.initialize();
    assert(game.isGameOver() == false);
}

void run_tests_game() {
    test_initialize_game();
}
