//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "raylib.h"

class Player {
private:

    Texture2D idleTexture{};
    Texture2D runningTexture{};
    Texture2D playerTexture{};

    Vector2 playerPosition{};
    Rectangle source{};
    Rectangle dest{};
    float leftOrRightDirection;

    const float timeLimitBetweenTwoTexture;
    const float maxTextureAmount;
    float timeCounterBetweenTextures{};
    float currentTexture{};

    float textureHeight;
    float textureWidth;

    const float movementSpeed;
    Vector2 movementDirection{};
    Vector2 positionOnMap{};
    Vector2 lastPositionFrameOnMap{};

public:

    Player(float windowWidth, float windowHeight);

    void DrawPlayer();
    void SetViewDirection();
    void AnimateTexture(float deltaTime);
    void Move();
    [[nodiscard]] bool CanMoveOnMap(float windowWidth, float windowHeight, float mapWidth, float mapHeight, float mapScale) const;
    Vector2 GetPosOnMap();
    Rectangle SetDest();
    Rectangle SetSource();
    Texture2D GetPlayerTexture();
    void SetPlayerTexture();
    void SetLastPositionFrame();
    void UndoMovement();
};


#endif //CLASSYCLASH2D_PLAYER_H
