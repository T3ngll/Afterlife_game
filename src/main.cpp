#include "raylib.h"
#include "Character.h"
#include <cmath>
#include <iostream>
using namespace std;





int main()
{

    InitWindow(800,800, "Afterlife");


    //SetTargetFPS(100);
    SetWindowState(FLAG_VSYNC_HINT);
    Image background = LoadImage("resources/hall.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    Texture2D texture = LoadTextureFromImage(background);

    UnloadImage(background);

    Character player(70,50,300,300,100,20);
    Vector2 mousePosition = {0};

    //cout << "Run path: " << GetWorkingDirectory() << endl;
    while (!WindowShouldClose())
    {
    
        mousePosition = GetMousePosition();

        float dx = mousePosition.x - player.getX();
        float dy = mousePosition.y - player.getY();

        float rotation = atan2f(dy, dx);

        if (IsKeyDown(KEY_D) && player.getX() < (GetScreenWidth()-player.getWidth())) player.setX(player.getSpeedX()*GetFrameTime()) ;
        if (IsKeyDown(KEY_A) && player.getX() > 1) player.setX(-1*player.getSpeedX()*GetFrameTime());
        if (IsKeyDown(KEY_W) && player.getY() >0) player.setY(-1*player.getSpeedY()*GetFrameTime()) ;
        if (IsKeyDown(KEY_S) && player.getY() < (GetScreenHeight()-player.getHeight())) player.setY(player.getSpeedY()*GetFrameTime());


        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, 0, 0, WHITE);

        DrawRectanglePro((Rectangle) { player.getX(), player.getY(), player.getWidth(), player.getHeight() },
            (Vector2) { player.getWidth() / 2, player.getHeight() / 2 }, rotation * RAD2DEG, BLACK);
       // player.Draw(player,player.getVector(),player.getRotation(),BLACK);


        DrawText("AfterLife Test \nPress W A S D to move", 10, 10, 20, WHITE);
        DrawFPS(10,70);

        EndDrawing();
    }
    UnloadTexture(texture);

    CloseWindow();

    return 0;
}
