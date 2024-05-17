#include "Weapon.hpp"

Weapon::Weapon(std::string name) : _type(name){}
Weapon::~Weapon(){}


const std::string &Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}