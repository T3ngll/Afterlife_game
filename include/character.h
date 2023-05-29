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
    int maxAmmo;
    int curAmmo;
    int curAid;
    int score;
    float HpPercent;
    float HpMaxPercent=1;

public:
    Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hpMax, int maxAmmo, int score);

    Texture2D getTexture();

    int getHp() const;
    void setHp(int hpNew);

    float getRotation();

    int getHpMax() const;
    void setHpMax(int hpMaxNew);

    int getMaxAmmo() const;
    void setMaxAmmo(int ammo);

    int getCurAmmo() const;
    void setCurAmmo(int ammo);

    int getCurAid() const;
    void setCurAid(int aid);


    int getScore() const;
    void setScore(int scoreNew);

      void setHpPercent(float hpPercentNew);
    float getHpPercent() const;

    void setHpMaxPercent(float hpMaxPercentNew);
    float getHpMaxPercent() const;
};














