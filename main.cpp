#include "GameManager.h"
#include "Player.h"
#include "raylib.h"
int main() {

    GameManager* gameManager = new GameManager;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        gameManager->Tick(GetFrameTime());

        EndDrawing();
    }

    delete gameManager;

    return 0;
}
