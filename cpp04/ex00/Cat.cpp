/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:45 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:07:23 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................

Cat::Cat() : Animal("Cat")
{
	std::cout << "     little 🐱 " <<LIGHT_GREEN<< this->type <<RESET_COLOR<< " \t-Default constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "     little 🐱 " <<LIGHT_GREEN<< this->type <<RESET_COLOR<< " \t-Destructor called." << std::endl;
}

Cat::Cat( std::string type) : Animal(type)
{
	std::cout << "     little 🐱 "  <<LIGHT_GREEN<< this->type <<RESET_COLOR<< " \t-Name constructor called." << std::endl;
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

Cat& Cat::operator=( const Cat &src )
{
	std::cout << "Cat assignement operator called.\n" << std::endl;
	if ( this != &src )
	{
		this->type = src.getType();
	}
	return *this;
}



//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Cat::makeSound() const
{
	std::cout << " Nyaaaaaaaaaa nyaaaa" << std::endl;
}
