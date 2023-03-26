#pragma once
#include "character.h"

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