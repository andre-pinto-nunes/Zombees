#pragma once
#include <string>
#include "Abeille.hh"

class Abeille_Zombie : public Abeille{
	public:
		Abeille_Zombie() : Abeille(){texture = "zombie.png";};
		~Abeille_Zombie(){};
};
