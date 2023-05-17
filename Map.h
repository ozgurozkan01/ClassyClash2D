//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_MAP_H
#define CLASSYCLASH2D_MAP_H

#include "raylib.h"

class Map {

private:

    Texture2D mapTexture = LoadTexture("./nature_tileset/WorldMap.png");
    Vector2 mapPosition{};
    const float movementSpeed;
    const float mapScale;
public:
    Vector2 movementDirection{};

    Map();

    void DrawMap();
    Texture2D GetMapTexture();
    void Move();
};


#endif //CLASSYCLASH2D_MAP_H
