#include "Cat.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "     little 🐈 "<< this->type << " \t-Default constructor called.\n" << std::endl;

}
Cat::~Cat()
{
	std::cout << "     little 🐈 " << this->type << " \t-Destructor called." << std::endl;
	delete this->_brain;
}

Cat::Cat( std::string type) : AAnimal(type)
{
	std::cout <<"     little 🐈 "<< this->type << " \t-Name constructor called." << std::endl;
}
//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
Cat::Cat( const Cat &cpy)
{
	*this = cpy;
	std::cout << "     little 🐈 " << this->type << " copy constructor called." << std::endl;
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
//cause de leaks
// Cat& Cat::operator=(const Cat& other) {
//     std::cout << "Cat assignment operator called." << std::endl;
//     if (this != &other) {
//         AAnimal::operator=(other);
//         delete _brain;
//         _brain = new Brain(*(other._brain));
//     }
//     return *this;
// }


//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Cat::makeSound() const
{
	std::cout << "Cat makeSound() called." << std::endl;
	std::cout << "'Makes " << this->type << " noise'\n" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}
