// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "../include/GameObject.h"

//Screen dimension
const int fps = 60;
const int frame_duration = 1000 / fps;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;

void my_SDL_init(){

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window,-1,0);

}

int main(int argv, char** args) 
{
  int start_time = 0;
  int last_start_time = 0;
  int duration = 0;

  bool is_running = true;
  SDL_Event event;

  my_SDL_init();

  // create game object player
  GameObject player (300, 250, 200, 300);
  player.load("./site.jpg", my_renderer);
  
  // game loop
  while(is_running){
    start_time = SDL_GetTicks();
    
    while(SDL_PollEvent(&event) > 0) {
      if (event.type == SDL_QUIT) {
        is_running = false;
      }
    }

    SDL_RenderClear(my_renderer);
    SDL_SetRenderDrawColor(my_renderer, 0, 0, 255, 255);

    player.draw(my_renderer);


    SDL_RenderPresent(my_renderer);

    // calculate delay 
    if (start_time >= (last_start_time + 1000)) {
      last_start_time = start_time;
    }
    duration = SDL_GetTicks() -  start_time;
    if (duration < frame_duration) {
      SDL_Delay(frame_duration - duration);
    }

  }

  player.clean();
  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}
