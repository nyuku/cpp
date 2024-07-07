/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:51 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:02:23 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Dog::Dog() : Animal("Dog")
{
	std::cout << "     little 🐶 " <<LIGHT_GREEN<< this->type <<RESET_COLOR<< " \t-Default constructor called." << std::endl;
}
Dog::~Dog()
{
	std::cout << "     little 🐶 "<<LIGHT_GREEN<< this->type <<RESET_COLOR<< " \t-Destructor called." << std::endl;
}

Dog::Dog( std::string type) : Animal(type)
{
	std::cout << "     little 🐶 "<< this->type << " \t-Name constructor called." << std::endl;
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

Dog& Dog::operator=( const Dog &src )
{
	std::cout <<CYAN<< "Dog"<< RESET_COLOR<<" assignement operator called.\n" << std::endl;
	if ( this != &src )
	{
		this->type = src.getType();
	}
	return *this;
}
//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Dog::makeSound() const
{
	
	std::cout << " WOOOOOOOOOF woooof " << std::endl;
}
