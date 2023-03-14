#include "raylib.h"
#include "Character.h"





int main(void)
{

    InitWindow(800,800, "Afterlife");


    //SetTargetFPS(100);
    SetWindowState(FLAG_VSYNC_HINT);

    Texture2D Background = LoadTexture("./resources/hall.png");

    Character player;




    while (!WindowShouldClose())
    {


        if (IsKeyDown(KEY_RIGHT) && player.x < (GetScreenWidth()-player.width)) player.x+= player.speedX*GetFrameTime();
        if (IsKeyDown(KEY_LEFT) && player.x > 1) player.x -= player.speedX*GetFrameTime();
        if (IsKeyDown(KEY_UP) && player.y >0) player.y -= player.speedY*GetFrameTime();
        if (IsKeyDown(KEY_DOWN) && player.y < (GetScreenHeight()-player.height)) player.y  += player.speedY*GetFrameTime();


        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(Background,0,0,WHITE);

        //DrawText("placeholder", 10, 10, 20, DARKGRAY);

    DrawRectangle(player.x, player.y, player.width, player.height, BLACK);


        DrawFPS(10,10);

        EndDrawing();
    }
    UnloadTexture(Background);

    CloseWindow();

    return 0;
}
