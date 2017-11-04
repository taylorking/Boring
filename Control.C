#include "Entity.h"
#include "Control.h"

Control::Control(Entity* controlled) {
  this->controlled = controlled;
}

Control::~Control() {

}

void Control::poll() {

}
