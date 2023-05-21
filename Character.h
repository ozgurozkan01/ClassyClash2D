//
// Created by ozgur on 5/21/2023.
//

#ifndef CLASSYCLASH2D_CHARACTER_H
#define CLASSYCLASH2D_CHARACTER_H
#include "raylib.h"

class Character {
private:

    Texture2D idleTexture{};
    Texture2D runningTexture{};
    Texture2D characterTexture{};
    Vector2 characterPosition{};
    Rectangle source{};
    Rectangle dest{};
    float leftOrRightDirection;
    float scale;
    const float timeLimitBetweenTwoTexture;
    const float maxTextureAmount;
    float timeCounterBetweenTextures{};
    float currentTexture{};

    float textureHeight;
    float textureWidth;

    Vector2 lastPositionFrameOnMap{};

protected:
    const float movementSpeed;
    Vector2 movementDirection{};
    Vector2 positionOnMap{};
public:
    Character(float windowWidth, float windowHeight, Texture2D idle, Texture2D run);

    [[nodiscard]] bool CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight) const;
    void Render();
    void SetViewDirection();
    void AnimateTexture(float deltaTime);
    Vector2 GetPosOnMap();
    Rectangle SetDest();
    Rectangle SetSource();
    Rectangle GetCollisionRec();
    Texture2D GetCharacterTexture();
    void SetCharacterTexture();
    void SetLastPositionFrame();
    void UndoMovement();
};


#endif //CLASSYCLASH2D_CHARACTER_H
