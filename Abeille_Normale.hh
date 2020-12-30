#pragma once
#include <string>
#include "Abeille.hh"

class Abeille_Normale : public Abeille{
	public:
		Abeille_Normale() : Abeille(){
			texture.loadFromFile("abeille_HP.png");           // Chargement de la texture à partir d'un fichier
			sprite = sf::Sprite(texture);
			sprite.setPosition(position_x, position_y);
			str_texture = "abeille_HP.png";
			rotation = 0;
		};
		~Abeille_Normale(){};

		void move(int x, int y){
			this->Abeille::move(x, y);
			update_pos();
		};

		void move(){printf("rien\n");};


};
