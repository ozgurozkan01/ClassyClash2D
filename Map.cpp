//
// Created by ozgur on 5/12/2023.
//

#include "Map.h"
#include "raymath.h"

Map::Map() : movementSpeed(4.f), mapScale(4.f)
{
    mapPosition = {0.f, 0.f};
}

void Map::LoadMapTexture()
{
    mapTexture = LoadTexture("./nature_tileset/WorldMap.png");
}

void Map::DrawMap()
{
    DrawTextureEx(mapTexture, mapPosition, 0, mapScale, WHITE);
}

Texture2D Map::GetMapTexture()
{
    return mapTexture;
}

void Map::Move()
{
    // Normally the player should move.
    // However, since we have a 2D world,
    // we create the impression that the character is actually moving by moving the map behind.

    movementDirection = {0.f, 0.f};
    if (IsKeyDown(KEY_A)) movementDirection.x -= 1;
    if (IsKeyDown(KEY_D)) movementDirection.x += 1;
    if (IsKeyDown(KEY_W)) movementDirection.y -= 1;
    if (IsKeyDown(KEY_S)) movementDirection.y += 1;

    if (Vector2Length(movementDirection) != 0)
    {
        mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(movementDirection), movementSpeed));
    }
}