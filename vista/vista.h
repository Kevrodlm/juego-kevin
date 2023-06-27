#pragma once
#include <SFML/Graphics.hpp>

//vista
//KEYBOARD____________________
//WASD:
bool keyboardPressW() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		return true;
	}
	return false;
}
bool keyboardPressS() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		return true;
	}
	return false;
}
bool keyboardPressA() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		return true;
	}
	return false;
}
bool keyboardPressD() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		return true;
	}
	return false;
}
//Flechas:
bool keyboardPressUp() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		return true;
	}
	return false;
}
bool keyboardPressDown() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		return true;
	}
	return false;
}
bool keyboardPressRight() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		return true;
	}
	return false;
}
bool keyboardPressLeft() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return true;
	}
	return false;
}


//sprite 
class sprite : public sf::Drawable {
protected:
	sf::Texture _Texture;
	sf::Sprite _Sprite;
	int spr_position[2] = {}; //{x,y}
public:
	sprite(std::string spr_location, int x, int y){
		_Texture.loadFromFile(spr_location);
		spr_position[0] = x;
		spr_position[1] = y;
		_Sprite.setTexture(_Texture);
	}
	void Update() {
		_Sprite.setPosition(spr_position[0], spr_position[1]);
	}
};

class ViewPlayer : public sprite {
public:
	ViewPlayer(std::string spr_location, int x, int y) : sprite(spr_location, x, y){};
	void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(_Sprite, states);
	}
};
