#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int i = 0;
	//array of C.zombie
	zombie = new Zombie[N];
	while (i < N)
	{
		zombie[i].setName(name);
		zombie[i].announce();
		i++;
	}
	return (zombie);
}
