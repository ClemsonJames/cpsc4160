#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "GameObject.h"
#include <iostream>

class Background: public GameObject {
      private:
            bool move = true;
	public:

		Background(int x, int y, int w, int h, double vel, const char* path, SDL_Renderer* renderer):
            GameObject(x, y, w, h) {
                  velX = vel;
                  sprite = new Sprite(0, 0, 0, path, renderer);
            }

		~Background() {}

            void updatePos(int screenWidth);
            void render(SDL_Renderer* renderer);
		
};

#endif