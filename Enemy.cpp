//
// Created by ozgur on 5/21/2023.
//

#include "Enemy.h"
#include "Player.h"
#include "raymath.h"

Enemy::Enemy(float windowWidth, float windowHeight, Texture2D idle, Texture2D run, Player* player) :
        BaseCharacter(windowWidth, windowHeight, idle, run)
{
    this->player = player;
    movementSpeed = 2.5f;
}

void Enemy::Tick(float deltaTime)
{
    UpdatePositionOnMap();
    Move();
    BaseCharacter::Tick(deltaTime);
}

void Enemy::UpdatePositionOnMap()
{
    screenPosition = Vector2Subtract(worldPosition, player->GetPosOnMap());
}

Vector2 Enemy::GetDirectionVector()
{
    directionVector = Vector2Normalize(Vector2Subtract(player->GetScreenPos(), screenPosition));
    return directionVector;
}

void Enemy::Move()
{
    directionVector = Vector2Scale(GetDirectionVector(), movementSpeed);
    worldPosition = Vector2Add(worldPosition, directionVector);
}
