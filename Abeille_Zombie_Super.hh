#pragma once
#include <string>
#include "Abeille_Zombie.hh"

class Abeille_Zombie_Super : public Abeille_Zombie{
	public:
		Abeille_Zombie_Super(int x, int y, int pv, int atk_spd, int mvmt_spd) : Abeille_Zombie(x, y, pv, atk_spd, mvmt_spd){texture = "super_zombie.png";};
		Abeille_Zombie_Super(int x, int y) : Abeille_Zombie_Super(x, y, 200, 10, 8){};
		Abeille_Zombie_Super() : Abeille_Zombie_Super(176, 756, 200, 10, 8){};
		~Abeille_Zombie_Super(){};
};
