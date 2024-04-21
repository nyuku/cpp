
# ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_equipment;
		std::string	_name;

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