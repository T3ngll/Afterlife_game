#pragma once
#include "object.h"
#include "movable.h"

class Bullet : public Object,public Movable
{
    Color color;
    int lifeSpawn;
    float radius;
    Vector2 target;
public:
    Bullet()= default;
    Bullet(Vector2 pos,Vector2 speed, bool active,int lifeSpawn,float radius,Color color);

    int getLifeSpawn();
    void setLifeSpawn(int life);

    void setRadius(float rad);
    float getRadius();

    void setColor(Color color);

    void setTargetToMouse();
    Vector2 getTarget();
};