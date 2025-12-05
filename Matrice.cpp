#include "Matrice.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Matrice::Matrice(string(fileName)) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Fichier initial introuvable" << endl;
        return;
    }
    file >> row >> column;
    matrice.resize(row, vector<Cell>(column));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            int state;
            file >> state;
            matrice[i][j] = Cell(state, j, i);
        }
    }
    buffer = matrice;
    file.close();
}

Matrice::~Matrice() =default;

void Matrice::copy() {
    this->matrice = this->buffer;
}

int Matrice::getColumn() const {return this->column;}
int Matrice::getRow() const {return this->row;}
