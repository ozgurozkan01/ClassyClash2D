//
// Created by ozgur on 5/13/2023.
//

#ifndef CLASSYCLASH2D_PLAYER_H
#define CLASSYCLASH2D_PLAYER_H

#include "raylib.h"

class Player {
private:

    Texture2D idleTexture;
    Texture2D runningTexture;
    Texture2D playerTexture;
    Vector2 playerPosition{};
    Rectangle source{};
    Rectangle dest{};
    float leftOrRightDirection;

    const float timeLimitBetweenTwoTexture;
    const float maxTextureAmount;
    float timeCounterBetweenTextures;
    float currentTexture;

    float textureHeight;
    float textureWidth;

public:

    Player();

    void LoadPlayerTexture();
    void SetPlayerPosition(int windowWidth, int windowHeight);
    void DrawPlayer();
    void SetViewDirection(float movementDirectionX);
    void AnimateTexture(float deltaTime);
    void SetTextureDimensions();
    Rectangle SetDest();
    Rectangle SetSource();
    Texture2D GetPlayerTexture();
    void SetPlayerTexture(Vector2 movementDirection);
};


#endif //CLASSYCLASH2D_PLAYER_H
