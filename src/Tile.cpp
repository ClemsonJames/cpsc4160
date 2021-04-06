#include "../include/Tile.h"

void Tile::render(SDL_Texture* texture, SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void Tile::updatePos(int screenWidth) {
    if (move) {
        if (destRect.x <= -screenWidth) {
            destRect.x += screenWidth * 2;
        }
        destRect.x += velX;
    }
    else {
        move = true;
    }

}