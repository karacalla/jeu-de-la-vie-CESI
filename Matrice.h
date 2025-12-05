#pragma once
#include <vector>
#include <string>
#include "Cell.h"
using namespace std;

class Matrice {
    private:
    int row, column;
    public:
    vector<vector<Cell>> matrice;
    vector<vector<Cell>> buffer;

    Matrice(string fileName);
    ~Matrice();

    int getRow() const;
    int getColumn() const;

    void createMatrice();
    void saveMatrice();
    void copy();
};
