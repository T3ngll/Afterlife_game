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
    int maxGren;
    int curAmmo;
    int curGren;
    int curAid;
    int score;
    float HpPercent;
    float HpMaxPercent=1;

public:
    Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hpMax, int maxAmmo,int maxGren, int score);

    Texture2D getTexture();

    int getHp() const;
    void setHp(int hpNew);

    float getRotation();

    int getHpMax() const;
    void setHpMax(int hpMaxNew);

    int getMaxAmmo() const;
    void setMaxAmmo(int ammo);

    int getMaxGren() const;
    void setMaxGren(int ammo);

    int getCurAmmo() const;
    void setCurAmmo(int ammo);

    int getCurGren() const;
    void setCurGren(int ammo);

    int getCurAid() const;
    void setCurAid(int aid);


    int getScore() const;
    void setScore(int scoreNew);

      void setHpPercent(float hpPercentNew);
    float getHpPercent() const;

    void setHpMaxPercent(float hpMaxPercentNew);
    float getHpMaxPercent() const;
};














