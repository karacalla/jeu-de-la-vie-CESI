#include "Cell.h"

Cell::Cell() {}

Cell::Cell(int state_, int posX_, int posY_) {
    this->posX = posX_;
    this->posY = posY_;
    if (state_ == 2) {
        this->state = 0;
        this->lockState = true;
    } else if (state_ == 3) {
        this->state = 1;
        this->lockState = true;
    } else {
        this->state = state_;
        this->lockState = false;
    }
}

Cell::~Cell() =default;

void Cell::setState(int state_) {
    if (lockState == false) {
        if (state_ == 0 || state_ == 1) {
            this->state = state_;
        } else if (state_ == 2 || state_ == 3) {}
    }
}

int Cell::getState() const {return this->state;}
int Cell::getPosX() const {return this->posX;}
int Cell::getPosY() const {return this->posY;}
bool Cell::getLockState() const {return this->lockState;}
