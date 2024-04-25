
#ifndef FIXED_HPP
#define FIXED_HPP

//--------------- Library -------------------
# include	<string>
# include	<iostream>
# include	<sstream>


//--------------- Color -------------------
#define RESET_COLOR "\033[0m"
#define SOFT_GREEN   "\033[0;92m"
#define LIGHT_GREEN	 "\033[1;32m"
#define LIGHTPURPLE		" \033[1;35m"
#define LIGHT_LILAC		" \033[1;34m"
#define LIGHT_MAGENTA   " \033[0;95m"
#define LIGHT_CYAN		" \033[1;36m"
#define MAGENTA			" \033[0;35m"
#define LILAC			" \033[0;94m"
#define BLUE			" \033[0;34m"
#define CYAN			" \033[0;36m"
#define LIGHT_RED       " \033[0;91m"


class Fixed
{
	private:
		int					_value;
		static int	const	_bitsNb = 8;

	public:
	//----------------- Constructor- destructor -----------------
		Fixed();
		~Fixed();
		Fixed( const Fixed &obj );			// Constructeur de copie
		Fixed &operator=(const Fixed &obj);	// Opérateur d'affectation

	// ----------------- Getters- Setter -----------------
		int getRawBits(void) const;
		void setRawBits(int const raw);

	//-------------- Fonction ----------------


};

#endif