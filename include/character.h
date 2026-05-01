#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected :
    std::string name;
    int hp;
    int attack;
    int defense;

public:
    //constructor
    Character(std::string n, int h, int a, int d);

    //attack function
    virtual void attackTarget(Character &target);
    
    //damage
    virtual void takeDamage(int dmg);

    //is still alive or not
    bool isAlive() const;

    //character's stats
    void display() const;

    //getters 
    std::string getName() const;
    int getHP() const;
    int getAttack() const;
    int getDefense() const ;

    //destructor
    virtual ~Character() {}
};

#endif