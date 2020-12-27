#pragma once
#include <string>
#include "Abeille.hh"

class Abeille_Normale : public Abeille{
	public:
		Abeille_Normale() : Abeille(){texture = "abeille.png";};
		~Abeille_Normale(){};

};
