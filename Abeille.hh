#pragma once
#include <string>

class Abeille {
	public:
		Abeille();
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
		std::string texture; //différente si c'est un zombie ou une abeille normale
};