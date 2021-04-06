  
#ifndef TILE_H
#define TILE_H
#include <stdio.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

// Tile constants
const int TILE_WIDTH = 16;
const int TILE_HEIGHT = 16;

// The different tile sprites
const int TILE_GRASS_0 = 0;
const int TILE_GRASS_1 = 1;
const int TILE_GRASS_2 = 2;
const int TILE_LEFT = 3;
const int TILE_CENTER = 4;
const int TILE_RIGHT = 5;
const int TILE_WATER_TOP = 6;
const int TILE_DOWN_CENTER_0 = 7;
const int TILE_BOX = 8;
const int TILE_SIGN = 9;
const int TILE_DOWN_LEFT = 10;
const int TILE_DOWN_CENTER_1 = 11;
const int TILE_DOWN_RIGHT = 12;
const int TILE_WATER_BOTTOM = 13;

class Tile {
    private:
        bool move = true;
        SDL_Rect srcRect;
        int velX = -1;
    public:
        SDL_Rect destRect;

        Tile(int x, int y, int tileType) {
            destRect.w = TILE_WIDTH * 2;
            destRect.h = TILE_HEIGHT * 2;
            destRect.x = x;
            destRect.y = y;

            srcRect.w = TILE_WIDTH;
            srcRect.h = TILE_HEIGHT;

            switch (tileType) {
                case TILE_GRASS_0:
                    srcRect.x = 0;
                    srcRect.y = 0;
                    break;
                case TILE_GRASS_1:
                    srcRect.x = 16;
                    srcRect.y = 0;
                    break;
                case TILE_GRASS_2:
                    srcRect.x = 32;
                    srcRect.y = 0;
                    break;
                case TILE_LEFT:
                    srcRect.x = 48;
                    srcRect.y = 0;
                    break;
                case TILE_CENTER:
                    srcRect.x = 64;
                    srcRect.y = 0;
                    break;
                case TILE_RIGHT:
                    srcRect.x = 80;
                    srcRect.y = 0;
                    break;
                case TILE_WATER_TOP:
                    srcRect.x = 96;
                    srcRect.y = 0;
                    break;
                case TILE_DOWN_CENTER_0:
                    srcRect.x = 0;
                    srcRect.y = 16;
                    break;
                case TILE_BOX:
                    srcRect.x = 16;
                    srcRect.y = 16;
                    break;
                case TILE_SIGN:
                    srcRect.x = 32;
                    srcRect.y = 16;
                    break;
                case TILE_DOWN_LEFT:
                    srcRect.x = 48;
                    srcRect.y = 16;
                    break;
                case TILE_DOWN_CENTER_1:
                    srcRect.x = 64;
                    srcRect.y = 12;
                    break;
                case TILE_DOWN_RIGHT:
                    srcRect.x = 80;
                    srcRect.y = 16;
                    break;
                case TILE_WATER_BOTTOM:
                    srcRect.x = 96;
                    srcRect.y = 16;
                    break;
            }
        }

        ~Tile() {}
        void render(SDL_Texture* texture, SDL_Renderer* renderer);
        void updatePos(int screenWidth);

};

#endif