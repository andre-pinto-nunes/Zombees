#include "Missile.hh"

Missile::Missile(int x, int y, int dir){
	position_x = x;
	position_y = y;
	vitesse = 10;
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