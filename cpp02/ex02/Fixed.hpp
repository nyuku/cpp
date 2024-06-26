
#ifndef FIXED_HPP
#define FIXED_HPP

//--------------- Library -------------------
# include	<string>
# include	<iostream>
# include	<sstream>


//--------------- Color -------------------
#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_LILAC		"\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define LIGHT_CYAN		"\033[1;36m"
#define MAGENTA			"\033[0;35m"
#define LILAC			"\033[0;94m"
#define BLUE			"\033[0;34m"
#define LIGHG_PURPLE	"\033[0;36m"
#define LIGHT_RED		"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE		"\033[0;94m"
#define PEACH			"\033[0;93m"
#define CYAN			"\033[0;36m"


class Fixed
{
	private:
		int					_value;
		static int	const	_bit = 8;

	public:
	//----------------- Constructor- destructor -----------------
		Fixed();
		~Fixed();

		Fixed(const int nb);
		Fixed(const float nb);

		Fixed( const Fixed &obj );			// Constructeur de copie
		Fixed &operator=(const Fixed &obj);	// Opérateur d'affectation

	//-------------------- Surcharges d'opérateurs de comparaison -----------

		bool  operator>(const Fixed &other) const;
		bool  operator<(const Fixed &other) const;
		bool  operator>=(const Fixed &other) const;
		bool  operator<=(const Fixed &other) const;
		bool  operator==(const Fixed &other) const;
		bool  operator!=(const Fixed &other) const;

	//-------------------- Surcharges d'opérateurs arithmétiques ------------
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

	//-------------------- opérateurs de post/pré incrémentation et de décrémentation ------------
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
	//----------------- Fonctions membresmax/min -----------------
		static Fixed min(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);
		static Fixed max(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);

	// ----------------- Getters- Setter -----------------
		int getRawBits(void) const;
		void setRawBits(int const raw);

	//-------------- Fonction ----------------

		float toFloat( void ) const; // convertit la valeur en virgule fixe en nombre à virgule flottante
		int toInt( void ) const; // convertit la valeur en virgule fixe en nombre entier.


};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
#endif