#pragma once
#include "character.h"



class Enemy: public Object, public Movable
{
    Texture2D FoeTexture;
    int hp;
    int hpMax;
public:
    Enemy(Texture2D FoeTexture, float width, float height, Vector2 speed, int hpMax):FoeTexture(FoeTexture), Object(pos,width,height), Movable(speed), hpMax(hpMax)
    {
        float randomX=GetRandomValue(100, 1800);
        float randomY=GetRandomValue(100, 1000);
        pos.x=float(randomX);
        pos.y=float(randomY);

        hp = hpMax;
    };
    Texture2D getTexture(){return FoeTexture;}

    float getRotationToPlayer(Character player);
    int getHp() const;
    void setHp(int hpNew);
    int getHpMax() const;
};