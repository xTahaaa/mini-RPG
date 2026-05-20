#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <iostream>

class Character {
protected :
    std::string name;
    int hp;
    int attack;
    int defense;
    int speed ;
    std::vector<std::string> inventory;

public:
    //constructor
    Character(std::string n, int h, int a, int d,int s);

    //attack function
    virtual void attackTarget(Character &target)=0;
    
    //damage
    virtual void takeDamage(int dmg);

    //is still alive or not
    bool isAlive() const;

    //character's stats
    void display() const;
    
    // inventory methods
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    bool hasItem(const std::string& item) const;
    void displayInventory() const;

    //getters 
    std::string getName() const;
    int getHP() const;
    int getAttack() const;
    int getDefense() const ;
    int getSpeed() const;
    //destructor
    virtual ~Character() {}
};

#endif
