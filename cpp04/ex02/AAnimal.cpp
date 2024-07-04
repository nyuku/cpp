#include "AAnimal.hpp"
//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << this->type << " default constructor called.\n" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->type << " destructor called" << std::endl;
}

AAnimal::AAnimal( std::string type) : type(type)
{
	std::cout << "AAnimal " << this->type << " constructor called.\n" << std::endl;
}

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
AAnimal::AAnimal( const AAnimal &cpy)
{
	*this = cpy;
	std::cout << "AAnimal " << this->type << " copy constructor called" << std::endl;
}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
AAnimal& AAnimal::operator=( const AAnimal &rhs )
{
	std::cout << "AAnimal assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}



//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void AAnimal::makeSound() const
{
	std::cout << "AAnimal makeSound() called." << std::endl;
	std::cout << "'Makes " << this->type << " noise'\n" << std::endl;
}

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
const std::string	AAnimal::getType( void ) const
{
	return (this->type);
}

void	AAnimal::setType( const std::string type )
{
	this->type = type;
}