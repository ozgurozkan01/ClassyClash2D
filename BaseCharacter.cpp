//
// Created by ozgur on 5/21/2023.
//

#include "BaseCharacter.h"
#include "raymath.h"
#include "Health.h"

BaseCharacter::BaseCharacter(Texture2D idle, Texture2D run) : timeLimitBetweenTwoTexture(1.f / 12.f), maxTextureAmount(6.f)
{
    scale = 4.f;
    isAlive = true;
    currentTexture = idle;
    idleTexture = idle;
    runningTexture = run;

    textureWidth = static_cast<float>(currentTexture.width) / maxTextureAmount;
    textureHeight = static_cast<float>(currentTexture.height);
    leftOrRightDirection = 1.f;
    color = WHITE;

    maxColorUpdateAmount = 6;
    colorFrameUpdatingTime = 1.f / 6.f;
    isColorChangeable = false;
    healthObject = new Health();

}

void BaseCharacter::Render()
{
    DrawTexturePro(currentTexture, SetSource(), SetDest(), Vector2{0.f, 0.f}, 1, color);
}

Rectangle BaseCharacter::SetDest() {
    dest = {worldPosition.x, worldPosition.y, scale * textureWidth, scale * textureHeight};
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

Vector2 BaseCharacter::GetScreenPos()
{
    return worldPosition;
}

Vector2 BaseCharacter::GetPosOnMap() {
    return mapPosition;
}

void BaseCharacter::SetLastPositionFrame()
{
    // set last position frame in moveable area
    lastPositionFrameOnMap = mapPosition;
}

void BaseCharacter::UndoMovement()
{
    // set last position frame as current position which is on border
    mapPosition = lastPositionFrameOnMap;
}

bool BaseCharacter::CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight) const
{
    return mapPosition.x < 0 ||
           mapPosition.y < 0 ||
           mapPosition.x + windowWidth > mapWidth * scale ||
           mapPosition.y + windowHeight > mapHeight * scale;
}

Rectangle BaseCharacter::GetCollisionRec() {
    return Rectangle{
            worldPosition.x,
            worldPosition.y,
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
    if (isColorChangeable)
    {
        ColorTimer();
    }
}

bool BaseCharacter::IsCharacterRunning()
{
    return Vector2Length(movementDirection) != 0;
}

void BaseCharacter::SetIsAlive(bool isAlive)
{
    this->isAlive = isAlive;
}

bool BaseCharacter::GetIsAlive() {
    return isAlive;
}


void BaseCharacter::TakeDamage(float damage)
{
    healthObject->DecreaseHealth(damage);

    if (healthObject->GetHealth() <= 0.f)
    {
        SetIsAlive(false);
    }
}

void BaseCharacter::SetColor()
{
    if (colorUpdateAmount % 2 == 0)
    {
        color = RED;
        return;
    }

    color = WHITE;
}

void BaseCharacter::ColorTimer()
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
    colorUpdatingTimer += GetFrameTime();
}

void BaseCharacter::SetIsColorChangeable(bool isColorChangeable)
{
    this->isColorChangeable = isColorChangeable;
}