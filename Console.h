#pragma once
#include "Matrice.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Console {
    public:
    Console();
    ~Console();
    void displayConsole(Matrice mat);
    void clearConsole();
};



