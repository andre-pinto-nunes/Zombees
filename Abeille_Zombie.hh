#pragma once
#include "Abeille.hh"
#include <stdlib.h>
#include <time.h>


class Abeille_Zombie : public Abeille{
	public:
		Abeille_Zombie(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg);
		Abeille_Zombie();
		~Abeille_Zombie();


		int tir();

		void move(int x, int y);

	protected:
		int probabilite_de_tir;
		int compteur_mouvement;
};
