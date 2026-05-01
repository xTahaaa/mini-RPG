#include <iostream>
#include "Character.h"

int main() {

    Character hero("Hero", 100, 20, 5);
    Character enemy("Enemy", 80, 15, 3);

    std::cout << "=== Before Fight ===" << std::endl;
    hero.display();
    enemy.display();

    std::cout << "\n=== Fight ===" << std::endl;

    hero.attackTarget(enemy);  
    enemy.attackTarget(hero);   

    std::cout << "\n=== After Fight ===" << std::endl;
    hero.display();
    enemy.display();

    return 0;
}