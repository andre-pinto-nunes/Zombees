#pragma once
#include <string>

class Missile {
	public:
		// direction = +1 ou -1
		Missile(int x, int y, int dir);
		Missile(const Missile& m) : Missile(m.position_x, m.position_y, m.direction){};
		~Missile(){};

		void move();

		int get_x() const {return position_x;}
		int get_y() const {return position_y;}
		int get_dir() const {return direction;}

	
	private:
		int position_x;
		int position_y;
		int vitesse;
		int direction;
};