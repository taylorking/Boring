#include <SDL2/SDL.h>
#include "Renderer.h" 

Renderer::Renderer(SDL_Renderer* renderer) {
  this->renderer = renderer;
}

Renderer::~Renderer() { 
  
}
