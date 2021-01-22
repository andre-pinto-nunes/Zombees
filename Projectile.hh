#pragma once
#include <SFML/Graphics.hpp>

class Projectile {
	public:
		Projectile(int x, int y, int vit, int rot, int dmg);
		Projectile();
		~Projectile(){};

		void move();

		/*
		 * Renvoie la position X du projectile
		 */
		int get_x() const;

		/*
		 * Renvoie la position Y du projectile
		 */
		int get_y() const;

		/*
		 * Renvoie la rotation du projectile
		 */
		int get_rot() const;

		/*
		 * Renvoie les dégats du projectile
		 */
		int get_dmg() const;

		/*
		 * Renvoie le sprite du projectile
		 */
		sf::Sprite get_sprite();
		
		/*
 		 * Met à jour le sprite du projectile
 		 */
		void update_sprite();

	
	protected:
		int position_x;
		int position_y;
		int vitesse;
		int degats;
		int rotation;
		sf::Texture projectile_texture;
		sf::Sprite projectile;
};