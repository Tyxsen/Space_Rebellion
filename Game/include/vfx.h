#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class VFXSprite {
public:
    // Constructeur
    VFXSprite();

    // Ajoute un effet � une position sp�cifique
    void addEffect(const sf::Vector2f& position);

    // Met � jour les animations des effets
    void update(float deltaTime);

    // Affiche les effets dans la fen�tre
    void render(sf::RenderWindow& window);


    static std::shared_ptr<VFXSprite> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<VFXSprite>(new VFXSprite());
        }
        return instance;
    }

    void setTexture(const std::vector<sf::Texture>& newTextures) { textures = newTextures;}
    void setFrameTime(float newFrameTime) { frameTime = newFrameTime;  }

private:
    static std::shared_ptr<VFXSprite> instance;
    struct Effect {
        sf::Sprite sprite;
        float currentTime;  // Temps actuel de l'animation
        size_t currentFrame; // Cadre actuel de l'animation
        bool finished;       // Indique si l'animation est termin�e
    };

    std::vector<sf::Texture> textures; // Textures des frames d'animation
    float frameTime;                   // Temps par frame (en secondes)
    std::vector<Effect> effects;       // Liste des effets actifs
};