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

void GameManager::CreateGameWindow()
{
    InitWindow(windowWidth, windowHeight, gameName);
}

int GameManager::GetFps() const
{
    return fps;
}

void GameManager::LoadGameObjectTextures() const
{
    map->LoadMapTexture();
    player->LoadPlayerTexture();
}

void GameManager::UnloadGameObjectTextures() const
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
}

void GameManager::DrawGameObjects() const
{
    map->DrawMap();
    player->DrawPlayer();
}

void GameManager::ArrangmentsBeforeGameStart()
{
    CreateGameWindow();
    SetTargetFPS(GetFps());
    LoadGameObjectTextures();
    player->SetPlayerPosition(windowWidth, windowHeight);
}

void GameManager::ArrangmentsAfterGameFinish() const
{
    UnloadGameObjectTextures();
    CloseWindow();
}

void GameManager::Tick(float deltaTime)
{

    map->Move();
    player->DeterminePlayerTexture(map->movementDirection);
    player->DetermineViewDirection(map->movementDirection.x);
    player->AnimateTexture(deltaTime);
    DrawGameObjects();
}
