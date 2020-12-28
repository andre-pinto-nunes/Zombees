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

    int const taille_fenetre_X = 400;
    int const taille_fenetre_Y = 800;

    // Ensemble des missiles dans le jeu
    std::vector<std::pair<Missile, sf::Sprite>> map_des_missiles;

    // Ensemble des abeilles dans le jeu
    std::vector<std::deque<std::pair<Abeille, sf::Sprite>>> map_des_abeilles;


	sf::Texture texture_zombie_super;						
	sf::Texture texture_zombie_normale;						
    for (int i = 0; i < 8; ++i)
    {
    	std::deque<std::pair<Abeille, sf::Sprite>> deque;
    	
    	Abeille_Zombie_Super super_zombie = Abeille_Zombie_Super(50 + i*50, 50);
		texture_zombie_super.loadFromFile(super_zombie.get_texture());
    	deque.push_back(std::make_pair(Abeille_Zombie_Super(super_zombie), sf::Sprite(texture_zombie_super)));

    	for (int j = 0; j < 3; ++j)
    	{
	    	Abeille_Zombie_Normale normale = Abeille_Zombie_Normale(50 + i*50, (j+1)*75 + 50);
			texture_zombie_normale.loadFromFile(normale.get_texture());
	    	deque.push_back(std::make_pair(normale, sf::Sprite(texture_zombie_normale)));    		
    	}

    	map_des_abeilles.push_back(deque);
    }

    // Création d'une abeille
    Abeille_Normale joueur;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(taille_fenetre_X, taille_fenetre_Y), "ZomBee"); // Création d'une fenêtre 400x800 , nom = ZomBee      
    window.setFramerateLimit(30);                                                         // FPS = 30
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Affichage de l'abeille
	sf::Texture image_texture;                                  // Création d'une texture
	image_texture.loadFromFile(joueur.get_texture());           // Chargement de la texture à partir d'un fichier
	sf::Sprite abeille(image_texture);                          // Création d'une forme et application de la texture
	abeille.setTextureRect(sf::IntRect(0, 0, 50, 50));          // Découpage d'une partie spécifique de la texture (premier photogramme)



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
        abeille.setPosition(joueur.get_x(), joueur.get_y());    // Mise à jour du positionnement de l'abeille


        // Lancement d'un dard
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and !(--cooldown_tir)){
            map_des_missiles.push_back(std::pair<Missile, sf::Sprite>(Missile(joueur.get_x() + 17,joueur.get_y(),-1), sf::Sprite(missile_texture)));
            cooldown_tir = 30/joueur.get_vitesse_de_attaque();
        }

        sf::IntRect rect_anim_1(50, 0, 50, 43);
        sf::IntRect rect_anim_2(0, 0, 50, 43);
        // Le compteur animation est incrémenté à chaque frame (à 30 FPS)
        if (animation++ == 15)
        {
			abeille.setTextureRect(rect_anim_1); // on compte 15 frames avant de changer l'affichage de l'abeille
        }
        else if(animation == 30)
        {
			abeille.setTextureRect(rect_anim_2); // on compte 15 frames avant de changer l'affichage de l'abeille
        	animation = 0;                                      // Remise à 0 du compteur
        }



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

            (i->second).setRotation(((i->first).get_dir() - 1) *90);    			// Rotation de 180º des missiles de direction -1
            (i->second).setPosition((i->first).get_x()+17, (i->first).get_y());    	// Mise à jour de la position du missile
            (i->first).move();														// Deplacement du missile à chaque frame
            window.draw(i->second);													// Affichage du missile
        }

        for (std::vector<std::deque<std::pair<Abeille, sf::Sprite>>>::iterator i = map_des_abeilles.begin(); i != map_des_abeilles.end(); ++i)
        {
        	for (std::deque<std::pair<Abeille, sf::Sprite>>::iterator j = (*i).begin(); j != (*i).end(); ++j)
        	{
        		if (animation < 15){(j->second).setTextureRect(rect_anim_1);}
        		else{(j->second).setTextureRect(rect_anim_2);}
	            (j->second).setRotation(180);    	
	            (j->second).setPosition((j->first).get_x(), (j->first).get_y());    	
		    	window.draw(j->second);                                   // Affichage de l'abeille
        	}
        }
        
        window.draw(abeille);                                   // Affichage de l'abeille
        window.display();
    }


    return 0;
}

