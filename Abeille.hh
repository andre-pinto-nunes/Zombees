#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Abeille {
	public:
		Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd);
		Abeille() : Abeille(176, 756, 100, 15, 8){};
		~Abeille(){};

		void move(int x, int y);
		void animate(int anim);

		int get_x() const;
		int get_y() const;
		int get_rotation() const;
		int get_vitesse_de_attaque() const;

		void update_pos();
		void update_tex();

		std::string get_texture() const;
		sf::Sprite get_sprite() const;

		bool operator==(Abeille const& a) const;

	protected:

		int position_x;
		int position_y;
		int points_de_vie;
		int vitesse;
		int vitesse_de_attaque;
		std::string str_texture;

		sf::Sprite sprite;
		sf::Texture texture;
		
		int rotation;
		
		int anim;

		sf::IntRect anim1;
        sf::IntRect anim2;

};