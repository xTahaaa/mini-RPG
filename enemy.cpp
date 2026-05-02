#include "enemy.h"
#include <iostream>
#include <cstdlib>

Enemy::Enemy(std::string name)
    : Character(name, 80, 15, 3) {}

void Enemy::attackTarget(Character &target) {
    int dmg = attack + (rand() % 5);
    std::cout << name << " attacks with " << dmg << " damage!\n";
    target.takeDamage(dmg);
}