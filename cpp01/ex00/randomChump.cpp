#include	"Zombie.hpp"

//Crée un zombie éphémère -> alloc "new"
// lui donne un nom et le fait se présenter.
//meurt
void randomChump( std::string name )
{
	Zombie	*snow = new Zombie();
	snow->setName(name);
	snow->announce();
	delete snow;
}