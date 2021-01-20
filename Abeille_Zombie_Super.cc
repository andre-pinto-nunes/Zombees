#include "Abeille_Zombie_Super.hh"


Abeille_Zombie_Super::Abeille_Zombie_Super(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg) : Abeille_Zombie(x, y, pv, atk_spd, mvmt_spd, dmg){
			texture = sf::Texture();
			texture.loadFromFile("img/super_zombie_HP.png");           // Chargement de la texture à partir d'un fichier
			sprite = sf::Sprite(texture);
			sprite.setRotation(rotation);
			str_texture = "img/super_zombie_HP.png";
			probabilite_de_tir = 4;
}

Abeille_Zombie_Super::Abeille_Zombie_Super(int x, int y) : Abeille_Zombie_Super(x, y, 200, 10, 8, 20){};
Abeille_Zombie_Super::Abeille_Zombie_Super() : Abeille_Zombie_Super(176, 756, 200, 10, 8, 20){};
Abeille_Zombie_Super::~Abeille_Zombie_Super(){};

