#include "Matrice.h"
#include "Rules.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Matrice::Matrice() {createMatrice();}

void Matrice::createMatrice() {
    ifstream file(&INIT_FILE_PATH);
    if (!file) {
        cerr << "Fichier initial introuvable" << endl;
        return;
    }
    file >> row >> column;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            file >> matrice[i][j];
        }
    }
    buffer = matrice;
    file.close();
}

Matrice::~Matrice() {}

const int Matrice::getColumn() {return this->column;}
const int Matrice::getRow() {return this->row;}

void Matrice::saveMatrice() {
    ofstream saveFile(&SAVE_FILE_PATH);
    if (!saveFile) {
        cerr << "Fichier de sauvegarde introuvable" << endl;
        return;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            saveFile << matrice[i][j];
            if (j < column - 1) {
                saveFile << ' ';
            }
        } saveFile << endl;
    }
    saveFile.close();
}
