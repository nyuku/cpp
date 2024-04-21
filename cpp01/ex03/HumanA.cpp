
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _equipment(weapon)//init
{
	std::cout <<LILAC<< this->_name <<RESET_COLOR<< " born with " <<CYAN<< this->_equipment.getType() <<RESET_COLOR<< std::endl;
}

HumanA::~HumanA(){}

void HumanA::attack()
{

	std::cout <<LILAC<< this->_name<<RESET_COLOR << " attacks with their "  <<CYAN<< this->_equipment.getType() <<RESET_COLOR<< std::endl;

}