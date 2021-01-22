#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.hh"

class Missile : public Projectile {
	public:
		Missile(int x, int y, int rot, int dmg);
		Missile(const Missile& m);
		~Missile(){};
};