#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.hh"

class Gelee_Royale : public Projectile {
	public:
		Gelee_Royale(int x, int y) : Projectile(x, y, 10, 180, 10, 0) { // la gelee fait un total de ~50 dmg car elle traverse lennemi et rentre en colision plusieures fois
//			projectile_texture.loadFromFile("img/gelee.png");
//			projectile = sf::Sprite(projectile_texture,sf::IntRect(0, 0, 260, 30));
		};
		~Gelee_Royale(){};

//		void set_disponibilite(int dispo) {disponibilite = dispo;}
//		void update_sprite(); // modifie le sprite a afficher en fonction de la disponibilite


};
