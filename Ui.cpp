#include "Ui.h"
#include <cstdint>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

Ui::Ui() : HEIGHT(768), WIDTH(1024){}

Ui::Ui(uint16_t HEIGHT_, uint16_t WIDTH_) {
    if (HEIGHT_ < 400 || WIDTH_ < 400) {
        this->HEIGHT = 768;
        this->WIDTH = 1024;
    } else {
        this->HEIGHT = HEIGHT_;
        this->WIDTH = WIDTH_;
    }
    createWindow();
}

Ui::~Ui() {}


void Ui::setSize(uint16_t HEIGHT_, uint16_t WIDTH_) {
    if (HEIGHT_ < 400 || WIDTH_ < 400) {
        this->HEIGHT = 768;
        this->WIDTH = 1024;
    } else {
        this->HEIGHT = HEIGHT_;
        this->WIDTH = WIDTH_;
    }
    createWindow();
}

const uint16_t Ui::getHeight() const {return this->HEIGHT;}
const uint16_t Ui::getWidth() const {return this->WIDTH;}

void Ui::createWindow() {
    window.create(sf::VideoMode({this->WIDTH, this->HEIGHT}), "Jeu de la vie Groupe D", sf::Style::Close | sf::Style::Titlebar, sf::State::Windowed);
}

void Ui::showWindow() {
    window.display();
}

void Ui::showMatrice(Matrice mat) {}
