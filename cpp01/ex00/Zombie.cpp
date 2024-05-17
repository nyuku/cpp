/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:55:56 by angela            #+#    #+#             */
/*   Updated: 2024/05/04 00:55:57 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//--------- Constructor - Destructor ---------//

Zombie::Zombie(std::string name)
{
	std::cout	<< "Something move on the ground...under the ground??"
				 << std::endl;
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout	<< "shhht...It's safe and sound..."
				<< this->_name
				<<" is gone"
				<< std::endl;
}
//------------- Fonction membre-------------//

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return;
}

void	Zombie::announce( void )
{
	std::cout <<CYAN<<this->_name
		  <<RESET_COLOR
		  <<": BraiiiiiiinnnzzzZ..."
		  << std::endl;
}
