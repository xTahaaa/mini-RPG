#include "Character.h"
#include <iostream>
#include <algorithm>
 
Character::Character(std::string n, int h, int a, int d, int s)
    : name(n), hp(h), attack(a), defense(d), speed(s), xp(0), level(1) {}
 
void Character::takeDamage(int dmg) {
    int realDamage = dmg - defense;
    if (realDamage < 0) realDamage = 0;
    hp = hp - realDamage;
    if (hp < 0) hp = 0;
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
              << " XP: " << xp
              << " LEVEL: " << level
              << std::endl;
    displayInventory();
}
 
void Character::addItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << "  [+] \"" << item << "\" added to inventory." << std::endl;
}
 
void Character::removeItem(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
        std::cout << "  [-] \"" << item << "\" removed from inventory." << std::endl;
    } else {
        std::cout << "  [!] \"" << item << "\" not found in inventory." << std::endl;
    }
}
 
bool Character::hasItem(const std::string& item) const {
    return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
}
 
void Character::displayInventory() const {
    if (inventory.empty()) {
        std::cout << "  Inventory: (empty)" << std::endl;
    } else {
        std::cout << "  Inventory: ";
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << "[" << inventory[i] << "]";
            if (i < inventory.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}
 
void Character::gainXP(int amount) {
    xp += amount;
    std::cout << "  [XP] " << name << " gained " << amount << " XP! (Total: " << xp << "/" << level * 100 << ")" << std::endl;
    int threshold = level * 100;
    if (xp >= threshold) {
        xp -= threshold;
        levelUp();
    }
}
 
void Character::levelUp() {
    level++;
    attack += 5;
    defense += 2;
    hp += 20;
    speed += 1;
    std::cout << "\n==============================" << std::endl;
    std::cout << ">>> LEVEL UP! Now Level " << level << " <<<" << std::endl;
    std::cout << "HP+20  ATK+5  DEF+2  SPD+1" << std::endl;
    std::cout << "==============================" << std::endl;
}
 
std::string Character::getName() const { return name; }
int Character::getHP() const { return hp; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }
int Character::getSpeed() const { return speed; }
int Character::getXP() const { return xp; }
int Character::getLevel() const { return level; }
 
void Character::setHP(int newHP) {
    if (newHP < 0) newHP = 0;
    hp = newHP;
}