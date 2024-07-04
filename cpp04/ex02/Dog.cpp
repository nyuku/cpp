#include "Dog.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog " << this->type << " default constructor called.\n" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory allocation failed : " << e.what() << std::endl;
	}
}

Dog::~Dog()
{
	std::cout << "Dog " << this->type << " destructor called.\n" << std::endl;
	delete this->_brain;
}

Dog::Dog( std::string type) : AAnimal(type)
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
	std::cout << "Dog assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		this->_brain = new Brain( *rhs._brain );
	}
	return *this;
}



//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Dog::makeSound() const
{
	std::cout << "Dog makeSound() called." << std::endl;
	std::cout << "'Makes " << this->type << " noise'\n" << std::endl;
}
