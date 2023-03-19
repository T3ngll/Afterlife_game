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
    Image character = LoadImage("resources/character.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    Texture2D Background = LoadTextureFromImage(background);
    Texture2D Character = LoadTextureFromImage(character);
    UnloadImage(background);


    auto frameWidth = (float)Character.width;
    auto frameHeight = (float)Character.height;




    // init character
    class Character player(Character,70,50,300,300,100,20);








    //main game loop
    while (!WindowShouldClose())
    {
        // mouse tracking
        Vector2 mousePosition = GetMousePosition();
        float dx = mousePosition.x - player.getX();
        float dy = mousePosition.y - player.getY();
        float rotation = atan2f(dy, dx)+(PI/2);


        //check if control key is down
        if (IsKeyDown(KEY_D) && player.getX() < (float(GetScreenWidth())-player.getWidth()))
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
        if (IsKeyDown(KEY_S) && player.getY() < (float(GetScreenHeight())-player.getWidth()))
        {
            player.setY(player.getSpeedY()*GetFrameTime());
        }

        // start render
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(Background, 0, 0, WHITE);
        DrawLine(0,GetScreenHeight()/2,GetScreenWidth(),GetScreenHeight()/2,BLACK);
        DrawLine(GetScreenWidth()/2,0,GetScreenWidth()/2,GetScreenHeight(),BLACK);

        DrawTexturePro(player.getTexture(),(Rectangle){0,0,frameWidth,frameHeight},
                       (Rectangle){player.getX(),player.getY(),player.getWidth(),player.getHeight()},
                       (Vector2){(float)player.getWidth()/2, (float)player.getHeight()/2},
                       rotation*RAD2DEG,
                       WHITE);



        DrawText("AfterLife Test \nPress W A S D to move", 10, 10, 20, WHITE);
        DrawFPS(10,70);

        EndDrawing(); // end render
    }

    // clear gpu
    UnloadTexture(Background);
    UnloadTexture(Character);


    //end
    CloseWindow();

    return 0;
}
