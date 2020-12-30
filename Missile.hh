#pragma once
#include <string>

class Missile {
	public:
		Missile(int x, int y, int dir, int dmg);
		Missile(const Missile& m) : Missile(m.position_x, m.position_y, m.rotation, m.degats){};
		~Missile(){};

		void move();

		int get_x() const {return position_x;}
		int get_y() const {return position_y;}
		int get_rot() const {return rotation;}
		int get_dmg() const {return degats;}

	
	private:
		int position_x;
		int position_y;
		int vitesse;
		int degats;
		int rotation;
};