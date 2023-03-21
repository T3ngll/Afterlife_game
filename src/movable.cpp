#include "movable.h"

Movable::Movable(Vector2 speed,float frameWidth, float frameHeight): speed(speed){}

float Movable::getFrameWidth (){ return frameWidth; }
float Movable::getFrameHeight (){ return frameHeight; }

void Movable::setFrameWidth (float frameWidth){ this->frameWidth=frameWidth; }
void Movable::setFrameHeight (float frameHeight){ this->frameHeight=frameHeight; }


Vector2 Movable::getSpeed()const {return speed;}
float Movable::getSpeedX() const { return speed.x; }
float Movable::getSpeedY() const { return speed.y; }

void Movable::setSpeed(Vector2 speed){ this->speed=speed; }
void Movable::setSpeedX(float speed)  { this->speed.x=speed; }
void Movable::setSpeedY(float speed)  { this->speed.y=speed; }