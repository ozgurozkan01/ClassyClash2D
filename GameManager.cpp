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

    player = new Player(static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    map = new Map();

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

    if (player->CanMoveOnMap(static_cast<float>(windowWidth),
                             static_cast<float>(windowHeight),
                             static_cast<float>(map->GetMapTexture().width),
                             static_cast<float>(map->GetMapTexture().height),
                             map->GetMapScale()))
    {
        player->UndoMovement();
    }
}

GameManager::~GameManager()
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
    CloseWindow();

    delete map;
    delete player;
}
