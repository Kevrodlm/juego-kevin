#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable_View.h"

class item_Model: public sf::Drawable, public Colision
{
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	item_Model();
	void update();
	void respawn();
	void  draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	sf::FloatRect getBounds() const override;
};

