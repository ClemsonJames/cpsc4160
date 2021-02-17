#include "..\include\GameObject.h"

// load the picture and create the texture
void GameObject::load(char* filename, SDL_Renderer* renderer) {
    surface = IMG_Load(filename);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

// put the rect on the screen 
void GameObject::draw(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

// clean up, free surface/texture
void GameObject::clean() {
    SDL_DestroyTexture(texture);
}