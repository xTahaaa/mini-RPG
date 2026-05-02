#include "player.h"
#include <iostream>

Player::Player(std::string name)
    : Character(name, 100, 20, 5), potions(3) {}

void Player::attackTarget(Character &target) {
    std::cout << name << " attacks!\n";
    target.takeDamage(attack);
}

void Player::usePotion() {
    if (potions > 0) {
        hp += 30;
        potions--;
        std::cout << name << " used a potion! HP: " << hp << "\n";
    } else {
        std::cout << "No potions left!\n";
    }
}