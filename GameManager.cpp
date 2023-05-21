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
    srand(time(NULL));
    gameName = "Classy Clash 2D";
    fps = 60;

    SetTargetFPS(fps);
    InitWindow(windowWidth, windowHeight, gameName);

    player = new Player(static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    map = new Map();

    for (int i = 0; i < sizeof(propPositions) / sizeof(propPositions[0]); ++i)
    {
        float xPos = (rand() % 2750) + 250.f;
        float yPos = (rand() % 2750) + 250.f;
        std::cout << xPos << "  " << yPos << std::endl;
        propPositions[i] = {xPos, yPos};
    }

    for (int i = 0; i < (sizeof(propPositions) / sizeof(propPositions[0])); ++i)
    {
        if (i % 2 == 0)
        {
            props[i] = new Prop{propPositions[i], LoadTexture("nature_tileset/Rock.png")};
        }

        else
            props[i] = new Prop{propPositions[i], LoadTexture("nature_tileset/Log.png")};
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
                             static_cast<float>(map->GetMapTexture().height)))
    {
        player->UndoMovement();
    }

    for (auto prop : props)
    {
        prop->DrawProp(player->GetPosOnMap());
    }


    for (auto prop : props)
    {
        if(CheckCollisionRecs(prop->GetCollisionRec(player->GetPosOnMap()), player->GetCollisionRec()))
        {
            player->UndoMovement();
        }
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