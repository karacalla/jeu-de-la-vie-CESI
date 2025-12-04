#ifndef POO_MATRICE_H
#define POO_MATRICE_H
#include <iostream>
#include "Cell.h"


class Matrice {
    private:
    int row, column;
    //Cell matrice[];
    public:
    Matrice();
    Matrice(int row_, int column_);
    ~Matrice();
    void setRow(int row_);
    const int getRow();
    void setColumn(int column_);
    const int getColumn();
    void createMatrix(char* fileName);
};


#endif //POO_MATRICE_H
