#pragma once
#include "character.h"

class Enemy: public Object, public Movable
{
    Texture2D FoeTexture;
    int hp;
    int hpMax;
public:
    Enemy(Texture2D FoeTexture, float width, float height, Vector2 speed, int hp, int hpMax):FoeTexture(FoeTexture), Object(pos,width,height), Movable(speed), hp(hp), hpMax(hpMax)
    {
        pos.x=float(GetScreenWidth() -700);
        pos.y=float(GetScreenHeight()) -100;
    };
    Texture2D getTexture(){return FoeTexture;}

    float getRotationToPlayer(Character player);
    int getHp() const;
    void setHp(int hpNew);
    int getHpMax() const;
};