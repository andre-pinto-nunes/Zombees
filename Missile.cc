#include "Missile.hh"

/*
Missile::Missile(){
	position_x = 100;
	position_y = 100;
	vitesse = 8;
}
*/

Missile::Missile(int x, int y, int dir){
	position_x = x;
	position_y = y;
	vitesse = 8;
	direction = dir;
}


void Missile::move(){
	if (direction<0)
	{
		position_y -= vitesse;
	}else{
		position_y += vitesse;
	}
}