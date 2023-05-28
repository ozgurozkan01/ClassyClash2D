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
    float leftOrRightDirection;
    float textureHeight;
    float textureWidth;

    float movementSpeed;
    Vector2 movementDirection{};
    Vector2 worldPosition{}; // In World Position
    Vector2 mapPosition{}; // On Map Position
public:
    BaseCharacter(Texture2D idle, Texture2D run);

    [[nodiscard]] bool CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight) const;
    void Render();
    void SetViewDirection();
    void AnimateTexture(float deltaTime);
    Vector2 GetPosOnMap();
    Vector2 GetScreenPos();
    Rectangle SetDest();
    Rectangle SetSource();
    Rectangle GetCollisionRec();
    Texture2D GetCharacterTexture();
    void SetCharacterTexture();
    void SetLastPositionFrame();
    void UndoMovement();
    virtual void Tick(float deltaTime);
    bool IsCharacterRunning();

};


#endif //CLASSYCLASH2D_BASECHARACTER_H
