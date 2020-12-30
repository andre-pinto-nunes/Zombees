#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>
#include <iostream>
#include "Abeille_Normale.hh"
#include "Abeille_Zombie_Normale.hh"
#include "Abeille_Zombie_Super.hh"
#include "Missile.hh"

int main()
{

    sf::Image icon;
	icon.loadFromFile("beewan.png");
    

    // Compteur de frames pour l'animation
	int animation = 0;

    // Compteur de frames pour la vitesse de tir
    int cooldown_tir = 1;

    int const taille_fenetre_X = 450;
    int const taille_fenetre_Y = 850;

    // Ensemble des missiles dans le jeu
    std::vector<std::pair<Missile, sf::Sprite>> map_des_missiles;

    // Ensemble des abeilles dans le jeu
    std::vector<std::deque<Abeille>> map_des_abeilles;
				
    for (int i = 0; i < 8; ++i){
    	std::deque<Abeille> deque;
    	deque.push_back(Abeille_Zombie_Super(50 + i*50, 50));

    	for (int j = 0; j < 3; ++j){
	    	deque.push_back(Abeille_Zombie_Normale(50 + i*50, (j+1)*75 + 50));    		
    	}

    	map_des_abeilles.push_back(deque);
    }

    // Création d'une abeille
    Abeille_Normale joueur;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(taille_fenetre_X, taille_fenetre_Y), "ZomBee"); // Création d'une fenêtre 400x800 , nom = ZomBee      
    window.setFramerateLimit(30);                                                         // FPS = 30
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Fond d'écran
    sf::Texture background_texture;                             // Création d'une texture
    background_texture.loadFromFile("background.png");          // Chargement de la texture à partir d'un fichier
    sf::Sprite background(background_texture);                  // Création d'une forme et application de la texture

    sf::Texture missile_texture;                                // Création d'une texture
    missile_texture.loadFromFile("missile.png");                // Chargement de la texture à partir d'un fichier


    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)    and joueur.get_y() > 0){joueur.move( 0, -1);}                     // Déplacement vers le haut
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)  and joueur.get_x() > 0){joueur.move(-1,  0);}                     // Déplacement vers la gauche
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  and joueur.get_y() < taille_fenetre_Y - 50){joueur.move( 0,  1);} // Déplacement vers le bas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and joueur.get_x() < taille_fenetre_X - 50){joueur.move( 1,  0);} // Déplacement vers la droite

        // Lancement d'un dard
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and !(--cooldown_tir)){
            map_des_missiles.push_back(std::pair<Missile, sf::Sprite>(Missile(joueur.get_x() + 34,joueur.get_y(),180, joueur.get_degats()), sf::Sprite(missile_texture)));
            cooldown_tir = 30/joueur.get_vitesse_de_attaque();
        }

        // Le compteur animation est incrémenté à chaque frame (à 30 FPS)
        if (animation++ == 30) animation = 0;

        joueur.animate(animation); // on compte 15 frames avant de changer l'affichage de l'abeille
        
        window.clear(sf::Color(255, 255, 255, 255));            // Netoyage de la fenêtre
        window.draw(background);                                // Affichage du Fond d'écran


        // Affichage des Missiles
        for (std::vector<std::pair<Missile, sf::Sprite>>::iterator i = map_des_missiles.begin(); i != map_des_missiles.end(); ++i)
        {
        	if ((i->first).get_y() < -10 || (i->first).get_y() > taille_fenetre_Y)	// suppression des missiles qui quittent la fenêtre
        	{
        		map_des_missiles.erase(i);
        		i--;
        		continue;
        	}

            (i->second).setRotation((i->first).get_rot());    			// Rotation de 180º des missiles de direction -1
            (i->second).setPosition((i->first).get_x(), (i->first).get_y());    	// Mise à jour de la position du missile
            (i->first).move();														// Deplacement du missile à chaque frame
            window.draw(i->second);													// Affichage du missile
        }

        // Affichage des abeilles
        for (std::vector<std::deque<Abeille>>::iterator i = map_des_abeilles.begin(); i != map_des_abeilles.end(); ++i)
        {
        	for (std::deque<Abeille>::iterator j = i->begin(); j != i->end(); ++j)
        	{
	            j->animate(animation);    	
	            j->update_pos();
	            j->update_tex();	
		    	window.draw(j->get_sprite());                                   // Affichage de l'abeille
	            if (*j == joueur)
	            { 
	            	/*
						À CHANGER
						(ici on tue des zombies si on les touche)
						(il faut que le joueur perde le jeu si il les touche)
	            	*/
	            	if ( j == (i->begin()))
	            	{
	            		i->pop_front();
	            		continue;
	            	}
	            	i->erase(j);
	            	j--;
	            	continue;
	            }

	            for (std::vector<std::pair<Missile, sf::Sprite>>::iterator k = map_des_missiles.begin(); k != map_des_missiles.end(); ++k)
    			{
    				if (*j == k->first)
    				{
    					// Si un missile touche un enemi, il perd des PV qui correspondent aux dégats du missile
    					j->perte_points_de_vie((k->first).get_dmg());

    					// Si un missile touche un enemi, le missile disparait
    					map_des_missiles.erase(k);
    					k--;

    					////////////////////// IL Y A UN SEG FAULT PAR ICI DES FOIS
    					if (j->dead())
    					{
	    					if ( j == (i->begin()))
			            	{
			            		i->pop_front();
			            		continue;
			            	}
			            	i->erase(j);
			            	j--;
			            	continue;
    					}
    				}
		        }
        	}
        }
        
        window.draw(joueur.get_sprite());                                   // Affichage de l'abeille
        window.display();
    }


    return 0;
}

