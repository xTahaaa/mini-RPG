#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Heroes.h"
#include "Enemies.h"

using namespace std;

int main() {

    srand(time(0));

    cout << "========== GLITCH ARENA ==========" << endl;

    // ================= HERO CREATION =================
    string heroName;
    int heroChoice;

    cout << "\nEnter your hero name: ";
    cin >> heroName;

    cout << "\nChoose your class:" << endl;
    cout << "1. Mage" << endl;
    cout << "2. Guerrier" << endl;
    cout << "3. Archer" << endl;
    cout << "Choice: ";
    cin >> heroChoice;

    Character* hero = nullptr;

    switch(heroChoice) {

        case 1:
            hero = new Mage(heroName);
            break;

        case 2:
            hero = new Guerrier(heroName);
            break;

        case 3:
            hero = new Archer(heroName);
            break;

        default:
            cout << "Invalid choice. Mage selected by default." << endl;
            hero = new Mage(heroName);
    }

    // ================= RANDOM ENEMY =================
    Character* enemy = nullptr;

    int randomEnemy = rand() % 2;

    if(randomEnemy == 0) {
        enemy = new Dragon("Inferno");
    }
    else {
        enemy = new Titan("Goliath");
    }

    // ================= DISPLAY STATS =================
    cout << "\n========== HERO ==========" << endl;
    hero->display();

    cout << "\n========== ENEMY ==========" << endl;
    enemy->display();

    cout << "\n========== BATTLE START ==========" << endl;

    // ================= COMBAT LOOP =================
    while(hero->isAlive() && enemy->isAlive()) {

        cout << "\n-----------------------------" << endl;

        cout << hero->getName()
             << " HP: " << hero->getHP() << endl;

        cout << enemy->getName()
             << " HP: " << enemy->getHP() << endl;

        cout << "\nChoose an action:" << endl;
        cout << "1. Attack" << endl;
        cout << "Choice: ";

        int action;
        cin >> action;

        if(action == 1) {

            // speed system
            if(hero->getSpeed() >= enemy->getSpeed()) {

                hero->attackTarget(*enemy);

                if(enemy->isAlive()) {
                    enemy->attackTarget(*hero);
                }
            }
            else {

                enemy->attackTarget(*hero);

                if(hero->isAlive()) {
                    hero->attackTarget(*enemy);
                }
            }
        }
        else {
            cout << "Invalid action!" << endl;
        }
    }

    // ================= RESULT =================
    cout << "\n========== BATTLE ENDED ==========" << endl;

    if(hero->isAlive()) {
        cout << hero->getName()
             << " wins the battle!" << endl;
    }
    else {
        cout << enemy->getName()
             << " wins the battle!" << endl;
    }

    // ================= FREE MEMORY =================
    delete hero;
    delete enemy;

    return 0;
}
