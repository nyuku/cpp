
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout <<PEACH << "      --------------Human A with weapon--------------"<< RESET_COLOR <<std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout <<PEACH << "      -----------Human B without weapon-----------"<< RESET_COLOR <<std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}