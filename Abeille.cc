#include "Abeille.hh"

Abeille::Abeille(){
	position_x = 176;
	position_y = 756;
	points_de_vie = 100;
	vitesse_de_attaque = 15; // max = 30
	vitesse = 8;
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