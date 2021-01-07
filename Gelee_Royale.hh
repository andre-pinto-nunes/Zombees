#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.hh"

class Gelee_Royale : public Projectile {
	public:
		Gelee_Royale(int x, int y, int rot, int dmg) : Projectile(x, y, 15, rot, dmg, 0) {
			chargement_texture.loadFromFile("img/gelee_bar.png");
			chargement = sf::Sprite(chargement_texture,sf::IntRect(0, 0, 260, 30));
		};
		~Gelee_Royale(){};

		void set_disponibilite(int dispo) {disponibilite = dispo;}
		void update_sprite(); // modifie le sprite a afficher en fonction de la disponibilite

	private:
		sf::Texture chargement_texture;
		sf::Sprite chargement;
};