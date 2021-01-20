#include "Missile.hh"

Missile::Missile(int x, int y, int rot, int dmg) : Projectile(x, y, 10, rot, dmg, 100) {
	projectile_texture.loadFromFile("img/missile.png");           
	projectile = sf::Sprite(projectile_texture);
	projectile.setPosition(position_x, position_y);
}; // vitesse de 10, toujours disponible
Missile::Missile(const Missile& m) : Missile(m.position_x, m.position_y, m.rotation, m.degats){};

/*
Missile::Missile(int x, int y, int rot, int dmg){
	position_x = x;
	position_y = y;
	vitesse = 10;
	degats = dmg;
	rotation = rot;
}
*/

/*
void Missile::move(){
	if (rotation==180)
	{
		position_y -= vitesse;
	}else{
		position_y += vitesse;
	}
}
*/