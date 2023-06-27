#pragma once
#include "Personaje_Model.h"
#include "item_Model.h"

class Bala_Triple_View : public item_Model {
public:
    Bala_Triple_View();
    void disparo(Personaje_Model& personaje);
};
