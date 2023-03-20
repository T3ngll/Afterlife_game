#pragma once
#include "raylib.h"

class Object{
protected:
    float x = 0;
    float y = 0;
    Vector2 pos{x,y};
    float width;
    float height;
    bool active;
public:
    Object() = default;
    Object(Vector2 pos, float width, float height): pos(pos),width(width),height(height),active(true){};

    Vector2 getPos() const{return pos;}
    void setPos(Vector2 posNew) {pos=posNew;}

    float getX() const {return pos.x;}
    void setX(float xNew) {pos.x+=xNew;}

    float getY() const {return pos.y;}
    void setY(float yNew) {pos.y+=yNew;}

    float getHeight() const {return height;}
    float getWidth() const {return width;}

    bool isActive() const{return active;}
    void isActive(bool isActive){active=isActive;}
};

class Movable{
protected:
    float speedX;
    float speedY;
    Vector2 speed{speedX,speedY};
public:
    Movable()= default;
    Movable(Vector2 speed): speed(speed){};
    Vector2 getSpeed(){return speed;}
    float getSpeedX() const {return speed.x;}
    float getSpeedY() const {return speed.y;}

    void setSpeed(Vector2 speed2){speed=speed2;}
    void setSpeedX(float speed)  {speedX=speed;}
    void setSpeedY(float speed)  {speedY=speed;}
};


class Character: public Object, public Movable
{
    Texture2D CharacterTexture;
    int hp;
    int hpMax;
    int ammo;
    int score;

public:
    Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hp, int hpMax, int ammo, int score): CharacterTexture(CharacterTexture), Object(pos,width,height),
                                                                                                Movable(speed),hp(hp), hpMax(hpMax), ammo(ammo),score(score)
    {
        pos.x=float(GetScreenWidth()) / 2 ;
        pos.y=float(GetScreenHeight()) / 2 ;
    };

    Texture2D getTexture(){return CharacterTexture;}
    //void setTexture(Texture2D Texture){CharacterTexture=Texture;}

    int getHp() const {return hp;}
    void setHp(int hpNew) {hp=hpNew;}
    int getHpMax() const {return hpMax;}
    int getAmmo() const{return ammo;}
    int getScore() const{return score;}
};

class Bullet : public Object,public Movable
{
Color color;
int lifeSpawn;
float radius;
Vector2 target;
public:
    Bullet()= default;
    Bullet(Vector2 pos,Vector2 speed,bool active,int lifeSpawn,float radius,Color color): Object(pos,0,0), Movable(speed),lifeSpawn(lifeSpawn),radius(radius),color(color){};

    int getLifeSpawn(){return lifeSpawn;}
    void setLifeSpawn(int life){lifeSpawn=life;}

    void setRadius(float rad){radius=rad;}
    float getRadius(){return radius;}

    void setColor(Color color){this->color=color;}

    void setTarget(Vector2 target){this->target=target;}\
    Vector2 getTarget() {return target;}
};


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
};









