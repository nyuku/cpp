
#include	"Zombie.hpp"

// Crée un zombie, lui donne un nom
// retourne un pointeur de type classe zombue, persistant en dehors de la fonction.
//char * = zombie *
//on the heap
Zombie *newZombie( std::string name)
{
	Zombie	*new_zombie;
	new_zombie = new Zombie(name);
	new_zombie->announce(); 
	return (new_zombie);
}