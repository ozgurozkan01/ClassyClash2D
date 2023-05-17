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

    void Tick(float deltaTime);

    void ArrangmentsBeforeGameStart();
    void ArrangmentsAfterGameFinish() const;
};


#endif //CLASSYCLASH2D_GAMEMANAGER_H
