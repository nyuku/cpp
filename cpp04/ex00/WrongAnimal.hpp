/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:02 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:33:13 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

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

/*
	Classe parent
	Ici on test sans mettre makesound en virtuel. On verra que c'est un simpke héritage
	où l'enfant recoit la fonction tel quel
*/

class WrongAnimal
{
	private:

	protected:
		std::string	type;

	public:
	//--------------------      Constructor- destructor     --------------------
		WrongAnimal();
		// ~WrongAnimal(); // si on veut tester la diff entre virtual et heritage
		virtual ~WrongAnimal();
		WrongAnimal( std::string type);
		WrongAnimal( const WrongAnimal &cpy);
	//--------------------------    Operator    ----------------------------
		WrongAnimal& operator=( const WrongAnimal &rhs );
		
 	//--------------------------    Fonctions membres     -----------------------
		void	makeSound() const;
		
    // ------------------------     Getters- Setter     -----------------------
		const std::string	getType( void ) const;
		void	setType( const std::string type );

};

#endif
