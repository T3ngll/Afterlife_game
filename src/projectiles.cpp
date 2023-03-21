#include "raylib.h"
#include "projectiles.h"



Bullet::Bullet(Vector2 pos,Vector2 speed, bool active,int lifeSpawn,float radius,Color color): Object(pos,0,0), Movable(speed),lifeSpawn(lifeSpawn),radius(radius),color(color){};

int Bullet::getLifeSpawn(){return lifeSpawn;}
void Bullet::setLifeSpawn(int life){lifeSpawn=life;}

void Bullet::setRadius(float rad){radius=rad;}
float Bullet::getRadius(){return radius;}

void Bullet::setColor(Color color){this->color=color;}

void Bullet::setTargetToMouse()
{
    Vector2 mousePos=GetMousePosition();
    this->target=mousePos;
}
Vector2 Bullet::getTarget() {return target;}