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
        return bala.getPosition().x > 1800;
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

//bala triple
void Personaje_Model::agregarBala(const Bala& bala) {
    _balas.push_back(bala);
}




/*#include "Personaje_Model.h"

Personaje_Model::Personaje_Model()
{
    velocidad = {0,0};
    _texture.loadFromFile("D:\\juego cccc2\\juego prueba 2\\ryu.jpg");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
    vida = 100;
    //AVANCE LEO
    //circle.setFillColor(sf::Color::Green);
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

sf::FloatRect Personaje_Model::getBounds() const
{
    return _sprite.getGlobalBounds();
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



void Personaje_Model::disparo() {
    Bala bala(_sprite.getPosition(), sf::Vector2f(1.f, 0.f), 10.f);
    _balas.push_back(bala);
}

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
/*void Personaje_Model::disparo()
{
    // Obtener la dirección actual del personaje
    sf::Vector2f direccion(1.f, 0.f); // Dirección predeterminada

    if (velocidad.x < 0) {
        direccion = sf::Vector2f(-1.f, 0.f);
    }
    else if (velocidad.x > 0) {
        direccion = sf::Vector2f(1.f, 0.f);
    }
    else if (velocidad.y < 0) {
        direccion = sf::Vector2f(0.f, -1.f);
    }
    else if (velocidad.y > 0) {
        direccion = sf::Vector2f(0.f, 1.f);
    }
    else {
        // Si el personaje no se está moviendo, usa la dirección predeterminada
    }

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
}*/

//lEO AVANCE
/*void Personaje_Model::mover(sf::RenderWindow& window, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key rightKey)
{
    if (sf::Keyboard::isKeyPressed(upKey))
    {
        if (circle.getPosition().y - movementSpeed >= 0)
            circle.move(0, -movementSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(downKey))
    {
        if (circle.getPosition().y + circle.getGlobalBounds().height + movementSpeed <= window.getSize().y)
            circle.move(0, movementSpeed);
    }

    if (sf::Keyboard::isKeyPressed(leftKey))
    {
        if (circle.getPosition().x - movementSpeed >= 0)
            circle.move(-movementSpeed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(rightKey))
    {
        if (circle.getPosition().x + circle.getGlobalBounds().width + movementSpeed <= window.getSize().x &&
            circle.getPosition().x + movementSpeed <= window.getSize().x)
            circle.move(movementSpeed, 0);
    }
}

void Personaje_Model::dibujar(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle, states);
}

const sf::CircleShape& Personaje_Model::getCircle() const
{
    return circle;
}*/
