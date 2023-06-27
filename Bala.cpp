#include "Bala.h"

Bala::Bala(const sf::Vector2f& posicionInicial, const sf::Vector2f& direccion, float velocidad) {
    _shape.setSize(sf::Vector2f(10.f, 5.f));
    _shape.setFillColor(sf::Color::Red);
    _shape.setPosition(posicionInicial);
    _direccion = direccion;
    _velocidad = velocidad;
}

void Bala::update() {
    _shape.move(_direccion * _velocidad);
}

sf::Vector2f Bala::getPosition() const {
    return _shape.getPosition();
}

void Bala::setDireccion(const sf::Vector2f& direccion) {
    _direccion = direccion;
}

void Bala::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_shape, states);
}


