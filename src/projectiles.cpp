#include "raylib.h"
#include "projectiles.h"



Bullet::Bullet(Vector2 pos,Vector2 speed, bool active,int lifeSpawn,float radius,Color color): Object(pos,0,0), Movable(speed),lifeSpawn(lifeSpawn),radius(radius),color(color){};


void Bullet::setRadius(float rad){radius=rad;}
float Bullet::getRadius(){return radius;}

void Bullet::setColor(Color color){this->color=color;}

void Bullet::setTargetToMouse()
{
    Vector2 mousePos=GetMousePosition();
    this->target=mousePos;
}
Vector2 Bullet::getTarget() {return target;}

int Bullet::getDamage() {return damage;}

void Bullet::setDamage(int damage) {this->damage=damage;}

bool Bullet::operator==(const Bullet &toCompare) {

    return this->getX() == toCompare.getX() && this->getY() == toCompare.getY();
}

