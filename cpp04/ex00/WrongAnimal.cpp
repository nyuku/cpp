/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:00 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:18:30 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout <<LILAC<<"W.ANIMAL, type:  "<< this->type<< " \t-Default constructor called." <<RESET_COLOR << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<LILAC<<"W.ANIMAL, type:  "<<RESET_COLOR<< this->type<<LILAC<< " \t-Destructor called." <<RESET_COLOR << std::endl;
}

WrongAnimal::WrongAnimal( std::string type) : type(type)
{
	std::cout <<LILAC<<"W.ANIMAL, type:  "<<RESET_COLOR<< this->type<<LILAC<< " \t-Name constructor called." <<RESET_COLOR << std::endl;
}
//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
WrongAnimal::WrongAnimal( const WrongAnimal &cpy)
{
	*this = cpy;
	std::cout << "WrongAnimal " <<RESET_COLOR<< this->type<<LILAC<< " \t-Copy constructor called" << std::endl;
}
//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &rhs )
{
	std::cout << "WrongAnimal assignement operator called.\n" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}


//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================

void WrongAnimal::makeSound() const
{
	std::cout << "Bip bip booop biip" << std::endl;
}
//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================

const std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::setType( const std::string type )
{
	this->type = type;
}