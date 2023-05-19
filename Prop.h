//
// Created by ozgur on 5/19/2023.
//

#ifndef CLASSYCLASH2D_PROP_H
#define CLASSYCLASH2D_PROP_H

#include "raylib.h"

class Prop {
private:
    Texture2D texture;
    Vector2 position;
    float scale;

public:

    Prop(Vector2 pos, Texture2D tex);
    void DrawProp(Vector2 playerPos);
};


#endif //CLASSYCLASH2D_PROP_H
