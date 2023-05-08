#include "character.h"
#include "projectiles.h"
#include "enemy.h"
#include "factory.h"
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <time.h>

#include "raylib.h"


using namespace std;


#define PLAYER_MAX_SHOOTS  20

//static Bullet bullet[PLAYER_MAX_SHOOTS];

vector<Bullet> bullets;
vector<Enemy*> enemies;
vector<Object*> heals;

Factory f;
typedef enum GameScreen { TITLE, GAMEPLAY, ENDING } GameScreen;



int main()
{

    srand(time(NULL));
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    //init window, set fps, set textures
    InitWindow(screenWidth,screenHeight, "Afterlife");

    SetTargetFPS(60);
    //SetWindowState(FLAG_VSYNC_HINT);
    Image background = LoadImage("resources/hall.png");
    Image character = LoadImage("resources/character.png");
    Image enemy = LoadImage("resources/character.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());

       
       
    Texture2D Background = LoadTextureFromImage(background);
    Texture2D Character = LoadTextureFromImage(character);
    Texture2D walker = LoadTextureFromImage(enemy);
    UnloadImage(background);
    UnloadImage(character);
    UnloadImage(enemy);


    int EnAmount=3;

    // init characters
    class Character player(Character,70,50,Vector2{200,200},100,20,0);
    Type type = Walker, Heal;
    for(int i=0; i<EnAmount; i++)
    {
    enemies.push_back(f.create(type,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},walker));
    }
    //heals.push_back(f.create(type,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));

    player.setFrameWidth(Character.width);
    player.setFrameHeight(Character.height);

   /* for(int i=0; i<2; i++)
    {
    auto monster = enemies[i];
    }
    */
    //auto aidkit = heals[0];

   //monster.setFrameWidth(Enemy.width);
   //monster.setFrameHeight(Enemy.height);

    bool collisionTakeDamage = false;
    bool collisionAttack = false;
    bool collisionObj = false;

    int frameCounter=0;
    int frameCounter2=0;
    GameScreen currentScreen = TITLE;

    //main game loop
    while (!WindowShouldClose())
    {
        switch(currentScreen)
        {
            case TITLE:
            {

                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        // start render
        BeginDrawing();

        ClearBackground(RAYWHITE);
        switch(currentScreen)
            {
                case GAMEPLAY:
                {
        DrawTexture(Background, 0, 0, WHITE);
        frameCounter++;

        //check if control key is down
        // --replace by switch
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


            if (bullets.size() < player.getMaxAmmo()) {


                Bullet temp;
                float dist = 0.002*sqrtf((player.getX()-GetMousePosition().x)*(player.getX()-GetMousePosition().x) +
                       (player.getY()-GetMousePosition().y)*(player.getY()-GetMousePosition().y));
               // float dist = 0.002* sqrtf((GetMousePosition().x-player.getX())*(GetMousePosition().x-player.getX())
                //        +(GetMousePosition().y-player.getY()*(GetMousePosition().y-player.getY())
                temp.setSpeed(Vector2 {(player.getX()-GetMousePosition().x)/dist,(player.getY()-GetMousePosition().y)/dist});
                temp.setRadius(10);
                temp.setStatus(true);
                temp.setDamage(34);
                temp.setPos((Vector2){player.getX(),player.getY()});
                temp.setColor(WHITE);
                temp.setTargetToMouse();
                bullets.push_back(temp);
                if(player.getCurAmmo()>0)
                {
                    player.setCurAmmo(player.getCurAmmo()-1);
                }

            }

        }
        if(player.getCurAmmo()==0)
        {
            bullets.clear();

        }

        for(auto bullet = bullets.begin(); bullet != bullets.end(); bullet++)
        {

                bullet->setX((-bullet->getSpeedX() ) * GetFrameTime() );

                bullet->setY((-bullet->getSpeedY() ) * GetFrameTime() );


            // add logic for collision


            if(bullet->getX() >= GetScreenWidth() || bullet->getX() <= 0 || bullet->getY() >= GetScreenHeight() || bullet->getY() <= 0) // check also y
            {

                //bullets.erase(bullet);
                continue;
            }

            if(bullet->isActive())
            {
                DrawCircleV(bullet->getPos(), bullet->getRadius(), WHITE);
            }
            else
            {
                bullet->setDamage(0);
            }


            //collision between bullet and a monster
                for(int i=0; i<EnAmount; i++)
    {
            if(enemies[i]->isActive())
        {
            collisionAttack=CheckCollisionCircleRec((Vector2){bullet->getPos()}, bullet->getRadius(),
          (Rectangle){enemies[i]->getX(),enemies[i]->getY(),enemies[i]->getWidth(),enemies[i]->getHeight()});
          if (collisionAttack)
          {
            enemies[i]->setHp(enemies[i]->getHp()-bullet->getDamage());
            if(enemies[i]->getHp()<=0)
            {
                enemies[i]->setStatus(false);
                player.setScore(player.getScore()+100);
                
            }
            bullet->setStatus(false);

          }
        }
    }
        

            /*if (i.isActive())
            {


                if(i.getX() > i.getTarget().x)
                {
                    i.setX(-1*(i.getSpeedX()+3)*GetFrameTime() );
                }
                if(i.getX() < i.getTarget().x)
                {
                    i.setX((i.getSpeedX()+3)*GetFrameTime() );
                }
                if(i.getY() >  i.getTarget().y)
                {
                    i.setY(-1*(i.getSpeedY()+3)*GetFrameTime() );
                }
                if(i.getY() < i.getTarget().y)
                {
                    i.setY((i.getSpeedY()+3)*GetFrameTime() );
                }

                //bullet[i].setX((bullet[i].getX()+3)*GetFrameTime());

                i.setLifeSpawn(i.getLifeSpawn()+1);

                if(i.getPos().x==i.getTarget().x && i.getPos().y==i.getTarget().y)
                {
                    i.setPos(Vector2{player.getX()+30,player.getY()+30});
                    i.setSpeed(Vector2{0,0});
                    i.setLifeSpawn(0);
                    i.isActive(false);
                }


                if(i.getX()>=800)
                {
                    i.setPos(Vector2{player.getX()+30,player.getY()+30});
                    i.setSpeed(Vector2{0,0});
                    i.setLifeSpawn(0);
                    i.isActive(false);
                }

                if(i.isActive())
                {
                    DrawCircleV(i.getPos(),i.getRadius(),WHITE);
                }

                //if(bullet[i].getLifeSpawn()>=80) {}

            }*/

        }


if (IsKeyPressed(KEY_KP_ADD))
{
    player.setCurAmmo(player.getCurAmmo()+20);
    player.setMaxAmmo(player.getCurAmmo());
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
        for(int i=0; i<EnAmount; i++)
    {
        if(enemies[i]->isActive())
        {
            if(player.getX() > enemies[i]->getX())
            {
            enemies[i]->setX(enemies[i]->getSpeedX()*GetFrameTime() );
            }
            if(player.getX() < enemies[i]->getX())
            {
            enemies[i]->setX(-1*enemies[i]->getSpeedX()*GetFrameTime() );
            }
            if(player.getY() > enemies[i]->getY())
            {
            enemies[i]->setY(enemies[i]->getSpeedY()*GetFrameTime() );
            }
            if(player.getY() < enemies[i]->getY())
            {
            enemies[i]->setY(-1*enemies[i]->getSpeedY()*GetFrameTime() );
            }
        }

            if(enemies[i]->isActive())
            {
          collisionTakeDamage = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
          (Rectangle){enemies[i]->getX(),enemies[i]->getY(),20.0f,20.0f});
        
          if (collisionTakeDamage)
          {
            if(frameCounter>60)
            {
            player.setHp(player.getHp()-20);
            frameCounter=0;
            }
          }
            }
    }

            /* if(aidkit->isActive())
            {
          collisionObj = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
          (Rectangle){aidkit->getX(),aidkit->getY(),20.0f,20.0f});
        
          if (collisionObj)
          {
            player.setHp(player.getHp()+50); 
          }
            }*/



        //DrawLine(0,GetScreenHeight()/2,GetScreenWidth(),GetScreenHeight()/2,BLACK);
       // DrawLine(GetScreenWidth()/2,0,GetScreenWidth()/2,GetScreenHeight(),BLACK);

        DrawTexturePro(player.getTexture(),(Rectangle){0,0,player.getFrameWidth(),player.getFrameHeight()},
                       (Rectangle){player.getX(),player.getY(),player.getWidth(),player.getHeight()},
                       (Vector2){(float)player.getWidth()/2, (float)player.getHeight()/2},
                       player.getRotation(),
                       WHITE);
        for(int i=0; i<EnAmount; i++)
    {
     if(enemies[i]->isActive())
     {
        DrawTexturePro(enemies[i]->getTexture(),(Rectangle){0,0,enemies[i]->getFrameWidth(),enemies[i]->getFrameHeight()},
                       (Rectangle){ enemies[i]->getX(),enemies[i]->getY(),enemies[i]->getWidth(),enemies[i]->getHeight()},
                       (Vector2){(float)enemies[i]->getWidth()/2, (float)enemies[i]->getHeight()/2},
                       enemies[i]->getRotationToPlayer(player),
                       RED);
     }
    }
    /*
     if(aidkit->isActive())
     {
         DrawRectangle(aidkit->getX(),aidkit->getY(),20,20, RED); 
     }*/

        //healthbar
       player.setHpPercent((float)(player.getHp())/(float)player.getHpMax());

        for(int i=0; i<EnAmount; i++)
    {
         enemies[i]->setHpPercent((float)(enemies[i]->getHp())/(float)enemies[i]->getHpMax());
    }
    

        DrawRectangle(10, 30, 400, 30, BLACK);  
        DrawRectangle(14, 34, 392.0f * player.getHpPercent(), (22), RED);
        //enemy hp
        for(int i=0; i<EnAmount; i++)
    {
        if(enemies[i]->isActive())
        {
             DrawRectangle(enemies[i]->getX()-90, enemies[i]->getY()-90, 200, 25, BLACK);  
             DrawRectangle(enemies[i]->getX()-86, enemies[i]->getY()-86, 192.0f * enemies[i]->getHpPercent(), (17), RED);
        }
    }
        if(player.getHp()<=0)
        {
            DrawText("YOU DIED", GetScreenWidth()/2-MeasureText("YOU DIED",200)/2, GetScreenHeight()/2, 200, RED);
        }
        DrawText(TextFormat("ammo: %i",player.getCurAmmo()),GetScreenWidth()/2, GetScreenHeight()/2, 50,BLACK);
        DrawText("AfterLife Test \nPress W A S D to move\nPress arrowup/arrowdown to increase/decrease HP value\nPress MouseLeft to shoot", 10, 80, 20, WHITE);
        DrawText(TextFormat("SCORE: %i", player.getScore()), 10, 200, 20, WHITE);
        DrawFPS(10, 230);
        } break;
        case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;

                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing(); // end render
    }

    // clear gpu
    UnloadTexture(Background);
    UnloadTexture(Character);
    UnloadTexture(walker);


    //end
    CloseWindow();

    return 0;
}
