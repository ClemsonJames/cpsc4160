#include "../include/Player.h"
#include <iostream>

void Player::controller(SDL_Event& event){
    const uint8_t* kbState = SDL_GetKeyboardState(NULL);

    if(kbState[SDL_SCANCODE_A]) {
                if (state != JUMP) {
                    state = RUN;
                }
                left = true;
                velX = -SPEED-1;
    }

    if(kbState[SDL_SCANCODE_D]) {
                if (state != JUMP) {
                    state = RUN;
                }
                left = false;
                velX = SPEED-1;
    }

    if(kbState[SDL_SCANCODE_SPACE]) {
                if (state != JUMP) {
                    state = JUMP;
                    velY = -4.0;
                }
    }

    if (!kbState[SDL_SCANCODE_A] && !kbState[SDL_SCANCODE_D]) {
        if (state != JUMP) {
            state = IDLE;
        }
    }
}

void Player::updatePos() {
    switch (state) {
        case IDLE:
            velX = 0;
            destRect.x += velX;
            destRect.y += velY;
            break;
        case RUN:
            destRect.x += velX;
            destRect.y += velY;
            sprite->nextFrame();
            break;
        case JUMP:

            switch (frameCount) {
                case 0:
                    sprite->setFrame(4);
                    break;
                case 4:
                    sprite->setFrame(5);
                    break;
                case 8:
                    sprite->setFrame(6);
                    break;
                case 12:
                    sprite->setFrame(7);
                    break;
                case 16:
                    sprite->setFrame(0);
                    break;
            }

            if (frameCount < JUMPFRAME) {
                frameCount++;
            }
            else {
                velY = 4.0;
                if (frameCount == (JUMPFRAME * 2)) {
                    frameCount = -1;
                    velY = 0.0;
                    state = IDLE;
                }
                frameCount++;
            }
            destRect.x += velX;
            destRect.y += velY;
            break;
        default:
            break;
    }
}

void Player::render(SDL_Renderer* renderer) {
    if (left) {
        SDL_RenderCopyEx(renderer,
            sprite->getTexture(), 
            &(sprite->srcRect),
            &(destRect), 
            0, 
            NULL, 
            SDL_FLIP_HORIZONTAL);
    }
    else {
        SDL_RenderCopyEx(renderer,
            sprite->getTexture(), 
            &(sprite->srcRect),
            &(destRect), 
            0, 
            NULL, 
            SDL_FLIP_NONE);
    }
}
