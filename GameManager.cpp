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

void GameManager::Play()
{
    map->Move();
}

int GameManager::GetFps() const
{
    return fps;
}

void GameManager::LoadGameObjectTextures()
{
    map->LoadMapTexture();
    player->LoadPlayerTexture();
}

void GameManager::UnloadGameObjectTextures()
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
}

void GameManager::DrawGameObjects()
{
    map->DrawMap();
    player->DrawPlayer();
}

void GameManager::ArrangmentsBeforeGameStart()
{
    CreateGameWindow();
    SetTargetFPS(GetFps());
    LoadGameObjectTextures();
    player->SetPlayerPosition();
}

void GameManager::ArrangmentsAfterGameFinish()
{
    UnloadGameObjectTextures();
    CloseWindow();
}
