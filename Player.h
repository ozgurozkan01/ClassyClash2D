//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "BaseCharacter.h"
#include "raylib.h"
#include "Weapon.h"

class Health;

class Player : public BaseCharacter {

    bool isColorChangeable;

    int maxColorUpdateAmount;
    int colorUpdateAmount{};
    float colorFrameUpdatingTime;
    float colorUpdatingTimer{};

public:
    Weapon* sword;
    Health* healthObject;

    Player(float windowWidth, float windowHeight,Texture2D idle, Texture2D run);
    virtual void Tick(float deltaTime) override;
    void Move();
    void TakeDamage(float damage);
    void SetColor();
    void ColorTimer();
    void SetIsColorChangeable(bool isColorChangeable);
};


#endif //CLASSYCLASH2D_PLAYER_H
