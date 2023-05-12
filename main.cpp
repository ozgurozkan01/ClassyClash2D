#include "GameManager.h"
#include "raylib.h"
int main() {

    GameManager* gameManager = new GameManager;

    gameManager->CreateGameWindow();
    SetTargetFPS(gameManager->GetFps());

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);

        EndDrawing();
    }
    CloseWindow();
    delete gameManager;
    return 0;
}
