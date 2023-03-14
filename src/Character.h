#pragma once


class Character
{
    float x;
    float y;
    float height;
    float width;
    float speedX;
    float speedY;
    float health;
    float ammo;
   // float rotation;
   // Vector2 mousePosition = {0};
public:
    Character(float height, float width, float speedX, float speedY, float health, float ammo):height(height),width(width),speedX(speedX),speedY(speedY),health(health),ammo(ammo)
    {
        x=GetScreenWidth() / 2 -width/2;
        y=GetScreenHeight() / 2 -height/2;
    };
    float getX() const {return x;}
    void setX(float xNew) {x+=xNew;}
    float getY() const {return y;}
    void setY(float yNew) {y+=yNew;}
    float getHeight() const {return height;}
    float getWidth() const {return width;}
    float getSpeedX() const {return speedX;}
    float getSpeedY() const {return speedY;}
    float getHealth() const {return health;}
    //Vector2 getVector() {return mousePosition;}
    //float getRotation() const {return rotation;}

    //void Draw(float x,float y, float width,float height);


};
/*
void Character::Draw(float x,float y, float width,float height)
{
    //Rectangle rec={character.x,character.y,character.width, character.height};
    DrawRectangle(x,y,width,height,LIME);
    //DrawRectanglePro(rec,(Vector2){character.x,character.y},rotation * RAD2DEG,BLACK);

}*/









