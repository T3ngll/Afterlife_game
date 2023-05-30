#pragma once
#include "enemy.h"
#include "object.h"
#include "raylib.h"

enum Type{Walker, Collect, Fatboy, Runner};

class Factory
{
    private:

    Texture2D walker;
    Texture2D runner;

    public:

    /*Factory() {

        
    }

    ~Factory()
    {
           UnloadTexture(walker);
    }*/

    Enemy* create(Type t,Vector2 pos,Texture2D tex)  // factory method
	{
		switch(t)
		{
			case Walker:
                {
				auto enemy = new Enemy(tex,140,140,pos,Vector2{100,100},100,40,100);

                enemy->setFrameWidth(tex.width);
                enemy->setFrameHeight(tex.height);
                return enemy;
                }

                case Fatboy:
                {
				auto enemy = new Enemy(tex,210,210,pos,Vector2{50,50},200,60,150);

                enemy->setFrameWidth(tex.width);
                enemy->setFrameHeight(tex.height);
                return enemy;
                }

                case Runner:
                {
				auto enemy = new Enemy(tex,100,100,pos,Vector2{180,180},40,30,50);

                enemy->setFrameWidth(tex.width);
                enemy->setFrameHeight(tex.height);
                return enemy;
                }
			
		}
	}
    Object* create(Type d,Vector2 pos)  // factory method
	{
		switch(d)
		{
			case Collect:
                
				auto collect = new Object(pos,140,140);
                return collect;
			
		}
	}
};