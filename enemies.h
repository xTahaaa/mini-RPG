#ifndef ENEMIES_H
#define ENEMIES_H

#include "Character.h"

// ================= DRAGON =================
class Dragon : public Character {
public:
    Dragon(const std::string& name);
    void attackTarget(Character& target) override;
};
// ================= TITAN =================

class Titan : public Character {
public:
    Titan(const std::string& name);
    void attackTarget(Character& target) override;
};

#endif