//
// Created by ozgur on 5/13/2023.
//

#include "Player.h"
#include "GameManager.h"
#include <iostream>

Player::Player()
{
}

void Player::LoadPlayerTexture()
{
    playerTexture = LoadTexture("characters/knight_idle_spritesheet.png");
}

void Player::SetPlayerPosition()
{
    playerPosition = {((float)GameManager::windowWidth / 2) - (4.0f * (0.5f * (float)playerTexture.width / 6.f)),
                      ((float)GameManager::windowHeight / 2) - (4.f * (0.5f * (float)playerTexture.height))};
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
    dest = {playerPosition.x, playerPosition.y, 4.f * (float)playerTexture.width / 6.f, 4.f * (float)playerTexture.height};
    return dest;
}

Rectangle Player::SetSource() {
    source = {0.f, 0.f, (float)playerTexture.width / 6.f, (float)playerTexture.height};
    return source;
}