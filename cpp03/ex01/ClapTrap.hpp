/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:59:06 by angela            #+#    #+#             */
/*   Updated: 2024/07/04 14:27:39 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

       ,
       |
    ]  |.-._
     \|"(0)"| _]
     `|=\#/=|\/
      :  _  :
       \/_\/ 
        |=| 
        `-' 
        
*/



#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"


#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_LILAC	       	"\033[1;34m"
#define LIGHT_MAGENTA	        "\033[0;95m"
#define CYAN	        	"\033[1;36m"
#define MAGENTA			"\033[0;35m"
#define LILAC			"\033[0;94m"
#define BLUE			"\033[0;34m"
#define LIGHG_PURPLE	        "\033[0;36m"
#define LIGHT_RED		"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE		"\033[0;94m"
#define PEACH			"\033[0;93m"
#define LIGHT_CYAN      	"\033[0;36m"
#define BOLD			"\033[1m"

class   ClapTrap
{
    private:
        // none, sinon l'enfant n'y a pas accès
    protected:
            std::string	    _name;
            //unsigned int parce qu'on ne tombe pas dans le negatif
            unsigned int    _hp;             //healt
            unsigned int    _energyPoints;   // point d'actions Attacking and repairing
            unsigned int    _attackDamage;
    
    public:
    //--------------------      Constructor- destructor     --------------------
            ClapTrap();
            ~ClapTrap();

            ClapTrap(std::string Name);		// Constructeur (Polymorphisme), donne un autre nom
	        ClapTrap(const ClapTrap &cpy);	// Constructeur de copie
            
    //--------------------------    Operator    ----------------------------
            ClapTrap &operator=(ClapTrap const &src);	// Opérateur d'affectation

     // ------------------------     Getters- Setter     -----------------------
     
            unsigned int getHitPoints() const;
            unsigned int getAttackPoints() const;
            unsigned int getEnergyPoints() const;
    //--------------------------    Fonctions membres     -----------------------
            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
};

#endif


/*

       ,
       |
    ]  |.-._
     \|"(0)"| _]
     `|=\#/=|\/
      :  _  :
       \/_\/ 
        |=| 
        `-' 
        
*/