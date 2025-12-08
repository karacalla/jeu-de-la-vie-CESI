#include "Game.h"
#include "Ui.h"
#include "Matrice.h"
#include "Cell.h"
#include "Rules.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Game::Game(const string& fileName_, int nbIteration) : mat(fileName_ + ".txt"), ui(mat.getColumn(), mat.getRow(), CELL_SIZE) {
    this->saveFileName = string(fileName_) + "_out.txt";
    NB_ITERATIONS = nbIteration;
}

Game::~Game() =default;

void Game::nextGeneration() {
    for (int i = 0; i < mat.getRow(); i++) {
        for (int j = 0; j < mat.getColumn(); j++) {
            int cptNeighbour = 0;
            for (int k = -1 ; k <= 1 ; k++) {
                for (int m = -1 ; m <= 1 ; m++) {
                    if (k == 0 && m == 0) continue;

                    int r = (mat.matrice[i][j].getPosY() + k + mat.getRow()) % mat.getRow();
                    int c = (mat.matrice[i][j].getPosX() + m + mat.getColumn()) % mat.getColumn();

                    if (mat.matrice[r][c].getState() == 1) {
                        cptNeighbour++;
                    }
                }
            }
            if (mat.matrice[i][j].getState() == 1) {
                if (cptNeighbour < NB_MIN_CELL || cptNeighbour > NB_MAX_CELL) {
                    mat.buffer[i][j].setState(0);
                } else {
                    mat.matrice[i][j].setState(1);
                }
            } else if (mat.matrice[i][j].getState() == 0) {
                if (cptNeighbour == NB_BORN_CELL) {
                    mat.buffer[i][j].setState(1);
                } else {
                    mat.matrice[i][j].setState(0);
                }
            }
        }
    }
    mat.matrice = mat.buffer;
}



void Game::save() {
    ofstream saveFile(saveFileName, ios::app);
    if (!saveFile) {
        cerr << "Erreur de sauvegarde" << endl;
        return;
    }
    saveFile << cptIterations << endl;

    for (int i = 0; i < mat.getRow(); i++) {
        for (int j = 0; j < mat.getColumn(); j++) {
            if (mat.matrice[i][j].getLockState() == false) {
                saveFile << mat.matrice[i][j].getState();
            } else {
                saveFile << mat.matrice[i][j].getState() + 2;
            }
            if (j < mat.getColumn() - 1) {
                saveFile << " ";
            }
        }
        saveFile << endl;
    }

    saveFile.close();
}

void Game::draw() {
    if (UI == true) {
        ui.handleEvents();
        ui.drawUi(mat);
    } else if (CONSOLE == true) {
        //console.clearConsole();
        console.drawConsole(mat);
    }
}

bool Game::isRunning() {
    if (UI == true) {
        return ui.isOpen();
    }
    return true;
}
