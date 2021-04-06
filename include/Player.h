#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "GameObject.h"

class Player: public GameObject {
	public:
            const int JUMPFRAME = 16;
            const double SPEED = 3.0;
            static constexpr int IDLE = 0;
            static constexpr int RUN = 1;
            static constexpr int JUMP = 2;
            int state = IDLE;
            int frameCount = 0;
            bool left = false;

		Player(int x, int y, int w, int h, int frame, int frameWidth, int frameHeight, const char* path, SDL_Renderer* renderer):
            GameObject(x, y, w, h) {
                  sprite = new Sprite(frame, frameWidth, frameHeight, path, renderer);
                  sprite->setFrame(0);
            }

		~Player() {}

            void controller(SDL_Event& event);
            void updatePos();
            void render(SDL_Renderer* renderer);
		
};

#endif