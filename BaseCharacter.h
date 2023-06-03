//
// Created by ozgur on 5/21/2023.
//

#ifndef CLASSYCLASH2D_BASECHARACTER_H
#define CLASSYCLASH2D_BASECHARACTER_H
#include "raylib.h"

class BaseCharacter {
private:

    Texture2D idleTexture{};
    Texture2D runningTexture{};
    Texture2D currentTexture{};
    Rectangle source{};
    Rectangle dest{};
    float scale;
    const float timeLimitBetweenTwoTexture;
    const float maxTextureAmount;
    float timeCounterBetweenTextures{};
    float currentTextureFrame{};
    Vector2 lastPositionFrameOnMap{};

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

    BaseCharacter(Texture2D idle, Texture2D run);
    virtual void Tick(float deltaTime);

    void Render();
    void SetViewDirection();
    void AnimateTexture(float deltaTime);
    void SetCharacterTexture();
    void SetLastPositionFrame();
    void UndoMovement();
    void SetIsAlive(bool isAlive);

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
