#include "Missile.hh"

Missile::Missile(){
	position_x = 100;
	position_y = 100;
	vitesse = 8;
}

void Missile::move(int y){
	if (y<0)
	{
		position_y -= vitesse;
	}else if (y>0){
		position_y += vitesse;
	}
}