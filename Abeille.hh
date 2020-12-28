#pragma once
#include <string>

class Abeille {
	public:
		Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd);
		Abeille() : Abeille(176, 756, 100, 15, 8){};
		~Abeille(){};
		void move(int x, int y);

		int get_x() const {return position_x;}
		int get_y() const {return position_y;}
		int get_vitesse_de_attaque() const {return vitesse_de_attaque;}

		std::string get_texture() const {return texture;}

	
	protected:

		int position_x;
		int position_y;
		int points_de_vie;
		int vitesse;
		int vitesse_de_attaque;
		std::string texture;
};