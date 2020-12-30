#include "Abeille.hh"

Abeille::Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg){
	position_x = x;
	position_y = y;
	points_de_vie = pv;
	points_de_vie_max = pv;
	vitesse_de_attaque = atk_spd; // max = 30
	vitesse = mvmt_spd;
	degats = 100;
	anim = 0;
	anim1 = sf::IntRect(50, 0, 50, 43);
    anim2 = sf::IntRect(0, 0, 50, 43);
}


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

void Abeille::animate(int anim) {
	update_pv();
	if (anim < 15){
		sprite.setTextureRect(anim1);
	}else{
		sprite.setTextureRect(anim2);
	}
}
void Abeille::update_pv(){
	 if (points_de_vie < points_de_vie_max/5)
	{
		anim1 = sf::IntRect(50, 215, 50, 43);
    	anim2 = sf::IntRect(0,  215, 50, 43);
	} else if (points_de_vie < 2*points_de_vie_max/5)
	{
		anim1 = sf::IntRect(50, 172, 50, 43);
    	anim2 = sf::IntRect(0,  172, 50, 43);
	} else if (points_de_vie < 3*points_de_vie_max/5)
	{
		anim1 = sf::IntRect(50, 129, 50, 43);
    	anim2 = sf::IntRect(0,  129, 50, 43);
	} else if (points_de_vie < 4*points_de_vie_max/5)
	{
		anim1 = sf::IntRect(50, 86, 50, 43);
    	anim2 = sf::IntRect(0,  86, 50, 43);
	} else if (points_de_vie < points_de_vie_max)
	{
		anim1 = sf::IntRect(50, 43, 50, 43);
    	anim2 = sf::IntRect(0,  43, 50, 43);
	} else
	{
		anim1 = sf::IntRect(50, 0, 50, 43);
    	anim2 = sf::IntRect(0,  0, 50, 43);
	}
}

bool Abeille::operator==(Abeille const& a) const{
	
	// Si les deux abeilles sont 'amies' il n'y a pas de colision
	if (a.get_rotation() == rotation)
	{
		return 0;
	}

	int x_zombie;
	int y_zombie;
	int x_joueur;
	int y_joueur;

	
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


	if (x_joueur < x_zombie - 65 || x_joueur > x_zombie - 35)
	{
		return 0;
	}

	if (y_joueur < y_zombie - 80 || y_joueur > y_zombie - 5)
	{
		return 0;
	}
	return 1;

}


bool Abeille::operator==(Missile const& a) const{

	// Pas de friendly fire
	if (a.get_rot() != rotation)
	{
		return 0;
	}

	if (a.get_x() < position_x - 30 || a.get_x() > position_x)
	{
		return 0;
	}

	if (a.get_y() < position_y - 50 || a.get_y() > position_y + 10)
	{
		return 0;
	}
	return 1;
}


void Abeille::perte_points_de_vie(int dmg){
	points_de_vie -= dmg;
	if (points_de_vie < 0) points_de_vie = 0;
};


int Abeille::get_x() const {return position_x;}
int Abeille::get_y() const {return position_y;}
int Abeille::get_degats() const {return degats;}
int Abeille::get_rotation() const {return rotation;}
int Abeille::get_vitesse_de_attaque() const {return vitesse_de_attaque;}

void Abeille::update_pos(){sprite.setPosition(position_x, position_y);}
void Abeille::update_tex(){sprite.setTexture(texture);}

std::string Abeille::get_texture() const {return str_texture;}
sf::Sprite  Abeille::get_sprite()  const {return sprite;}