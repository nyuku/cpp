/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:42:28 by angela            #+#    #+#             */
/*   Updated: 2024/07/04 15:24:35 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
        ,
       |
    ]  |.-._  *biip*
     \|"(0)"| _]
     `|=\#/=|\/          /       *boup*
      :  _  :            ["]  ,<     
       \/_\/             [~]\/  
        |=|              OOO      
        `-'               
 */
 
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP



#include "ClapTrap.hpp"

//will inherit the constructors and destructor from Clap- Trap
//its constructors, destructor and attack() will print different messages.
//.......................................................................................................
//										    Scavtrap			                       					|
//.......................................................................................................

class ScavTrap : public ClapTrap{
     private:
        //use Claptrap attribute(parent)

     public:
        // Constructor- destructor    
            ScavTrap();
            ~ScavTrap();
            
        // Constructeur par copie et polymorphisme
            ScavTrap(std::string name);
            ScavTrap(const ScavTrap &other);
            
        //  Operator  
            ScavTrap& operator=(ScavTrap const &src);
            
        //  Fonctions membres
            void guardGate();
            void attack(const std::string& target);
};

#endif