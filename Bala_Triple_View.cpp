#include "Bala_Triple_View.h"
#include "Personaje_Model.h"

Bala_Triple_View::Bala_Triple_View() : item_Model() {
    
}

void Bala_Triple_View::disparo(Personaje_Model& personaje) {
    sf::Vector2f direccion(1.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direccion = sf::Vector2f(-1.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        direccion = sf::Vector2f(0.f, 1.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direccion = sf::Vector2f(1.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        direccion = sf::Vector2f(0.f, -1.f);
    }

    // Crear tres balas en diferentes direcciones
    Bala bala1(personaje.getPosition(), direccion, 10.f);
    Bala bala2(personaje.getPosition(), direccion + sf::Vector2f(1.f, -1.f), 10.f);
    Bala bala3(personaje.getPosition(), direccion + sf::Vector2f(1.f, 1.f), 10.f);

    personaje.agregarBala(bala1);
    personaje.agregarBala(bala2);
    personaje.agregarBala(bala3);
}
