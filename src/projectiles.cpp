#include "raylib.h"
#include "projectiles.h"
#include "math.h"



Bullet::Bullet(Texture2D BulletTexture, Vector2 pos,Vector2 speed, bool active,float radius,Color color): Object(pos,0,0), Movable(speed),radius(radius),color(color){};

float Bullet::getRotation() {
    Vector2 mousePosition = GetMousePosition();
    float dx = mousePosition.x - pos.x;
    float dy = mousePosition.y - pos.y;
    float rotation = atan2f(dy, dx)+(PI/2);
    return rotation*RAD2DEG;
}

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

Texture2D Bullet::getTexture() {
    return BulletTexture;
}

Grenade::Grenade(Texture2D GrenadeTexture, Vector2 pos, Vector2 speed, bool active, float radius, Color color): Object(pos,0,0), Movable(speed),radius(radius),color(color){}

Texture2D Grenade::getTexture() {
    return GrenadeTexture;
}

bool Grenade::operator==(const Grenade &toCompare) {
    return this->getX() == toCompare.getX() && this->getY() == toCompare.getY();
}

float Grenade::getRotation() {
    Vector2 mousePosition = GetMousePosition();
    float dx = mousePosition.x - pos.x;
    float dy = mousePosition.y - pos.y;
    float rotation = atan2f(dy, dx)+(PI/2);
    return rotation*RAD2DEG;
}

int Grenade::getDamage() {
    return damage;
}

void Grenade::setDamage(int damage) {this->damage=damage;}

void Grenade::setRadius(float rad){radius=rad;}

float Grenade::getRadius(){return radius;}

void Grenade::setColor(Color color){this->color=color;}

void Grenade::setTargetToMouse()
{
    Vector2 mousePos=GetMousePosition();
    this->target=mousePos;
}

Vector2 Grenade::getTarget() {return target;}










