#include "player.h"
#include <iostream>

Player::Player(std::string n)
    : Character(n, 120, 25, 8) {
}

void Player::attackTarget(Character &target) {
    std::cout << "\n[PLAYER ATTACK]" << std::endl;
    std::cout << "Attacker: " << name << std::endl;
    std::cout << "Target: " << target.getName() << std::endl;

    int hpBefore = target.getHP();

    target.takeDamage(attack + 5);

    int hpAfter = target.getHP();
    int damageDone = hpBefore - hpAfter;

    std::cout << target.getName() << " took " << damageDone << " damage" << std::endl;
    std::cout << target.getName() << " HP: " << hpBefore << " -> " << hpAfter << std::endl;
}