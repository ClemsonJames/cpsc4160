  
#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <functional>
#include <memory>

class Sprite {
    private:
        int spriteFrames;
        int currentFrame = 0;
        int frameWidth;
        int frameHeight;
        
        std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture *)>> texture;

        void loadSpriteSheet(const char* path, SDL_Renderer* renderer) {
            auto surface = std::shared_ptr<SDL_Surface> (IMG_Load(path), SDL_FreeSurface);
            texture = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture *)>>
                (SDL_CreateTextureFromSurface(renderer, surface.get()), SDL_DestroyTexture);
        }

        SDL_Rect getRect(int frame);

    public:
        SDL_Rect srcRect;

    	Sprite(int frame, int w, int h, const char* path, SDL_Renderer* renderer) {
            frameWidth = w;
            frameHeight = h;
            spriteFrames = frame;
            loadSpriteSheet(path, renderer);
        }

        ~Sprite() {}

        SDL_Texture* getTexture();
        void nextFrame();
        void setFrame(int frame);

};

#endif