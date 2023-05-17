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

    SetTargetFPS(fps);
    InitWindow(windowWidth, windowHeight, gameName);

    map = new Map();
    player = new Player();
}

void GameManager::ArrangmentsBeforeGameStart() const
{
    player->SetPlayerPosition(windowWidth, windowHeight);
}

void GameManager::Tick(float deltaTime) const
{

    map->Move();
    map->DrawMap();

    player->SetPlayerTexture(map->movementDirection);
    player->SetViewDirection(map->movementDirection.x);
    player->AnimateTexture(deltaTime);
    player->DrawPlayer();
}

void GameManager::ArrangmentsAfterGameFinish() const
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
    CloseWindow();
}