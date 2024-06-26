
#include "Fixed.hpp"

//(1 << _bit) == / 256

//--------- Constructor - Destructor default ---------//
//si sans arguments, init = 0
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//-------------------Constructor-----------------------
//prend l'argument(int ou float) et set en virgule fixe
//convertie en virgule fixe nb * 256
Fixed::Fixed(int const nb)
{
	this->_value = nb * (1 << _bit);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb)
{
	this->_value = roundf(nb * (1 << _bit));//arrondi à l'entier le plus proche.
	std::cout << "Float constructor called" << std::endl;
}

//-----------------------Copyr--------------------------------

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return;
}

//--------------------Fonction-------------------------------

float Fixed::toFloat( void ) const // convertit la valeur en virgule fixe en nombre -> float, n/ 256
{
	return static_cast<float>(this->_value) / (1 << _bit);
}

int Fixed::toInt( void ) const // convertit la valeur en virgule fixe -> nombre entier, n / 256
{
	return this->_value / (1 << _bit);
}

//--------------Surcharge de l'opérateur ---------------------
//convertit la valeur brute de la virgule fixe en une valeur flottante 
std::ostream& operator<<(std::ostream& o, const Fixed &obj) //  endroit ou l'on veut qu'il envoir,o = out flux, l'objet)
{
	o << obj.toFloat(); // converti l'objet en float
	return o;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = obj.getRawBits();
	return (*this);
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