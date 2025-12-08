#pragma once

#include "Matrice.h"
#include "Cell.h"
#include "Rules.h"
#include "Config.h"
#include "Ui.h"
#include <iostream>
#include <fstream>
#include <string>

#include "Console.h"
using namespace std;

class Game {
    public:
    string saveFileName;
    Matrice mat;
    Console console;
    Ui ui;

    explicit Game(const string& fileName, int nbIteration);
    ~Game();

    void draw();

    void save();

    void nextGeneration();

    bool isRunning();
};
