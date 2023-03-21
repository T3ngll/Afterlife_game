#pragma once
#include "raylib.h"

class Movable{
protected:
    Vector2 speed;
    float frameWidth;
    float frameHeight;
public:
    Movable() = default;
    Movable(Vector2 speed,float frameWidth = 0, float frameHeight = 0);

    float getFrameWidth ();
    float getFrameHeight ();

    void setFrameWidth (float frameWidth);
    void setFrameHeight (float frameHeight);


    Vector2 getSpeed()const;
    float getSpeedX() const;
    float getSpeedY() const;

    void setSpeed(Vector2 speed);
    void setSpeedX(float speed);
    void setSpeedY(float speed);
};
