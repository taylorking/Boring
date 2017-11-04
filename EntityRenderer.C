#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include "Entity.h"
#include "State.h"
#include "Renderer.h"
#include "EntityRenderer.h"
EntityRenderer::EntityRenderer(SDL_Renderer* renderer) : Renderer(renderer) {
  this->rootRenderer = renderer;
}

EntityRenderer::~EntityRenderer(){

}


void EntityRenderer::render() {
   
}

void EntityRenderer::renderPlayer() { 
  // need to l
}

void EntityRenderer::renderNonPlayers() {

}
