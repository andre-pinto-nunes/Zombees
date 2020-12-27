#pragma once
#include <string>

class Missile {
	public:
		//Missile();
		Missile(int x, int y, int dir);
		~Missile(){};
		void move();

		int get_x() const {return position_x;}
		int get_y() const {return position_y;}

		bool operator <(const Missile &rhs) const {return id <= rhs.id;}

	
	private:
		int static id;
		int position_x;
		int position_y;
		int vitesse;
		int direction;
};