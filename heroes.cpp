#include "Heroes.h"
#include <iostream>
#include <cstdlib>

// ================= MAGE =================
Mage::Mage(const std::string& name)
    : Character(name, 80, 35, 8, 10) {
        addItem("Magic Staff");
        addItem("Mana Potion");
        addItem("Spell Book");
    }

void Mage::attackTarget(Character& target) {
    std::cout << getName() << " (Mage) casts a spell on "
              << target.getName() << std::endl;

    int magicDamage = getAttack() + (rand() % 20);

    if (rand() % 100 < 20) {
        std::cout << "Critical Magic Hit!" << std::endl;
        magicDamage *= 2;
    }

    target.takeDamage(magicDamage);
}

// ================= ARCHER =================
Archer::Archer(const std::string& name)
    : Character(name, 90, 22, 8, 18) {
        addItem("Bow");
        addItem("Quiver of Arrows");
        addItem("Dagger");
    }

void Archer::attackTarget(Character& target) {
    std::cout << getName() << " (Archer) shoots an arrow at "
              << target.getName() << std::endl;

    int damage = getAttack();

    if (rand() % 100 < 35) {
        std::cout << "Critical Shot!" << std::endl;
        damage *= 2;
    }

    damage += rand() % 5;

    target.takeDamage(damage);
}

// ================= GUERRIER =================
Guerrier::Guerrier(const std::string& name)
    : Character(name, 120, 25, 15, 8) {
        addItem("Iron Sword");
        addItem("Shield");
        addItem("Health Potion");
    }

void Guerrier::attackTarget(Character& target) {
    std::cout << getName() << " (Guerrier) attacks "
              << target.getName() << std::endl;

    int damage = getAttack() + 5;

    target.takeDamage(damage);
}
