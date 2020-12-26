#include <SFML/Graphics.hpp>
#include "Abeille.cc"

int main()
{
    // Compteur de frames pour l'animation
	int animation = 0;

    // Création d'une abeille (mettre des STL)
    Abeille joueur;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(400, 800), "ZomBee"); // Création d'une fenêtre 800x600 , nom = ZomBee      
    window.setFramerateLimit(30);                               // FPS = 30

    // Affichage de l'abeille
	sf::Texture image_texture;                                  // Création d'une texture
	image_texture.loadFromFile("1beille.png");                  // Chargement de la texture à partir d'un fichier
	sf::Sprite abeille(image_texture);                          // Création d'une forme et application de la texture
	abeille.setTextureRect(sf::IntRect(0, 0, 50, 50));          // Découpage d'une partie spécifique de la texture (premier photogramme)



	sf::Texture background_texture;                             // Création d'une texture
	background_texture.loadFromFile("background.png");          // Chargement de la texture à partir d'un fichier
	sf::Sprite background(background_texture);                  // Création d'une forme et application de la texture
	//background.setScale(0.7, 0.7);                              // Changement de la taille 


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){joueur.move( 0, -1);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){joueur.move(-1,  0);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){joueur.move( 0,  1);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){joueur.move( 1,  0);}

        if (animation++ == 15)
        {
			abeille.setTextureRect(sf::IntRect(50, -5, 50, 50));
        }else if(animation == 30) {
			abeille.setTextureRect(sf::IntRect(0, 0, 50, 50));
        	animation = 0;
        }

        window.clear(sf::Color(255, 255, 255, 255));
        abeille.setPosition(joueur.get_x(), joueur.get_y());
        window.draw(background);
        window.draw(abeille);
        window.display();
    }

    return 0;
}

