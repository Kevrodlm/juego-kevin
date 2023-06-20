#include "Personaje_Model.h"


Personaje_Model::Personaje_Model()
{
    velocidad = {0,0};
    _texture.loadFromFile("D:\\juego cccc2\\juego prueba 2\\ryu.jpg");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
    vida = 100;

    
}


void Personaje_Model::setVida(int vida)
{
    this->vida = vida;
}




int Personaje_Model::getVida() const
{
    return vida;
}
void Personaje_Model::setPosition(const sf::Vector2f& position)
{
    _sprite.setPosition(position);
}

sf::Vector2f Personaje_Model::getPosition() const
{
    return _sprite.getPosition();
}
//hitbox
sf::FloatRect Personaje_Model::getHitbox() const
{
    return _sprite.getGlobalBounds();
}


void Personaje_Model::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        //_sprite.move(0,-4);
        velocidad.y=-4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        //_sprite.move(-4, 0);
        velocidad.x = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        //_sprite.move(0, 4);
        velocidad.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        //_sprite.move(4, 0);
        velocidad.x = 4;
    }

    _sprite.move(velocidad);
    
    //rotar a los lados
    if (velocidad.x < 0) {
        _sprite.setScale(-1, 1);
    }
    else if (velocidad.x > 0) {
        _sprite.setScale(1, 1);
    }

    //dejar de mover
    velocidad.x = velocidad.y = 0;



    // Condiciones de límites de la ventana
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 1800) {
        _sprite.setPosition(1800 -(_sprite.getGlobalBounds().width -_sprite.getOrigin().x), _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 900) {
        _sprite.setPosition(_sprite.getPosition().x, 900 +(_sprite.getGlobalBounds().height-_sprite.getOrigin().y));
    }
}

void Personaje_Model::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Personaje_Model::disparo()
{
    
    sf::Vector2f direccion(1.f, 0.f); // Cambia la dirección 
    /*if (velocidad.x < 0) {
        sf::Vector2f direccion(1.f, 0.f);;
    }
    else if (velocidad.x > 0) {
        sf::Vector2f direccion(0.f, 1.f);;
    }
    */
    float velocidad = 5.f; // Cambia la velocidad 

    Bala bala(_sprite.getPosition(), direccion, velocidad);
    _balas.push_back(bala);
}

void Personaje_Model::updateBalas()
{
    for (auto& bala : _balas)
    {
        bala.update();
    }

    _balas.erase(std::remove_if(_balas.begin(), _balas.end(),
        [](const Bala& bala) { return bala.getPosition().x >1800.f || bala.getPosition().x < 0.f; }),
        _balas.end());
}

