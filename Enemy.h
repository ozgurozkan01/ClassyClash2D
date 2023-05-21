//
// Created by ozgur on 5/21/2023.
//

#ifndef CLASSYCLASH2D_ENEMY_H
#define CLASSYCLASH2D_ENEMY_H
#include "Character.h"

class Enemy : public Character{

public:
    Enemy(float windowWidth, float windowHeight, Texture2D idle, Texture2D run);
};


#endif //CLASSYCLASH2D_ENEMY_H
