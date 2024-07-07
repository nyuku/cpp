#include "AAnimal.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
AAnimal::AAnimal() : type("AAnimal")
{

	std::cout <<LILAC<<"AAnimal, type:  "<< this->type<< " \t-Default constructor called." <<RESET_COLOR << std::endl;
}
AAnimal::~AAnimal()
{

	std::cout <<LILAC<<"AAnimal, type:  "<< this->type<< " \t-Destructor called." <<RESET_COLOR << std::endl;
}

AAnimal::AAnimal( std::string type) //type(type)
{
	this->type = type;
	std::cout <<LILAC<<"AAnimal, type:  "<< this->type<< " \t-Name constructor called." <<RESET_COLOR << std::endl;
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
	std::cout << "Grooaaaaa" << std::endl;
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