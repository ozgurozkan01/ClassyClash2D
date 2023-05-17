//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"
#include "Map.h"
#include "Player.h"

GameManager::GameManager()
{
    gameName = "Classy Clash 2D";
    fps = 60;

    map = new Map();
    player = new Player();
}

void GameManager::ArrangmentsBeforeGameStart()
{
    InitWindow(windowWidth, windowHeight, gameName);
    SetTargetFPS(fps);

    map->LoadMapTexture();

    player->LoadPlayerTexture();
    player->SetTextureDimensions();
    player->SetPlayerPosition(windowWidth, windowHeight);
}

void GameManager::Tick(float deltaTime)
{

    map->Move();
    map->DrawMap();

    player->DeterminePlayerTexture(map->movementDirection);
    player->DetermineViewDirection(map->movementDirection.x);
    player->AnimateTexture(deltaTime);
    player->DrawPlayer();
}

void GameManager::ArrangmentsAfterGameFinish() const
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
    CloseWindow();
}