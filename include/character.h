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
    float HpPercent;

public:
    Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hpMax, int ammo, int score);

    Texture2D getTexture();

    int getHp() const;
    void setHp(int hpNew);

    float getRotation();

    int getHpMax() const;

    int getAmmo() const;

    int getScore() const;
    void setScore(int scoreNew);

      void setHpPercent(float hpPercentNew);
    float getHpPercent() const;
};














