#include "Abeille_Zombie.hh"

int Abeille_Zombie::compteur_de_zombies = 0;

Abeille_Zombie::Abeille_Zombie(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg) : Abeille(x, y, pv, atk_spd, mvmt_spd, dmg){
	
	// chaque zombie a un id different
	id = compteur_de_zombies++;

	// Toutes les abeilles Zombies sont tournées vers la bas (le sprite devra être tourné de 180º)
	rotation = 180;

	// Compteur de mouvement pour la fonction move()
	compteur_mouvement = 0;

	// Par défaut, la probabilité de tir est de 2/100
	probabilite_de_tir = 2;

	// generation d'une seed pour la fonction de tir
	srand( (unsigned)time(NULL) );
}

Abeille_Zombie::Abeille_Zombie() : Abeille(){
		
	// chaque zombie a un id different
	id = compteur_de_zombies++;

	// Toutes les abeilles Zombies sont tournées vers la bas (le sprite devra être tourné de 180º)
	rotation = 180;

	// Compteur de mouvement pour la fonction move()
	compteur_mouvement = 0;

	// Par défaut, la probabilité de tir est de 2/100
	probabilite_de_tir = 2;

	// generation d'une seed pour la fonction de tir
	srand( (unsigned)time(NULL) );

};
Abeille_Zombie::~Abeille_Zombie(){};

/*
 * Fonction de déplacement des Zombies (zigzag):
 * Déplace les abeilles de 50 pixels vers la droite, ensuite 8 pixels vers le bas et 50 pixels vers la gauche
 */
void Abeille_Zombie::move(int x, int y){

	int range = 50;
	compteur_mouvement++;
	
	// 50 déplacements élémentaires vers la droite
	if (compteur_mouvement < range) {position_x++;}

	// un déplacement de 8 pixels vers le bas
	else if (compteur_mouvement == range) {position_y += 8;}

	// un déplacement de 8 pixels vers le bas et remise à 0 du compteur
	else if (compteur_mouvement == range*2){
		compteur_mouvement = 0;
		position_y += 8;
	}
	
	// 50 déplacements élémentaires vers la gauche
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


int Abeille_Zombie::get_id() const{return id;};

bool Abeille_Zombie::operator==(Gelee_Royale const& a) const{

	// Pas de friendly fire
	if (a.get_rot() != rotation) return 0;

	// Condition de colision sur l'axe horizontal
	if (a.get_x() < position_x - 30 || a.get_x() > position_x     ) return 0;

	// Condition de colision sur l'axe vertical
	if (a.get_y() < position_y - 50 || a.get_y() > position_y + 10) return 0;

	// Si on arrive sur cette ligne, le zombie est en contact avec la gelée

	// Si la gelée a deja infligé des degats au zombie, il n'y a pas de nouvelle colision
	std::vector<int> v = a.get_vecteur();
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		if (*i == id)
			return 0;

	return 1;
}


/*
 * Vérifie si l'abeille touche une abeille ennemie
 */
bool Abeille_Zombie::operator==(Abeille const& a) const{
	return Abeille::operator==(a);
};

/*
 * Vérifie si l'abeille touche un missile
 */
bool Abeille_Zombie::operator==(Missile const& a) const{
	return Abeille::operator==(a);
};