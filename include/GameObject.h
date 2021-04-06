#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "Sprite.h"
#include <functional>
#include <memory>

class GameObject {
    
	public:
        SDL_Rect destRect;
        Sprite* sprite;
        double velX = 0.0;
        double velY = 0.0;
	
		GameObject(int x, int y, int w, int h) {
            destRect.x = x;
            destRect.y = y;
            destRect.w = w;
            destRect.h = h;
        }

		~GameObject() {}

};

#endif
