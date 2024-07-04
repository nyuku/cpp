/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:58:22 by angela            #+#    #+#             */
/*   Updated: 2024/07/04 15:55:26 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//ClapTrap:ClapTrap pour le cpp



//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
    ClapTrap::ClapTrap(): _name("Default"), _hp(10), _energyPoints(10), _attackDamage(0)
    {
        std::cout << "Default constructor called, user called default" << std::endl;
    }
    ClapTrap::~ClapTrap()
    {
        std::cout << "Destructor called for     " <<LILAC<< this->_name<< RESET_COLOR<< std::endl;
    }


// Constructeur (Polymorphisme), donne un autre nom( param)
    ClapTrap::ClapTrap(std::string newName): _name(newName), _hp(10), _energyPoints(10), _attackDamage(0)
    {
        std::cout <<RESET_COLOR<< "Claptrap: Name constructor called for " <<LILAC<<newName<<RESET_COLOR<< std::endl;
    }

//.......................................................................................................
//										 Copy constructor												|
//.......................................................................................................

// Copy constructor, crée nouveau "a" en copie de cpy, objet this = cpy(existants)
    ClapTrap::ClapTrap(const ClapTrap &cpy)
    {
        //std::cout << "Copy constructor called" << std::endl;
        *this = cpy;
        return;
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................


// copier les données d'un objet existant dans un objet déjà existant. '='
// copier les données de l'objet 'other' dans l'objet courant '(*this)'.
    ClapTrap &ClapTrap::operator=(ClapTrap const &src)
    {
        if (this != &src)
        {
            this->_name = src._name;
            this->_hp = src._hp;
            this->_energyPoints = src._energyPoints;
            this->_attackDamage = src._attackDamage;
        }
        return (*this);
    }

/*

       ,
       |
    ]  |.-._
     \|"(0)"| _] *bip booop bup *
     `|=\#/=|\/
      :  _  :
       \/_\/ 
        |=| 
        `-' 
        
*/
//=======================================================================================================
//										   Fonctions membres													|
//=======================================================================================================
    void ClapTrap::attack(const std::string& target)
    {
      
        if (this->_energyPoints == 0)
            std::cout <<LILAC << this->_name <<RESET_COLOR<<LIGHT_RED<< " no energy points left. He cannot attack." << RESET_COLOR<<std::endl;
        else if (this->_hp == 0) 
		    std::cout <<LILAC << this->_name <<RESET_COLOR<<LIGHT_RED << " is already dead and can't attack! " <<RESET_COLOR<<target<< RESET_COLOR<< std::endl;
        else
        {
            std::cout <<LILAC << this->_name<<RESET_COLOR<< " attacks "<<LIGHT_RED<< target <<RESET_COLOR<<" who get " <<LIGHT_RED<< this->_attackDamage<< " points of damage !"<< RESET_COLOR<< std::endl;
		    this->_energyPoints--;
        }
    }
    
    void ClapTrap::takeDamage(unsigned int amount)
    //unsigned int deborde si on passe le cap des negatifs
    {
        
        if (this->_hp == 0) 
		    std::cout <<LILAC << this->_name <<LIGHT_RED << " is already dead and can't take more!" << RESET_COLOR<< std::endl;
        else
        {
             std::cout <<LILAC << this->_name << RESET_COLOR<< " gets hit and gets -" <<LIGHT_RED<< amount << " damage points !" <<RESET_COLOR<< std::endl;
             if (amount >= this->_hp)
                {
                    
                    std::cout <<LILAC << this->_name <<RESET_COLOR << " is completely destroyed and dead with -"<<LIGHT_RED<<amount<<RESET_COLOR<< " pts damages" << RESET_COLOR << " on "<<LIGHT_GREEN<<this->_hp<<RESET_COLOR<< " hp"<< std::endl;
                    this->_hp = 0;
                }
             else
                this->_hp -= amount;
             if (this->_hp > 0)
                std::cout <<LILAC << this->_name << RESET_COLOR<< " has " <<LIGHT_GREEN<< this->_hp<<RESET_COLOR << " healt points left !" << std::endl;
            else
                std::cout <<LILAC << this->_name << LIGHT_RED<< " is deadly dead " <<RESET_COLOR<< std::endl;
        }
    }
    void ClapTrap::beRepaired(unsigned int amount)
    {
        if (this->_energyPoints == 0)
            std::cout <<LILAC << this->_name <<RESET_COLOR<<LIGHT_RED<< " no energy points left. He cannot heal himself." << RESET_COLOR<<std::endl;
        else if (this->_hp == 0) 
		    std::cout <<LILAC << this->_name <<RESET_COLOR<<LIGHT_RED << " is already dead and can't heal!" << RESET_COLOR<< std::endl;
        else
        {
            this->_hp += amount;
            std::cout <<LILAC << this->_name <<RESET_COLOR<< " heal with"<< LIGHT_CYAN<< " 1 "<< RESET_COLOR <<"energy point. +" <<LIGHT_GREEN<< amount<<RESET_COLOR<< " pt, current health: " <<LIGHT_GREEN << this->_hp <<RESET_COLOR<< " hp"<<std::endl;
        }
    }
//=======================================================================================================
//										   Getters-Setters													|
//=======================================================================================================
    //est ce que je peux print directement depuis la fonction qui va cherche la valeur de la varible.
    //ou besoin du getteur pour print les valeur.. parce quon est en dehors de ka fonction?
    unsigned int ClapTrap::getHitPoints() const
    {
       return(this->_hp);
    }
    unsigned int ClapTrap::getAttackPoints() const
    {
        return(this->_attackDamage);
    }
    unsigned int ClapTrap::getEnergyPoints() const
    {
        return(this->_energyPoints);
    }