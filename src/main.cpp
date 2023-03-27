#include "character.h"
#include "projectiles.h"
#include "enemy.h"
#include "enfactory.h"

#include <cmath>
#include <vector>

#include "raylib.h"


using namespace std;


#define PLAYER_MAX_SHOOTS  20

//static Bullet bullet[PLAYER_MAX_SHOOTS];

vector<Bullet> bullets;
vector<Enemy*> enemies;

Factory f;



int main()
{

    //init window, set fps, set textures
    InitWindow(1920,1080, "Afterlife");

    SetTargetFPS(60);
    //SetWindowState(FLAG_VSYNC_HINT);
    Image background = LoadImage("resources/hall.png");
    Image character = LoadImage("resources/character.png");
    //Image enemy = LoadImage("resources/character.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    Image enemy = LoadImage("resources/character.png");
       
       
    Texture2D Background = LoadTextureFromImage(background);
    Texture2D Character = LoadTextureFromImage(character);
    auto walker = LoadTextureFromImage(enemy);
    UnloadImage(background);
    UnloadImage(character);
    UnloadImage(enemy);


    
    // init characters
    class Character player(Character,70,50,Vector2{200,200},100,20,0);
    Type type = Walker;
    enemies.push_back(f.create(type,Vector2{100,100},walker));
    //class Enemy monster(Enemy,140,140,Vector2{100,100},100);

    player.setFrameWidth(Character.width);
    player.setFrameHeight(Character.height);

    auto monster = enemies[0];

   //monster.setFrameWidth(Enemy.width);
   //monster.setFrameHeight(Enemy.height);

    bool collisionTakeDamage = false;
    bool collisionAttack = false;

    int frameCounter=0;
    int frameCounter2=0;


    //main game loop
    while (!WindowShouldClose())
    {
        // start render
        BeginDrawing();

        ClearBackground(RAYWHITE);
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


            if (bullets.size() < PLAYER_MAX_SHOOTS) {


                Bullet temp;
                float dist = 0.002*sqrtf((player.getX()-GetMousePosition().x)*(player.getX()-GetMousePosition().x) +
                       (player.getY()-GetMousePosition().y)*(player.getY()-GetMousePosition().y));
               // float dist = 0.002* sqrtf((GetMousePosition().x-player.getX())*(GetMousePosition().x-player.getX())
                //        +(GetMousePosition().y-player.getY()*(GetMousePosition().y-player.getY())
                temp.setSpeed(Vector2 {(player.getX()-GetMousePosition().x)/dist,(player.getY()-GetMousePosition().y)/dist});
                temp.setRadius(10);
                temp.setActive(false);
                temp.setPos((Vector2){player.getX(),player.getY()});
                temp.setColor(WHITE);
                temp.setTargetToMouse();
                bullets.push_back(temp);
            }

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


            DrawCircleV(bullet->getPos(), bullet->getRadius(), WHITE);

            //collision between bullet and a monster
            if(monster->isActive())
        {
            collisionAttack=CheckCollisionCircleRec((Vector2){bullet->getPos()}, bullet->getRadius(),
          (Rectangle){monster->getX(),monster->getY(),monster->getWidth(),monster->getHeight()});
          if (collisionAttack)
          {
            monster->setHp(monster->getHp()-2);
            if(monster->getHp()<=0)
            {
                monster->setActive(false);
                player.setScore(player.getScore()+100);
                
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
        if(monster->isActive())
        {
            if(player.getX() > monster->getX())
            {
            monster->setX(monster->getSpeedX()*GetFrameTime() );
            }
            if(player.getX() < monster->getX())
            {
            monster->setX(-1*monster->getSpeedX()*GetFrameTime() );
            }
            if(player.getY() > monster->getY())
            {
            monster->setY(monster->getSpeedY()*GetFrameTime() );
            }
            if(player.getY() < monster->getY())
            {
            monster->setY(-1*monster->getSpeedY()*GetFrameTime() );
            }
        }

            if(monster->isActive())
            {
          collisionTakeDamage = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
          (Rectangle){monster->getX(),monster->getY(),20.0f,20.0f});
        
          if (collisionTakeDamage)
          {
            if(frameCounter>60)
            {
            player.setHp(player.getHp()-20);
            frameCounter=0;
            }
          }
            }



        DrawLine(0,GetScreenHeight()/2,GetScreenWidth(),GetScreenHeight()/2,BLACK);
        DrawLine(GetScreenWidth()/2,0,GetScreenWidth()/2,GetScreenHeight(),BLACK);

        DrawTexturePro(player.getTexture(),(Rectangle){0,0,player.getFrameWidth(),player.getFrameHeight()},
                       (Rectangle){player.getX(),player.getY(),player.getWidth(),player.getHeight()},
                       (Vector2){(float)player.getWidth()/2, (float)player.getHeight()/2},
                       player.getRotation(),
                       WHITE);

     if(monster->isActive())
     {
        DrawTexturePro(monster->getTexture(),(Rectangle){0,0,monster->getFrameWidth(),monster->getFrameHeight()},
                       (Rectangle){ monster->getX(),monster->getY(),monster->getWidth(),monster->getHeight()},
                       (Vector2){(float)monster->getWidth()/2, (float)monster->getHeight()/2},
                       monster->getRotationToPlayer(player),
                       RED);
     }

        //healthbar
        auto HpPercent=  (float)(player.getHp())/(float)player.getHpMax();
        auto HpPercent2=  (float)(monster->getHp())/(float)monster->getHpMax();

        DrawRectangle(10, 30, 400, 30, BLACK);  
        DrawRectangle(14, 34, 392.0f * HpPercent, (22), RED);
        //enemy hp
        if(monster->isActive())
        {
             DrawRectangle(monster->getX()-90, monster->getY()-90, 200, 25, BLACK);  
             DrawRectangle(monster->getX()-86, monster->getY()-86, 192.0f * HpPercent2, (17), RED);
        }

        if(player.getHp()<=0)
        {
            DrawText("oh, you died(", 350, 400, 40, WHITE);
        }

        DrawText("AfterLife Test \nPress W A S D to move\nPress arrowup/arrowdown to increase/decrease HP value\nPress MouseLeft to shoot", 10, 80, 20, WHITE);
        DrawText(TextFormat("SCORE: %i", player.getScore()), 10, 200, 20, WHITE);
        DrawFPS(10, 230);

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
