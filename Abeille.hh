#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.hh"
#include <string>

class Abeille {
	public:
		Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg);
		Abeille() : Abeille(200, 752, 100, 15, 8, 10){};
		~Abeille(){};

		virtual void move()=0;
		void move(int x, int y);
		void animate(int anim);

		int get_x() const;
		int get_y() const;
		int get_degats() const;
		int get_rotation() const;
		int get_vitesse_de_attaque() const;

		void update_pos();
		void update_tex();
		void update_pv();

		bool dead(){return !points_de_vie;};

		void perte_points_de_vie(int dmg);

		std::string get_texture() const;
		sf::Sprite get_sprite() const;

		bool operator==(Abeille const& a) const;
		bool operator==(Missile const& a) const;


	protected:
		int position_x;
		int position_y;
		int points_de_vie;
		int points_de_vie_max;
		int vitesse;
		int degats;
		int vitesse_de_attaque;
		std::string str_texture;

		sf::Sprite sprite;
		sf::Texture texture;
		
		int rotation;
		
		int anim;

		sf::IntRect anim1;
        sf::IntRect anim2;

};