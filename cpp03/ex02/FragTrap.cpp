/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:23:19 by angela            #+#    #+#             */
/*   Updated: 2024/07/04 15:57:14 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


//.......................................................................................................
//										    Héritage			                       					|
//                                  Constructor - Destructor				        					|
//.......................................................................................................

    FragTrap::FragTrap() : ClapTrap() 
    {
        std::cout << LIGHT_GREEN<< "Default constructor FragTrap called, child of Claptrap" <<RESET_COLOR<< std::endl;
            // this->_hp = 100;
            this->_energyPoints = 100;
            this->_attackDamage = 30;
    }

    FragTrap::~FragTrap() 
    {
         std::cout << "Destructor(FT) called for " <<GREEN<< this->_name<< RESET_COLOR<< std::endl;
    }


    // Constructeur (Polymorphisme), donne un autre nom( param)
//avec les bons réglages
    FragTrap::FragTrap(std::string newName) : ClapTrap(newName) 
    {
        std::cout << "Name constructor FragTrap called for  "<<LIGHT_GREEN<<newName<<RESET_COLOR<< std::endl;
        this->_hp = 100;
        this->_energyPoints = 50;
        this->_attackDamage = 20;
    }

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
//non-hérité, copie construtor de type heritage de parent
//claptrap->FRAGtrap(default)
// Copy constructor, crée nouveau "a" en copie de cpy, objet this = cpy(existants)

   FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap() 
    {
        // std::cout <<GREEN<< "Copy constructor FragTrap called" << RESET_COLOR<< std::endl;
        *this = cpy;
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
// copier les données d'un objet existant dans un objet déjà existant. '='
//FragTrap = FragTrap
// copier les données de l'objet 'other' dans l'objet courant '(*this)'.

            
    FragTrap &FragTrap::operator=(FragTrap const &src)
    {
        // std::cout << "Operator '=' FragTrap called" << std::endl;
        if (this != &src)
        {
            // this->_name = src._name;
            this->_hp = src._hp;
            this->_energyPoints = src._energyPoints;
            this->_attackDamage = src._attackDamage;
        }
        return (*this);
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
    void	FragTrap::highFivesGuys() 
    {
	    std::cout <<GREEN<< this->_name << " want a high five 👋 !" <<RESET_COLOR<< std::endl;
    }