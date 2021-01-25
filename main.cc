#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>
#include <deque>
#include <iostream>
#include "Abeille_Normale.hh"
#include "Abeille_Zombie_Normale.hh"
#include "Abeille_Zombie_Super.hh"
#include "Missile.hh"
#include "Gelee_Royale.hh"
#include "Projectile.hh"

int main()
{

    sf::Music intro_music;
    intro_music.openFromFile("intro.wav");
    intro_music.setLoop(true);

    sf::Music music;
    music.openFromFile("musique.wav");
    music.setLoop(true);

    sf::Image icon;
	icon.loadFromFile("img/beewan.png");

    // Son missile
    sf::SoundBuffer missilebuffer;
    missilebuffer.loadFromFile("missile.wav");

    sf::Sound sound_missile;
    sound_missile.setBuffer(missilebuffer);
    
    // Son gelee
    sf::SoundBuffer geleebuffer;
    geleebuffer.loadFromFile("vomi.wav");

    sf::Sound sound_gelee;
    sound_gelee.setBuffer(geleebuffer);
    
    // Son manger
    sf::SoundBuffer mangerbuffer;
    mangerbuffer.loadFromFile("son_manger.wav");

    sf::Sound sound_manger;
    sound_manger.setBuffer(mangerbuffer);
    

    // Compteur de frames pour l'animation
	int animation = 0;

    // Dimensions de la fenêtre
    int const taille_fenetre_X = 450;
    int const taille_fenetre_Y = 850;

    // Ensemble des missiles dans le jeu
    std::vector<std::pair<Missile, sf::Sprite>> map_des_missiles;

    // Ensemble des gelees dans le jeu
    std::vector<std::pair<Gelee_Royale, sf::Sprite>> map_des_gelees;

    // Ensemble des abeilles dans le jeu
    std::vector<std::deque<Abeille_Zombie>> map_des_abeilles;

    // Ensemble des charges de gelee
    std::deque<std::pair<Gelee_Royale, sf::Sprite>> stack_gelee;

    // Création d'une abeille
    Abeille_Normale joueur;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(taille_fenetre_X, taille_fenetre_Y), "ZomBee"); 	// Création d'une fenêtre 400x800 , nom = ZomBee      
    window.setFramerateLimit(30);                                                         	// FPS = 30
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());				// Icone

    // Fond d'écran
    sf::Texture background_texture;                       // Création d'une texture
    background_texture.loadFromFile("img/background.png");    // Chargement de la texture à partir d'un fichier
    sf::Sprite background(background_texture);            // Création d'une forme et application de la texture

    // bouton play 1
    sf::Texture bouton_play_1;                       // Création d'une texture
    bouton_play_1.loadFromFile("img/play.png");    // Chargement de la texture à partir d'un fichier
    sf::Sprite sprite_bouton_play_1(bouton_play_1);            // Création d'une forme et application de la texture
    sprite_bouton_play_1.setPosition(25, 500);                // Positionnement

    // bouton play 2
    sf::Texture bouton_play_2;                       // Création d'une texture
    bouton_play_2.loadFromFile("img/play_pressed.png");    // Chargement de la texture à partir d'un fichier
    sf::Sprite sprite_bouton_play_2(bouton_play_2);            // Création d'une forme et application de la texture
    sprite_bouton_play_2.setPosition(25, 500);                // Positionnement


    // Ruche
    sf::Texture ruche_texture;                       // Création d'une texture
    ruche_texture.loadFromFile("img/ruche.png");    // Chargement de la texture à partir d'un fichier
    sf::Sprite ruche(ruche_texture);            // Création d'une forme et application de la texture

    // Missiles
    sf::Texture missile_texture;                          // Création d'une texture
    missile_texture.loadFromFile("img/missile.png");          // Chargement de la texture à partir d'un fichier

    // Missiles Forts
    sf::Texture missile_fort_texture;                          // Création d'une texture
    missile_fort_texture.loadFromFile("img/missile_fort.png");          // Chargement de la texture à partir d'un fichier


    // Gelee
    sf::Texture gelee_texture;                            // Création d'une texture
    gelee_texture.loadFromFile("img/gelee.png");          // Chargement de la texture à partir d'un fichier

    // Chargement
    sf::Texture chargement;                               // Création d'une texture
    chargement.loadFromFile("img/mana.png");              // Chargement de la texture à partir d'un fichier


    // Stack_gelee
    sf::Texture stack_gel;                                // Création d'une texture
    stack_gel.loadFromFile("img/stack_gelee.png");        // Chargement de la texture à partir d'un fichier
    sf::Sprite stack_gel_sprite(stack_gel);               // Création d'une forme et application de la texture
    stack_gel_sprite.setPosition(10, 792);                // Positionnement


	// Victoire
    sf::Texture victoire_texture;                         // Création d'une texture
    victoire_texture.loadFromFile("img/victoire.png");    // Chargement de la texture à partir d'un fichier
    sf::Sprite victoire(victoire_texture);                // Création d'une forme et application de la texture
    victoire.setPosition(25, 350);						  // Positionnement


	// Défaite
    sf::Texture defaite_texture;                          // Création d'une texture
    defaite_texture.loadFromFile("img/defaite.png");      // Chargement de la texture à partir d'un fichier
    sf::Sprite defaite(defaite_texture);                  // Création d'une forme et application de la texture
    defaite.setPosition(25, 350);						  // Positionnement

	// Traître
    sf::Texture traitre_texture;                          // Création d'une texture
    traitre_texture.loadFromFile("img/traitre_v2.png");   // Chargement de la texture à partir d'un fichier
    sf::Sprite traitre(traitre_texture);                  // Création d'une forme et application de la texture
    traitre.setPosition(0, 310);						  // Positionnement
    
    // Booléen : indique si aucun zombie n'a été tué
    bool fin_alternative = 1;
    
    // Indique si le jeu est fini: 0 - pas fini ; 1 - victoire ; 2 - défaite
    int jeu_fini = 0;
    
    // Booléen : indique si la fenêtre est sélectionnée
    bool focus = true;
    
    int gelee_cooldown = 0;

    int intro = 0;

    int revenir = 0;
    
    bool start_game = false;
    bool mouse_on_play = false;

    window.requestFocus();
    intro_music.play();
    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::GainedFocus)	focus = true;
        	if (event.type == sf::Event::LostFocus)		focus = false;

            // Si on appuie sur play, on commence le jeu
            if (mouse_on_play && event.type == sf::Event::MouseButtonPressed){
                start_game = true;
                intro_music.stop();
                music.play();

                // Initialisation de l'ensemble des abeilles
                for (int i = 0; i < 8; ++i){
                    std::deque<Abeille_Zombie> deque;
                    deque.push_back(Abeille_Zombie_Super(50 + i*50, 50));

                    for (int j = 0; j < 3; ++j){
                        deque.push_back(Abeille_Zombie_Normale(50 + i*50, (j+1)*75 + 50));          
                    }

                    map_des_abeilles.push_back(deque);
                }
            }

            if (jeu_fini && event.type == sf::Event::MouseButtonPressed){
                music.stop();
                intro_music.play();
                jeu_fini = 0;
                start_game = false;
                stack_gelee.clear();
                map_des_abeilles.clear();
                map_des_missiles.clear();
                map_des_gelees.clear();
                joueur.reset();
                revenir = 0;
                fin_alternative = 1;
            }
        }

        // Video intro
        if(!start_game){

            // Nom du fichier à ouvrir
            char buffer[50];

            // les noms des images commencent par 'Comp 1_00' et terminent par un nombre entre 0 et 359
            sprintf(buffer,"intro/Comp 1_00%03d.png", intro++);

            // quand 'intro' dépasse 359, on le remet à 0
            if (intro==360) intro = 0;
            
            sf::Texture intro_tex;                  // Création d'une texture
            intro_tex.loadFromFile(buffer);         // Chargement de la texture à partir d'un fichier
            sf::Sprite intro_sprite(intro_tex);     // Création d'une forme et application de la texture
            window.draw(intro_sprite);              // Affichage

            window.draw(sprite_bouton_play_1);
            auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
            auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
            if(sprite_bouton_play_1.getGlobalBounds().contains(translated_pos)){ // Rectangle-contains-point check
                mouse_on_play = true;
                window.draw(sprite_bouton_play_2);
            }else{
                mouse_on_play = false;
            }

            // Affichage de la fenêtre (écran bleu de la mort si on l'oublie)
            window.display();
            continue;                             
        }

        // Tant que le jeu n'est pas fini, le joueur peut contrôler l'abeille
        if (!jeu_fini && focus){

        	// Déplacements
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)    and joueur.get_y() > - 50)					joueur.move( 0, -1); // Déplacement vers le haut
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)  and joueur.get_x() > 0)						joueur.move(-1,  0); // Déplacement vers la gauche
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  and joueur.get_y() < taille_fenetre_Y - 50)	joueur.move( 0,  1); // Déplacement vers le bas
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and joueur.get_x() < taille_fenetre_X - 50)	joueur.move( 1,  0); // Déplacement vers la droite

	        // Lancement d'un dard
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and joueur.tir()){
                map_des_missiles.push_back(std::pair<Missile, sf::Sprite>(Missile(joueur.get_x() + 34,joueur.get_y(),180, joueur.get_degats()), sf::Sprite(missile_texture)));
	            //map_des_missiles.push_back(Missile(joueur.get_x() + 34,joueur.get_y(),180, joueur.get_degats()));
	            sound_missile.play();
	        }
	        
            if (gelee_cooldown>0)
                gelee_cooldown--;

            // Tir de gelée
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ){
                if (!gelee_cooldown)
                {
                    if (joueur.get_charges() == 3 and joueur.get_gelee_chargee()){
                        joueur.reset_gelee();
                        map_des_gelees.push_back(std::pair<Gelee_Royale, sf::Sprite>(Gelee_Royale(joueur.get_x() + 34,joueur.get_y()), sf::Sprite(gelee_texture)));
                        sound_gelee.play();
                    }else if (joueur.get_charges() > 0){
                        joueur.decremente_charges();
                        stack_gelee.pop_front();
                        map_des_gelees.push_back(std::pair<Gelee_Royale, sf::Sprite>(Gelee_Royale(joueur.get_x() + 34,joueur.get_y()), sf::Sprite(gelee_texture)));
                        sound_gelee.play();
                    }
                    gelee_cooldown = 30;
                }
            }

            // Manger la gelee
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                if (!gelee_cooldown)
                {
                    if (joueur.get_charges() == 3 and joueur.get_gelee_chargee()){
                        joueur.reset_gelee();
                        joueur += 10;
                        sound_manger.play();
                    }else if (joueur.get_charges() > 0){
                        joueur.decremente_charges();
                        stack_gelee.pop_front();
                        joueur += 10;
                        sound_manger.play();
                    }
                    gelee_cooldown = 30;
                }
            }
	    }

        // Le compteur animation est incrémenté à chaque frame (à 30 FPS)
        if (animation++ == 30) animation = 0;

        // On compte 15 frames avant de changer l'affichage de l'abeille (une demi-seconde)
        joueur.animate(animation);
        
        window.clear(sf::Color(255, 255, 255, 255));            // Nettoyage de la fenêtre
        window.draw(background);                                // Affichage du Fond d'écran
        window.draw(ruche);                                     // Affichage de la ruche

        window.draw(stack_gel_sprite);                          // Affichage de la stack de gelee


        // Affichage des Missiles
        for (std::vector<std::pair<Missile, sf::Sprite>>::iterator i = map_des_missiles.begin(); i != map_des_missiles.end(); ++i)
        {
            if ((i->first).get_y() < -10 || (i->first).get_y() > taille_fenetre_Y)  // suppression des missiles qui quittent la fenêtre
            {
                map_des_missiles.erase(i);
                i--;
                continue;
            }

            (i->second).setRotation((i->first).get_rot());                          // Rotation des missiles
            (i->first).move();                                                      // Déplacement du missile à chaque frame
            (i->second).setPosition((i->first).get_x(), (i->first).get_y());        // Mise à jour de la position du sprite (affichage)
            window.draw(i->second);                                                 // Affichage du missile
        }
        

        // Affichage des Gelees
        for (std::vector<std::pair<Gelee_Royale, sf::Sprite>>::iterator i = map_des_gelees.begin(); i != map_des_gelees.end(); ++i)
        {
            if ((i->first).get_y() < -10 || (i->first).get_y() > taille_fenetre_Y)  // suppression des missiles qui quittent la fenêtre
            {
                map_des_gelees.erase(i);
                i--;
                continue;
            }

            (i->second).setRotation((i->first).get_rot());                          // Rotation des missiles
            (i->first).move();                                                      // Déplacement du missile à chaque frame
            (i->second).setPosition((i->first).get_x(), (i->first).get_y());        // Mise à jour de la position du sprite (affichage)
            window.draw(i->second);                                                 // Affichage du missile
        }

        // Affichage des abeilles
        for (std::vector<std::deque<Abeille_Zombie>>::iterator i = map_des_abeilles.begin(); i != map_des_abeilles.end(); ++i)
        {
        	for (std::deque<Abeille_Zombie>::iterator j = i->begin(); j != i->end(); ++j)
        	{
	            j->animate(animation);												// Animation des abeilles
	            if (!jeu_fini) j->move(0,0);       									// Déplacement des abeilles
	            j->update_pos();													// Mise à jour de la position du sprite
	            j->update_tex();													// Mise à jour de la texture

                if (j->tir() && !jeu_fini){
                    if (j->get_degats()<15)
                        map_des_missiles.push_back(std::pair<Missile, sf::Sprite>(Missile(j->get_x() - 34,j->get_y(), 0, j->get_degats()), sf::Sprite(missile_texture)));
                    else
                        map_des_missiles.push_back(std::pair<Missile, sf::Sprite>(Missile(j->get_x() - 34,j->get_y(), 0, j->get_degats()), sf::Sprite(missile_fort_texture)));
                }

		    	window.draw(j->get_sprite());                                   	// Affichage de l'abeille
                if (*j == joueur)   jeu_fini = 2;                                   // Si le joueur touche un zombie, il perd
                if (j->get_y() > 700)   jeu_fini = 2;                               // Si les zombies arrivent au niveau de la ruche, le jeu se termine   

            	/*
	            	// On tue les zombies si on les touche (pour debugger plus vite)            	
		            if (*j == joueur)
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
	            */
                
                // Verification des colisions Missiles
                for (std::vector<std::pair<Missile, sf::Sprite>>::iterator k = map_des_missiles.begin(); k != map_des_missiles.end(); ++k)
                {
                    // Pour chaque Zombie et pour chaque missile, on vérifie s'il y a une collision (si zombie == missile)
                    if ((*j) == k->first)
                    {
                        // Si un missile touche un enemi, il perd des PV qui correspondent aux dégats du missile
                        j->perte_points_de_vie((k->first).get_dmg());

                        // Si un missile touche un enemi, le missile disparait
                        map_des_missiles.erase(k);
                        k--;

                        // si le joueur touche un enemi, il charge la gelee
                        joueur.incremente_chargement();

                        // Si l'ennemi arrive à 0 PV, il meurt et on l'enleve de l'ensemble
                        if (j->dead())
                        {
                            // Si le joueur tue, il charge +4 gelée (en plus de l'incrementation derivee du tir) 
                            for (int u = 0; u < 4; ++u)
                                joueur.incremente_chargement();

                            // Si un zombie meurt, la fin alternative n'est plus disponible
                            fin_alternative = 0;

                            // Si l'élément à éliminer est le premier, on l'élimine et on passe au prochain tour de boucle
                            if ( j == (i->begin()))
                            {
                                i->pop_front();
                                break;
                            }

                            // Si l'élément à éliminer n'est pas le premier, on l'élimine et on décrémente l'itérateur avant de passer au prochain tour de boucle
                            i->erase(j);
                            j--;
                            break;
                        }
                    }
                }
                // Verification des colisions Gelee
                for (std::vector<std::pair<Gelee_Royale, sf::Sprite>>::iterator k = map_des_gelees.begin(); k != map_des_gelees.end(); ++k)
                {
                    // Pour chaque Zombie et pour chaque gelee, on vérifie s'il y a une collision (si zombie == gelee)
                    if (*j == k->first)
                    {
                        (k->first).nouvelle_colision(j->get_id());

                        // Si une gelee touche un enemi, il perd des PV qui correspondent aux dégats de la gelee
                        j->perte_points_de_vie((k->first).get_dmg());

                        // Si une gelee touche un enemi, la gelee ne disparait pas

                        // Si l'ennemi arrive à 0 PV, il meurt et on l'enleve de l'ensemble
                        if (j->dead())
                        {
                            // Si un zombie meurt, la fin alternative n'est plus disponible
                            fin_alternative = 0;

                            // Si l'élément à éliminer est le premier, on l'élimine et on passe au prochain tour de boucle
                            if ( j == (i->begin()))
                            {
                                i->pop_front();
                                break;
                            }

                            // Si l'élément à éliminer n'est pas le premier, on l'élimine et on décrémente l'itérateur avant de passer au prochain tour de boucle
                            i->erase(j);
                            j--;
                            break;
                        }
                    }
                }
        	}

        	if (i->empty())
        	{
            	map_des_abeilles.erase(i);
            	i--;
        	}
        }

        // Mise a jour des charges de gelee (suite aux colisions)
        if ((int)stack_gelee.size() < joueur.get_charges())
            stack_gelee.push_front(std::pair<Gelee_Royale, sf::Sprite>(Gelee_Royale(joueur.get_charges()*25,800), sf::Sprite(gelee_texture)));
        

        for (std::deque<std::pair<Gelee_Royale, sf::Sprite>>::iterator i = stack_gelee.begin(); i != stack_gelee.end(); ++i){
            (i->second).setPosition((i->first).get_x(), (i->first).get_y());        // Mise à jour de la position du sprite (affichage)
            window.draw(i->second);
        }

        // Verification des colisions avec le joueur
        for (std::vector<std::pair<Missile, sf::Sprite>>::iterator k = map_des_missiles.begin(); k != map_des_missiles.end(); ++k)
        {
            // Pour chaque Zombie et pour chaque missile, on vérifie s'il y a une collision (si zombie == missile)
            if (joueur == k->first)
            {
                // Si un missile touche un enemi, il perd des PV qui correspondent aux dégats du missile
                joueur.perte_points_de_vie((k->first).get_dmg());

                // Si un missile touche le joueur, le missile disparait
                map_des_missiles.erase(k);
                k--;

                if (joueur.dead())
                    jeu_fini = 2;
            }
        }


        // Si toutes les abeilles ont été tuées => victoire
        if (map_des_abeilles.empty()) jeu_fini = 1;
        
        // Affichage du joueur
        window.draw(joueur.get_sprite());                                   // Affichage de l'abeille
        window.draw(joueur.get_chargement());                                   // Affichage de l'abeille

        // Jeu_fini = 1 -> Victoire ;  Jeu_fini = 2 -> Défaite
    	if (jeu_fini == 1)		window.draw(victoire);
    	else if(jeu_fini == 2)	window.draw(defaite); 
        
        // Si le joueur arrive à s'enfuir sans tuer aucun zombie, il gagne
        if(joueur.get_y() < -50 && fin_alternative){
	        window.draw(victoire); 
	        window.draw(traitre);
	        jeu_fini = 3;
        }

        if (jeu_fini){
            
            char buffer[50];
            sprintf(buffer,"revenir/revenir_00%03d.png", revenir++);

            if (revenir==120) revenir = 0;
            
            sf::Texture revenir_tex;                                // Création d'une texture
            revenir_tex.loadFromFile(buffer);        // Chargement de la texture à partir d'un fichier
            sf::Sprite revenir_sprite(revenir_tex);               // Création d'une forme et application de la texture
            revenir_sprite.setPosition(0, 200);                // Positionnement
            window.draw(revenir_sprite);
            
        }

        // Affichage de la fenêtre (écran bleu de la mort si on l'oublie)
        window.display();
    }

    stack_gelee.clear();
    map_des_abeilles.clear();
    map_des_missiles.clear();
    map_des_gelees.clear();
    return 0;
}

