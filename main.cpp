#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Rules.h"
#include "Matrice.h"
#include "Cell.h"
#include "Console.h"
#include "NextGen.h"

using namespace std;

int main() {
    Ui HUD;
    Console CON;
    Matrice mat;
    Cell cell;
    HUD.showWindow();
    while (HUD.window.isOpen()) {
        while (const std::optional event = HUD.window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                HUD.window.close();
            }
            if (UI == true) {
                HUD.window.draw(mat);
            } else if (CONSOLE == true) {
                CON.displayConsole(mat);
            }
            if (cptIterations == NB_ITERATIONS) {
                mat.saveMatrice();
                cptIterations = 0;
            }
            nextGeneration(mat, cell);
            cptIterations++;
        }
    }
}
