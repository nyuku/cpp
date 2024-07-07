#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>
#include "Brain.hpp"

#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_LILAC	    "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m" //bold light blu
#define MAGENTA			"\033[0;35m"
#define LILAC			"\033[0;94m"
#define BLUE			"\033[0;34m"
#define LIGHG_PURPLE	"\033[0;36m"
#define LIGHT_RED		"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE		"\033[0;94m"
#define PEACH			"\033[0;93m"
#define LIGHT_CYAN      "\033[0;36m"
#define BOLD			"\033[1m"

class AAnimal
{
	private:

	protected:
		std::string	type;

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal( std::string type);
		AAnimal( const AAnimal &cpy);
		AAnimal& operator=( const AAnimal &rhs );
		
	

		virtual void	makeSound() const = 0;// Méthode virtuelle pure
		// virtual void	makeSound() const;

		const std::string	getType( void ) const;
		void	setType( const std::string type );

};

#endif

