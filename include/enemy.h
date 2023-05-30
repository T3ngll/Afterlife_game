#pragma once
#include "character.h"



class Enemy: public Object, public Movable
{
    Texture2D FoeTexture;
    int hp;
    int hpMax;
    int damage;
    int score;
    float HpPercent;
public:
    Enemy(Texture2D FoeTexture, float width, float height,Vector2 pos, Vector2 speed, int hpMax, int damage, int score):FoeTexture(FoeTexture), Object(pos,width,height), Movable(speed), hpMax(hpMax), damage(damage), score(score)
    {
        hp = hpMax;
    };
    Texture2D getTexture(){return FoeTexture;}

    float getRotationToPlayer(Character player);
    int getHp() const;
    void setHp(int hpNew);
    int getHpMax() const;
    void setHpPercent(float hpPercentNew);
    float getHpPercent() const;
    void setDamage(int damagenew);
    int getDamage() const;
     void setScore(int scorenew);
    int getScore() const;
};