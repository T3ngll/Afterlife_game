#include "raylib.h"
#include "Character.h"
#include <iostream>
using namespace std;





int main(void)
{

    InitWindow(800,800, "Afterlife");


    //SetTargetFPS(100);
    SetWindowState(FLAG_VSYNC_HINT);
    Image background = LoadImage("resources/hall.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    Texture2D texture = LoadTextureFromImage(background);

    UnloadImage(background);

    Character player;


    //cout << "Run path: " << GetWorkingDirectory() << endl;
    while (!WindowShouldClose())
    {


        if (IsKeyDown(KEY_D) && player.x < (GetScreenWidth()-player.width)) player.x+= player.speedX*GetFrameTime();
        if (IsKeyDown(KEY_A) && player.x > 1) player.x -= player.speedX*GetFrameTime();
        if (IsKeyDown(KEY_W) && player.y >0) player.y -= player.speedY*GetFrameTime();
        if (IsKeyDown(KEY_S) && player.y < (GetScreenHeight()-player.height)) player.y  += player.speedY*GetFrameTime();


        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, 0, 0, RAYWHITE);

        //DrawText("placeholder", 10, 10, 20, DARKGRAY);

    DrawRectangle(player.x, player.y, player.width, player.height, BLACK);


        DrawFPS(10,10);

        EndDrawing();
    }
    UnloadTexture(texture);

    CloseWindow();

    return 0;
}
