#include "Enemies.h"
#include <iostream>
#include <cstdlib>

// ================= DRAGON =================
Dragon::Dragon(const std::string& name)
    : Character(name, 160, 28, 10, 10) {
        addItem("Dragon Scale");
        addItem("Fire Crystal");
        addItem("Ancient Coin");
    }

void Dragon::attackTarget(Character& target) {
    std::cout << getName() << " (Dragon) breathes fire on "
              << target.getName() << std::endl;

    int damage = getAttack() + (rand() % 15);

    if (rand() % 100 < 20) {
        std::cout << "🔥 DRAGON FIRE BLAST!" << std::endl;
        damage = static_cast<int>(damage * 1.5);
    }

    target.takeDamage(damage);
}

int Dragon::getMagicResistance(const std::string& magicType) const {
    if (magicType == "fire")  return 50;   // resistant to fire
    if (magicType == "ice")   return -30;  // weak to ice
    return 0;
}

// ================= TITAN =================
Titan::Titan(const std::string& name)
    : Character(name, 200, 22, 15, 5) {
        addItem("Stone Hammer");
        addItem("Titan Armor");
        addItem("Earth Rune");
    }

void Titan::attackTarget(Character& target) {
    std::cout << getName() << " (Titan) crushes the ground under "
              << target.getName() << std::endl;

    int damage = getAttack() + (rand() % 10);

    if (rand() % 100 < 15) {
        std::cout << "💥 TITAN SMASH!" << std::endl;
        damage = static_cast<int>(damage * 2);
    }

    target.takeDamage(damage);
}

int Titan::getMagicResistance(const std::string& magicType) const {
    if (magicType == "earth")     return 50;   // resistant to earth
    if (magicType == "lightning") return -30;  // weak to lightning
    return 0;
}
