//
// Created by ozgur on 5/21/2023.
//

#include "Enemy.h"
#include "Player.h"
#include "raymath.h"

Enemy::Enemy(float positionX, float positionY, Texture2D idle, Texture2D run, Player* player) :
        BaseCharacter(idle, run)
{
    this->target = player;
    movementSpeed = 2.5f;
    damage = 10.f;
    radius = 25.f;
    mapPosition = {positionX, positionY};
    maxNoticeDistance = 200.f;
}

void Enemy::Tick(float deltaTime)
{
    if (!GetIsAlive()) return;
    UpdatePositionOnMap();

    if (ShouldMove()) Move();
    else movementDirection = {};

    BaseCharacter::Tick(deltaTime);

    if (CheckCollisionRecs(target->GetCollisionRec(), GetCollisionRec()))
    {
        target->TakeDamage(damage * deltaTime); 
        target->SetIsColorChangeable(true);
    }
}

void Enemy::UpdatePositionOnMap()
{
    worldPosition = Vector2Subtract(mapPosition, target->GetPosOnMap());
}

Vector2 Enemy::GetDirectionVector()
{
    movementDirection = Vector2Normalize(Vector2Subtract(target->GetScreenPos(), worldPosition));
    return movementDirection;
}

Vector2 Enemy::ScaleDirecionVector() {
    movementDirection = Vector2Scale(GetDirectionVector(), movementSpeed);
    return movementDirection;
}

void Enemy::Move()
{
    mapPosition = Vector2Add(mapPosition, ScaleDirecionVector());
}

bool Enemy::ShouldMove() {
    return Vector2Length(Vector2Subtract(target->GetScreenPos(), worldPosition)) > radius &&
            Vector2Length(Vector2Subtract(target->GetScreenPos(), worldPosition)) < maxNoticeDistance;
}

