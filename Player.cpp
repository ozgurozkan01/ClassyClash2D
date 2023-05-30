//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight,Texture2D idle, Texture2D run) :
        BaseCharacter(idle, run)
{
    worldPosition = {
            (static_cast<float>(windowWidth) / 2) - (4.0f * (0.5f * textureWidth)),
            (static_cast<float>(windowHeight) / 2) - (4.f * (0.5f * textureHeight))
    };

    movementSpeed = 4.f;

    sword = new Weapon(LoadTexture("characters/weapon_sword.png"), this);
}
void Player::Move()
{
    movementDirection = {0.f, 0.f};
    if (IsKeyDown(KEY_A)) movementDirection.x -= 1;
    if (IsKeyDown(KEY_D)) movementDirection.x += 1;
    if (IsKeyDown(KEY_W)) movementDirection.y -= 1;
    if (IsKeyDown(KEY_S)) movementDirection.y += 1;

    if (IsCharacterRunning())
    {
        mapPosition = Vector2Add(mapPosition, Vector2Scale(Vector2Normalize(movementDirection), movementSpeed));
    }
}

void Player::Tick(float deltaTime)
{
    if (!GetIsAlive()) return;

    BaseCharacter::Tick(deltaTime);
    Move();
    sword->Tick(deltaTime);
}
