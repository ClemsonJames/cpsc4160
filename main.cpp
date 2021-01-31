// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

//Screen dimension
const int fps = 60;
const int frame_duration = 1000 / fps;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;
SDL_Event input;

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

int main() 
{
  int start_time = 0;
  int last_start_time = 0;
  int duration = 0;
  my_SDL_init();
  
  SDL_Texture* my_texture = NULL;
  SDL_Texture* rocket_texture = NULL;
  SDL_Surface* image = IMG_Load("./site.jpg");
  SDL_Surface* temp = IMG_Load("./rocket.png");
  
  my_texture = SDL_CreateTextureFromSurface(my_renderer, image);
  rocket_texture = SDL_CreateTextureFromSurface(my_renderer, temp);

  SDL_FreeSurface(temp);
  
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 200;
  rect.w = 150;
  rect.h = 75;

  SDL_Rect rocket_rect;
  rocket_rect.x = 300;
  rocket_rect.y = 400;
  rocket_rect.w = 200;
  rocket_rect.h = 300;
  

  while(true){
    start_time = SDL_GetTicks();

    SDL_RenderClear(my_renderer);

    rocket_rect.y -= 3;
    if (rocket_rect.y > -rocket_rect.h) {
      rocket_rect.y = 400;
    }

    SDL_RenderCopy(my_renderer, my_texture, NULL, NULL);
    SDL_SetRenderDrawColor(my_renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(my_renderer, &rect);
    SDL_RenderCopy(my_renderer, rocket_texture, NULL, &rocket_rect);



    SDL_RenderPresent(my_renderer);

    if (start_time >= (last_start_time + 1000)) {
      last_start_time = start_time;
    }

    duration = SDL_GetTicks() -  start_time;

    if (duration < frame_duration) {
      SDL_Delay(frame_duration - duration);
    }


  }

  SDL_DestroyTexture(my_texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}
