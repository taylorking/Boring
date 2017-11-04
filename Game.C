#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include "Level.h"
#include "Display.h"
#include "Entity.h"
#include "State.h"
#include "Control.h"
#include "Game.h"
static int running = 1;

Game::Game() {

}


Game::~Game() {
  delete this->video;
}

void Game::start() {
  this->video = new Display("Test Game");
  
  this->video->playIntro();
  while (running) {
    State* currentState = State::getStateInstance();
  }
}
