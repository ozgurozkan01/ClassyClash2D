//
// Created by ozgur on 5/28/2023.
//

#ifndef CLASSYCLASH2D_WEAPON_H
#define CLASSYCLASH2D_WEAPON_H

#include "raylib.h"

class Player;

class Weapon {

    Player* player;
    Texture2D weaponTexture;
    float scale;
    float rotation;
    Vector2 origin;
    Vector2 offset;
    Rectangle weaponCollisionRec;
public:

    Weapon(Texture2D weaponTex, Player* player);

    void Tick(float deltaTime);
    void DrawWeapon();
    void SetWeaponOrigin();
    Rectangle SetSource();
    Rectangle SetDest();
    Rectangle GetWeaponCollisionRec();

};


#endif //CLASSYCLASH2D_WEAPON_H
