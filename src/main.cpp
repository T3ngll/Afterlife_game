#include "raylib.h"
#include "Character.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Afterlife");
    SetWindowState(FLAG_VSYNC_HINT);

    Character ch;



    SetTargetFPS(60);



    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_RIGHT)) ch.x+= ch.speedX+GetFrameTime();
        if (IsKeyDown(KEY_LEFT)) ch.x -= ch.speedX+GetFrameTime();
        if (IsKeyDown(KEY_UP)) ch.y -= ch.speedY+GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) ch.y += ch.speedY+GetFrameTime();



        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("init window and move mechanic", 10, 10, 20, DARKGRAY);

            DrawCircleV(Character, 50, GRAY);


            DrawFPS(10,10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
