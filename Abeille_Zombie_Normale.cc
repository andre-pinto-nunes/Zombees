#include "Abeille_Zombie_Normale.hh"


Abeille_Zombie_Normale::Abeille_Zombie_Normale(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg) : Abeille_Zombie(x, y, pv, atk_spd, mvmt_spd, dmg){

			// Chargement de la texture à partir d'un fichier
			texture.loadFromFile("img/zombie_HP.png");

			// Création d'un sprite à partir d'une texture
			sprite = sf::Sprite(texture);
			
			// Rotation du sprite
			sprite.setRotation(rotation);			
			probabilite_de_tir = 4;
}

Abeille_Zombie_Normale::Abeille_Zombie_Normale(int x, int y) : Abeille_Zombie_Normale(x, y, 200, 10, 8, 20){};
Abeille_Zombie_Normale::Abeille_Zombie_Normale() : Abeille_Zombie_Normale(176, 756, 200, 10, 8, 20){};
Abeille_Zombie_Normale::~Abeille_Zombie_Normale(){};

