#ifndef HEROES_H
#define HEROES_H

#include "Character.h"
#include <string>

// ================= Mage =================
class Mage : public Character {
public:
    Mage(const std::string& name);
    void attackTarget(Character& target) override;
    virtual ~Mage() {}
};

// ================= Guerrier =================
class Guerrier : public Character {
public:
    Guerrier(const std::string& name);
    void attackTarget(Character& target) override;
    virtual ~Guerrier() {}
};

// ================= Archer =================
class Archer : public Character {
public:
    Archer(const std::string& name);
    void attackTarget(Character& target) override;
    virtual ~Archer() {}
};

#endif // HEROES_H