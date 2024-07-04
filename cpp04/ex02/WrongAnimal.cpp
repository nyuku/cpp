#include "WrongAnimal.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << this->type << " default constructor called.\n" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << this->type << " destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type) : type(type)
{
	std::cout << "WrongAnimal " << this->type << " constructor called.\n" << std::endl;
}

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
WrongAnimal::WrongAnimal( const WrongAnimal &cpy)
{
	*this = cpy;
	std::cout << "WrongAnimal " << this->type << " copy constructor called" << std::endl;
}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
WrongAnimal& WrongAnimal::operator=( const WrongAnimal &rhs )
{
	std::cout << "WrongAnimal assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================

void WrongAnimal::makeSound() const
{
	std::cout << this->type << " makeSound() called." << std::endl;
	std::cout << "'Makes WrongAnimal noise'\n" << std::endl;
}

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
const std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::setType( const std::string type )
{
	this->type = type;
}