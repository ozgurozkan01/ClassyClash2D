//
// Created by ozgur on 5/19/2023.
//

#include "Prop.h"
#include "raymath.h"
#include <iostream>

Prop::Prop(Vector2 pos, Texture2D tex) : position(pos), texture(tex)
{
    scale = 4.f;
}

void Prop::DrawProp(Vector2 playerPos)
{
    Vector2 posOnMap = {Vector2Subtract(position, playerPos)};
    DrawTextureEx(texture, posOnMap, 0.f, scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 playerPos)
{
    Vector2 posOnMap = {Vector2Subtract(position, playerPos)};
    return Rectangle{
        posOnMap.x,
        posOnMap.y,
        static_cast<float>(texture.width) * scale,
        static_cast<float>(texture.height) * scale
    };
}

