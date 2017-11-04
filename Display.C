#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Display.h" 
#include <unordered_map>
#include "Level.h"
#include "Entity.h"
#include "State.h"
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const int WINDOW_X = 0;
static const int WINDOW_Y = 0;

// set up the window and play a short intro
Display::Display(std::string gameTitle) { 
  State* gameState = State::getStateInstance();
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Error setting up SDL." << std::endl;
    gameState->stopGame();
  }

  this->window = SDL_CreateWindow(gameTitle.c_str(),
     WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  
}


Display::~Display() {

}


void Display::playIntro() {


}



void Display::update() {

}
