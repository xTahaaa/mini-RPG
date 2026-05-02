#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
public:
    Enemy(std::string name);

    void attackTarget(Character &target) override;
};

#endif