#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include "Entity.h"
#include "Level.h"
#include "Display.h" 
#include "Control.h"
#include "Renderer.h"
#include "EntityRenderer.h"
#include "State.h"
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const int WINDOW_X = 0;
static const int WINDOW_Y = 0;

// set up the window and play a short intro
Display::Display(std::string gameTitle) { 
  State* gameState = State::getStateInstance();
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Error setting up SDL: " << SDL_GetError() << std::endl;
    gameState->stopGame();
  }
  IMG_Init(IMG_INIT_PNG);
  this->window = SDL_CreateWindow(gameTitle.c_str(),
     WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  if (this->window == NULL) {
    std::cout << "Error setting up SDL Window: " << SDL_GetError() << std::endl; 
  }
}


Display::~Display() {

}


void Display::playIntro() {
 // Might move this to a pp macro at some point
  
  // SDL_Surface* renderingSurface = SDL_GetWindowSurface(this->window);
  SDL_Renderer* renderer = SDL_CreateRenderer(this->window, -1, 0);
  if (TTF_Init() == -1)  {
    std::cout << "Couldn't play the intro :( I wont stop the game though." << std::endl;
  }

  TTF_Font *sans = TTF_OpenFont("/Library/Fonts/Arial.ttf", 24);
  if (sans == NULL) {
    std::cout << "Couldn't play the intro :( I wont stop the game though.\n" <<  SDL_GetError() << std::endl;
  }
  SDL_Color white = {255, 255, 255};
  SDL_Rect messageRect;
  int TEXT_HEIGHT = 100;
  int TEXT_WIDTH =400;
  
  messageRect.x = WINDOW_WIDTH / 2 - (TEXT_WIDTH / 2);
  messageRect.y = WINDOW_HEIGHT / 2 - (TEXT_HEIGHT / 2);
  messageRect.w = TEXT_WIDTH;
  messageRect.h = TEXT_HEIGHT;

  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sans, "A boring video game.", white);
  SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  
  SDL_RenderCopy(renderer, message, NULL, &messageRect);
  
  TEXT_HEIGHT = 50;
  TEXT_WIDTH = 200; 
  
  messageRect.x = WINDOW_WIDTH / 2 - (TEXT_WIDTH / 2);
  messageRect.y = WINDOW_HEIGHT - TEXT_HEIGHT;
  messageRect.w = TEXT_WIDTH;
  messageRect.h = TEXT_HEIGHT;

  sans = TTF_OpenFont("/Library/Fonts/Arial.ttf", 12);
  
  surfaceMessage = TTF_RenderText_Solid(sans, "Taylor King 2017", white);
  message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  SDL_RenderCopy(renderer, message, NULL, &messageRect);
  SDL_RenderPresent(renderer);
  SDL_Delay(3000);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

// Invoke outside renderers and then just render
void Display::update() {
  SDL_Renderer* renderer = SDL_GetRenderer(this->window);
  if (renderer == NULL) {
    renderer = SDL_CreateRenderer(this->window, -1, 0);
  }
  /**SetRenderer* setRenderer = new SetRenderer(renderer);
  setRenderer->render();
  delete setRenderer;
  **/
  EntityRenderer* entityRenderer = new EntityRenderer(renderer);
  entityRenderer->render();
  SDL_RenderPresent(renderer); 
}
