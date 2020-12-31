#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.hh"
#include <string>

class Abeille {
	public:

		/*
 		 * Constructeur
 		 */
		Abeille(int x, int y, int pv, int atk_spd, int mvmt_spd, int dmg);

		/*
		 * Constructeur
		 */
		Abeille() : Abeille(200, 752, 100, 15, 8, 10){};

		/*
		 * Destructeur
		 */
		~Abeille(){};

		/*
		 * Déplacement automatique
		 */
		virtual void move()=0;

		/*
		 * Déplace l'abeille
		 */
		void move(int x, int y);

		/*
		 * Change la texture de l'abeille periodiquement
		 */
		void animate(int anim);

		/*
		 * Vérifie si l'abeille touche une abeille ennemie
		 */
		bool operator==(Abeille const& a) const;

		/*
		 * Vérifie si l'abeille touche un missile
		 */
		bool operator==(Missile const& a) const;

		/*
		 * Renvoie la valeur de position_x
		 */
		int get_x() const;

		/*
		 * Renvoie la valeur de position_y
		 */		
		int get_y() const;
		
		/*
		 * Renvoie la valeur de degats
		 */
		int get_degats() const;
		
		/*
		 * Renvoie la valeur de rotation
		 */
		int get_rotation() const;
		
		/*
		 * Renvoie la valeur de vitesse_de_attaque
		 */
		int get_vitesse_de_attaque() const;

		/*
		 * Syncronise les coordonées du sprite (affichage) avec celles de l'objet
		 */
		void update_pos();

		/*
		 * Met à jour l'affichage de l'abeille
		 */
		void update_tex();
		
		/*
		 * Met à jour l'affichage de la barre de points de vie
		 */
		void update_pv();

		/*
		 * Indique si l'abeille est morte
		 */
		bool dead();

		/*
		 * Diminue les points de vie selon les dégats reçus.
		 * Si les dégats sont supérieurs aux points de vie, met les points de vie à 0
		 */
		void perte_points_de_vie(int dmg);
		
		/*
		 * Renvoie le nom de la texture
		 */
		std::string get_texture() const;

		/*
		 * Renvoie le sprite à afficher
		 */
		sf::Sprite get_sprite() const;



	protected:
		int position_x;
		int position_y;
		int points_de_vie;
		int points_de_vie_max;
		int vitesse_de_attaque;
		int rotation;
		int vitesse;
		int degats;
		int anim;
		sf::IntRect anim1;
        sf::IntRect anim2;
		sf::Sprite sprite;
		sf::Texture texture;
		std::string str_texture;

};