#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <unordered_map>
#include "Entity.h"
#include "Display.h" 
#include "Level.h"
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

  this->window = SDL_CreateWindow(gameTitle.c_str(),
     WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  if (this->window == NULL) {
    std::cout << "Error setting up SDL Window: " << SDL_GetError() << std::endl; 
  }
}


Display::~Display() {

}


void Display::playIntro() {
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

  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sans, "A boring video game.\n Taylor King™ 2017", white);
  SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  SDL_RenderCopy(renderer, message, NULL, NULL);
  SDL_RenderPresent(renderer);
}

void Display::drawEntity(Entity* entity) {

}


void Display::update() {

}
