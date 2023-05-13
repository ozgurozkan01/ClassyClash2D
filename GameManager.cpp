//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"
#include "Map.h"

GameManager::GameManager()
{
    gameName = "Classy Clash 2D";
    fps = 60;

    map = new Map();
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
}

void GameManager::UnloadGameObjectTextures()
{
    UnloadTexture(map->GetMapTexture());
}

void GameManager::DrawGameObjects()
{
    map->DrawMap();
}
