#include <SFML/Graphics.hpp>
#include "Personaje_Model.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 900), "SU PUTAMADRE LEO Y FABRI");
    window.setFramerateLimit(60);
    Personaje_Model personaje;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    personaje.disparo();
                }
            }
        }

        personaje.update();
        personaje.updateBalas();
        //update
        window.clear();
        //draw
        window.draw(personaje);
        //
        // Dibujar las balas
        for (const auto& bala : personaje.getBalas())
        {
            window.draw(bala);
        }

        window.display();
    }

    return 0;
}
