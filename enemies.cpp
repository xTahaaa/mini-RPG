#include "Enemies.h"
#include <iostream>
#include <cstdlib>

// ================= DRAGON =================
Dragon::Dragon(const std::string& name)
    : Character(name, 200, 40, 20, 12) {}

void Dragon::attackTarget(Character& target) {
    std::cout << getName() << " (Dragon) breathes fire on "
              << target.getName() << std::endl;

    int damage = getAttack() + (rand() % 25);

    if (rand() % 100 < 25) {
        std::cout << "🔥 DRAGON FIRE BLAST!" << std::endl;
        damage *= 2;
    }

    target.takeDamage(damage);
}

// ================= TITAN =================
Titan::Titan(const std::string& name)
    : Character(name, 300, 35, 30, 6) {}

void Titan::attackTarget(Character& target) {
    std::cout << getName() << " (Titan) crushes the ground under "
              << target.getName() << std::endl;

    int damage = getAttack() + (rand() % 15);

    if (rand() % 100 < 15) {
        std::cout << "💥 TITAN SMASH!" << std::endl;
        damage *= 3;
    }

    target.takeDamage(damage);
}