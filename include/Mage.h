// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_MAGE_H_
#define INCLUDE_MAGE_H_

#include "Character.h"

// Mage class, derived from Character
class Mage : public Character {
 public:
    // Constructor
    Mage(const std::string& name);

    // Overridden attack method
    void attack(Character* target) override;

    // Overridden defend method
    void defend() override;
};

#endif  // INCLUDE_MAGE_H_
