#include "Console.h"
#include "Matrice.h"
#include "Cell.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Console::Console() = default;

Console::~Console() = default;

void Console::drawConsole(Matrice mat) {
    std::cout << cptIterations << std::endl;
    for (int i = 0; i < mat.getRow(); i++) {
        for (int j = 0; j < mat.getColumn(); j++) {
            if (mat.matrice[i][j].getState() == 0 || mat.matrice[i][j].getState() == 2) {
                std::cout << ".";
            } else if (mat.matrice[i][j].getState() == 1 || mat.matrice[i][j].getState() == 3) {
                std::cout << "#";
            }
        } std::cout << endl;
    }
}

void Console::clearConsole() {
    if (WIN32) {
        system("cls");
    } else {
        system("clear");
    }
}
