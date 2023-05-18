//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "raymath.h"
#include <iostream>

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

    lastPositionFrameOnMap = {0.f, 0.f};
    positionOnMap = {0.f, 0.f};
    movementDirection = {0.f, 0.f};
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
        positionOnMap = Vector2Add(positionOnMap, Vector2Scale(Vector2Normalize(movementDirection), movementSpeed));
    }
}

Vector2 Player::GetPosOnMap() {
    return positionOnMap;
}

void Player::SetLastPositionFrame()
{
    // set last position frame in moveable area
    lastPositionFrameOnMap = positionOnMap;
}

void Player::UndoMovement()
{
    // set last position frame as current position which is on border
    positionOnMap = lastPositionFrameOnMap;
}

bool Player::CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight, float mapScale) const
{
    return positionOnMap.x < 0 ||
           positionOnMap.y < 0 ||
           positionOnMap.x + windowWidth > mapWidth * mapScale ||
           positionOnMap.y + windowHeight > mapHeight * mapScale;
}

int Player::sum() const
{
    return 0;
}
