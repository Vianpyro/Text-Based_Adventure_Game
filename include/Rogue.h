// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_ROGUE_H_
#define INCLUDE_ROGUE_H_

#include <string>

#include "Character.h"

// Rogue class, derived from Character
class Rogue : public Character {
 public:
    // Constructor
    explicit Rogue(const std::string& name);

    // Overridden attack method
    void attack(Character* target) override;

    // Overridden defend method
    void defend() override;
};

#endif  // INCLUDE_ROGUE_H_
