#include "Missile.hh"

Missile::Missile(int x, int y, int rot, int dmg) : Projectile(x, y, 10, rot, dmg) {
	projectile_texture.loadFromFile("img/missile.png");           
	projectile = sf::Sprite(projectile_texture);
	projectile.setPosition(position_x, position_y);
};

Missile::Missile(const Missile& m) : Missile(m.position_x, m.position_y, m.rotation, m.degats){};