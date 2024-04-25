#include "Fixed.hpp"

//--------- Constructor - Destructor ---------//

Fixed::Fixed()
{
	std::cout	<<LIGHT_RED<< "Default constructor called"
				 <<RESET_COLOR<< std::endl<< std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout	<<LIGHT_RED<< "Destructor called"
				 <<RESET_COLOR<< std::endl;
}
//------------- Fonction membre-------------//
//copy constructor- créer un nouvel objet à partir d'un objet existant.
Fixed::Fixed(const Fixed &a)
{
	std::cout	<<BLUE<< "Copy constructor called"
				 <<RESET_COLOR<< std::endl;
	*this = a;
	// copie tout l onjet other dans this
}

//copier les données d'un objet existant dans un objet déjà existant. =
// copier les données de l'objet other dans l'objet courant (*this).
Fixed& Fixed::operator=(const Fixed &other)// copy assignment operator, utilisé pour copier les données d'un objet existant dans un objet déjà existant.
{
	if (this != &other)
	{
		std::cout << MAGENTA<< "Copy assignment operator called" << RESET_COLOR<<std::endl;
		this->_value = other.getRawBits(); // copie seulement le champ _value et pas tout l objet.
	}
	return (*this);
}

// retourne la valeur du nombre à virgule fixe sans la convertir.
int Fixed::getRawBits(void) const
{
	std::cout <<LIGHT_GREEN<< " getRawBits member function called" <<RESET_COLOR<< std::endl;
	return (this->_value);
}

//initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}