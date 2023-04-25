#pragma once
#include "object.h"
#include "raylib.h"

enum Type{Heal};

class Factory
{
    private:

    //Texture2D walker;

    public:

    /*Factory() {

        
    }

    ~Factory()
    {
           UnloadTexture(walker);
    }*/

    Object* create(Type t,Vector2 pos)  // factory method
	{
		switch(t)
		{
			case Heal:
                
				auto heal = new Object(pos,140,140);
                return heal;
			
		}
	}
};