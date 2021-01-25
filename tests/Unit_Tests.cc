#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Abeille.hh"
#include "Abeille_Normale.hh"
#include "Abeille_Zombie.hh"
#include "Abeille_Zombie_Normale.hh"
#include "Abeille_Zombie_Super.hh"
#include "Projectile.hh"
#include "Missile.hh"
#include "Gelee_Royale.hh"
#include <iostream>
#include <string>

TEST_CASE("Abeille - Initialisation")
{
  // Test de l'initialisation d'une abeille normale
  Abeille_Normale a_1;

  REQUIRE(a_1.get_x() == 200);					// Test get_x()
  REQUIRE(a_1.get_y() == 752);					// Test get_y()
  REQUIRE(a_1.get_degats() == 10);				// Test get_degats()
  REQUIRE(a_1.get_rotation() == 0);				// Test get_rotation()
  REQUIRE(a_1.get_vitesse_de_attaque() == 15);	// Test get_vitesse_de_attaque()
}

TEST_CASE("Abeille - Colision")
{

	/* ---------- Colision Normale-Normale ---------- */
  Abeille_Normale a_1;
  Abeille_Normale a_2;

  // Test colision : les abeilles ont les memes coordonées mais il n'y a pas de colision
  //                 car elles ne sont pas ennemies
  REQUIRE(a_1.get_x() == a_2.get_x());			
  REQUIRE(a_1.get_y() == a_2.get_y());			
  REQUIRE(!(a_1 == a_2));				

  	/* ---------- Colision Zombie-Zombie ---------- */
  Abeille_Zombie z_1;
  Abeille_Zombie z_2;

  // Test colision : les abeilles ont les memes coordonées mais il n'y a pas de colision
  //                 car elles ne sont pas ennemies
  REQUIRE(z_1.get_x() == z_2.get_x());			
  REQUIRE(z_1.get_y() == z_2.get_y());			
  REQUIRE(!(z_1 == z_2));						


	/* ---------- Colision Normale-Zombie ---------- */

  /* Test colision : les abeilles ont les memes coordonées mais il n'y a pas de colision
   *                car leurs sprites ne se touchent pas
   *
   * les coordonées du point d'ancrage (coin haut-gauche) n'ont pas bougé mais le sprite
   * a tourné 180º autour de ce point
   *
   * (donc le point d'ancrage d'un zombie se situe en bas à droite)
   */
  REQUIRE(!(a_1==z_1));

  // Test fonction move
  a_1.move(-1, -1);			// deplacement de  8 px vers la gauche et  8 px vers le haut
  a_1.move(-1, -1);			// deplacement de 16 px vers la gauche et 16 px vers le haut
  a_1.move(-1, -1);			// deplacement de 24 px vers la gauche et 24 px vers le haut
  a_1.move(-1, -1);			// deplacement de 32 px vers la gauche et 32 px vers le haut
  a_1.move(-1, -1);			// deplacement de 40 px vers la gauche et 40 px vers le haut
  a_1.move(-1, -1);			// deplacement de 48 px vers la gauche et 48 px vers le haut


  //suite au deplacement, les sprites des abeilles doivent se superposer
  REQUIRE(a_1==z_1);


}

TEST_CASE("Abeille_Zombie - Initialisation")
{
  Abeille_Zombie z_1;
  REQUIRE(z_1.get_x() == 200);					// Test get_x()
  REQUIRE(z_1.get_y() == 752);					// Test get_y()
  REQUIRE(z_1.get_degats() == 10);				// Test get_degats()
  REQUIRE(z_1.get_rotation() == 180);			// Test get_rotation()
  REQUIRE(z_1.get_vitesse_de_attaque() == 15);	// Test get_vitesse_de_attaque()
}

TEST_CASE("Abeille - Fonctions : dead()")
{
  Abeille_Normale a;

  // L'abeille meurt si elle perd 100 pv
  REQUIRE(!a.dead());
  a.perte_points_de_vie(100);
  REQUIRE(a.dead());

  a += 1; // Test de l'operateur += qui soigne l'abeille, tant qu'on y est

  // Si l'abeille se soigne, elle n'a plus 0 pv, donc elle est vivante (ce qui sera impossible de faire dans le jeu)
  REQUIRE(!a.dead());
}

