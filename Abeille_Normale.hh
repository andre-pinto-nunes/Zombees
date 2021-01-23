#pragma once
#include <string>
#include "Abeille.hh"
#include "Gelee_Royale.hh"

class Abeille_Normale : public Abeille{
	public:

		/*
		 * Constructeur
		 */
		Abeille_Normale();

		/*
		 * Destructeur
		 */
		~Abeille_Normale(){};

		/*
		 * Déplace l'abeille
		 */
		void move(int x, int y);

		/*
		 * Indique si l'abeille peut tirer
		 */
		int tir();

		/*
		 * Charge la barre de gelée de 1 point
		 */
		void incremente_chargement();

		/*
		 * Renvoie le sprite de la barre de chargement
		 */
		sf::Sprite get_chargement() const;

		/*
		 * Indique si la barre de gelée est chargée
		 */
		int get_gelee_chargee() const;
		
		/*
		 * Renvoie le nombre de charges
		 */
		int get_charges() const;

		/*
		 * Decremente le nombre de charges
		 */
		void decremente_charges();
		
		/*
		 * Remet le chargement de la gelee à 0 et met à jour le sprite
		 */
		void reset_gelee();
		
		/*
		 * Met à jour le sprite du chargement de gelee
		 */
		void update_chargement();

		/*
		 * Soigne l'abeille
		 */
		void operator+=(int a);


	private:

		int chargement_gelee;
		int gelee_chargee;
		int cooldown_tir;
		sf::Sprite sprite_chargement;
		sf::Texture texture_chargement;
		int charges;
};
