#include "Fixed.hpp"

int
main( void )
{
	std::cout <<std::endl<< CYAN <<" ------------- Constructor default, Fixed a ------------"<< RESET_COLOR<<std::endl;
		Fixed a;
		std::cout << "[default]\t a is " << a << std::endl;
	std::cout <<std::endl<< CYAN <<" ------------- Int Constructor, Fixed b ----------------"<< RESET_COLOR<<std::endl; // converti deja en virgule fixe
		Fixed const b(10);
		std::cout <<LIGHT_CYAN<< "Value de 'b' en virgule fixe: "<<	b.getRawBits()<< RESET_COLOR<< std::endl;
	std::cout <<std::endl<< CYAN << "------------- Float Constructor, fixed c ---------------"<< RESET_COLOR<<std::endl;
		Fixed const c( 42.42f );
		std::cout<<LIGHT_CYAN << "Value de 'c'  en virgule fixe: "<< c.getRawBits()<< RESET_COLOR<< std::endl;
	std::cout <<std::endl<< CYAN <<" -------- Copy constructor, fixed d(b) --------"<< RESET_COLOR<<std::endl; // copie b 
		Fixed const d( b );
		std::cout<<LIGHT_CYAN << "Value de 'd' par copie en virgule fixe: "<< d.getRawBits()<< RESET_COLOR<< std::endl;
	std::cout <<std::endl<< CYAN << "----------- Float , Copy assignment operator '=', a = fixed(1234,4321f)----------"<< RESET_COLOR<<std::endl;
		a = Fixed( 1234.4321f );
		std::cout<<LIGHT_CYAN << "Value de 'a'  en virgule fixe: " <<a.getRawBits()<< RESET_COLOR<< std::endl;

	std::cout <<std::endl<< CYAN << "•·✦------- Show time(<<) nb ->virgule fixe -> int/float -------✦·•"<< RESET_COLOR<<std::endl;
	std::cout << "[float]\t a is " << a << std::endl;
	std::cout << "[int]\t b is " << b << std::endl;
	std::cout << "[float]\t c is " << c << std::endl;
	std::cout << "[int]\t d is " << d << std::endl;

	std::cout <<std::endl<< CYAN << "•·✦----- Convertion en int-----✦·•"<< RESET_COLOR<<std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout <<std::endl;
	return 0;
}