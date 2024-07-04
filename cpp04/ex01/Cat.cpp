#include "Cat.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat " << this->type << " default constructor called.\n" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory allocation failed : " << e.what() << std::endl;
	}
}
Cat::~Cat()
{
	std::cout << "Cat " << this->type << " destructor called.\n" << std::endl;
	delete this->_brain;
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
	std::cout << "Cat " << this->type << " copy constructor called.\n" << std::endl;
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
		this->_brain = new Brain( *rhs._brain );
	}
	return *this;
}


//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Cat::makeSound() const
{
	std::cout << "Cat makeSound() called." << std::endl;
	std::cout << "'Makes " << this->type << " noise'\n" << std::endl;
}
