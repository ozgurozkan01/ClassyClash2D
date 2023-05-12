//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_GAMEMANAGER_H
#define CLASSYCLASH2D_GAMEMANAGER_H
#include "raylib.h"


class GameManager {

private:
    const int windowHeight;
    const int windowWidth;
    const char* gameName;

    int fps;

public:

    GameManager();

    void CreateGameWindow();
    void Play();
    int GetFps() const;
};


#endif //CLASSYCLASH2D_GAMEMANAGER_H
