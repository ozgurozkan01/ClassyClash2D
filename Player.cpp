//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "raymath.h"

Player::Player() : movementSpeed(4.f), timeLimitBetweenTwoTexture(1.f / 12.f), maxTextureAmount(6.f)
{
    playerTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    idleTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    runningTexture = LoadTexture("characters/knight_run_spritesheet.png");

    textureWidth = (float)playerTexture.width / maxTextureAmount;
    textureHeight = (float)playerTexture.height;

    timeCounterBetweenTextures = 0.f;
    currentTexture = 0;
    leftOrRightDirection = 1.f;
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

void Player::SetViewDirection()
{
    movementDirection.x < 0.f ? leftOrRightDirection = -1.f : leftOrRightDirection = 1.f;
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

void Player::SetPlayerTexture()
{
    if (movementDirection.x == 0 && movementDirection.y == 0)
    {
        playerTexture = idleTexture;
        return;
    }

    playerTexture = runningTexture;
}

void Player::Move()
{
    movementDirection = {0.f, 0.f};
    if (IsKeyDown(KEY_A)) movementDirection.x -= 1;
    if (IsKeyDown(KEY_D)) movementDirection.x += 1;
    if (IsKeyDown(KEY_W)) movementDirection.y -= 1;
    if (IsKeyDown(KEY_S)) movementDirection.y += 1;

    if (Vector2Length(movementDirection) != 0)
    {
        mapPosition = Vector2Add(mapPosition, Vector2Scale(Vector2Normalize(movementDirection), movementSpeed));
    }
}

Vector2 Player::GetPosOnMap() {
    return mapPosition;
}
