#include "raylib.h"
#include "Character.h"

struct Character
{
    float x,y;
    float height,width;
    float speedX,speedY;
    float health;
    float ammo;

};

int main(void)
{

    InitWindow(800,800, "Afterlife");
    SetTargetFPS(60);
    SetWindowState(FLAG_VSYNC_HINT);



    Character player;
    player.x= GetScreenWidth() / 2 - 25;
    player.y= GetScreenHeight() / 2 - 35;
    player.speedX=50;
    player.speedY=50;
    player.height=70;
    player.width=50;



    while (!WindowShouldClose())
    {


        if (IsKeyDown(KEY_RIGHT) && player.x < (GetScreenWidth()-player.width)) player.x+= player.speedX;
        if (IsKeyDown(KEY_LEFT) && player.x > 1) player.x -= player.speedX;
        if (IsKeyDown(KEY_UP) && player.y >0) player.y -= player.speedY;
        if (IsKeyDown(KEY_DOWN) && player.y < (GetScreenHeight()-player.height)) player.y  += player.speedY;


        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("", 10, 10, 20, DARKGRAY);

        DrawRectangle(player.x, player.y, player.width, player.height, BLACK);


            DrawFPS(10,10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
