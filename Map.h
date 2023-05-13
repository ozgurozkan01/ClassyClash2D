//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_MAP_H
#define CLASSYCLASH2D_MAP_H

#include "raylib.h"

class Map {

private:

    Texture2D mapTexture;
    Vector2 mapPosition;
    Vector2 movementDirection;
    const float movementSpeed;
    const float mapScale;
public:

    Map();

    void LoadMapTexture();
    void DrawMap();
    Texture2D GetMapTexture();
    void Move();
};


#endif //CLASSYCLASH2D_MAP_H
