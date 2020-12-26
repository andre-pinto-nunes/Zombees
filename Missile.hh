#pragma once
#include <string>

class Missile {
	public:
		Missile();
		~Missile(){};
		void move(int y);

	
	private:

		int position_x;
		int position_y;
		int vitesse;
		std::string texture;
};