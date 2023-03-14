#include "raylib.h"
#include "Character.h"
#include <cmath>
using namespace std;





int main()
{

    //init window, set fps, set textures
    InitWindow(800,800, "Afterlife");

    SetTargetFPS(60);
    //SetWindowState(FLAG_VSYNC_HINT);
    Image background = LoadImage("resources/hall.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    Texture2D texture = LoadTextureFromImage(background);
    UnloadImage(background);


    // init character
    Character player(70,50,300,300,100,20);
    Rectangle rect{GetScreenWidth()-175.0f,GetScreenHeight()-250.0f,50,200};
    Vector2 mousePosition = {0};



    //main game loop
    while (!WindowShouldClose())
    {
        // mouse tracking
        mousePosition = GetMousePosition();
        float dx = mousePosition.x - player.getX();
        float dy = mousePosition.y - player.getY();
        float rotation = atan2f(dy, dx);


        //check if control key is down
        if (IsKeyDown(KEY_D) && player.getX() < (GetScreenWidth()-player.getWidth()))
        {
            player.setX(player.getSpeedX()*GetFrameTime()) ;
        }
        if (IsKeyDown(KEY_A) && player.getX() >player.getWidth())
        {
            player.setX(-1*player.getSpeedX()*GetFrameTime());
        }
        if (IsKeyDown(KEY_W) && player.getY() >player.getWidth())
        {
            player.setY(-1*player.getSpeedY()*GetFrameTime()) ;
        }
        if (IsKeyDown(KEY_S) && player.getY() < (GetScreenHeight()-player.getWidth()))
        {
            player.setY(player.getSpeedY()*GetFrameTime());
        }

        // start render
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, 0, 0, WHITE);
        DrawRectangleRec(rect,RED);

        DrawRectanglePro((Rectangle) { player.getX(), player.getY(), player.getWidth(), player.getHeight() },
            (Vector2) { player.getWidth() / 2, player.getHeight() / 2 }, rotation * RAD2DEG, BLACK);




        DrawText("AfterLife Test \nPress W A S D to move", 10, 10, 20, WHITE);
        DrawFPS(10,70);

        EndDrawing(); // end render
    }

    // clear gpu
    UnloadTexture(texture);


    //end
    CloseWindow();

    return 0;
}
