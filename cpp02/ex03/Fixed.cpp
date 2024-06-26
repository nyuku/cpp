
#include "Fixed.hpp"

//
//(1 << _bit) == / 256
/*Rappel virgule fixe
5.75 en virgule fixe :

    Partie entière : 5
    Partie fractionnaire : 0.75 (0.75×256=1920.75×256=192)
    Valeur en virgule fixe : 5×256+192=14085×256+192=1408

Probleme rencontré pour la multiplication: 

1408(5.75)×256(1.0)= 360448 (devrait etre 1408)
solution: Décalage à droite de 8 bits : 360448>>8=1408(5.75)
concret: /2^8. on decale de 8 bit

       10110110000000000000000  avant decalage
>> 8   ------------------------
       00000000101101100000000  apres decalage, /256
*/

//--------- Constructor - Destructor ---------//
Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//-------------------Constructor-----------------------
//prend l'argument(int ou float) et set en virgule fixe
//convertie en virgule fixe nb * 256
Fixed::Fixed(int const nb)
{
	this->_value = nb * (1 << _bit);
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb)
{
	this->_value = roundf(nb * (1 << _bit));
	// std::cout << "Float constructor called" << std::endl;
}

//-----------------------Copy constructor--------------------------------
//copie objet a= b(existants)
Fixed::Fixed(const Fixed &obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return;
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

//.......................................................................................................
//										 Opérator 														|
//.......................................................................................................

std::ostream& operator<<(std::ostream& o, const Fixed &obj) // o = out flux
{
	o << obj.toFloat();
	return o;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
// 	this->_value = obj.getRawBits();
// 	return (*this);
 if (this != &obj) { // Vérifier l'auto-affectation
        _value = obj._value;
    }
    return *this;
}
//-------------------- Surcharges d'opérateurs de comparaison -----------

bool Fixed::operator>(const Fixed &other) const {
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const {
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const {
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const {
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const {
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const {
    return (this->_value != other._value);
}


//-------------------- Surcharges d'opérateurs arithmétiques ------------
Fixed Fixed::operator+(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}
Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->_value * other.getRawBits()) >> _bit);//valeur brut multiplié, risque perdre précision. Sans ce décalage, le résultat serait incorrectement interprété, car il inclurait trop de bits pour la fraction.
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->_value << _bit)  / other.getRawBits());// / (1 << _bit)
    return result;
}

//-------------------- opérateurs de post/pré incrémentation et de décrémentation ------------
/*
    Pré-incrémentation (++a) : Incrémente d'abord l'objet, puis retourne la nouvelle valeur.
    Post-incrémentation (a++) : Retourne d'abord l'ancienne valeur, puis incrémente l'objet.
*/

//+++++++++++++++++++++++++++++++++++++++++++++++++
//Pré-incrémentation (++a)
// int b = ++a;  a est incrémenté avant d'être assigné à b
Fixed& Fixed::operator++() // incremente l'objet meme
{
	this->_value += 1;
	return(*this); //Retourne une référence à l'objet courant.
}

// Post- incrémentation (a++)
//la valeur de l'objet est utilisée avant d'être incrémentée. L'opérateur retourne l'ancienne valeur de l'objet avant incrémentation.
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this); // crée une copie temporaire  de l'objet et stock la valeur, destruction du temp
	this->_value = this->_value + 1;
	return(tmp); // Retourne la copie temporaire (valeur avant incrémentation)
}

//-------------------------------------------------
Fixed& Fixed::operator--() // --a
{
	this->_value = this->_value - 1;
	return(*this);
}

Fixed Fixed::operator--(int) // a--
{
	Fixed tmp(*this);
	this->_value = this->_value - 1;
	return(tmp);
}

//-----------quatre fonctions membres publiques surchargées min/max------------------
//min
// prenant en paramètres deux références sur des nombres à virgule fixe
Fixed Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
		return b;
}
//prenant en paramètres deux références sur des nombres à virgule fixe constants
Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}


//max
// prenant en paramètres deux références sur des nombres à virgule fixe
Fixed Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
//prenant en paramètres deux références sur des nombres à virgule fixe constants
Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
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