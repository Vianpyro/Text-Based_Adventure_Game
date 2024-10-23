#ifndef INCLUDE_CHARACTER_H_
#define INCLUDE_CHARACTER_H_

#include <string>

// Base class for all characters
class Character {
 protected:
    std::string name;
    int health;
    int maxHealth;
    int level;
    int strength;
    int intelligence;
    int agility;

 public:
    // Constructor
    Character(const std::string& name, int health, int mana, int strength, int intelligence, int agility);

    // Destructor
    virtual ~Character() = default;

    // Getters for character attributes
    std::string getName() const;
    int getHealth() const;
    int getLevel() const;
    int getStrength() const;
    int getIntelligence() const;
    int getAgility() const;

    // Virtual methods for actions (to be overridden by subclasses)
    virtual void attack(Character& target) = 0;
    virtual void defend() = 0;
    virtual void takeDamage(int damage);

    // Level up the character
    void levelUp();

    // Check if the character is still alive
    bool isAlive() const;
};

#endif  // INCLUDE_CHARACTER_H_
