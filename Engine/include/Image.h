#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Image {

public:

    // Constructeur : initialise la fen�tre
    Image() = default;

    // M�thode pour charger une image PNG
    bool loadImage(const std::string& filePath);

    // M�thode pour afficher l'image
    void drawImage(sf::RenderWindow& window, float targetWidth, float targetHeight, float x, float y);

private:

    sf::Texture texture;      // Texture pour charger l'image
    sf::Sprite sprite;        // Sprite pour afficher l'image

};