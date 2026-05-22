#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Heroes.h"
#include "Enemies.h"

using namespace std;

int main() {

    srand(time(0));

    cout << "========== GLITCH ARENA (UPDATED) ==========" << endl;

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
            cout << "Invalid choice → Mage selected by default." << endl;
            hero = new Mage(heroName);
    }

    // ================= GAME LOOP =================
    bool playing = true;

    while (playing && hero->isAlive()) {

        cout << "\n=============================" << endl;
        cout << " HERO STATUS" << endl;
        cout << "=============================" << endl;
        hero->display();

        cout << "\n1. Fight enemy" << endl;
        cout << "2. Exit game" << endl;

        int choice;
        cin >> choice;

        if (choice == 2) {
            playing = false;
            break;
        }

        if (choice == 1) {

            // ================= RANDOM ENEMY =================
            Character* enemy = nullptr;

            int randomEnemy = rand() % 2;

            if (randomEnemy == 0) {
                enemy = new Dragon("Inferno");
            } else {
                enemy = new Titan("Goliath");
            }

            cout << "\n========== NEW ENEMY ==========" << endl;
            enemy->display();

            cout << "\n========== BATTLE START ==========" << endl;

            // ================= COMBAT LOOP =================
            while (hero->isAlive() && enemy->isAlive()) {

                cout << "\n-----------------------------" << endl;
                cout << hero->getName() << " HP: " << hero->getHP() << endl;
                cout << enemy->getName() << " HP: " << enemy->getHP() << endl;

                cout << "\n1. Attack" << endl;
                cout << "Choice: ";

                int action;
                cin >> action;

                if (action == 1) {

                    // speed system
                    if (hero->getSpeed() >= enemy->getSpeed()) {

                        hero->attackTarget(*enemy);

                        if (enemy->isAlive()) {
                            enemy->attackTarget(*hero);
                        }

                    } else {

                        enemy->attackTarget(*hero);

                        if (hero->isAlive()) {
                            hero->attackTarget(*enemy);
                        }
                    }

                } else {
                    cout << "Invalid action!" << endl;
                }
            }

            // ================= RESULT =================
            cout << "\n========== BATTLE RESULT ==========" << endl;

            if (hero->isAlive()) {
                cout << hero->getName() << " wins!" << endl;

                // XP reward
                hero->gainXP(100);
            } else {
                cout << enemy->getName() << " wins!" << endl;
            }

            // cleanup enemy
            delete enemy;
        }
    }

    // ================= END GAME =================
    cout << "\n========== GAME OVER ==========" << endl;

    if (hero->isAlive()) {
        cout << "Final status of hero:" << endl;
        hero->display();
    } else {
        cout << "You died in battle!" << endl;
    }

    delete hero;

    return 0;
}