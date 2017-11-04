#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include "Entity.h"
#include "Level.h"
#include "Display.h"
#include "Control.h"
#include "State.h"
#include "Game.h"
// this class just loads and runs the game

int main() {
  Game* g = new Game();
  g->start();
}
