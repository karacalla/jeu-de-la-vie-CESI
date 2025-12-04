#include "Matrice.h"

Matrice::Matrice() {}

Matrice::Matrice(int row_, int column_) : row(row_), column(column_){}

Matrice::~Matrice() {}

void Matrice::setRow(int row_) {this->row = row_;}

void Matrice::setColumn(int column_) {this->column = column_;}

const int Matrice::getRow() {return this->row;}

const int Matrice::getColumn() {return this->column;}

void Matrice::createMatrix(char *fileName) {
    /* Ouverture du fichier
     * [type] file = ...;
     * setRow(file[indice]);
     * setColumn(file[indice]);
     * Lecture du fichier
     * Parcours du fichier :
     * for (int i = 0; i = this->row; i++) {
     *      for (int j = 0; j = this->column; i++) {
     *          cellule.setState(file[indice]);
     *      }
     * }
     */
}
