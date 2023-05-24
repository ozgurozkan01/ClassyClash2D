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
    dest = {screenPosition.x, screenPosition.y, scale * textureWidth, scale * textureHeight};
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
    return worldPosition;
}

void BaseCharacter::SetLastPositionFrame()
{
    // set last position frame in moveable area
    lastPositionFrameOnMap = worldPosition;
}

void BaseCharacter::UndoMovement()
{
    // set last position frame as current position which is on border
    worldPosition = lastPositionFrameOnMap;
}

bool BaseCharacter::CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight) const
{
    return worldPosition.x < 0 ||
           worldPosition.y < 0 ||
           worldPosition.x + windowWidth > mapWidth * scale ||
           worldPosition.y + windowHeight > mapHeight * scale;
}

Rectangle BaseCharacter::GetCollisionRec() {
    return Rectangle{
            screenPosition.x,
            screenPosition.y,
            textureWidth * scale,
            textureHeight * scale
    };
}

void BaseCharacter::SetViewDirection()
{
    movementDirection.x < 0.f ? leftOrRightDirection = -1.f : leftOrRightDirection = 1.f;
}

void BaseCharacter::Tick(float deltaTime)
{
    SetLastPositionFrame();
    SetCharacterTexture();
    SetViewDirection();
    AnimateTexture(deltaTime);
    Render();

/*    if (CanMoveOnMap(static_cast<float>(windowWidth),
                             static_cast<float>(windowHeight),
                             static_cast<float>(map->GetMapTexture().width),
                             static_cast<float>(map->GetMapTexture().height)))
    {
        UndoMovement();
    }*/
}
