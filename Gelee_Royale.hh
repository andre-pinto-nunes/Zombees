#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.hh"

class Gelee_Royale : public Projectile {
	public:
		// la gelee fait un total de ~50 dmg car elle traverse l'ennemi et rentre en colision plusieures fois
		Gelee_Royale(int x, int y);
		~Gelee_Royale(){};
};
