#include "Missile.hh"

Missile::Missile(int x, int y, int rot, int dmg){
	position_x = x;
	position_y = y;
	vitesse = 10;
	degats = dmg;
	rotation = rot;
}


void Missile::move(){
	if (rotation==180)
	{
		position_y -= vitesse;
	}else{
		position_y += vitesse;
	}
}