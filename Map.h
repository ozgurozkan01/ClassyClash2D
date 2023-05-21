//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_MAP_H
#define CLASSYCLASH2D_MAP_H

#include "raylib.h"

class Map {

private:

    Texture2D mapTexture{};
    Vector2 position{};
    const float mapScale;
public:

    Map();

    void DrawMap();
    Texture2D GetMapTexture();
    void Move(Vector2 position);
};


#endif //CLASSYCLASH2D_MAP_H
