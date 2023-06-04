//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "BaseCharacter.h"
#include "raylib.h"
#include "Weapon.h"

class Player : public BaseCharacter {

public:
    Weapon* sword;

    Player(float windowWidth, float windowHeight,Texture2D idle, Texture2D run);
    virtual void Tick(float deltaTime) override;
    void Move();

};


#endif //CLASSYCLASH2D_PLAYER_H
