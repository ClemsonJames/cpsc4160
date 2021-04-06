#include "../include/GameEngine.h"

void GameEngine::my_SDL_init() {
      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
    }

    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);
    
    my_window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window *)>> (SDL_CreateWindow("my_game", 
                    SDL_WINDOWPOS_CENTERED, 
                    SDL_WINDOWPOS_CENTERED, 
                    screenWidth,
                    screenHeight, 0), 
                    SDL_DestroyWindow);

    my_renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)>> 
        (SDL_CreateRenderer(my_window.get(), -1, SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);
}

void GameEngine::gameLoop() {
    is_running = true;
    SDL_Event event;

    // create game object player
    Player *player = new Player(100, 256, 64, 64, 4, 32, 32, "./asset/character.png", my_renderer.get());
    Background *mountain_far = new Background(0, -150, screenWidth*2 , screenHeight, -1, "./asset/mountain_far.png", my_renderer.get());
    Background *mountain = new Background(0, -150, screenWidth*2 , screenHeight, -2, "./asset/mountain.png", my_renderer.get());
    Background *tree_far = new Background(0, -150, screenWidth*2 , screenHeight, -3, "./asset/tree_far.png", my_renderer.get());
    Background *tree = new Background(0, -150, screenWidth*2 , screenHeight, -4, "./asset/tree.png", my_renderer.get());
    
    // load map 
    TileHandler *tileHandler = new TileHandler(my_renderer.get(), "./asset/tileset.png");
    tileHandler->loadTileset("./asset/map.txt", screenWidth);
    
    // game loop
    while(is_running){
        bool eventStatus= SDL_PollEvent(&event);

        SDL_RenderClear(my_renderer.get());
        SDL_SetRenderDrawColor(my_renderer.get(), 171, 106, 140, 255);


        player->controller(event);

        player->updatePos();
        tileHandler->updatePos(screenWidth);
        mountain_far->updatePos(screenWidth);
        mountain->updatePos(screenWidth);
        tree_far->updatePos(screenWidth);
        tree->updatePos(screenWidth);

        mountain_far->render(my_renderer.get());
        mountain->render(my_renderer.get());
        tree_far->render(my_renderer.get());
        tree->render(my_renderer.get());
        tileHandler->render(my_renderer.get());
        player->render(my_renderer.get());

        if(eventStatus) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }

        SDL_RenderPresent(my_renderer.get());

    }
}
