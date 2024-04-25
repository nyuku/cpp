
#include "Fixed.hpp"

//
//(1 << _bit) == / 256

//--------- Constructor - Destructor ---------//
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
//------------------------------------------------
Fixed::Fixed(int const nb)
{
	this->_value = nb * (1 << _bit);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb)
{
	this->_value = roundf(nb * (1 << _bit));
	std::cout << "Float constructor called" << std::endl;
}
//-----------------------Copyr--------------------------------


Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = obj.getRawBits();
	return (*this);
}

//--------------------Fonction-------------------------------

float Fixed::toFloat( void ) const // convertit la valeur en virgule fixe en nombre à virgule flottante
{
	return static_cast<float>(this->_value) / (1 << _bit);
}

int Fixed::toInt( void ) const // convertit la valeur en virgule fixe en nombre entier.
{
	return this->_value / (1 << _bit);
}

std::ostream& operator<<(std::ostream& o, const Fixed &obj) // o = out flux
{
	o << obj.toFloat();
	return o;
}

//-----------------------getters setters--------------------------------


int Fixed::getRawBits(void) const // retourne la valeur du nombre à virgule fixe sans la convertir.
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw) //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
{
	this->_value = raw;
}