#include "colisionable_View.h"
bool Colision::isCollision(Colision& obj)const {
	return getBounds().intersects(obj.getBounds());

}
