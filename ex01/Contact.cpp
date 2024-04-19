#include	"Contact.hpp"

//---------  Consctructor - Destructor  -----------------
Contact::Contact(void)
{
//	std::cout << "Constructor Contact called"
//			  << std::endl;
//	return;
}

Contact::~Contact(void)
{
//	std::cout << "Destructor Contact called"
//	          << std::endl;
//	return;
}

//---------  fonctions Getters attributs  -----------------
std::string	Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string	Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string	Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string	Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

//---------  fonctions Setter attributs  -----------------
//inialise nos attributs membres de la classe
void	Contact::setFirstName(std::string str)
{
	if (!str.empty())
	{
		this->_firstName = str;
		return;
	}
}

void	Contact::setLastName(std::string str)
{
	if (!str.empty())
	{
		this->_lastName = str;
		return;
	}
}

void	Contact::setNickname(std::string str)
{
	if (!str.empty())
	{
		this->_nickname = str;
		return;
	}
}

void	Contact::setPhoneNumber(std::string str)
{
	if (!str.empty())
	{
		this->_phoneNumber = str;
		return;
	}
}
void	Contact::setDarkestSecret(std::string str)
{
	if (!str.empty())
	{
		this->_darkestSecret = str;
		return;
	}
}