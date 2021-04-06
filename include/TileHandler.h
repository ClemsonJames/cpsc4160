#ifndef TILE_HANDLER_H
#define TILE_HANDLER_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "Tile.h"

#include <memory>
#include <vector>
#include <fstream> 
#include <stdlib.h>
#include <functional>

class TileHandler {
    private:
        std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture *)>> TilesetTexture;
        std::vector<Tile*> tileset;
	public:
	
		TileHandler(SDL_Renderer* renderer, const char* filepath) {
            auto surface = std::shared_ptr<SDL_Surface> (IMG_Load(filepath), SDL_FreeSurface);
            TilesetTexture = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture *)>>
                (SDL_CreateTextureFromSurface(renderer, surface.get()), SDL_DestroyTexture);
        }

		~TileHandler() {}

        void render(SDL_Renderer* renderer);
        void updatePos(int screenWidth);
        void loadTileset(const char* map, int screenWidth);

};

#endif