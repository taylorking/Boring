#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Display.h" 
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const int WINDOW_X = 0;
static const int WINDOW_Y = 0;

// set up the window and play a short intro
Display::Display(std::string gameTitle) { 
  SDL_Init(SDL_INIT_VIDEO);
  this->window = SDL_CreateWindow(gameTitle.c_str(),
     WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
   
}


Display::~Display() {

}


void Display::playIntro() {


}



void Display::update() {

}
