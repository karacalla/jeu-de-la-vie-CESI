#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Ui.h"

int main() {
    Ui HUD;
    HUD.showWindow();
    while (HUD.window.isOpen()) {
        while (const std::optional event = HUD.window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                HUD.window.close();
            }




        }
    }
}
