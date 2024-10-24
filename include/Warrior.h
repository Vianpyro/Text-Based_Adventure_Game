// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_WARRIOR_H_
#define INCLUDE_WARRIOR_H_

#include "Character.h"

// Warrior class, derived from Character
class Warrior : public Character {
 public:
    // Constructor
    Warrior(const std::string& name);

    // Overridden attack method
    void attack(Character& target) override;

    // Overridden defend method
    void defend() override;
};

#endif  // INCLUDE_WARRIOR_H_
