//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"
#include "Map.h"
#include "Player.h"

GameManager::GameManager() : windowWidth(384), windowHeight(384)
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

//  MAP

    player->Move();
    map->Move(player->GetPosOnMap());
    map->DrawMap();

//  PLAYER
    player->SetPlayerTexture();
    player->SetViewDirection();
    player->AnimateTexture(deltaTime);
    player->DrawPlayer();
}

void GameManager::ArrangmentsAfterGameFinish() const
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
    CloseWindow();
}