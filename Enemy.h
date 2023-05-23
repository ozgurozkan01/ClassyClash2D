//
// Created by ozgur on 5/21/2023.
//

#ifndef CLASSYCLASH2D_ENEMY_H
#define CLASSYCLASH2D_ENEMY_H
#include "BaseCharacter.h"

class Enemy : public BaseCharacter{

public:
    Enemy(float windowWidth, float windowHeight, Texture2D idle, Texture2D run);
    virtual void Tick(float deltaTime) override;
};


#endif //CLASSYCLASH2D_ENEMY_H
