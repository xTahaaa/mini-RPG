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
    int xp;
    int level;
 
public:
    //constructor
    Character(std::string n, int h, int a, int d,int s);
 
    //attack function
    virtual void attackTarget(Character &target)=0;
    
    //damage
    virtual void takeDamage(int dmg);

    // magic resistance (0 = normal, positive = resistant, negative = weak)
    virtual int getMagicResistance(const std::string& magicType) const { return 0; }
 
    //is still alive or not
    bool isAlive() const;
 
    //character's stats
    void display() const;
    //level
    virtual void levelUp();
    
    // inventory methods et xp
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    bool hasItem(const std::string& item) const;
    void displayInventory() const;
    void gainXP(int amount);
    
    
    //getters 
    std::string getName() const;
    int getXP() const;
    int getHP() const;
    int getAttack() const;
    int getDefense() const ;
    int getSpeed() const;
    int getLevel() const;
 
    void setHP(int newHP); 
 
    //destructor
    virtual ~Character() {}
};
 
#endif