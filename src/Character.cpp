#include "Character.h"

#include <iostream>

// Constructor implementation
Character::Character(
    const std::string& name,
    int health,
    int mana,
    int strength,
    int intelligence,
    int agility)
    : name(name),
      health(health),
      maxHealth(health),
      strength(strength),
      intelligence(intelligence),
      agility(agility),
      level(1) {}

// Getters
std::string Character::getName() const { return name; }
int Character::getHealth() const { return health; }
int Character::getLevel() const { return level; }
int Character::getStrength() const { return strength; }
int Character::getIntelligence() const { return intelligence; }
int Character::getAgility() const { return agility; }

// Taking damage
void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << name << " takes " << damage << " damage! Current health: " << health << "/" << maxHealth << std::endl;
}

// Level up the character
void Character::levelUp() {
    level++;
    maxHealth += 10;
    strength += 2;
    intelligence += 2;
    agility += 2;
    health = maxHealth;
    std::cout << name << " leveled up! Now level " << level << "!" << std::endl;
}

// Check if the character is still alive
bool Character::isAlive() const {
    return health > 0;
}
