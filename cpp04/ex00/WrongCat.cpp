/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:04 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:20:16 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................


WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "       little 🦁 " << this->type << " \t-Default constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "     little 🦁 " << this->type << " \t-Destructor called." << std::endl;
}

WrongCat::WrongCat( std::string type) : WrongAnimal(type)
{
	std::cout << "     little 🦁 " << this->type << " \t-Name constructor called." << std::endl;
}
//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................

WrongCat::WrongCat( const WrongCat &cpy)
{
	*this = cpy;
	std::cout << "     little 🦁 " << this->type << " copy constructor called." << std::endl;
}
//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................

WrongCat& WrongCat::operator=( const WrongCat &rhs )
{
	std::cout << "WrongCat assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}



// void WrongCat::makeSound() const
// {
// 	std::cout << "GROOOOOAAAAA" << std::endl;
// }
