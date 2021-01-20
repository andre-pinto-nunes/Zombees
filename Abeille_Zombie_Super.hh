#pragma once
#include <string>
#include "Abeille_Zombie.hh"

class Abeille_Zombie_Super : public Abeille_Zombie{
	public:
		Abeille_Zombie_Super(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg);
		Abeille_Zombie_Super(int x, int y);
		Abeille_Zombie_Super();
		~Abeille_Zombie_Super();
};
