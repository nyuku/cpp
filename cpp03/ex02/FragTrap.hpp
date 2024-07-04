/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:13:48 by angela            #+#    #+#             */
/*   Updated: 2024/07/04 15:25:35 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
        ;     /        ,--.     
       ["]   ["]  ,<  |__**|    
      /[_]\  [~]\/    |//  |    
       ] [   OOO      /o|__|   */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//.......................................................................................................
//                                         FRAGTRAP                   					|
//.......................................................................................................

class FragTrap : public ClapTrap
{
        private:

        public:
                FragTrap();
                ~FragTrap();
                
                FragTrap(std::string Name); // Constructeur string (Polymorphisme)
                FragTrap(const FragTrap &cpy); // Constructeur de copie
                
                FragTrap &operator=(FragTrap const &rhs); // Opérateur d'affectation
              
	        void	highFivesGuys();
};


#endif