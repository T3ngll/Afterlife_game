#pragma once
#include "raylib.h"

class Object{
protected:
    float x = 0;
    float y = 0;
    Vector2 pos{x,y};
    float width;
    float height;
public:
    Object(Vector2 pos, float width, float height): pos(pos),width(width),height(height){};

    Vector2 getPos() {return pos;}
    void setPos(Vector2 posNew) {pos=posNew;}

    float getX() const {return pos.x;}
    void setX(float xNew) {pos.x+=xNew;}

    float getY() const {return pos.y;}
    void setY(float yNew) {pos.y+=yNew;}

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
    int hp;
    int hpMax;
    int ammo;
    int score;
    Texture2D CharacterTexture;
public:
    Character(Texture2D CharacterTexture , float width, float height, float speedX, float speedY, int hp, int hpMax, int ammo, int score): CharacterTexture(CharacterTexture), Object(pos,width,height),
                                                                                                Movable(speedX,speedY),hp(hp), hpMax(hpMax), ammo(ammo),score(score)
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









