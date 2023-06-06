#pragma once
#include "object.h"
#include "movable.h"

class Bullet : public Object,public Movable
{
    Texture2D BulletTexture;
    Color color;
    float radius;
    Vector2 target;
    int damage=5;
public:
    Bullet() = default;
    Bullet(Texture2D BulletTexture, Vector2 pos,Vector2 speed, bool active,float radius,Color color);

    Texture2D getTexture();

    bool operator==(const Bullet& toCompare);
    float getRotation();
    int getDamage();
    void setDamage(int damage);

    void setRadius(float rad);
    float getRadius();

    void setColor(Color color);

    void setTargetToMouse();
    Vector2 getTarget();
};



class Grenade : public Object,public Movable
{
    Texture2D GrenadeTexture;
    Color color;
    float radius;
    Vector2 target;
    int damage=5;
public:
    Grenade() = default;
    Grenade(Texture2D GrenadeTexture, Vector2 pos,Vector2 speed, bool active,float radius,Color color);

    Texture2D getTexture();

    bool operator==(const Grenade& toCompare);
    float getRotation();
    int getDamage();
    void setDamage(int damage);

    void setRadius(float rad);
    float getRadius();

    void setColor(Color color);

    void setTargetToMouse();
    Vector2 getTarget();
};