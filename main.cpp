#include "GameManager.h"
#include "Player.h"
#include "raylib.h"
int main() {

    GameManager* gameManager = new GameManager;

    gameManager->ArrangmentsBeforeGameStart();

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        gameManager->Play();

        gameManager->DrawGameObjects();
        EndDrawing();
    }

    gameManager->ArrangmentsAfterGameFinish();
    delete gameManager;

    return 0;
}
