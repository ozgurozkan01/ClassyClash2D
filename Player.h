//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "raylib.h"

class Player {
private:

    Texture2D playerTexture;
    Vector2 playerPosition;
    Rectangle source;
    Rectangle dest;
public:

    Player();

    void LoadPlayerTexture();
    void SetPlayerPosition();
    void DrawPlayer();
    Rectangle SetDest();
    Rectangle SetSource();
    Texture2D GetPlayerTexture();
};


#endif //CLASSYCLASH2D_PLAYER_H
