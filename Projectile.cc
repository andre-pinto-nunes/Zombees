#include <SFML/Graphics.hpp>
#include "Projectile.hh"

Projectile::Projectile(int x, int y, int vit, int rot, int dmg, int dispo){
	position_x = x;
	position_y = y;
	vitesse = vit;
	degats = dmg;
	rotation = rot;
	disponibilite = dispo;
}

void Projectile::move(){
	if (rotation == 180) 	position_y -= vitesse;
	else 					position_y += vitesse;
}

