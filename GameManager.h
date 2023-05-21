//
// Created by ozgur on 5/12/2023.
//

#ifndef CLASSYCLASH2D_GAMEMANAGER_H
#define CLASSYCLASH2D_GAMEMANAGER_H
#include "raylib.h"

class Map;
class Player;
class Prop;
class Enemy;

class GameManager {

private:

    const char* gameName;
    const int windowHeight;
    const int windowWidth;

    int fps;

    Vector2 propPositions[6];

    // CLASSES
    Map* map;
    Player* player;
    Prop *props[6];
    Enemy* goblin;

public:


    GameManager();
    ~GameManager();
    void Tick(float deltaTime) const;
};


#endif //CLASSYCLASH2D_GAMEMANAGER_H
