#include "../include/TileHandler.h"

void TileHandler::loadTileset(const char* map, int screenWidth) {

    //The tile offsets
    int x = 0;
    int y = 0;
    int tileType = -1;

    std::ifstream ifs;
    ifs.open (map, std::ifstream::in);

    while (!ifs.eof()) {
        ifs >> tileType;
        if(tileType >= 0) {
            tileset.push_back(new Tile(x, y, tileType));
        }
        
        x += TILE_WIDTH * 2;
        if(x >= screenWidth * 2) {
            x = 0;
            y += TILE_HEIGHT * 2;
        }
    }

    ifs.close();
}

void TileHandler::render(SDL_Renderer* renderer) {
    for(int i=0; i < (int)tileset.size(); i++){
        tileset[i]->render(TilesetTexture.get(), renderer);
    }
}

void TileHandler::updatePos(int screenWidth) {
    for(int i=0; i < (int)tileset.size(); i++){
        tileset[i]->updatePos(screenWidth);
    }
}