//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_GAMEMANAGER_H
#define CLASSYCLASH2D_GAMEMANAGER_H
#include "raylib.h"

class Map;

class GameManager {

private:

    const char* gameName;

    int fps;

    // CLASSES
    Map* map;

public:
    static const int windowHeight = 384.f;
    static const int windowWidth = 384.f;
    GameManager();

    void CreateGameWindow();
    void LoadGameObjectTextures();
    void UnloadGameObjectTextures();
    void DrawGameObjects();
    void Play();
    int GetFps() const;
};


#endif //CLASSYCLASH2D_GAMEMANAGER_H
