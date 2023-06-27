
#pragma once

#include <SFML/Graphics.hpp>

class Bala : public sf::Drawable {
private:
    sf::RectangleShape _shape;
    sf::Vector2f _direccion;
    float _velocidad;

public:
    Bala(const sf::Vector2f& posicionInicial, const sf::Vector2f& direccion, float velocidad);
    void update();
    sf::Vector2f getPosition() const;
    void setDireccion(const sf::Vector2f& direccion);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
