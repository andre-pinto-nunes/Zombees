#pragma once
#include <string>
#include "Abeille.hh"

class Abeille_Zombie : public Abeille{
	public:
		Abeille_Zombie(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg) : Abeille(x, y, pv, atk_spd, mvmt_spd, dmg){rotation = 180; compteur_mouvement = 0;};
		Abeille_Zombie() : Abeille(){};
		~Abeille_Zombie(){};

		void move(){
			int range = 50;
			compteur_mouvement++;
			if (compteur_mouvement < range) {position_x++;}
			else if (compteur_mouvement == range) {position_y += 8;}
			else if (compteur_mouvement == range*2){
				compteur_mouvement = 0;
				//position_x--;
				position_y += 8;
			}
			else {position_x--;}

		}

	protected:
		int probabilite_de_tir;
		int compteur_mouvement;
};
