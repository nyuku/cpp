
# ifndef WEAPON_HPP
# define WEAPON_HPP


//--------------- Library -------------------
# include	<string>
# include	<iostream>

//--------------- Color -------------------
#define RESET_COLOR 	"\033[0m"
#define SOFT_GREEN  	"\033[0;92m"
#define LIGHT_GREEN	"\033[1;32m"
#define LIGHTPURPLE	"\033[1;35m"
#define LIGHT_LILAC	"\033[1;34m"
#define LIGHT_MAGENTA   "\033[0;95m"
#define LIGHT_CYAN	"\033[1;36m"
#define MAGENTA		"\033[0;35m"
#define LILAC		"\033[0;94m"
#define BLUE		"\033[0;34m"
#define CYAN		"\033[0;36m"
#define LIGHT_RED       " \033[0;91m"
#define GREEN           " \033[0;32m"
#define DARK_BLUE       "\033[0;94m"
# efine PEACH		"\033[0;93m"

class Weapon
{
	private:
		std::string	_type;

	public:
	//----------------- Constructor- destructor -----------------
		Weapon(std::string name);
		~Weapon(void);
	// -----------------  Getters -----------------
		const std::string	&getType(void)const;
	// -----------------  Setters -----------------
		void 			setType(std::string str);
	//-------------- Fonction ----------------

};

#endif
