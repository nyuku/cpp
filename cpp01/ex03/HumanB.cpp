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
		std::cout <<LIGHT_GREEN<<" "<< this->_name << " attacks without weapon" <<RESET_COLOR<< std::endl;
	else
		std::cout <<DARK_BLUE<<" "<< this->_name  <<RESET_COLOR " attacks with their " <<CYAN<< this->_equipment->getType() <<CYAN<< std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->_equipment = &weapon;
}

//
//std::string	getName() const;
//std::string	getWeapon() const;
//// -----------------  Setters -----------------
//void setWeapon(Weapon & weapon);
////-------------- Fonction ----------------
//void attack();