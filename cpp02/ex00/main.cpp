#include "Fixed.hpp"

int main( void )
{
	std::cout << " ----- Fixed a -----" << std::endl;
	Fixed a;
	std::cout << " ----- Fixed b(a) -----" << std::endl;
	Fixed b( a ); // crée b en copiant les données de a
	std::cout << std::endl<< " ----- Fixed c -----" << std::endl;
	Fixed c;
	std::cout << " ----- c = b-----" << std::endl;
	c = b; //  copier les valeurs d'un objet dans un autre

	std::cout << std::endl<< " ----- Call 1 with a. -----" << std::endl;
	std::cout << a.getRawBits() << std::endl;

	std::cout << " -----Call 2 with b. -----" << std::endl;
	std::cout << b.getRawBits() << std::endl;

	std::cout << " ----- Call 3 with c. -----" << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}