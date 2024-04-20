#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int main(int argc, char **argv)
{

	if (argc < 4)
	{

		std::cout << "Please give 3 zombie's name: [1]Persistant[2]killing [3] auto-killing" << std::endl;
		return 1;
	}
	std::string firstZombieName = argv[1];
	std::string secondZombieName = argv[2];
	std::string thirdZombieName = argv[3];

	std::cout << std::endl<< BLUE<< "------Round 1 [killed at the end]------" << RESET_COLOR<<std::endl;

		//died at the end of the bloc  if {}
		Zombie firstZombie;
		firstZombie.setName(firstZombieName);
		firstZombie.announce();


	std::cout << std::endl<< BLUE<< "------Round 2 [heap, have to kill it]------" << RESET_COLOR<< std::endl;
		Zombie *secondZombie;
		secondZombie = newZombie(secondZombieName);
		secondZombie->announce();
		delete secondZombie;
	std::cout << std::endl<< BLUE<< "------Round 3 [stack, instant kill]------" << RESET_COLOR<< std::endl;
		randomChump(thirdZombieName);
	std::cout << std::endl<<LIGHT_GREEN<<" END of Programme " << RESET_COLOR<< std::endl;
	return(0);

}