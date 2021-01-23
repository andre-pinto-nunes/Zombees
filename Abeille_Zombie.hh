#pragma once
#include "Abeille.hh"
#include "Gelee_Royale.hh"
#include <stdlib.h>
#include <time.h>


class Abeille_Zombie : public Abeille{
	public:
		Abeille_Zombie(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg);
		Abeille_Zombie();
		~Abeille_Zombie();
		
		int tir();

		void move(int x, int y);

		int get_id() const;

		bool operator==(Gelee_Royale const& a) const;

		/*
		 * Vérifie si l'abeille touche une abeille ennemie
		 */
		bool operator==(Abeille const& a) const;

		/*
		 * Vérifie si l'abeille touche un missile
		 */
		bool operator==(Missile const& a) const;


	protected:
		static int compteur_de_zombies;
		int id;
		int probabilite_de_tir;
		int compteur_mouvement;
};
