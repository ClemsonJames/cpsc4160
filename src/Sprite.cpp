#include "../include/Sprite.h"

SDL_Texture* Sprite::getTexture() {
    return texture.get();
}

// get the src rect based on the frame number
SDL_Rect Sprite::getRect(int frame) {
    SDL_Rect r;
    r.w = frameWidth;
    r.h = frameHeight;
    r.x = frameWidth * frame;
    r.y = 0;
    return r;
}

void Sprite::nextFrame() {
    int ticks = SDL_GetTicks();
    int currentFrame = (ticks / 100) % spriteFrames;
    srcRect = getRect(currentFrame);
}

void Sprite::setFrame(int frame) {
    srcRect = getRect(frame);
}