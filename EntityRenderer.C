#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <string>
#include <unordered_map>
#include "Entity.h"
#include "State.h"
#include "Renderer.h"
#include "EntityRenderer.h"
const char* CHARACTER_SPRITE_SHEET = "characters.png";
const int SPRITE_WIDTH = 28; 

EntityRenderer::EntityRenderer(SDL_Renderer* renderer) : Renderer(renderer) {
  this->renderer = renderer;
}

EntityRenderer::~EntityRenderer(){

}


void EntityRenderer::render() {
  renderPlayer();
  renderNonPlayers();
}

void EntityRenderer::renderPlayer() { 
  State* gameState = State::getStateInstance();
  Entity* player = gameState->getPlayer();
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_Surface* image = IMG_Load(CHARACTER_SPRITE_SHEET);
  int sprite = (SDL_GetTicks() / 100) % 3;
  SDL_Rect srcrect = { sprite * 28 + 4, 40, 28, 28 };
  SDL_Rect dstrect = { 100, 100, 96, 96 };
  SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_RenderCopy(renderer, spriteTexture, &srcrect, &dstrect);
//  SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);
//  SDL_RenderPresent(renderer);
}

void EntityRenderer::renderNonPlayers() {
  
}
