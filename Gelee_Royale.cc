#include "Gelee_Royale.hh"

Gelee_Royale::Gelee_Royale(int x, int y) : Projectile(x, y, 10, 180, 50) {};

std::vector<int> Gelee_Royale::get_vecteur() const{return zombies_touches;}


void Gelee_Royale::nouvelle_colision(int a){
	zombies_touches.push_back(a);
}