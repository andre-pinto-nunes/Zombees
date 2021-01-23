#pragma once
#include <vector>
#include "Projectile.hh"

class Gelee_Royale : public Projectile {
	public:
		// la gelee fait un total de ~50 dmg car elle traverse l'ennemi et rentre en colision plusieures fois
		Gelee_Royale(int x, int y);
		~Gelee_Royale(){};

		std::vector<int> get_vecteur() const;

		void nouvelle_colision(int a);

	private:
		// La gelee traverse les zombies donc on garde en memoire ceux qui ont deja ete touches pour qu'il n'y ait pas de colision a chaque frame
		std::vector<int> zombies_touches;
};
