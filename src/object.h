#pragma once
#include "raylib.h"

class Object{
protected:
    float x = 0;
    float y = 0;
    Vector2 pos{x,y};
    float width = 0;
    float height = 0;
    bool active = true;// in new logic we can delete it
public:
    Object() = default;
    Object(Vector2 pos, float width, float height);

    Vector2 getPos()const;
    void setPos(Vector2 posNew);

    float getX() const ;
    void setX(float xNew) ;

    float getY() const ;
    void setY(float yNew) ;

    float getHeight() const;
    float getWidth() const;

    bool isActive() const;
    void setActive(bool isActive);
};