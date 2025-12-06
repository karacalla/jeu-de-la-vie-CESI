#include "Ui.h"
#include <SFML/Graphics.hpp>

Ui::Ui(int width, int height, int cellSize_)
    : window(sf::VideoMode(width * cellSize_, height * cellSize_), "Jeu de la Vie Groupe D"),
      cellSize(cellSize_),
      cellShape(sf::Vector2f(cellSize_ - 1.0f, cellSize_ - 1.0f)) {
    cellShape.setFillColor(sf::Color::White);
}

Ui::~Ui() {
    if (window.isOpen()) {
        window.close();
    }
}

void Ui::drawUi(Matrice& mat) {
    window.clear(sf::Color::Black);

    for (int i = 0; i < mat.getRow(); i++) {
        for (int j = 0; j < mat.getColumn(); j++) {
            if (mat.matrice[i][j].getState() == 1) {
                cellShape.setFillColor(sf::Color::White);
                cellShape.setPosition(j * cellSize, i * cellSize);
                window.draw(cellShape);
            }

            if (mat.matrice[i][j].getLockState()) {
                if (mat.matrice[i][j].getState() == 1) {
                    cellShape.setFillColor(sf::Color::Green);
                } else {
                    cellShape.setFillColor(sf::Color::Blue);
                }
                cellShape.setPosition(j * cellSize, i * cellSize);
                window.draw(cellShape);
            }
        }
    }

    window.display();
}

bool Ui::isOpen() {
    return window.isOpen();
}

void Ui::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Touche Espace pour pause (optionnel)
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }
}

void Ui::clear() {
    window.clear(sf::Color::Black);
}

void Ui::display() {
    window.display();
}
