#include <unordered_map>
#include <string>
#include "Display.h"
#include "Entity.h"
#include "State.h"
#include "Control.h"
#include "Game.h"

Game::Game() {
  this->video = new Display;
  this->state = new State;
}


Game::~Game() {
  delete this->video;
}

State* Game::getState() { 
  return this->state;
}
void Game::start() {

}
