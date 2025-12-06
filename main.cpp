#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Matrice.h"
#include "Cell.h"
#include "Rules.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


int main() {
    Game game("C:\\Users\\arthu\\CLionProjects\\Jeu de la vie\\matrice", 1000);
    // Plus besoin de passer cellSize !

    while (game.isRunning() && (NB_ITERATIONS == 0 || cptIterations < NB_ITERATIONS)) {
        clock_t begin = clock();

        game.draw();

        game.nextGeneration();

        if (cptIterations % NB_IT_SAVE == 0) {
            game.save();
        }

        cptIterations++;

        if (clock () - begin < TIME) {
            while (clock () - begin < TIME) {}
        }
    }

    return 0;
}
