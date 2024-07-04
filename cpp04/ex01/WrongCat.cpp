#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat " << this->type << " default constructor called.\n" << std::endl;
}

WrongCat::WrongCat( std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat " << this->type << " constructor called.\n" << std::endl;
}

WrongCat::WrongCat( const WrongCat &cpy)
{
	*this = cpy;
	std::cout << "WrongCat " << this->type << " copy constructor called.\n" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &rhs )
{
	std::cout << "WrongCat assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->type << " destructor called.\n" << std::endl;
}

// void WrongCat::makeSound() const
// {
// 	std::cout << "WrongCat makeSound() called." << std::endl;
// 	std::cout << "'Makes " << this->type << " noise'\n" << std::endl;
// }
