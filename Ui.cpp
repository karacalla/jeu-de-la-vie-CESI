#include "Ui.h"
#include <cstdint>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

Ui::Ui() : HEIGHT(768), WIDTH(1024){
    std::cout << "[Ui] Constructeur par défaut (HAUTEUR=768, LARGEUR=1024)\n";
    createWindow();
    std::cout << "[Ui] Rejoice! Window created\n";
}

Ui::Ui(uint16_t HEIGHT_, uint16_t WIDTH_) {
    std::cout << "[Ui] Constructeur paramétré appelé avec (" << HEIGHT_ << ", " << WIDTH_ << ")\n";

    if (false) {
        std::cout << "[Ui] Taille customisée déclenchée";
            // nous avons supprimé le régulateur de taille minimum car nous avons
            //décidés d'utiliser un autre protocole
            // Nous l'intégrerons une fois que nous arrivons à
            // faire Ui et Parse marcher en parallèle
    } else {
        this->HEIGHT = HEIGHT_;
        this->WIDTH = WIDTH_;
    }

    std::cout << "[Ui] Taille finale : H=" << this->HEIGHT << " W=" << this->WIDTH << "\n";
    createWindow();
}

Ui::~Ui() {
    std::cout << "[Ui] Destructeur appelé\n";
}

void Ui::setSize(uint16_t HEIGHT_, uint16_t WIDTH_) {
    std::cout << "[Ui] setSize(" << HEIGHT_ << ", " << WIDTH_ << ")\n";

    if (false) {
        // voir ligne 19
    } else {
        this->HEIGHT = HEIGHT_;
        this->WIDTH = WIDTH_;
    }

    std::cout << "[Ui] Nouvelle taille : H=" << this->HEIGHT << " W=" << this->WIDTH << "\n";
    createWindow();
}

const uint16_t Ui::getHeight() const {
    std::cout << "[Ui] getHeight() -> " << this->HEIGHT << "\n";
    return this->HEIGHT;
}

const uint16_t Ui::getWidth() const {
    std::cout << "[Ui] getWidth() -> " << this->WIDTH << "\n";
    return this->WIDTH;
}

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
            std::cout << "[Ui] Événement reçu\n";

            const sf::Event& event = *eventOpt;

            if (event.is<sf::Event::Closed>()) {
                std::cout << "[Ui] Événement : fermeture de la fenêtre\n";
                window.close();
            } else {
                std::cout << "[Ui] Événement : autre\n";
            }
        }

        window.display();
    }

    std::cout << "[Ui] Sortie de la boucle showWindow() (fenêtre fermée)\n";
}
