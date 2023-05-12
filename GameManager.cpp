//
// Created by ozgur on 5/12/2023.
//

#include "GameManager.h"

GameManager::GameManager() : windowHeight(384), windowWidth(384)
{
    gameName = "Classy Clash 2D";
    fps = 60;
}

void GameManager::CreateGameWindow()
{
    InitWindow(windowWidth, windowHeight, gameName);
}

void GameManager::Play()
{

}

int GameManager::GetFps() const
{
    return fps;
}
