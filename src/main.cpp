#include <iostream>

#include "character.h"
#include "projectiles.h"
#include "enemy.h"
#include "factory.h"
#include "preload.h"

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
vector<Object*> treasure;

Factory f;
typedef enum GameScreen { TITLE, GAMEPLAY, ENDING } GameScreen;

int main()
{
    srand(time(NULL));
    Init();

    Preload p;

    int randomchoose=GetRandomValue(1, 3);
    int minenemy=1;
    int maxenemy=5;
    int scoregoal=500;
    int RandomEnemy=GetRandomValue(minenemy, maxenemy);
    int EnAmount=RandomEnemy;
    int HealAmount=GetRandomValue(0, 1);
    int AmmoKitAmount=GetRandomValue(1, 3);
    int TreasureAmount=GetRandomValue(1, 3);
    // init characters
    class Character player(p.getCharacter(),70,50,Vector2{200,200},100,20,0);

    Type type1 = Collect;
    Type type2 = Walker;
    Type type3 = Fatboy;
    Type type4 = Runner;



    for(int i=0; i<EnAmount; i++)
    {
        if(randomchoose==1)
        enemies.push_back(f.create(type2,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
        else if(randomchoose==2)
        enemies.push_back(f.create(type3,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
        else if(randomchoose==3)
        enemies.push_back(f.create(type4,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
    }
    for(int i=0; i<HealAmount; i++)
    {
        heals.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    for(int i=0; i<AmmoKitAmount; i++)
    {
        ammokits.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    for(int i=0; i<TreasureAmount; i++)
    {
        treasure.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    player.setFrameWidth(p.getCharacter().width);
    player.setFrameHeight(p.getCharacter().height);



    bool collisionTakeDamage = false;
    bool collisionAttack = false;
    bool collisionAttackMelee = false;
    bool collisionObj = false;
    bool collisionDoor = false;
    bool LevelUp=false;
    bool Clear=false;

    int frameCounter=0;
    int frameCounter2=0;
    int frameCounter3=0;
    int sourceWidth=0;
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
                         for(int i=0; i<TreasureAmount; i++)
                      {
                             treasure[i]->setStatus(false);
                        }
                        }
                    DrawTexture(p.getBackground(), 0, 0, WHITE);
                   // ClearBackground(WHITE);
                   // DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                   if(scoregoal<player.getScore())
                   {
                    scoregoal=scoregoal+2000;
                    minenemy=minenemy+2;
                    maxenemy=maxenemy+2; 
                    RandomEnemy=GetRandomValue(minenemy, maxenemy);
                   }
                     EnAmount=EnAmount+RandomEnemy;
                     HealAmount=HealAmount+(GetRandomValue(0, 1));
                     AmmoKitAmount=AmmoKitAmount+(GetRandomValue(1, 3));
                     TreasureAmount=TreasureAmount+(GetRandomValue(1, 3));
                      player.setPos(Vector2{(float)GetScreenWidth()/2, (float)GetScreenHeight()-10});
                      for(int i=0; i<EnAmount; i++)
    {
   int randomchoose=GetRandomValue(1, 3);
        if(randomchoose==1)
        enemies.push_back(f.create(type2,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
        else if(randomchoose==2)
        enemies.push_back(f.create(type3,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
        else if(randomchoose==3)
        enemies.push_back(f.create(type4,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))},p.getWalker()));
    }
    for(int i=0; i<HealAmount; i++)
    {
    heals.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    for(int i=0; i<AmmoKitAmount; i++)
    {
    ammokits.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
    for(int i=0; i<TreasureAmount; i++)
    {
    treasure.push_back(f.create(type1,Vector2{float(GetRandomValue(0, 1900)),float(GetRandomValue(0, 1000))}));
    }
                    }
                }
            } break;
            case ENDING:
            {
                
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
                frameCounter3++;

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

                 for(int i=0; i<TreasureAmount; i++)
                {
                    if(treasure[i]->isActive())
                    {
                        DrawTextureV(p.getGold(), (Vector2){treasure[i]->getX(),treasure[i]->getY()}, WHITE);
                        collisionObj = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
                                                          (Rectangle){treasure[i]->getX(),treasure[i]->getY(),205,125});

                        if (collisionObj)
                        {
                            treasure[i]->setStatus(false);
                            PlaySound(p.getCollectSound());
                            player.setScore(player.getScore()+100);
                        }
                    }
                }

                for(int i=0; i<AmmoKitAmount; i++)
                {
                    if(ammokits[i]->isActive())
                    {
                         DrawTextureV(p.getAmmo(), (Vector2){ammokits[i]->getX(),ammokits[i]->getY()}, WHITE);
                        collisionObj = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
                                                          (Rectangle){ammokits[i]->getX(),ammokits[i]->getY(),85,65});

                        if (collisionObj)
                        {
                            ammokits[i]->setStatus(false);
                            PlaySound(p.getCollectSound());
                            player.setCurAmmo(player.getCurAmmo()+4);
                        }
                    }
                }
                
                for(int i=0; i<HealAmount; i++)
                {
                    if(heals[i]->isActive())
                    {
                         DrawTextureV(p.getAid(), (Vector2){heals[i]->getX(),heals[i]->getY()}, WHITE);
                        collisionObj = CheckCollisionRecs((Rectangle){player.getX(),player.getY(),(float)player.getWidth(),(float)player.getHeight()},
                                                          (Rectangle){heals[i]->getX(),heals[i]->getY(),85,85});

                        if (collisionObj)
                        {
                            heals[i]->setStatus(false);
                            PlaySound(p.getCollectSound());
                            player.setCurAid(player.getCurAid()+1);
                        }
                    }
                }



                //shooting
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    if(player.getCurAmmo()>0)
                    {
                        sourceWidth=0+p.getCharacter().width/3;
                    }

                   // player.setFrameWidth(player.getFrameWidth()+p.getCharacter().width/3);

                    if (player.getCurAmmo() != 0) {

                        //if (bullets.size() < player.getMaxAmmo()) {


                        float dist = 0.002*sqrtf((player.getX()-GetMousePosition().x)*(player.getX()-GetMousePosition().x) +
                                                 (player.getY()-GetMousePosition().y)*(player.getY()-GetMousePosition().y));
                        Bullet temp(p.getBullet(),(Vector2){player.getX()+10,player.getY()},Vector2 {(player.getX()-GetMousePosition().x)/dist,(player.getY()-GetMousePosition().y)/dist},true,10,WHITE);
                        temp.setDamage(34);
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
                    //DrawCircleV(bullet->getPos(), bullet->getRadius(), WHITE);
                    DrawTextureV(p.getBullet(),bullet->getPos(),WHITE);



                    //collision between bullet and a monster
                    for(int i=0; i<EnAmount; i++)
                    {
                        if(enemies[i]->isActive())
                        {
                            collisionAttack=CheckCollisionCircles((Vector2){bullet->getPos()}, bullet->getRadius(),
                                                                    (Vector2){enemies[i]->getPos()},(enemies[i]->getHeight()-((enemies[i]->getHeight()/100)*60)));
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


                //melee attack
                if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && frameCounter3>30)
                {
                    frameCounter3=0;
                    DrawCircleV(player.getPos(), 70, WHITE);
                    for(int i=0; i<EnAmount; i++)
                    {
                        if(enemies[i]->isActive())
                        {
                    collisionAttackMelee=CheckCollisionCircles((Vector2){player.getX(), player.getY()}, 70,
                                                                    (Vector2){enemies[i]->getPos()},(enemies[i]->getHeight()-((enemies[i]->getHeight()/100)*43)));
                    if(collisionAttackMelee)
                            {
                    PlaySound(p.getMeleeSound());
                    enemies[i]->setHp(enemies[i]->getHp()-20);
                    if(enemies[i]->getHp()<=0)
                                {
                                    enemies[i]->setStatus(false);
                                    PlaySound(p.getKillSound());
                                    player.setScore(player.getScore()+100);

                                }
                            }
                        }
                         else
                            PlaySound(p.getMelee2Sound());
                    }
                }


                if (IsKeyPressed(KEY_KP_ADD))
                {
                    player.setCurAmmo(player.getCurAmmo()+20);
                    player.setMaxAmmo(player.getCurAmmo());
                }

                //aidkit use
                if (IsKeyPressed(KEY_E) && player.getHp() < player.getHpMax() && player.getCurAid()!=0)
                {
                    if(player.getHp()>(player.getHpMax()-50))
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
                if (IsKeyPressed(KEY_UP) && player.getHp() < player.getHpMax())
                {
                    if(IsKeyPressed(KEY_UP) && player.getHp()>(player.getHpMax()-20))
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
                        collisionTakeDamage = CheckCollisionCircles((Vector2){player.getPos()},player.getHeight()-60,
                                                                 (Vector2){enemies[i]->getPos()},(enemies[i]->getHeight()-((enemies[i]->getHeight()/100)*43)));

                        if (collisionTakeDamage)
                        {
                            if(frameCounter>60)
                            {
                                PlaySound(p.getDamageSound());
                                player.setHp(player.getHp()-enemies[i]->getDamage());
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
     if(heals[i]->isActive())
         {
            Clear=false;
            break;
         } 
    }
    for(int i=0; i<AmmoKitAmount; i++)
    {
     if(ammokits[i]->isActive())
         {
            Clear=false;
            break;
         } 
    }
         for(int i=0; i<TreasureAmount; i++)
    {
     if(treasure[i]->isActive())
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
                     

                DrawTexturePro(player.getTexture(),(Rectangle){(float)sourceWidth,0,player.getFrameWidth()/3,player.getFrameHeight()},
                               (Rectangle){player.getX()+20,player.getY(),player.getWidth(),player.getHeight()},
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


                //healthbar
                player.setHpPercent((float)(player.getHp())/(float)player.getHpMax());

                for(int i=0; i<EnAmount; i++)
                {
                    enemies[i]->setHpPercent((float)(enemies[i]->getHp())/(float)enemies[i]->getHpMax());
                }


                DrawRectangle(10, 30, 400.0f * player.getHpMaxPercent() , 30, BLACK);
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
                DrawText("PRESS Esc to Close Game", 120, 220, 20, WHITE);

            } break;
            default: break;
        }


        sourceWidth=0;

        EndDrawing(); // end render
    }

    // clear gpu



    //end
    CloseWindow();

    return 0;
}
