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
}

void Enemy::Tick(float deltaTime)
{
    BaseCharacter::Tick(deltaTime);

    UpdatePositionOnMap();
}

void Enemy::UpdatePositionOnMap()
{
    screenPosition = Vector2Subtract(worldPosition, player->GetPosOnMap());
}
