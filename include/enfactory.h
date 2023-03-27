#pragma once
#include "enemy.h"
#include "raylib.h"

enum Type{Walker};

class Factory
{
    private:

    Texture2D walker;

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
                
				auto enemy = new Enemy(tex,140,140,pos,100);
                enemy->setFrameWidth(tex.width);
                enemy->setFrameHeight(tex.height);
                return enemy;
			
		}
	}
};