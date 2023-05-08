#include "object.h"

Object::Object(Vector2 pos, float width, float height): pos(pos),width(width),height(height),active(true){};

Vector2 Object::getPos() const{return pos;}
void Object::setPos(Vector2 posNew) {pos=posNew;}

float Object::getX() const {return pos.x;}
void Object::setX(float xNew) {pos.x+=xNew;}

float Object::getY() const {return pos.y;}
void Object::setY(float yNew) {pos.y+=yNew;}

float Object::getHeight() const {return height;}
float Object::getWidth() const {return width;}

bool Object::isActive() const{return active;}
void Object::setStatus(bool status){active=status;}