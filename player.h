#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Player(std::string n);

    void attackTarget(Character &target) override;
};

#endif