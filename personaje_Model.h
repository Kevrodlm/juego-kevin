#pragma once

#include <SFML/Graphics.hpp>
#include "colisionable_View.h"
#include "Bala.h"

class Personaje_Model : public sf::Drawable, public Colision {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f velocidad;
    int vida;
    std::vector<Bala> _balas;

public:
    Personaje_Model();
    void setVida(int vida);
    int getVida() const;
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    sf::FloatRect getHitbox() const;
    void disparo();
    void updateBalas();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();
    void mover(const sf::Vector2f& direccion);
    const std::vector<Bala>& getBalas() const;
    sf::FloatRect getBounds() const override;


    void agregarBala(const Bala& bala);
};
class Jugador : public Personaje_Model
{
public:
    Jugador()
    {
        
    }
    
};

class Enemigo : public Personaje_Model
{
public:
    Enemigo()
    {
        
    }
   
};
