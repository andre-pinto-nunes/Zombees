#pragma once
#include <string>
#include "Abeille.hh"

class Abeille_Zombie : public Abeille{
	public:
		Abeille_Zombie(int x, int y, int pv, int atk_spd, int mvmt_spd) : Abeille(x, y, pv, atk_spd, mvmt_spd){};
		Abeille_Zombie() : Abeille(){};
		~Abeille_Zombie(){};
};
