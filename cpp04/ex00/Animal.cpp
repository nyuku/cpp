/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:39 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:06:48 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Animal::Animal() : type("Animal")
{
	std::cout <<LILAC<<"ANIMAL, type:  "<< this->type<< " \t-Default constructor called." <<RESET_COLOR << std::endl;
}

Animal::~Animal()
{
	std::cout <<LILAC<< "Animal, type:  " << this->type << " \t-Destructor called" <<RESET_COLOR<< std::endl;
}

Animal::Animal( std::string type) : type(type)
{
	std::cout <<LILAC<< "Animal, type:  " <<RESET_COLOR<< this->type <<LILAC<< " \t-Name constructor called." <<RESET_COLOR<< std::endl;
}

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
Animal::Animal( const Animal &cpy)
{
	*this = cpy;
	std::cout << "Animal " << this->type << " copy constructor called" << std::endl;
}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
Animal& Animal::operator=( const Animal &rhs )
{
	std::cout << "Animal assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void Animal::makeSound() const
{
	std::cout <<LILAC<< "Mooooooo" <<RESET_COLOR<< std::endl;
}
/*
	Par default les autres classes feront "mooooo" s'ils ont pas override a leur sauce. 
	± des layers
*/

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
const std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::setType( const std::string type )
{
	this->type = type;
}