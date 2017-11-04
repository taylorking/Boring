#include <SDL2/SDL.h>
#include "Renderer.h" 

Renderer::Renderer(SDL_Renderer* renderer) {
  this->rootRenderer = renderer;
}

Renderer::~Renderer() { 
  
}
