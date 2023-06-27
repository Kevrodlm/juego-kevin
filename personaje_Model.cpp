#include "Personaje_Model.h"

Personaje_Model::Personaje_Model() {
    velocidad = { 0,0 };
    _texture.loadFromFile("D:\\juego cccc2\\juego prueba 2\\ryu.jpg");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    vida = 100;
}

void Personaje_Model::setVida(int vida) {
    this->vida = vida;
}

int Personaje_Model::getVida() const {
    return vida;
}

void Personaje_Model::setPosition(const sf::Vector2f& position) {
    _sprite.setPosition(position);
}

sf::Vector2f Personaje_Model::getPosition() const {
    return _sprite.getPosition();
}

sf::FloatRect Personaje_Model::getHitbox() const {
    return _sprite.getGlobalBounds();
}

void Personaje_Model::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        mover(sf::Vector2f(0.f, -1.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mover(sf::Vector2f(-1.f, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        mover(sf::Vector2f(0.f, 1.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mover(sf::Vector2f(1.f, 0.f));
    }

    _sprite.move(velocidad);

    if (velocidad.x < 0) {
        _sprite.setScale(-1, 1);
    }
    else if (velocidad.x > 0) {
        _sprite.setScale(1, 1);
    }

    velocidad.x = velocidad.y = 0;

    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
}

void Personaje_Model::disparo() {
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

    Bala bala(_sprite.getPosition(), direccion, 10.f);
    _balas.push_back(bala);
}

void Personaje_Model::updateBalas() {
    for (auto& bala : _balas) {
        bala.update();
    }

    _balas.erase(std::remove_if(_balas.begin(), _balas.end(), [](const Bala& bala) {
        return bala.getPosition().x > 800;
        }), _balas.end());
}

void Personaje_Model::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
    for (const auto& bala : _balas) {
        target.draw(bala, states);
    }
}

void Personaje_Model::mover(const sf::Vector2f& direccion) {
    velocidad += direccion;
}

const std::vector<Bala>& Personaje_Model::getBalas() const {
    return _balas;
}

sf::FloatRect Personaje_Model::getBounds() const {
    return _sprite.getGlobalBounds();
}
