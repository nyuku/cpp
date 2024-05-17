/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:02:36 by angela            #+#    #+#             */
/*   Updated: 2024/05/16 18:15:58 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_equipment = NULL;
	std::cout <<BLUE<< this->_name <<RESET_COLOR<< " born with "<<CYAN<<"no weapon"<<RESET_COLOR << std::endl;
}
HumanB::~HumanB()
{
}
//-------------------------------------
void	HumanB::attack()
{
	if (this->_equipment == NULL)
		std::cout <<LIGHT_RED<< this->_name << " attacks without weapon" <<RESET_COLOR<< std::endl;
	else
		std::cout <<DARK_BLUE<< this->_name  <<RESET_COLOR " attacks with their " <<CYAN<< this->_equipment->getType() <<CYAN<< std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->_equipment = &weapon;
}