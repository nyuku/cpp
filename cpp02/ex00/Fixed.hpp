
#ifndef Harl_HPP
#define Harl_HPP

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


class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
	//----------------- Constructor- destructor -----------------
		Harl(void);
		~Harl(void);
	// ----------------- Getters- Setter -----------------

	//-------------- Fonction ----------------
		void complain( std::string level);

};

#endif
