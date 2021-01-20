#include "Abeille.hh"

/*
 * Constructeur
 */
Abeille::Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg){
	position_x = x;
	position_y = y;
	points_de_vie = pv;
	points_de_vie_max = pv;
	vitesse_de_attaque = atk_spd; // max = 30
	vitesse = mvmt_spd;
	degats = dmg;
	anim = 0;
	anim1 = sf::IntRect(50, 0, 50, 43);
    anim2 = sf::IntRect(0, 0, 50, 43);
}

/*
 * Déplace l'abeille
 */
/*

void Abeille::move(int x, int y){
	if (x<0)
	{
		position_x -= vitesse;
	}else if (x>0){
		position_x += vitesse;
	}

	if (y<0)
	{
		position_y -= vitesse;
	}else if (y>0){
		position_y += vitesse;
	}
}

*/


/*
 * Change la texture de l'abeille periodiquement
 */
void Abeille::animate(int anim) {
	update_pv();
	if (anim < 15){
		sprite.setTextureRect(anim1);
	}else{
		sprite.setTextureRect(anim2);
	}
}

/*
 * Vérifie si l'abeille touche une abeille ennemie
 */
bool Abeille::operator==(Abeille const& a) const{

	// Si les deux abeilles sont 'amies' il n'y a pas de colision
	if (a.get_rotation() == rotation) return 0;

	int x_zombie, y_zombie, x_joueur, y_joueur;

	// Si la rotation de 'this' est non-nulle alors, 'this' est un zombie
	if (rotation)
	{
		x_zombie = position_x;
		y_zombie = position_y;

		x_joueur = a.get_x();
		y_joueur = a.get_y();
	}else{
		x_joueur = position_x;
		y_joueur = position_y;

		x_zombie = a.get_x();
		y_zombie = a.get_y();
	}
	
	if (x_joueur < x_zombie - 65 || x_joueur > x_zombie - 35) return 0;
	if (y_joueur < y_zombie - 80 || y_joueur > y_zombie - 5)  return 0;

	// Il y a une collision seulement si les corps des abeilles se touchent (pas les ailes)
	return 1;
}

/*
 * Vérifie si l'abeille touche un missile
 */
bool Abeille::operator==(Missile const& a) const{

	// Pas de friendly fire
	if (a.get_rot() != rotation) return 0;

	if (rotation)
	{
		if (a.get_x() < position_x - 30 || a.get_x() > position_x     ) return 0;

		if (a.get_y() < position_y - 50 || a.get_y() > position_y + 10) return 0;
	}
	else
	{
		if (a.get_x() < position_x      || a.get_x() > position_x + 30) return 0;

		if (a.get_y() < position_y - 20 || a.get_y() > position_y + 40) return 0;
	}

	// Il y a une collision seulement si le missile touche le corps de l'abeille (pas les ailes)
	return 1;
}

/*
 * Diminue les points de vie selon les dégats reçus.
 * Si les dégats sont supérieurs aux points de vie, met les points de vie à 0
 */
void Abeille::perte_points_de_vie(int dmg){

	points_de_vie -= dmg;
	
	if (points_de_vie < 0) points_de_vie = 0;
};

/*
 * Renvoie la valeur de position_x
 */
int Abeille::get_x() const {return position_x;}

/*
 * Renvoie la valeur de position_y
 */
int Abeille::get_y() const {return position_y;}

/*
 * Renvoie la valeur de degats
 */
int Abeille::get_degats() const {return degats;}

/*
 * Renvoie la valeur de rotation
 */
int Abeille::get_rotation() const {return rotation;}

/*
 * Renvoie la valeur de vitesse_de_attaque
 */
int Abeille::get_vitesse_de_attaque() const {return vitesse_de_attaque;}

/*
 * Renvoie le nom de la texture
 */
std::string Abeille::get_texture() const {return str_texture;}

/*
 * Renvoie le sprite à afficher
 */
sf::Sprite  Abeille::get_sprite()  const {return sprite;}

/*
 * Synchronise les coordonées du sprite (affichage) avec celles de l'objet
 */
void Abeille::update_pos(){sprite.setPosition(position_x, position_y);}

/*
 * Met à jour l'affichage de l'abeille
 */
void Abeille::update_tex(){sprite.setTexture(texture);}


/*
 * Met à jour l'affichage de la barre de points de vie
 */
void Abeille::update_pv(){
	if (points_de_vie < points_de_vie_max/5){

		anim1 = sf::IntRect(50, 215, 50, 43);
    	anim2 = sf::IntRect(0,  215, 50, 43);

	} else if (points_de_vie < 2*points_de_vie_max/5){

		anim1 = sf::IntRect(50, 172, 50, 43);
    	anim2 = sf::IntRect(0,  172, 50, 43);

	} else if (points_de_vie < 3*points_de_vie_max/5){

		anim1 = sf::IntRect(50, 129, 50, 43);
    	anim2 = sf::IntRect(0,  129, 50, 43);

	} else if (points_de_vie < 4*points_de_vie_max/5){

		anim1 = sf::IntRect(50, 86, 50, 43);
    	anim2 = sf::IntRect(0,  86, 50, 43);

	} else if (points_de_vie < points_de_vie_max){

		anim1 = sf::IntRect(50, 43, 50, 43);
    	anim2 = sf::IntRect(0,  43, 50, 43);

	} else {

		anim1 = sf::IntRect(50, 0, 50, 43);
    	anim2 = sf::IntRect(0,  0, 50, 43);
	}
}

/*
 * Indique si l'abeille est morte
 */
bool Abeille::dead(){return !points_de_vie;}
