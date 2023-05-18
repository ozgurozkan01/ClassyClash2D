//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"
#include "Map.h"
#include "Player.h"
#include <iostream>

GameManager::GameManager() : windowWidth(384), windowHeight(384)
{
    gameName = "Classy Clash 2D";
    fps = 60;

    SetTargetFPS(fps);
    InitWindow(windowWidth, windowHeight, gameName);

    player = new Player();
    map = new Map();

}

void GameManager::ArrangmentsBeforeGameStart() const
{
    player->SetPlayerPosition(windowWidth, windowHeight);
}

void GameManager::Tick(float deltaTime) const
{

    map->Move(player->GetPosOnMap());
    map->DrawMap();

    player->SetLastPositionFrame();
    player->Move();
    player->SetPlayerTexture();
    player->SetViewDirection();
    player->AnimateTexture(deltaTime);
    player->DrawPlayer();

    if (player->CanMoveOnMap((float)windowWidth,
                             (float)windowHeight,
                             (float)map->GetMapTexture().width,
                             (float)map->GetMapTexture().height,
                             map->GetMapScale()))
    {
        player->UndoMovement();
    }
}

void GameManager::ArrangmentsAfterGameFinish() const
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
    CloseWindow();
}