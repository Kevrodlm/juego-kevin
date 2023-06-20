#pragma once
#include <SFML/Graphics.hpp>

class Bala;

class Personaje_Model : public sf::Drawable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    //modelo
    sf::Vector2f velocidad;
    int vida;
    std::vector<Bala> _balas;

public:
    Personaje_Model();

    void setVida(int vida);
    int getVida() const;
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    //hitbox
    sf::FloatRect getHitbox() const;

    void disparo();
    void updateBalas();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void update();


    const std::vector<Bala>& getBalas() const {
        return _balas;
    }

};



class Bala : public sf::Drawable
{
private:
    sf::RectangleShape _shape;
    sf::Vector2f _direccion;
    float _velocidad;

public:
    Bala(const sf::Vector2f& posicionInicial, const sf::Vector2f& direccion, float velocidad)
        : _direccion(direccion), _velocidad(velocidad)
    {
        _shape.setSize(sf::Vector2f(10.f, 10.f));
        _shape.setFillColor(sf::Color::Red);
        _shape.setPosition(posicionInicial);
    }

    void update()
    {
        _shape.move(_direccion * _velocidad);
    }

    sf::Vector2f getPosition() const
    {
        return _shape.getPosition();
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_shape, states);
    }
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
