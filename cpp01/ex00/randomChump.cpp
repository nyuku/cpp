#include	"Zombie.hpp"

//Crée un zombie éphémère sur la stack
// lui donne un nom et le fait se présenter.
// dès qu'on sort de la fonction
void randomChump( std::string name )
{
	Zombie snow(name);
	snow.announce();
}