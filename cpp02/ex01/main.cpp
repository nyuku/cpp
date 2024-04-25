#include "Fixed.hpp"

int
main( void )
{
	std::cout <<std::endl<< CYAN <<" ----- Fixed a -----"<< RESET_COLOR<<std::endl;
		Fixed a;
	std::cout << CYAN <<" ----- Fixed b(10) -----"<< RESET_COLOR<<std::endl;
		Fixed const b( 10 );
	std::cout << CYAN << "----- Fixed const c,(42, 42f) -----"<< RESET_COLOR<<std::endl;
		Fixed const c( 42.42f );
	std::cout << CYAN <<" ----- Fixed const d(b) -----"<< RESET_COLOR<<std::endl;
		Fixed const d( b );
	std::cout << CYAN << "----- a = fixed (1234,4321f) -----"<< RESET_COLOR<<std::endl;
	a = Fixed( 1234.4321f );

	std::cout <<std::endl<< CYAN << "----- Result -----"<< RESET_COLOR<<std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout <<std::endl<< CYAN << "----- Convert -----"<< RESET_COLOR<<std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout <<std::endl;
	return 0;
}