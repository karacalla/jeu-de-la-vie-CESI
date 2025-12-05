#include "Cell.h"
#include <cstdlib>

using namespace std;

Cell::Cell() {}

Cell::~Cell() {}

void Cell::setState(bool state_) {this->state = state_;}

void Cell::setPos(int x_, int y_) {
    this->x = x_;
    this->y = y_;
}

bool Cell::getState() {return this->state;}

int Cell::getPosX() const {return this->x;}
int Cell::getPosY() const {return this->y;}
