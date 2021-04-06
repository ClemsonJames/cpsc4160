#include "../include/Background.h"

void Background::updatePos(int screenWidth) {
    if (move) {
        if (destRect.x <= -screenWidth) {
            destRect.x = 0;
        }
        destRect.x += velX;
    }
    else {
        move = true;
    }

}

void Background::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &(destRect));
}