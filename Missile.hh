#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.hh"

class Missile : public Projectile {
	public:
		Missile(int x, int y, int rot, int dmg) : Projectile(x, y, 10, rot, dmg, 100) {}; // vitesse de 10, toujours disponible
		Missile(const Missile& m) : Missile(m.position_x, m.position_y, m.rotation, m.degats){};
		~Missile(){};

};