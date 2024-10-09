// Copyright 2024 Vianney Veremme
#include <cassert>
#include <iostream>

void testAddition() {
    assert(1 + 1 == 2);
}

void testSubtraction() {
    assert(2 - 1 == 1);
}

int main() {
    std::cout << "Running tests..." << std::endl;
    testAddition();
    testSubtraction();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
