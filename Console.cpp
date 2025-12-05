#include "Console.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

Console::Console() {}

Console::~Console() {}

void Console::displayConsole(Matrice mat) {
    for (int i = 0; i < mat.getRow(); i++) {
        for (int j = 0; j < mat.getColumn(); j++) {
            if (mat.matrice[i][j] == 0) {
                cout << "  ";
            } else {
                cout << "██";
            }
        } cout << endl;
    }
}

void Console::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}