
# ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_equipment; // ne vient pas avoir une arme, on lui attrivue après
		
	public:
		//----------------- Constructor- destructor -----------------
		HumanB(std::string name);
		~HumanB(void);

		// -----------------  Getters -----------------
//		std::string	getName() const;
//		std::string	getWeapon() const;
		// -----------------  Setters -----------------
		void setWeapon(Weapon & weapon);
		//-------------- Fonction ----------------
		void attack();
};


#endif