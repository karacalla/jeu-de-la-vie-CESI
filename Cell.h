#ifndef JEU_DE_LA_VIE_CELL_H
#define JEU_DE_LA_VIE_CELL_H


class Cell {
private:
    int state, posX, posY;
    bool lockState;
public:
    Cell();
    Cell(int state_, int posX_, int posY_);
    ~Cell();

    void setState(int state);

    [[nodiscard]] int getState () const;
    [[nodiscard]] int getPosX () const;
    [[nodiscard]] int getPosY() const;
    [[nodiscard]] bool getLockState() const;
};


#endif //JEU_DE_LA_VIE_CELL_H
