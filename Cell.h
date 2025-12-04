#ifndef TEST_CELL_H
#define TEST_CELL_H
#include <cstdlib>

class Cell {
    private:
    bool state;
    int x, y;
    bool lockState;
    public:
    Cell();
    ~Cell();
    void setState(bool state_);
    bool getState();
    void setPos(int x_, int y_);
    int getPosX() const;
    int getPosY() const;

};


#endif //TEST_CELL_H
