#ifndef TEST_NEXTGEN_H
#define TEST_NEXTGEN_H
#include "Rules.h"
#include "Matrice.h"
#include "Cell.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

bool checkNeighbour(Matrice mat, Cell cell) {
    int cptNeighbour = 0;
    for (int k = -1 ; k < 2 ; k++) {
        for (int m = -1 ; m < 2 ; m++) {
            if (k == 0 && m == 0) continue;
            if (mat.matrice[cell.getPosX() + k][cell.getPosY() + m] == 1) {
                cptNeighbour++;
            }
        }
    } if (cptNeighbour == NB_MIN_CELL || cptNeighbour == NB_MAX_CELL) {
        return 1;
    } return 0;
}


void nextGeneration(Matrice mat, Cell cell) {
    for (int i = 0; i < mat.getRow(); i++) {
        for (int j = 0; j < mat.getColumn(); j++) {
            cell.setPos(j, i);
            mat.buffer[i][j] = checkNeighbour(mat, cell);
        }
    } mat.matrice = mat.buffer;
}


#endif //TEST_NEXTGEN_H
