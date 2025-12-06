#pragma once
#include <SFML/Graphics.hpp>
#include "Matrice.h"

class Ui {
private:
    sf::RenderWindow window;
    int cellSize;
    sf::RectangleShape cellShape;

public:
    Ui(int width, int height, int cellSize_);
    ~Ui();

    void drawUi(Matrice& mat);
    bool isOpen();
    void handleEvents();
    void clear();
    void display();
};
