// Copyright 2024 Vianney Veremme
#include "../include/Warrior.h"

#include <iostream>

Warrior::Warrior(const std::string& name)
    : Character(name, 25, 15, 5, 10) {}

void Warrior::attack(Character& target) {
    int damage = strength;
    std::cout << name << " slashes " << target.getName()
              << " for " << damage << " damage!" << std::endl;
    target.takeDamage(damage);
}

void Warrior::defend() {
    std::cout << name << " raises a shield to defend!" << std::endl;
}
