//
// Created by ozgur on 5/21/2023.
//

#ifndef CLASSYCLASH2D_BASECHARACTER_H
#define CLASSYCLASH2D_BASECHARACTER_H
#include "raylib.h"

class Health;

class BaseCharacter {
private:

    Texture2D idleTexture{};
    Texture2D runningTexture{};
    Texture2D currentTexture{};
    Rectangle source{};
    Rectangle dest{};
    Vector2 lastPositionFrameOnMap{};
    const float timeLimitBetweenTwoTexture;
    const float maxTextureAmount;
    float scale;
    float timeCounterBetweenTextures{};
    float currentTextureFrame{};
    float colorFrameUpdatingTime;
    float colorUpdatingTimer{};
    int maxColorUpdateAmount;
    int colorUpdateAmount{};
    bool isColorChangeable;

protected:
    bool isAlive;
    float textureHeight;
    float textureWidth;
    float movementSpeed;
    Vector2 movementDirection{};
    Vector2 worldPosition{}; // In World Position
    Vector2 mapPosition{}; // On Map Position
    Color color;
public:
    float leftOrRightDirection;
    float damage;
    Health* healthObject;

    BaseCharacter(Texture2D idle, Texture2D run);
    virtual void Tick(float deltaTime);

    void Render();
    void SetViewDirection();
    void AnimateTexture(float deltaTime);
    void SetCharacterTexture();
    void SetLastPositionFrame();
    void UndoMovement();
    void SetIsAlive(bool isAlive);
    void TakeDamage(float damage);
    void SetColor();
    void ColorTimer();
    void SetIsColorChangeable(bool isColorChangeable);

    Vector2 GetPosOnMap();
    Vector2 GetScreenPos();
    Rectangle SetDest();
    Rectangle SetSource();
    Rectangle GetCollisionRec();
    Texture2D GetCharacterTexture();

    bool IsCharacterRunning();
    bool CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight) const;
    bool GetIsAlive();
};


#endif //CLASSYCLASH2D_BASECHARACTER_H
