#include <unordered_map>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "Entity.h"
#include "State.h"
#include "Control.h"

Control::Control(Entity* controlled) {
  this->controlled = controlled;
}

Control::~Control() {

}

void Control::poll() {
  State* gameState = State::getStateInstance(); 
  Entity* player = gameState->getPlayer();
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN:
        std::cout << "key pressed";
        break;
      default: 
        break;
    }
  }
}
