#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Cell.h"
using namespace std;

class Matrice {
    private:
    int row, column;

    public:
    vector<vector<Cell>> matrice;
    vector<vector<Cell>> buffer;

    explicit Matrice(string(fileName));
    ~Matrice();

    int getRow() const;
    int getColumn() const;

    void copy();
};
