#include "WrongCat.hpp"
//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat " << this->type << " default constructor called.\n" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->type << " destructor called.\n" << std::endl;
}


WrongCat::WrongCat( std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat " << this->type << " constructor called.\n" << std::endl;
}
//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
WrongCat::WrongCat( const WrongCat &cpy)
{
	*this = cpy;
	std::cout << "WrongCat " << this->type << " copy constructor called.\n" << std::endl;
}
//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
WrongCat& WrongCat::operator=( const WrongCat &rhs )
{
	std::cout << "WrongCat assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}
