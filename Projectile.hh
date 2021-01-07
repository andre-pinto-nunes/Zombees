#pragma once
#include <SFML/Graphics.hpp>

class Projectile {
	public:
		Projectile() : 	position_x(-1),
						position_y(-1),
						vitesse(0),
						degats(0),
						rotation(0),
						disponibilite(0){};
		Projectile(int x, int y, int vit, int rot, int dmg, int dispo);
		~Projectile(){};

		void move();

		int get_x() const {return position_x;}
		int get_y() const {return position_y;}
		int get_rot() const {return rotation;}
		int get_dmg() const {return degats;}
		int get_disponibilite() const {return disponibilite;}
		inline bool is_available() const {return (disponibilite == 100);}

	
	protected:
		int position_x;
		int position_y;
		int vitesse;
		int degats;
		int rotation;
		int disponibilite; // entre 0 et 100, 100 si dispo
};