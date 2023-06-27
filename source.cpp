#include <SFML/Graphics.hpp>

#include "Personaje_Model.h"
#include "item_Model.h"

#include<ctime>
#include<stdlib.h>

int main()
{
    std::srand((unsigned)std::time(0));//para el random
    
    sf::RenderWindow window(sf::VideoMode(1800, 900), "SU PUTAMADRE LEO Y FABRI");//ventana
    window.setFramerateLimit(60);

    Personaje_Model personaje;//objetos
    item_Model moneda1;

    moneda1.respawn();//respawn monedita


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)
                {
                    personaje.mover(sf::Vector2f(-1.f, 0.f));
                    personaje.disparo();
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    personaje.mover(sf::Vector2f(0.f, 1.f));
                    personaje.disparo();
                }
                else if (event.key.code == sf::Keyboard::D)
                {
                    personaje.mover(sf::Vector2f(1.f, 0.f));
                    personaje.disparo();
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    personaje.mover(sf::Vector2f(0.f, -1.f));
                    personaje.disparo();
                }
            }
        }

        personaje.update();
        personaje.updateBalas();

        if (personaje.isCollision(moneda1)) {//colision item o moneda
            moneda1.respawn();
        }
                                               
        //update
        window.clear();
        
        
        window.draw(personaje);//draw
        window.draw(moneda1);
        
        // Dibujar las balas
        for (const auto& bala : personaje.getBalas())
        {
            window.draw(bala);
        }

        window.display();
    }

    return 0;
}
