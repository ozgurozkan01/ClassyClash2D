//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight,Texture2D idle, Texture2D run) : Character(
        windowWidth,
        windowHeight,
        idle,
        run
        )
{}
void Player::Move()
{
    movementDirection = {0.f, 0.f};
    if (IsKeyDown(KEY_A)) movementDirection.x -= 1;
    if (IsKeyDown(KEY_D)) movementDirection.x += 1;
    if (IsKeyDown(KEY_W)) movementDirection.y -= 1;
    if (IsKeyDown(KEY_S)) movementDirection.y += 1;

    if (Vector2Length(movementDirection) != 0)
    {
        positionOnMap = Vector2Add(positionOnMap, Vector2Scale(Vector2Normalize(movementDirection), movementSpeed));
    }
}