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
    worldPosition = Vector2Subtract(mapPosition, player->GetPosOnMap());
}

Vector2 Enemy::GetDirectionVector()
{
    directionVector = Vector2Normalize(Vector2Subtract(player->GetScreenPos(), worldPosition));
    return directionVector;
}

Vector2 Enemy::ScaleDirecionVector() {
    directionVector = Vector2Scale(GetDirectionVector(), movementSpeed);
    return directionVector;
}

void Enemy::Move()
{
    mapPosition = Vector2Add(mapPosition, ScaleDirecionVector());
}

