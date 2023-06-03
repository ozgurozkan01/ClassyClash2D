//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "Health.h"
#include "raymath.h"
#include <iostream>

Player::Player(float windowWidth, float windowHeight,Texture2D idle, Texture2D run) :
        BaseCharacter(idle, run)
{
    worldPosition = {
            (static_cast<float>(windowWidth) / 2) - (4.0f * (0.5f * textureWidth)),
            (static_cast<float>(windowHeight) / 2) - (4.f * (0.5f * textureHeight))
    };

    movementSpeed = 4.f;
    sword = new Weapon(LoadTexture("characters/weapon_sword.png"), this);
    healthObject = new Health();

    maxColorUpdateAmount = 6;
    colorFrameUpdatingTime = 1.f / 6.f;
    isColorChangeable = false;
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
    BaseCharacter::Tick(deltaTime);

    if (!GetIsAlive()) return;
    Move();
    sword->Tick(deltaTime);

    if (isColorChangeable)
    {
        ColorTimer();
    }
}

void Player::TakeDamage(float damage)
{
    healthObject->DecreaseHealth(damage);

    if (healthObject->GetHealth() <= 0.f)
    {
        SetIsAlive(false);
    }
}

void Player::SetColor()
{
    if (colorUpdateAmount % 2 == 0)
    {
        color = RED;
        return;
    }

    color = WHITE;
}

void Player::ColorTimer()
{
    if (colorUpdatingTimer >= colorFrameUpdatingTime)
    {
        SetColor();
        colorUpdatingTimer = 0;
        colorUpdateAmount++;
    }

    if (colorUpdateAmount == maxColorUpdateAmount)
    {
        SetIsColorChangeable(false);
        colorUpdateAmount = 0;
    }
    std::cout << colorUpdateAmount << std::endl;
    colorUpdatingTimer += GetFrameTime();
}

void Player::SetIsColorChangeable(bool isColorChangeable)
{
    this->isColorChangeable = isColorChangeable;
}
