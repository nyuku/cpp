#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name );
int is_alpha(std::string& str);

int is_alpha(std::string& str)
{
	int i = 0;
	int len = str.length();
	while (i < len)
	{
		if (!(std::isalpha(str[i])))
			return(1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{

	if (argc < 3)
	{

		std::cout << "Please give zombie's a name and a number for the horde, try again with arguments "<< std::endl;
		return 1;
	}

	std::string ZombieName = argv[1];
	std::istringstream iss(argv[2]);
	int numberZombie = 0;

	if (is_alpha(ZombieName))
	{
		std::cout << "Please give a right name with only letters, first argument" << std::endl;
		return 1;
	}
	if (!(iss >> numberZombie) )
	{
		std::cout << "Please give a right number for the horde, 2nd argument" << std::endl;
		return 1;
	}
	if (numberZombie < 0 )
	{
		std::cout << "non negative, enter an other number please" << std::endl;
		return 1;
	}
	Zombie	*horde;
	horde = zombieHorde(numberZombie, ZombieName);
	delete [] horde;

	return(0);

}