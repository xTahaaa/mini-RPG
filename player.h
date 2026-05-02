#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {
private:
    int potions;

public:
    Player(std::string name);

    void attackTarget(Character &target) override;
    void usePotion();
};

#endif