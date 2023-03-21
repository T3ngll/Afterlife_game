#pragma once
#include "raylib.h"
#include "object.h"
#include "movable.h"
#include <cmath>

class Character: public Object, public Movable
{
    Texture2D CharacterTexture;
    int hp;
    int hpMax;
    int ammo;
    int score;

public:
    Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hp, int hpMax, int ammo, int score);

    Texture2D getTexture();

    int getHp() const;
    void setHp(int hpNew);

    float getRotation();

    int getHpMax() const;

    int getAmmo() const;

    int getScore() const;
};




class Enemy: public Object, public Movable
{
    Texture2D FoeTexture;
public:
    Enemy(Texture2D FoeTexture, float width, float height, Vector2 speed):FoeTexture(FoeTexture), Object(pos,width,height), Movable(speed)
    {
        pos.x=float(GetScreenWidth() -700);
        pos.y=float(GetScreenHeight()) -100;
    };
    Texture2D getTexture(){return FoeTexture;}

    float getRotationToPlayer(Character player);
};









