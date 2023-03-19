#include "raylib.h"
#include "Character.h"
#include <cmath>
using namespace std;


#define PLAYER_MAX_SHOOTS  20

static Bullet bullet[PLAYER_MAX_SHOOTS];




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
    //class Character player(Character,70,50,300,300,100,100,20,0);
    class Character player(Character,70,50,Vector2{200,200},100,100,20,0);
    class Enemy monster(140,40,Vector2{100,100});

    bool collision = false;

    for(int i=0;i<PLAYER_MAX_SHOOTS;i++)
    {
        bullet[i].setPos((Vector2){player.getX(),player.getY()});
        bullet[i].setSpeed(Vector2 {300,300});
        bullet[i].setRadius(10);
        bullet[i].isActive(false);
        bullet[i].setColor(WHITE);
        
    }





    //main game loop
    while (!WindowShouldClose())
    {
        // start render
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(Background, 0, 0, WHITE);

        // mouse tracking

        Vector2 mousePosition = GetMousePosition();
        float dx = mousePosition.x - player.getX();
        float dy = mousePosition.y - player.getY();
        float rotation = atan2f(dy, dx)+(PI/2);

        auto HpPercent=  (float)(player.getHp())/(float)player.getHpMax();


        //check if control key is down
        if (IsKeyDown(KEY_W) && player.getY() >player.getWidth())
        {
            player.setY(-1*player.getSpeedY()*GetFrameTime()) ;
        }
        if (IsKeyDown(KEY_A) && player.getX() >player.getWidth())
        {
            player.setX(-1*player.getSpeedX()*GetFrameTime());
        }
        if (IsKeyDown(KEY_S) && player.getY() < (float(GetScreenHeight())-player.getWidth()))
        {
            player.setY(player.getSpeedY()*GetFrameTime());
        }
        if (IsKeyDown(KEY_D) && player.getX() < (float(GetScreenWidth())-player.getWidth()))
        {
            player.setX(player.getSpeedX()*GetFrameTime()) ;

        }




        //shooting
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            for(int i=0;i<PLAYER_MAX_SHOOTS;i++)
            {
                if (!bullet[i].isActive())
                {
                    bullet[i].setPos((Vector2) {player.getX()+30, player.getY()+30});

                    bullet[i].isActive(true);
                    bullet[i].setTarget(mousePosition);
                    break;
                }
            }
        }


        for(int i=0;i<PLAYER_MAX_SHOOTS;i++)
        {
            if (bullet[i].isActive())
            {


                if(bullet[i].getX() > bullet[i].getTarget().x)
                {
                    bullet[i].setX(-1*(bullet[i].getSpeedX()+3)*GetFrameTime() );
                }
                if(bullet[i].getX() < bullet[i].getTarget().x)
                {
                    bullet[i].setX((bullet[i].getSpeedX()+3)*GetFrameTime() );
                }
                if(bullet[i].getY() >  bullet[i].getTarget().y)
                {
                    bullet[i].setY(-1*(bullet[i].getSpeedY()+3)*GetFrameTime() );
                }
                if(bullet[i].getY() < bullet[i].getTarget().y)
                {
                    bullet[i].setY((bullet[i].getSpeedY()+3)*GetFrameTime() );
                }

                //bullet[i].setX((bullet[i].getX()+3)*GetFrameTime());

                bullet[i].setLifeSpawn(bullet[i].getLifeSpawn()+1);

                if(bullet[i].getPos().x==bullet[i].getTarget().x && bullet[i].getPos().y==bullet[i].getTarget().y)
                {
                    bullet[i].setPos(Vector2{player.getX()+30,player.getY()+30});
                    bullet[i].setSpeed(Vector2{0,0});
                    bullet[i].setLifeSpawn(0);
                    bullet[i].isActive(false);
                }


                if(bullet[i].getX()>=800)
                {
                    bullet[i].setPos(Vector2{player.getX()+30,player.getY()+30});
                    bullet[i].setSpeed(Vector2{0,0});
                    bullet[i].setLifeSpawn(0);
                    bullet[i].isActive(false);
                }

                if(bullet[i].isActive())
                {
                    DrawCircleV(bullet[i].getPos(),bullet[i].getRadius(),WHITE);
                }

                //if(bullet[i].getLifeSpawn()>=80) {}

            }

        }




        //hp decrease and increase
        if (IsKeyPressed(KEY_UP) && player.getHp() < 100)
        {
            if(IsKeyPressed(KEY_UP) && player.getHp()>80)
            player.setHp(player.getHpMax());
            else
            player.setHp(player.getHp()+20);
        }
        if (IsKeyPressed(KEY_DOWN) && player.getHp() > 0)
        {
            player.setHp(player.getHp()-20) ;
        }

        //enemy movement
        if(player.getX() > monster.getX())
        {
          monster.setX(monster.getSpeedX()*GetFrameTime() );
        }
        if(player.getX() < monster.getX())
        {
          monster.setX(-1*monster.getSpeedX()*GetFrameTime() );
        }
        if(player.getY() > monster.getY())
        {
          monster.setY(monster.getSpeedY()*GetFrameTime() );
        }
        if(player.getY() < monster.getY())
        {
          monster.setY(-1*monster.getSpeedY()*GetFrameTime() );
        }

          collision = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),player.getWidth(),player.getHeight()},
          (Rectangle){monster.getX(),monster.getY(),monster.getWidth(),monster.getHeight()});
          if (collision)
          {
              if(player.getHp() > 0)
            player.setHp(player.getHp()-1);
          }





        DrawLine(0,GetScreenHeight()/2,GetScreenWidth(),GetScreenHeight()/2,BLACK);
        DrawLine(GetScreenWidth()/2,0,GetScreenWidth()/2,GetScreenHeight(),BLACK);

        DrawTexturePro(player.getTexture(),(Rectangle){0,0,frameWidth,frameHeight},
                       (Rectangle){player.getX(),player.getY(),player.getWidth(),player.getHeight()},
                       (Vector2){(float)player.getWidth()/2, (float)player.getHeight()/2},
                       rotation*RAD2DEG,
                       WHITE);

        DrawRectangle(monster.getX(), monster.getY(), monster.getWidth(), monster.getHeight(), BLACK); 
        DrawText("ENEMY", monster.getX(), monster.getY(), 40, WHITE);


        DrawRectangle(10, 10, 400, 30, BLACK);  
        DrawRectangle(14, 14, (392) * HpPercent, (22), RED);


        if(player.getHp()<=0)
        {
            DrawText("oh, you died(", 350, 400, 40, WHITE);
        }

        DrawText("AfterLife Test \nPress W A S D to move\nPress arrowup/arrowdown to increase/decrease HP value", 10, 50, 20, WHITE);
        DrawFPS(10, 140);

        EndDrawing(); // end render
    }

    // clear gpu
    UnloadTexture(Background);
    UnloadTexture(Character);


    //end
    CloseWindow();

    return 0;
}
