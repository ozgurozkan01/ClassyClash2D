//
// Created by ozgur on 5/21/2023.
//

#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(float windowWidth, float windowHeight, Texture2D idle, Texture2D run) : movementSpeed(4.f), timeLimitBetweenTwoTexture(1.f / 12.f), maxTextureAmount(6.f)
{
    scale = 4.f;

    currentTexture = idle;
    idleTexture = idle;
    runningTexture = run;

    textureWidth = static_cast<float>(currentTexture.width) / maxTextureAmount;
    textureHeight = static_cast<float>(currentTexture.height);
    leftOrRightDirection = 1.f;
}

void BaseCharacter::Render()
{
    DrawTexturePro(currentTexture, SetSource(), SetDest(), Vector2{0.f, 0.f}, 1, WHITE);
}

Rectangle BaseCharacter::SetDest() {
    dest = {characterPosition.x, characterPosition.y, scale * textureWidth, scale * textureHeight};
    return dest;
}

Rectangle BaseCharacter::SetSource() {
    source = {currentTextureFrame * textureWidth, 0.f, leftOrRightDirection * textureWidth, textureHeight};
    return source;
}

Texture2D BaseCharacter::GetCharacterTexture() {
    return currentTexture;
}

void BaseCharacter::AnimateTexture(float deltaTime)
{
    timeCounterBetweenTextures += deltaTime;

    if (timeCounterBetweenTextures >= timeLimitBetweenTwoTexture)
    {
        timeCounterBetweenTextures = 0;
        currentTextureFrame++;

        if (currentTextureFrame >= maxTextureAmount)
        {
            currentTextureFrame = 0;
        }
    }
}

void BaseCharacter::SetCharacterTexture()
{
    if (movementDirection.x == 0 && movementDirection.y == 0)
    {
        currentTexture = idleTexture;
        return;
    }

    currentTexture = runningTexture;
}
Vector2 BaseCharacter::GetPosOnMap() {
    return positionOnMap;
}

void BaseCharacter::SetLastPositionFrame()
{
    // set last position frame in moveable area
    lastPositionFrameOnMap = positionOnMap;
}

void BaseCharacter::UndoMovement()
{
    // set last position frame as current position which is on border
    positionOnMap = lastPositionFrameOnMap;
}

bool BaseCharacter::CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight) const
{
    return positionOnMap.x < 0 ||
           positionOnMap.y < 0 ||
           positionOnMap.x + windowWidth > mapWidth * scale ||
           positionOnMap.y + windowHeight > mapHeight * scale;
}

Rectangle BaseCharacter::GetCollisionRec() {
    return Rectangle{
            characterPosition.x,
            characterPosition.y,
            textureWidth * scale,
            textureHeight * scale
    };
}

void BaseCharacter::SetViewDirection()
{
    movementDirection.x < 0.f ? leftOrRightDirection = -1.f : leftOrRightDirection = 1.f;
}
