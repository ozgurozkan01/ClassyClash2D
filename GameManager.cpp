//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"
#include "Map.h"
#include "Player.h"
#include "Prop.h"
#include "Enemy.h"
#include "Health.h"
#include <iostream>

GameManager::GameManager() : windowWidth(384), windowHeight(384)
{
    srand(time(NULL));
    gameName = "Classy Clash 2D";
    fps = 60;

    SetTargetFPS(fps);
    InitWindow(windowWidth, windowHeight, gameName);

    player = new Player(
            static_cast<float>(windowWidth),
            static_cast<float>(windowHeight),
            LoadTexture("characters/knight_idle_spritesheet.png"),
            LoadTexture("characters/knight_run_spritesheet.png"));
    map = new Map();

    for (int i = 0; i < sizeof(propPositions) / sizeof(propPositions[0]); ++i)
    {
        float xPos = (rand() % 2750) + 250.f;
        float yPos = (rand() % 2750) + 250.f;
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

    goblin = new Enemy(
            static_cast<float>(windowWidth),
            static_cast<float>(windowHeight),
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png"),
            player);
}

void GameManager::Tick(float deltaTime)
{

    map->Move(player->GetPosOnMap());
    map->DrawMap();


    if (!player->GetIsAlive())
    {
        GameOver();
    }

    else
    {
        player->healthObject->DrawHealth();

        player->Tick(deltaTime);

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

        goblin->Tick(deltaTime);

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionRecs(goblin->GetCollisionRec(), player->sword->GetWeaponCollisionRec()))
        {
            goblin->SetIsAlive(false);
        }
    }

}

GameManager::~GameManager()
{
    UnloadTexture(map->GetMapTexture());
    UnloadTexture(player->GetCharacterTexture());
    CloseWindow();

    delete map;
    delete player;

    for (Prop *prop : props)
    {
        delete prop;
    }
}

void GameManager::GameOver() {
    DrawText("Game Over!", 100, 150, 40, RED);
}