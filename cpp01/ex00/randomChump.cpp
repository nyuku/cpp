#include	"Zombie.hpp"

//Crée un zombie éphémère
// lui donne un nom et le fait se présenter.
// dès qu'on sort de la fonction
void randomChump( std::string name )
{
	Zombie snow;
	snow.setName(name);
	snow.announce();
}