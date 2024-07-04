#include "Cat.hpp"

/.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat " << this->type << " default constructor called.\n" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat " << this->type << " destructor called.\n" << std::endl;
}

Cat::Cat( std::string type) : Animal(type)
{
	std::cout << "Cat " << this->type << " constructor called.\n" << std::endl;
}


//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................

Cat::Cat( const Cat &cpy)
{
	*this = cpy;
	std::cout <<LILAC<< "Cat " << RESET_COLOR<< this->type << " copy constructor called.\n" << std::endl;
}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................

Cat& Cat::operator=( const Cat &rhs )
{
	std::cout << "Cat assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}



//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Cat::makeSound() const
{
	std::cout << "Cat makeSound() called." << std::endl;
	std::cout << "'Makes " <<LILAC<< this->type << RESET_COLOR<< " noise'\n" << std::endl;
}
