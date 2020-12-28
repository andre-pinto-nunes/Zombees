#include <SFML/Graphics.hpp>
#include <vector>
#include "Abeille_Normale.hh"
#include "Abeille_Zombie.hh"
#include "Missile.hh"

int main()
{
    // Compteur de frames pour l'animation
	int animation = 0;

    // Compteur de frames pour la vitesse de tir
    int cooldown_tir = 1;

    int const taille_fenetre_X = 400;
    int const taille_fenetre_Y = 800;

    // Ensemble des missiles dans le jeu
    std::vector<std::pair<Missile, sf::Sprite>> map_des_missiles;

    // Création d'une abeille (mettre des STL)
    Abeille_Normale joueur;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(taille_fenetre_X, taille_fenetre_Y), "ZomBee"); // Création d'une fenêtre 400x800 , nom = ZomBee      
    window.setFramerateLimit(30);                                                         // FPS = 30

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
        while (window.pollEvent(event))
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

        // Le compteur animation est incrémenté à chaque frame (à 30 FPS)
        if (animation++ == 15)
        {
			abeille.setTextureRect(sf::IntRect(50, 0, 50, 43)); // on compte 15 frames avant de changer l'affichage de l'abeille
        }
        else if(animation == 30)
        {
			abeille.setTextureRect(sf::IntRect( 0, 0, 50, 43));  // on compte encore 15 frames avant de changer l'affichage de l'abeille
        	animation = 0;                                      // Remise à 0 du compteur
        }



        window.clear(sf::Color(255, 255, 255, 255));            // Netoyage de la fenêtre
        window.draw(background);                                // Affichage du Fond d'écran


        // Affichage des Missiles
        for (std::vector<std::pair<Missile, sf::Sprite>>::iterator i = map_des_missiles.begin(); i != map_des_missiles.end(); ++i)
        {
        	if ((i->first).get_y() < -10 || (i->first).get_y() > taille_fenetre_Y)
        	{
        		map_des_missiles.erase(i);
        		i--;
        		continue;
        	}
            (i->second).setRotation(((i->first).get_dir() - 1) *90);    
            (i->second).setPosition((i->first).get_x()+17, (i->first).get_y());    // Mise à jour du positionnement de l'abeille
            (i->first).move();
            window.draw(i->second);
        }
        
        window.draw(abeille);                                   // Affichage de l'abeille
        window.display();
    }

    return 0;
}

