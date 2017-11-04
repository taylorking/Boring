#include <iostream>
#include <string>
#include <unordered_map>
#include "Entity.h"
#include "Level.h"
#include "State.h"

State* State::stateInstance = NULL;

State::State() {
  this->entities = new std::unordered_map<std::string, Entity*>;
}

Entity* State::getEntity(std::string name) { 

}

Entity* State::getPlayer() { 
  std::unordered_map<std::string, Entity*>::const_iterator got = this->entities->find("player");
  if (got == this->entities->end()) {
    //Will replace this with a proper exception class st some point
    std::cout << "Game did not setup correctly." << std::endl;
    throw 1;
  }
  return got->second;
}

bool State::getIsRunning() {
  return isRunning;
}

void State::startGame() {
  isRunning = true;
}

void State::stopGame() {
  isRunning = false;
}

// iterate through the list of entites and tear them all up
State::~State() {
  for (std::unordered_map<std::string, Entity*>::iterator it = this->entities->begin(); it != this->entities->end(); ++it) {
    std::string key = it->first;
    std::unordered_map<std::string, Entity*>::const_iterator got = this->entities->find(key);
    if (got != this->entities->end()) 
      delete got->second;
  }
  delete this->entities;
}

State* State::getStateInstance() { 
  if (stateInstance == NULL)
    stateInstance = new State();
  return stateInstance;
}

