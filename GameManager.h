//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_GAMEMANAGER_H
#define CLASSYCLASH2D_GAMEMANAGER_H
#include "raylib.h"

class Map;
class Player;

class GameManager {

private:

    const char* gameName;

    int fps;

public:
    // CLASSES
    Map* map;
    Player* player;

    const int windowHeight = 384.f;
    const int windowWidth = 384.f;
    GameManager();

    void Tick();

    void ArrangmentsBeforeGameStart();
    void ArrangmentsAfterGameFinish() const;
    void CreateGameWindow();
    void LoadGameObjectTextures() const;
    void UnloadGameObjectTextures()const ;
    void DrawGameObjects() const;
    void Play() const;
    int GetFps() const;
};


#endif //CLASSYCLASH2D_GAMEMANAGER_H
