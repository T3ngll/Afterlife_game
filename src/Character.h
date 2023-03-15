#pragma once
#include "raylib.h"

class Object{
protected:
    Vector2 pos{};
    float width;
    float height;
public:
    Object(float x,float y, float width, float height):width(width),height(height)
    {
        pos.x=x;
        pos.y=y;
    };

    float getX() const {return pos.x;}
    void setX(float x) {pos.x+=x;}
    float getY() const {return pos.y;}
    void setY(float y) {pos.y+=y;}

    float getHeight() const {return height;}
    float getWidth() const {return width;}
};

class Movable{
protected:
    float speedX;
    float speedY;
public:
    Movable( float speedX, float speedY): speedX(speedX),speedY(speedY) {};

    float getSpeedX() const {return speedX;}
    float getSpeedY() const {return speedY;}
};


class Character: public Object, public Movable
{
    int health;
    int ammo;
public:
    Character(float width, float height, float speedX, float speedY, int health, int ammo): Object(0,0,width,height),
                                                                                                Movable(speedX,speedY),health(health),ammo(ammo)
    {
        pos.x=float(GetScreenWidth()) / 2 -width/2;
        pos.y=float(GetScreenHeight()) / 2 -height/2;
    };



    int getHealth() const {return health;}
    int getAmmo() const{return ammo;}



};









