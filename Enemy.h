//
// Created by ozgur on 5/21/2023.
//

#ifndef CLASSYCLASH2D_ENEMY_H
#define CLASSYCLASH2D_ENEMY_H
#include "BaseCharacter.h"

class Player;

class Enemy : public BaseCharacter{

public:
    Enemy(float windowWidth, float windowHeight, Texture2D idle, Texture2D run, Player* player);
    virtual void Tick(float deltaTime) override;
    void UpdatePositionOnMap();
    Vector2 GetDirectionVector();
    Vector2 ScaleDirecionVector();
    void Move();
private:
    Player* player;
};


#endif //CLASSYCLASH2D_ENEMY_H
