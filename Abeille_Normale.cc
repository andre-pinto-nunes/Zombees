#include "Abeille_Normale.hh"

/*
 * Constructeur
 */
Abeille_Normale::Abeille_Normale() : Abeille(){

	// Init Abeille
	texture.loadFromFile("img/abeille_HP.png");			// Chargement de la texture à partir d'un fichier
	sprite = sf::Sprite(texture);						// Creation d'un sprite a partir de la texture
	sprite.setPosition(position_x, position_y);			// Mise à jour de la position
	str_texture = "img/abeille_HP.png";
	rotation = 0;
	gelee_chargee = 0;
	chargement_gelee = 0;
	cooldown_tir = 1;
	
	// Init Mana
	texture_chargement.loadFromFile("img/mana.png");           
	sprite_chargement = sf::Sprite(texture_chargement);
	sprite_chargement.setPosition(position_x, position_y + 5);
	sprite_chargement.setTextureRect(sf::IntRect(0, 817, 50, 43));
};

/*
 * Déplace l'abeille
 */
void Abeille_Normale::move(int x, int y){
	if (x<0){
		position_x -= vitesse;
	}else if (x>0){
		position_x += vitesse;
	}

	if (y<0){
		position_y -= vitesse;
	}else if (y>0){
		position_y += vitesse;
	}

	update_pos();
	update_chargement();
};

/*
 * Indique si l'abeille peut tirer
 */
int Abeille_Normale::tir(){
	if (!(--cooldown_tir))
	{
		cooldown_tir = 30/vitesse_de_attaque;
		return 1;
	}
	return 0;
};

/*
 * Charge la barre de gelée de 1 point
 */
void Abeille_Normale::incremente_chargement(){
	if (++chargement_gelee > 19){
		chargement_gelee = 19;
		gelee_chargee = 1;
	}
	update_chargement();
}

/*
 * Renvoie le sprite de la barre de chargement
 */
sf::Sprite Abeille_Normale::get_chargement() const {return sprite_chargement;};

/*
 * Indique si la barre de gelée est chargée
 */
int Abeille_Normale::get_gelee_chargee() const {return gelee_chargee;}

/*
 * Remet le chargement de la gelee à 0 et met à jour le sprite
 */
void Abeille_Normale::reset_gelee() {
	gelee_chargee = 0;
	chargement_gelee = 0;
	update_chargement();
}

/*
 * Met à jour le sprite du chargement de gelee
 */
void Abeille_Normale::update_chargement() {
	sprite_chargement.setPosition(position_x, position_y + 5);
	sprite_chargement.setTextureRect(sf::IntRect(0, 817 - (chargement_gelee * 43), 50, 43));
}