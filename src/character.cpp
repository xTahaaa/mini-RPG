#include "Character.h"
#include <iostream>

Character::Character(std::string n, int h, int a, int d, int s)
    : name(n), hp(h), attack(a), defense(d), speed(s) {}

void Character::takeDamage(int dmg) {
    int realDamage = dmg - defense;

    if (realDamage < 0) {
        realDamage = 0;
    }

    hp = hp - realDamage;

    if (hp < 0) {
        hp = 0;
    }
}

bool Character::isAlive() const {
    return hp > 0;
}

void Character::display() const {
    std::cout << name
              << " HP: " << hp
              << " ATTACK: " << attack
              << " DEFENCE: " << defense
              << " SPEED: " << speed
              << std::endl;
}

std::string Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getAttack() const {
    return attack;
}

int Character::getDefense() const {
    return defense;
}

int Character::getSpeed() const {
    return speed;
}