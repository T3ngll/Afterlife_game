#include <iostream>

#include "character.h"
#include "projectiles.h"
#include "enemy.h"
#include "factory.h"
#include "preload.h"
#include "game.h"

#include <stdlib.h>
#include <cmath>
#include <vector>
#include <time.h>
#include <algorithm>

#include "raylib.h"


using namespace std;

void Init()
{
    srand(time(NULL));
    //init window, set fps, set textures
    InitWindow(1920,1080, "Afterlife");
    ToggleFullscreen();
    SetTargetFPS(60);

    InitAudioDevice();



}
vector<Bullet> bullets;
vector<Bullet> bulletsToDelete;

vector<Enemy*> enemies;
vector<Object*> heals;
vector<Object*> ammokits;

Factory f;
typedef enum GameScreen { TITLE, GAMEPLAY, ENDING } GameScreen;
const int screenWidth = 1920;
const int screenHeight = 1080;


int main()
{
    srand(time(NULL));
    Init();

    Preload p;

   int EnAmount=GetRandomValue(0, 10);
    int HealAmount=GetRandomValue(0, 2);
    int AmmoKitAmount=GetRandomValue(1, 6);
    // init characters
    class Character player(p.getCharacter(),70,50,Vector2{200,200},100,20,0);
    Type type1 = Walker;
    Type type2 = Collect;
    for(int i=0; i<EnAmount; i++)
    {
        enemies.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
    }
    for(int i=0; i<HealAmount; i++)
    {
        heals.push_back(f.create(type2,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    for(int i=0; i<AmmoKitAmount; i++)
    {
        ammokits.push_back(f.create(type2,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    player.setFrameWidth(p.getCharacter().width);
    player.setFrameHeight(p.getCharacter().height);



    bool collisionTakeDamage = false;
    bool collisionAttack = false;
    bool collisionObj = false;
    bool collisionDoor = false;
     bool Clear=false;

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
               if (player.getHp()<=0)
                {
                    currentScreen = ENDING;
                }
                else if(collisionDoor)
                {
                    frameCounter=0;
                    if(frameCounter==0)
                    {
                        if(Clear)
                        {
                     for(int i=0; i<EnAmount; i++) 
                          {
                             enemies[i]->setStatus(false);
                              }
                    for(int i=0; i<HealAmount; i++)
                      {
                             heals[i]->setStatus(false);
                         }
                    for(int i=0; i<AmmoKitAmount; i++)
                      {
                             ammokits[i]->setStatus(false);
                        }
                        }
                    DrawTexture(p.getBackground(), 0, 0, WHITE);
                   // ClearBackground(WHITE);
                   // DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                     EnAmount=EnAmount+(GetRandomValue(0, 10));
                     HealAmount=HealAmount+(GetRandomValue(0, 2));
                     AmmoKitAmount=AmmoKitAmount+(GetRandomValue(1, 6));
                      player.setPos(Vector2{GetScreenWidth()/2, GetScreenHeight()-10});
                      for(int i=0; i<EnAmount; i++)
    {
    enemies.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
    }
    for(int i=0; i<HealAmount; i++)
    {
    heals.push_back(f.create(type2,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    for(int i=0; i<AmmoKitAmount; i++)
    {
    ammokits.push_back(f.create(type2,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
                    }
                }
            } break;
            case ENDING:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    CloseWindow();

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
                DrawTexture(p.getBackground(), 0, 0, WHITE);
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

                    if (player.getCurAmmo() != 0) {

                        //if (bullets.size() < player.getMaxAmmo()) {

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
                        //if(player.getCurAmmo()>0)
                        {
                            PlaySound(p.getShootSound());
                            player.setCurAmmo(player.getCurAmmo()-1);
                        }

                    }
                    else
                        PlaySound(p.getEmptyAmmoSound());

                }

                for(auto bullet = bullets.begin(); bullet != bullets.end(); bullet++)
                {

                    bullet->setX((-bullet->getSpeedX() ) * GetFrameTime() );

                    bullet->setY((-bullet->getSpeedY() ) * GetFrameTime() );

                    if(bullet->getX() >= GetScreenWidth() || bullet->getX() <= 0 || bullet->getY() >= GetScreenHeight() || bullet->getY() <= 0) // check also y
                    {
                        bulletsToDelete.push_back(*bullet);
                        continue;
                    }

                    DrawCircleV(bullet->getPos(), bullet->getRadius(), WHITE);

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
                                    PlaySound(p.getKillSound());
                                    player.setScore(player.getScore()+100);

                                }

                                bulletsToDelete.push_back(*bullet);

                            }
                        }
                    }
                }


                if (IsKeyPressed(KEY_KP_ADD))
                {
                    player.setCurAmmo(player.getCurAmmo()+20);
                    player.setMaxAmmo(player.getCurAmmo());
                }

                //aidkit use
                if (IsKeyPressed(KEY_E) && player.getHp() < 100 && player.getCurAid()!=0)
                {
                    if(player.getHp()>50)
                    {
                        PlaySound(p.getHealSound());
                        player.setCurAid(player.getCurAid()-1);
                        player.setHp(player.getHpMax());
                    }
                    else
                    {
                        PlaySound(p.getHealSound());
                        player.setCurAid(player.getCurAid()-1);
                        player.setHp(player.getHp()+50);
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
                                PlaySound(p.getDamageSound());
                                player.setHp(player.getHp()-20);
                                frameCounter=0;
                            }
                        }
                    }
                }

                for (auto & it : bulletsToDelete) {
                    auto found = std::find(bullets.begin(), bullets.end(), it);
                    if (found != bullets.end()) {
                        bullets.erase(found);
                    }
                }

                bulletsToDelete.clear();


                for(int i=0; i<HealAmount; i++)
                {
                    if(heals[i]->isActive())
                    {
                        collisionObj = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
                                                          (Rectangle){heals[i]->getX(),heals[i]->getY(),110,110});

                        if (collisionObj)
                        {
                            heals[i]->setStatus(false);
                            PlaySound(p.getCollectSound());
                            player.setCurAid(player.getCurAid()+1);
                        }
                    }
                }

                for(int i=0; i<AmmoKitAmount; i++)
                {
                    if(ammokits[i]->isActive())
                    {
                        collisionObj = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
                                                          (Rectangle){ammokits[i]->getX(),ammokits[i]->getY(),110,110});

                        if (collisionObj)
                        {
                            ammokits[i]->setStatus(false);
                            PlaySound(p.getCollectSound());
                            player.setCurAmmo(player.getCurAmmo()+10);
                        }
                    }
                }

while(true)
    {
        for(int i=0; i<EnAmount; i++)
    {
        if(enemies[i]->isActive())
         {
            Clear=false;
            break;
         } 
    }
    for(int i=0; i<HealAmount; i++)
    {
     if(enemies[i]->isActive())
         {
            Clear=false;
            break;
         } 
    }
    for(int i=0; i<AmmoKitAmount; i++)
    {
     if(enemies[i]->isActive())
         {
            Clear=false;
            break;
         } 
    }
    Clear=true;
    break;
    }
                
                   //door
                    collisionDoor = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
                     (Rectangle){(float)GetScreenWidth()/2-150,0,300,100});
                     DrawRectangle(GetScreenWidth()/2-150,0,300,100, BROWN);
    

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

                //aidkits
                for(int i=0; i<HealAmount; i++)
                {
                    if(heals[i]->isActive())
                    {
                        DrawRectangle(heals[i]->getX(),heals[i]->getY(),100,100, RED);
                    }
                }

                //ammokits
                for(int i=0; i<AmmoKitAmount; i++)
                {
                    if(ammokits[i]->isActive())
                    {
                        DrawRectangle(ammokits[i]->getX(),ammokits[i]->getY(),100,100, DARKBROWN);
                    }
                }

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
                DrawText(TextFormat("AMMO: %i",player.getCurAmmo()), 10, 980, 30, WHITE);
                DrawText(TextFormat("AIDKITS: %i",player.getCurAid()), 10, 1010, 30, WHITE);
                DrawText("AfterLife Test \nPress W A S D to move\nPress arrowup/arrowdown to increase/decrease HP value \nPress MouseLeft to shoot \nPress E to heal", 10, 80, 20, WHITE);
                DrawText(TextFormat("SCORE: %i", player.getScore()), 10, 1040, 30, WHITE);
                DrawFPS(GetScreenWidth()-90, 10);
            } break;
            case TITLE:
            {
                // TITLE screen
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
                DrawText("AfterLife", GetScreenWidth()/2, GetScreenHeight()/2, 100, BLACK);
                DrawText("PRESS ENTER to Gameplay Screen", 120, 220, 20, BLACK);

            } break;

            case ENDING:
            {
                // ENDING screen
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
                DrawText("Game Over", GetScreenWidth()/2, GetScreenHeight()/2, 100, WHITE);
                DrawText("PRESS ENTER to Close Game", 120, 220, 20, WHITE);

            } break;
            default: break;
        }

        EndDrawing(); // end render
    }

    // clear gpu



    //end
    CloseWindow();

    return 0;
}
