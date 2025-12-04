#ifndef TEST_CONSOLE_H
#define TEST_CONSOLE_H
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


#endif //TEST_CONSOLE_H
