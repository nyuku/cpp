/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:18:56 by angela            #+#    #+#             */
/*   Updated: 2024/07/04 15:08:33 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

//.......................................................................................................
//										    Héritage			                       					|
//                                  Constructor - Destructor				        					|
//.......................................................................................................
//...: ClapTrap() 
/*
• Name, which is passed as parameter to a constructor -> constructeur par (Polymorphisme)
• Hit points (100), represent the health of the ClapTrap
• Energy points (50)
• Attack damage (20)*/
    ScavTrap::ScavTrap() : ClapTrap() 
    {
        std::cout << LIGHT_CYAN<< "Default constructor ScavTrap called, child of Claptrap" <<RESET_COLOR<< std::endl;
        this->_hp = 100;
        this->_energyPoints = 50;
        this->_attackDamage = 20;
    }
    
    ScavTrap::~ScavTrap() 
    {
         std::cout << "Destructor(ST) called for " <<CYAN<< this->_name<< RESET_COLOR<< std::endl;
    }

// Constructeur (Polymorphisme), donne un autre nom( param)
//avec les bons réglages
    ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) 
    {
        std::cout << "Name constructor ScavTrap called for  "<<LIGHT_CYAN<<newName<<RESET_COLOR<< std::endl;
        this->_hp = 100;
        this->_energyPoints = 50;
        this->_attackDamage = 20;
    }
    

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................
//non-hérité, copie construtor de type heritage de parent
//claptrap->scavtrap(default)
// Copy constructor, crée nouveau "a" en copie de cpy, objet this = cpy(existants)

    ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap() 
    {
        // std::cout <<CYAN<< "Copy constructor ScavTrap called" << RESET_COLOR<< std::endl;
        *this = cpy;
    }


//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
// copier les données d'un objet existant dans un objet déjà existant. '='
//scavtrap = scavtrap
// copier les données de l'objet 'other' dans l'objet courant '(*this)'.

            
    ScavTrap &ScavTrap::operator=(ScavTrap const &src)
    {
        // std::cout << "Operator '=' ScavTrap called" << std::endl;
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
  void ScavTrap::attack(const std::string& target)
    {
      
        if (this->_energyPoints == 0)
            std::cout <<CYAN<< this->_name <<RESET_COLOR<<LIGHT_RED<< "(ST) no energy points left. He cannot attack." << RESET_COLOR<<std::endl;
        else if (this->_hp == 0) 
		    std::cout <<CYAN << this->_name <<RESET_COLOR<<LIGHT_RED << "(ST) is already dead and can't attack! " <<RESET_COLOR<<target<< RESET_COLOR<< std::endl;
        else
        {
            std::cout <<CYAN << this->_name<<RESET_COLOR<< "(ST) attacks "<<LIGHT_RED<< target <<RESET_COLOR<<" who get " <<LIGHT_RED<< this->_attackDamage<< " points of damage !"<< RESET_COLOR<< std::endl;
		    this->_energyPoints--;
        }
    }

    void	ScavTrap::guardGate() 
    {
        if (this->_hp == 0)
        {
            std::cout <<CYAN << this->_name << RESET_COLOR<< LIGHT_RED<< " No hit points left but he keeps his duty as a stone statue" << RESET_COLOR<< std::endl;
        }
        else 
            std::cout <<CYAN<< this->_name << " enter in gate keeper mode" <<RESET_COLOR<< std::endl;
    }
    