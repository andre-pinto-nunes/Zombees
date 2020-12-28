#include "Abeille.hh"

Abeille::Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd){
	position_x = x;
	position_y = y;
	points_de_vie = pv;
	vitesse_de_attaque = atk_spd; // max = 30
	vitesse = mvmt_spd;
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