#include "GameManager.h"
#include "raylib.h"
int main() {

    GameManager* gameManager = new GameManager;

    gameManager->CreateGameWindow();
    SetTargetFPS(gameManager->GetFps());
    gameManager->LoadGameObjectTextures();

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        gameManager->Play();

        EndDrawing();
    }
    gameManager->UnloadGameObjectTextures();
    CloseWindow();
    delete gameManager;
    return 0;
}
