#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

class GameObject {
	public:
	
		GameObject(int x, int y, int w, int h) {
            this->surface = NULL;
            this->texture = NULL;
            rect.x = x;
            rect.y = y;
            rect.w = w;
            rect.h = h;
        }

		~GameObject() {}
		
		void load(char* filename, SDL_Renderer* renderer);
		void draw(SDL_Renderer* my_renderer);
		void clean();
		
	//private:
		SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect rect;
};

#endif
