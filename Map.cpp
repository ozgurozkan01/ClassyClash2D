//
// Created by ozgur on 5/12/2023.
//

#include "Map.h"
#include "raymath.h"
#include <iostream>
Map::Map() : mapScale(4.f)
{
    mapTexture = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
    position = {0.f, 0.f};
}

void Map::DrawMap()
{
    DrawTextureEx(mapTexture, position, 0, mapScale, WHITE);
}

Texture2D Map::GetMapTexture()
{
    return mapTexture;
}

void Map::Move(Vector2 playerPosition)
{
    // Normally the player should move.
    // However, since we have a 2D world,
    // we create the impression that the character is actually moving by moving the map behind.
    position = Vector2Scale(playerPosition, -1.f);
}