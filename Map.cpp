//
// Created by ozgur on 5/12/2023.
//

#include "Map.h"

Map::Map()
{
    mapPosition = {0.f, 0.f};
}

void Map::LoadMapTexture()
{
    mapTexture = LoadTexture("./nature_tileset/WorldMap.png");
}

void Map::DrawMap()
{
    DrawTextureEx(mapTexture, mapPosition, 0, 4.f, WHITE);
}

Texture2D Map::GetMapTexture()
{
    return mapTexture;
}


