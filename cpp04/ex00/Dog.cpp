#include "Dog.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog " << this->type << " default constructor called.\n" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog " << this->type << " destructor called.\n" << std::endl;
}

Dog::Dog( std::string type) : Animal(type)
{
	std::cout << "Dog " << this->type << " constructor called.\n" << std::endl;
}

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................

Dog::Dog( const Dog &cpy)
{
	*this = cpy;
	std::cout << "Dog " << this->type << " copy constructor called.\n" << std::endl;
}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................

Dog& Dog::operator=( const Dog &rhs )
{
	std::cout <<CYAN<< "Dog"<< RESET_COLOR<<" assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}
//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Dog::makeSound() const
{
	std::cout << "Dog makeSound() called." << std::endl;
	std::cout << "'Makes " <<CYAN<< this->type <<RESET_COLOR<< " noise'\n" << std::endl;
}
