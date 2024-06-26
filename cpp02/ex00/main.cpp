#include "Fixed.hpp"

/*
Rappel proto:

int Fixed::getRawBits(void) const
-> retourne la valeur du nombre à virgule fixe sans la convertir.


void Fixed::setRawBits(int const raw)
->initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
*/

int main(void)
{
	//Bloque où les objets sont définis
	std::cout<< std::endl << " ------------------------------ Copy constructor ------------------------------" <<std::endl;
	std::cout << std::endl<< "  ✿----- Fixed (a) -----✿" << std::endl;
	Fixed a;
	std::cout<<LIGHT_CYAN << "Value de 'a' par le constructor:" <<a.getRawBits()<< RESET_COLOR<< std::endl;
	a.setRawBits(256);


	std::cout << std::endl<< "  ✿----- Fixed b(a) -----✿" << std::endl;
	Fixed b( a ); // crée b en copiant les données de a dont sa valeur
	std::cout <<LIGHT_CYAN<< "Value de 'b' par copie: "<<	b.getRawBits()<< RESET_COLOR<< std::endl;


	std::cout << std::endl<< std::endl;
	std::cout << std::endl<< "  -------------------------  Copy assignment operator  ------------------------- " << std::endl;
	Fixed c;
	std::cout<<LIGHT_CYAN << "Value de 'c' par le constructor: "<< c.getRawBits()<< RESET_COLOR<< std::endl;
	std::cout << "  ✿----- c = b -----✿" << std::endl;
	c = b; //  copier les valeurs d'un objet dans un autre
	std::cout <<LIGHT_CYAN<< "Value de 'c' par le constructor: "<< c.getRawBits()<< RESET_COLOR<< std::endl;




	std::cout << std::endl<< std::endl;
	std::cout << std::endl<< "  ----------------------------------  Values   ---------------------------------- " << std::endl;
	std::cout << "  ✿-- Call 1 with a --✿" << std::endl;
	std::cout << a.getRawBits() << std::endl;

	std::cout << "  ✿-- Call 2 with b  --✿" << std::endl;
	std::cout << b.getRawBits() << std::endl;

	std::cout << "  ✿-- Call 3 with c --✿" << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}