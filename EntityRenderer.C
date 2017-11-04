#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <string>
#include <unordered_map>
#include "Entity.h"
#include "State.h"
#include "Renderer.h"
#include "EntityRenderer.h"
const char* PLAYER_SPRITE_SHEET = "assets/images/characters.png";


EntityRenderer::EntityRenderer(SDL_Renderer* renderer) : Renderer(renderer) {
  this->rootRenderer = renderer;
}

EntityRenderer::~EntityRenderer(){

}


void EntityRenderer::render() {
   
}

void EntityRenderer::renderPlayer() { 
  State* gameState = State::getStateInstance();
  Entity* player = gameState->getPlayer();

}

void EntityRenderer::renderNonPlayers() {

}
