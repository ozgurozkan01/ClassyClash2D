//
// Created by ozgur on 5/28/2023.
//

#ifndef CLASSYCLASH2D_WEAPON_H
#define CLASSYCLASH2D_WEAPON_H

#include "raylib.h"

class Weapon {

    Texture2D weaponTexture;
    float scale;
public:

    Weapon(Texture2D weaponTex);

    void Tick(float deltaTime, float playerPosX, float playerPosY, float rightLeft);
    Rectangle SetSource(float rightLeft);
    Rectangle SetDest(float playerPosX, float playerPosY);
    void DrawWeapon(float playerPosX, float playerPosY, float rightLeft);
};


#endif //CLASSYCLASH2D_WEAPON_H
