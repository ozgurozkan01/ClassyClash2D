//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_GAMEMANAGER_H
#define CLASSYCLASH2D_GAMEMANAGER_H
#include "raylib.h"

class Map;

class GameManager {

private:
    const int windowHeight;
    const int windowWidth;
    const char* gameName;

    int fps;

    // CLASSES
    Map* map;

public:

    GameManager();

    void CreateGameWindow();
    void LoadGameObjectTextures();
    void UnloadGameObjectTextures();
    void Play();
    int GetFps() const;
};


#endif //CLASSYCLASH2D_GAMEMANAGER_H
