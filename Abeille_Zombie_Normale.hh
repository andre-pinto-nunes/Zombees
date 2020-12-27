#pragma once
#include <string>
#include "Abeille_Zombie.hh"

class Abeille_Zombie_Normale : public Abeille_Zombie{
	public:
		Abeille_Zombie_Normale() : Abeille_Zombie(){texture = "zombie.png";};
		~Abeille_Zombie_Normale(){};

};
