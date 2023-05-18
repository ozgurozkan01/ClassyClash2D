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
    position = Vector2Scale(playerPosition, -1.f);
}

float Map::GetMapScale() const {
    return mapScale;
}