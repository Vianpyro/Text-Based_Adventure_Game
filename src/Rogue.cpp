// Copyright 2024 Vianney Veremme
#include "../include/Rogue.h"

#include <iostream>

Rogue::Rogue(const std::string& name)
    : Character(name, 20, 10, 10, 10) {}

void Rogue::attack(Character& target) {
    int damage = strength;
    std::cout << name << " stabs " << target.getName()
              << " for " << damage << " damage!" << std::endl;
    target.takeDamage(damage);
}

void Rogue::defend() {
    std::cout << name << " dodges the attack!" << std::endl;
}
