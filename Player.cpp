//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"

Player::Player() : timeLimitBetweenTwoTexture(1.f / 12.f), maxTextureAmount(6.f)
{
    timeCounterBetweenTextures = 0.f;
    currentTexture = 0;
    leftOrRightDirection = 1.f;
}

void Player::LoadPlayerTexture()
{
    playerTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    idleTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    runningTexture = LoadTexture("characters/knight_run_spritesheet.png");
}

void Player::SetTextureDimensions()
{
    textureWidth = playerTexture.width / maxTextureAmount;
    textureHeight = playerTexture.height;
}

void Player::SetPlayerPosition(int windowWidth, int windowHeight)
{
    playerPosition = {((float)windowWidth / 2) - (4.0f * (0.5f * textureWidth)),
                      ((float)windowHeight / 2) - (4.f * (0.5f * textureHeight))};
}

void Player::DrawPlayer()
{
    DrawTexturePro(playerTexture, SetSource(),SetDest(), Vector2{0.f, 0.f}, 1, WHITE);
}

Texture2D Player::GetPlayerTexture() {
    return playerTexture;
}

Rectangle Player::SetDest()
{
    dest = {playerPosition.x, playerPosition.y, 4.f * textureWidth, 4.f * textureHeight};
    return dest;
}

Rectangle Player::SetSource() {
    source = {currentTexture * textureWidth, 0.f, leftOrRightDirection * textureWidth, textureHeight};
    return source;
}

void Player::DetermineViewDirection(float movementDirectionX)
{
    movementDirectionX < 0.f ? leftOrRightDirection = -1.f : leftOrRightDirection = 1.f;
}

void Player::AnimateTexture(float deltaTime)
{
    timeCounterBetweenTextures += deltaTime;

    if (timeCounterBetweenTextures >= timeLimitBetweenTwoTexture)
    {
        timeCounterBetweenTextures = 0;
        currentTexture++;

        if (currentTexture >= maxTextureAmount)
        {
            currentTexture = 0;
        }
    }
}

void Player::DeterminePlayerTexture(Vector2 movementDirection)
{
    if (movementDirection.x == 0 && movementDirection.y == 0)
    {
        playerTexture = idleTexture;
        return;
    }

    playerTexture = runningTexture;
}