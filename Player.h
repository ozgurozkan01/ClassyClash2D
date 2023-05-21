//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "Character.h"
#include "raylib.h"

class Player : public Character{

public:

    Player(float windowWidth, float windowHeight, Texture2D idle, Texture2D run);
    void Move();
};


#endif //CLASSYCLASH2D_PLAYER_H
