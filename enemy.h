#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string n);

    void attackTarget(Character &target) override;
};

#endif