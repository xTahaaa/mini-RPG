#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string n)
    : Character(n, 80, 15, 3) {
}

void Enemy::attackTarget(Character &target) {
    std::cout << "\n[ENEMY ATTACK]" << std::endl;
    std::cout << "Attacker: " << name << std::endl;
    std::cout << "Target: " << target.getName() << std::endl;

    int hpBefore = target.getHP();

    target.takeDamage(attack);

    int hpAfter = target.getHP();
    int damageDone = hpBefore - hpAfter;

    std::cout << target.getName() << " took " << damageDone << " damage" << std::endl;
    std::cout << target.getName() << " HP: " << hpBefore << " -> " << hpAfter << std::endl;
}