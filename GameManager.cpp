//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"
#include "Map.h"
#include "Player.h"
#include "Prop.h"
#include <iostream>

GameManager::GameManager() : windowWidth(384), windowHeight(384)
{
    gameName = "Classy Clash 2D";
    fps = 60;

    SetTargetFPS(fps);
    InitWindow(windowWidth, windowHeight, gameName);

    player = new Player(static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    map = new Map();

    for (int i = 0; i < sizeof(propPositions) / sizeof(propPositions[0]); ++i)
    {
        propPositions[i] = {static_cast<float>(100 * i+1), static_cast<float>(1000 - 100 * i+1)};
    }

    for (int i = 0; i < sizeof(props) / sizeof(props[0]); ++i)
    {
        props[i] = new Prop{propPositions[i], LoadTexture("nature_tileset/Rock.png")};
    }
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

    for (auto prop : props)
    {
        prop->DrawProp(player->GetPosOnMap());
    }
}

GameManager::~GameManager()
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetPlayerTexture());
    CloseWindow();

    delete map;
    delete player;

    for (Prop *prop : props)
    {
        delete prop;
    }
}