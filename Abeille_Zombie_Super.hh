#pragma once
#include <string>
#include "Abeille_Zombie.hh"

class Abeille_Zombie_Super : public Abeille_Zombie{
	public:
		Abeille_Zombie_Super() : Abeille_Zombie(){texture = "super_zombie.png";};
		~Abeille_Zombie_Super(){};

};
