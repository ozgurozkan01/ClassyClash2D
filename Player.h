//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "BaseCharacter.h"
#include "raylib.h"

class Weapon;

class Player : public BaseCharacter{

    Weapon* sword;

public:

    Player(float windowWidth, float windowHeight,Texture2D idle, Texture2D run);
    void Move();
    virtual void Tick(float deltaTime) override;
};


#endif //CLASSYCLASH2D_PLAYER_H
