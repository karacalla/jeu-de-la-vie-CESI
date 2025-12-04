#ifndef POO_UI_H
#define POO_UI_H
#include <cstdint>
// #include "Matrice.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Ui {

    private:
    uint16_t HEIGHT, WIDTH;
    const char livingCell = *"▓▓";
    const char deadCell = *"░░";


    public:
    sf::RenderWindow window; // changed this
    Ui();
    Ui(uint16_t HEIGHT_, uint16_t WIDTH_);
    ~Ui();

    void setSize(uint16_t HEIGHT_, uint16_t WIDTH_);

    const uint16_t getHeight() const;
    const uint16_t getWidth() const;

    void createWindow();
    void showWindow();
};


#endif //POO_UI_H
