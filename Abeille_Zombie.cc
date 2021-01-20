#include "Abeille_Zombie.hh"


Abeille_Zombie::Abeille_Zombie(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg) : Abeille(x, y, pv, atk_spd, mvmt_spd, dmg){
	rotation = 180;
	compteur_mouvement = 0;
	probabilite_de_tir = 2;
	srand( (unsigned)time(NULL) ); // generation d'une seed pour la fonction de tir
}

Abeille_Zombie::Abeille_Zombie() : Abeille(){};
Abeille_Zombie::~Abeille_Zombie(){};

void Abeille_Zombie::move(int x, int y){
	int range = 50;
	compteur_mouvement++;
	if (compteur_mouvement < range) {position_x++;}
	else if (compteur_mouvement == range) {position_y += 8;}
	else if (compteur_mouvement == range*2){
		compteur_mouvement = 0;
		position_y += 8;
	}
	else {
		position_x--;
	}
}

/*
 * Fonction de tir:
 * Indique si l'abeille peut tirer
 * Un zombie tire avec une probabilité de 1/100 * (probabilité_de_tir) (sachant que la fonction est appelée 30 fois par seconde)
 */
int Abeille_Zombie::tir(){

	if (!(rand()%(probabilite_de_tir*100))) return 1;

	return 0;
}
