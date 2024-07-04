#include "Animal.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Animal::Animal() : type("Animal")
{
	std::cout << this->type << " default constructor called.\n" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal " << this->type << " destructor called" << std::endl;
}

Animal::Animal( std::string type) : type(type)
{
	std::cout << "Animal " << this->type << " constructor called.\n" << std::endl;
}


//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................

Animal::Animal( const Animal &cpy)
{
	*this = cpy;
	std::cout << "Animal " << this->type << " copy constructor called" << std::endl;
}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
Animal& Animal::operator=( const Animal &rhs )
{
	std::cout << "Animal assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}


//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Animal::makeSound() const
{
	std::cout << "Animal makeSound() called." << std::endl;
	std::cout << "'Makes " << this->type << " noise'\n" << std::endl;
}

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
const std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::setType( const std::string type )
{
	this->type = type;
}