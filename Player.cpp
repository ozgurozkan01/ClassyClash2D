//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight) : movementSpeed(4.f), timeLimitBetweenTwoTexture(1.f / 12.f), maxTextureAmount(6.f)
{
    playerTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    idleTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    runningTexture = LoadTexture("characters/knight_run_spritesheet.png");

    textureWidth = static_cast<float>(playerTexture.width) / maxTextureAmount;
    textureHeight = static_cast<float>(playerTexture.height);
    leftOrRightDirection = 1.f;

    playerPosition = {(static_cast<float>(windowWidth)/ 2) - (4.0f * (0.5f * textureWidth)),
                      (static_cast<float>(windowHeight) / 2) - (4.f * (0.5f * textureHeight))};
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