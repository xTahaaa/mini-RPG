#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
 
#include "Heroes.h"
#include "Enemies.h"
 
using namespace std;
 
int main() {
 
    srand(time(0));
 
    cout << "========== mini-RPG ARENA (UPDATED) ==========" << endl;
 
    // ================= HERO CREATION =================
    string heroName;
    int heroChoice;
 
    cout << "\nEnter your hero name: ";
    cin >> heroName;
    cin.ignore(10000, '\n');
 
    cout << "\nChoose your class:" << endl;
    cout << "1. Mage" << endl;
    cout << "2. Guerrier" << endl;
    cout << "3. Archer" << endl;
    cout << "Choice: ";
    cin >> heroChoice;
    cin.ignore(10000, '\n');
 
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
 
    Mage* mageHero = dynamic_cast<Mage*>(hero);
 
    // ================= GAME LOOP =================
    bool playing = true;
 
    while (playing && hero->isAlive()) {
 
        cout << "\n=============================" << endl;
        cout << " HERO STATUS" << endl;
        cout << "=============================" << endl;
        hero->display();
 
        cout << "\n1. Fight enemy" << endl;
        cout << "2. Exit game" << endl;
        cout << "Choice: ";
 
        int choice;
        cin >> choice;
        cin.ignore(10000, '\n');
 
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
                cout << "2. Use Item (Inventory)" << endl;
                if (mageHero) cout << "3. Cast Spell" << endl;
                cout << "Choice: ";
 
                int action = 0;
                cin >> action;
                cin.ignore(10000, '\n');
 
                if (action == 2) {
                    cout << "\n--- INVENTORY ---" << endl;
                    cout << "1. Health Potion (+50 HP)" << endl;
                    cout << "2. Mana Potion (+40 HP)" << endl;
                    cout << "Choice: ";
                    int itemChoice = 0;
                    cin >> itemChoice;
                    cin.ignore(10000, '\n');
                    if (itemChoice == 1) {
                        if (hero->hasItem("Health Potion")) {
                            hero->removeItem("Health Potion");
                            hero->setHP(hero->getHP() + 50);
                            cout << "+50 HP! Current HP: " << hero->getHP() << endl;
                        } else {
                            cout << "No Health Potion!" << endl;
                        }
                    } else if (itemChoice == 2) {
                        if (hero->hasItem("Mana Potion")) {
                            hero->removeItem("Mana Potion");
                            hero->setHP(hero->getHP() + 40);
                            cout << "+40 HP! Current HP: " << hero->getHP() << endl;
                        } else {
                            cout << "No Mana Potion!" << endl;
                        }
                    } else {
                        cout << "Invalid choice!" << endl;
                    }
 
                } else if (action == 3 && mageHero) {
 
                    // ================= MAGIC SYSTEM =================
                    cout << "\n--- CHOOSE SPELL ---" << endl;
                    cout << "1. Fire" << endl;
                    cout << "2. Ice" << endl;
                    cout << "3. Lightning" << endl;
                    cout << "4. Earth" << endl;
                    cout << "Choice: ";
                    int spellChoice = 0;
                    cin >> spellChoice;
                    cin.ignore(10000, '\n');
 
                    string spellType;
                    if (spellChoice == 1) spellType = "fire";
                    else if (spellChoice == 2) spellType = "ice";
                    else if (spellChoice == 3) spellType = "lightning";
                    else spellType = "earth";
 
                    mageHero->castSpell(*enemy, spellType);
 
                    if (enemy->isAlive()) {
                        enemy->attackTarget(*hero);
                    }
 
                } else if (action == 1) {
 
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
 
                if (dynamic_cast<Dragon*>(enemy)) {
                    cout << "Dragon defeated! +60 XP" << endl;
                    hero->gainXP(60);
                } else {
                    cout << "Titan defeated! +80 XP" << endl;
                    hero->gainXP(80);
                }
 
            } else {
                cout << enemy->getName() << " wins!" << endl;
            }
 
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