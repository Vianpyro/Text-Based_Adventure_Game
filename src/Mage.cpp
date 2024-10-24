// Copyright 2024 Vianney Veremme
#include "../include/Mage.h"

#include <iostream>

Mage::Mage(const std::string& name)
    : Character(name, 15, 5, 15, 10) {}

void Mage::attack(Character& target) {
    int damage = intelligence;
    std::cout << name << " casts a spell on " << target.getName()
              << " for " << damage << " damage!" << std::endl;
    target.takeDamage(damage);
}

void Mage::defend() {
    std::cout << name << " casts a healing spell!" << std::endl;
    health += 5;
    if (health > maxHealth) health = maxHealth;
}
