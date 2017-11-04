#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include "Level.h"
#include "Entity.h"
#include "Display.h"
#include "Control.h"
#include "State.h"
#include "Game.h"

Game::Game() {

}


Game::~Game() {
  delete this->display;
}

void Game::start() {
  display = new Display("Test Game");
  
  display->playIntro();
  State* currentState = State::getStateInstance();
  currentState->startGame();
  Control* controller = new Control(currentState->getPlayer());
  while (currentState->getIsRunning()) {
    
    // the controller will handle getting input and manipulating entity state directly.
    controller->poll();
    currentState->update();
    // trigger drawing and rendering the scene
    display->update();
  }
}
