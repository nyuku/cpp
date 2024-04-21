
# ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_equipment; // réference


	public:

		HumanA(std::string name, Weapon &type);
		~HumanA(void);

		// -----------------  Getters -----------------
//		std::string	getName() const;
//		std::string	getWeapon() const;
		// -----------------  Setters -----------------
		void setWeapon(Weapon & weapon);
		//-------------- Fonction ----------------
		void attack();
};


#endif