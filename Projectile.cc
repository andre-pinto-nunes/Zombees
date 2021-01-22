#include "Projectile.hh"

Projectile::Projectile(int x, int y, int vit, int rot, int dmg){
	position_x = x;
	position_y = y;
	vitesse = vit;
	degats = dmg;
	rotation = rot;
}

Projectile::Projectile() : 	position_x(-1),
							position_y(-1),
							vitesse(0),
							degats(0),
							rotation(0){};

void Projectile::move(){
	if (rotation == 180) 	position_y -= vitesse;
	else 					position_y += vitesse;
}


/*
 * Renvoie la position X du projectile
 */
int Projectile::get_x()	const	{return position_x;}

/*
 * Renvoie la position Y du projectile
 */
int Projectile::get_y()	const	{return position_y;}

/*
 * Renvoie la rotation du projectile
 */
int Projectile::get_rot()	const	{return rotation;}

/*
 * Renvoie les dégats du projectile
 */
int Projectile::get_dmg()	const	{return degats;}

/*
 * Renvoie le sprite du projectile
 */
sf::Sprite Projectile::get_sprite()	{return projectile;}

/*
 * Met à jour le sprite du projectile
 */
void Projectile::update_sprite(){
    projectile.setRotation(rotation);                      // Mise à jour de la rotation du sprite
    projectile.setPosition(position_x, position_y);        // Mise à jour de la position du sprite
}
