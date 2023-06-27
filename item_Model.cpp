#include<stdlib.h>
#include "item_Model.h"
#include <SFML/Graphics.hpp>
item_Model::item_Model() {
	_texture.loadFromFile("mone.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height / 2);
}
void item_Model::update() {

}

void item_Model::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_sprite, states);
}
sf::FloatRect item_Model::getBounds() const
{
	return _sprite.getGlobalBounds();
}
void item_Model::respawn() {
	_sprite.setPosition(std::rand() % 1750 + _sprite.getGlobalBounds().width, std::rand() % 750+ _sprite.getGlobalBounds().height);//debemos tener en cuenta el tamaño del png o jpg
}
