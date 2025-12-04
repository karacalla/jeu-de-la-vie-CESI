#include "Ui.h"
#include <cstdint>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>


Ui::Ui() {
    std::cout << "[Ui] Constructeur par défaut\n";
    generateSize();   
    createWindow();
    std::cout << "[Ui] Rejoice! Window created\n";
}

// cleaned this up


Ui::~Ui() {
    std::cout << "[Ui] Destructeur appelé\n";
}

// cleaned this up too 


void Ui::createWindow() {
    std::cout << "[Ui] Création de la fenêtre... H=" << this->HEIGHT << " W=" << this->WIDTH << "\n";

    window.create(
        sf::VideoMode({this->WIDTH, this->HEIGHT}),
        "Jeu de la vie Groupe D",
        sf::Style::Close | sf::Style::Titlebar,
        sf::State::Windowed
    );

    if (window.isOpen())
        std::cout << "[Ui] Fenêtre créée avec succès !\n";
    else
        std::cout << "[Ui] Échec de la création de la fenêtre !!\n";
}

void Ui::showWindow() {
    std::cout << "[Ui] Entrée dans la boucle showWindow()...\n";

    while (window.isOpen()) {

        while (auto eventOpt = window.pollEvent()) {
            //removed bloat

            const sf::Event& event = *eventOpt;

            if (event.is<sf::Event::Closed>()) {
                std::cout << "[Ui] Événement : fermeture de la fenêtre\n";
                window.close();
            } else {
                //removed bloat
            }
        }

        window.display();
    }

    std::cout << "[Ui] Sortie de la boucle showWindow() (fenêtre fermée)\n";
}


void Ui::generateSize() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    unsigned int screenWidth  = desktop.size.x;
    unsigned int screenHeight = desktop.size.y;

    // DIMENSIONS DE LA MATRICE à intégrer
    unsigned int longueur = 10;
    unsigned int largeur = 5;




    WIDTH  = static_cast<uint16_t>(screenWidth  * 0.8f);
    HEIGHT  = static_cast<uint16_t>(screenHeight  * 0.8f);

    if (longueur > largeur) {
        HEIGHT = static_cast<uint16_t>((float)largeur / longueur * WIDTH);
    } else {

        WIDTH = static_cast<uint16_t>((float)longueur / largeur * HEIGHT);
    }

    CARREAU = WIDTH / largeur;

    std::cout << "[Ui] Taille magique de l'écran: H=" << HEIGHT 
              << " W=" << WIDTH << " C=" << CARREAU << "\n";
}
