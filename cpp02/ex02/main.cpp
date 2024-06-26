#include "Fixed.hpp"

int main( void )
{
	std::cout <<std::endl<< CYAN <<" ----- Fixed a -----"<< RESET_COLOR<<std::endl;
		Fixed a;
		std::cout<<LIGHT_CYAN << "[default]\t a is " << a << std::endl<< std::endl<<RESET_COLOR;
	std::cout << CYAN <<" ----- Fixed b( 5.05f ) * Fixed( 2 ) ) -----"<< RESET_COLOR<<std::endl;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout <<LIGHT_CYAN<< "Value de 'b' en virgule fixe: "<<	b.getRawBits()<< RESET_COLOR<< std::endl;
		Fixed c (10);
		Fixed d (5);

	std::cout <<std::endl<< CYAN << "----- Opérateurs arithmétiques -----"<< RESET_COLOR<<std::endl;
		std::cout << "valeur de a   : "	<< a 	<<"\t\t,[virgule fixe] "<< a.getRawBits()<< std::endl;
		std::cout << "valeur de c   : "	<< c 	<<"\t\t,[virgule fixe] "<< c.getRawBits()<< std::endl;
		std::cout << "valeur de d   : "	<< d 	<<"\t\t,[virgule fixe] "<< d.getRawBits()<< std::endl<< std::endl;

		std::cout << "a + c [0 + 10]: "	<< a+c 	<<"\t\t,[virgule fixe] "<< a.getRawBits()+ c.getRawBits()<< std::endl;
		std::cout << "c - d [10 - 5]: "	<< c-d 	<<"\t\t,[virgule fixe] "<< c.getRawBits()- d.getRawBits()<< std::endl;
		std::cout << "a * d [0 * 5]: "	<< a*d 	<<"\t\t,[virgule fixe] "<< a.getRawBits()* d.getRawBits()<< std::endl;
		std::cout << "c / d [10 / 5]: "	<< c/d 	<<"\t\t,[virgule fixe] "<< c.getRawBits()/ d.getRawBits()<< std::endl;

	std::cout <<std::endl<< CYAN << "----- Opérateurs comparaison -----"<< RESET_COLOR<<std::endl;
		std::cout << "valeur de a   : "	<< a 	<<"\t\t,[virgule fixe] "<< a.getRawBits()<< std::endl;
		std::cout << "valeur de c   : "	<< c 	<<"\t\t,[virgule fixe] "<< c.getRawBits()<< std::endl;
		std::cout << "valeur de d   : "	<< d 	<<"\t\t,[virgule fixe] "<< d.getRawBits()<< std::endl<< std::endl;

		std::cout << "retourne 0 si faux, 1 si vrai "	<< (a > c )	<< std::endl;
		std::cout << "a > c \t[0 >? 10] \t"		<< (a > c )	<< std::endl;
		std::cout << "a < c \t[0 >? 10] \t"		<< (a < c )	<< std::endl;
		std::cout << "c == d \t[10 ==? 5] \t"	<< (c == d) << std::endl;
		std::cout << "a != d \t[0 != 5] \t"		<< (a != d) << std::endl;
		std::cout << "c <= d \t[10 <= 5] \t"		<< (c<=d) 	<< std::endl;
		std::cout << "c >= d \t[10 >= 5] \t"		<< (c>=d) 	<< std::endl;

	std::cout <<std::endl<< CYAN << "----- Decrementation -----"<< RESET_COLOR<<std::endl;
			std::cout << "valeur de c   : "	<< c 	<<"\t,[virgule fixe] "<<	c.getRawBits()<< std::endl  << std::endl;

			std::cout << "valeur de --c : "	<< --c 	<<"\t,[virgule fixe] "<<	c.getRawBits()<< std::endl;
			std::cout << "valeur de c   : "	<< c 	<<"\t,[virgule fixe] "<<	c.getRawBits()<< std::endl<< std::endl;

			Fixed temp = c;
			std::cout << "valeur de c-- : "	<< c-- 	<<"\t,[virgule fixe] "<<	temp.getRawBits()<< std::endl;
			std::cout << "valeur de c   : "	<< c 	<<"\t,[virgule fixe] "<<	c.getRawBits()<< std::endl<< std::endl;
			
	std::cout <<std::endl<< CYAN << "----- Incrementation -----"<< RESET_COLOR<<std::endl;
		std::cout << "valeur de a   : "	<< a 	<<"\t\t,[virgule fixe] "<< a.getRawBits()<< std::endl<< std::endl;

		std::cout << "valeur de ++a : "	<< ++a 	<<"\t,[virgule fixe] "<< a.getRawBits()<< std::endl;
		std::cout << "valeur de a   : "	<< a 	<<"\t,[virgule fixe] "<< a.getRawBits()<< std::endl<< std::endl;

		temp = a;// si on met a++, renvoie une copie temporaire avant l'incrementation
		std::cout << "valeur de a++ : "	<< a++ 	<<"\t,[virgule fixe] " <<temp.getRawBits()<< std::endl;
		std::cout << "valeur de a   : "	<< a 	<<"\t,[virgule fixe] "<< a.getRawBits()<< std::endl<< std::endl;
		

	std::cout << std::endl<< CYAN << "----- Fixed max (a, b) -----"<< RESET_COLOR<<std::endl;
		std::cout << "valeur de a : \t\t\t"<< a 	<<",\t[virgule fixe] "<< a.getRawBits()<< std::endl;
		std::cout << "valeur de b : \t\t\t"	<< b 	<<",\t[virgule fixe] "<< b.getRawBits()<< std::endl;
		std::cout <<"valeur de max entre a et b : \t"<<Fixed::max( a, b ) <<  std::endl<<  std::endl;
	
	std::cout << std::endl<< CYAN << "----- Fixed min (a, b) -----"<< RESET_COLOR<<std::endl;
		std::cout << "valeur de a : \t\t\t"<< a 	<<",\t[virgule fixe] "<< a.getRawBits()<< std::endl;
		std::cout << "valeur de b : \t\t\t"	<< b 	<<",\t[virgule fixe] "<< b.getRawBits()<< std::endl;
		std::cout <<"valeur de min entre a et b : \t"<<Fixed::min( a, b ) <<  std::endl<<  std::endl;
	return 0;
}