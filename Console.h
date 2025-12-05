#ifndef JEU_DE_LA_VIE_CONSOLE_H
#define JEU_DE_LA_VIE_CONSOLE_H
#include "Matrice.h"
#include "Cell.h"
#include "Rules.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <string>

class Console {
public:
    Console();
    ~Console();

    void drawConsole(Matrice mat);
    void clearConsole();
};


#endif //JEU_DE_LA_VIE_CONSOLE_H
