#include "ScavTrap.hpp"


int main()
{
	
	
	std::cout <<  "......................................................................................................................."<< std::endl;
	std::cout <<  " \t\t\t\t\t\ttCLAPTRAP & SCAVTRAP \t\t"<< std::endl;
	std::cout <<  "......................................................................................................................."<< std::endl;
	
	std::cout<<LILAC<<"• This color is for Claptrap"<<std::endl;
	std::cout<<CYAN<<"• This color is for Scavtrap"<<std::endl<<std::endl;


	std::cout<<std::endl;
	ClapTrap tom("Tom");

	std::cout<<std::endl;
	ScavTrap jerry("Jerry");

	std::cout<<std::endl;
	ScavTrap tuffy("Tuffy");

	std::cout << std::endl<< " ✿----- Current status Tom -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tom.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<LIGHT_GREEN<< tom.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
	tom.attack("spike");
	tom.beRepaired(10);
	tom.takeDamage(5);
	std::cout << std::endl<< " ✿-----Current status Tom -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tom.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<LIGHT_GREEN<< tom.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl<<std::endl<<std::endl;


	std::cout<<".............................................\tScavtrapp\t...................................................."<<std::endl<<std::endl;
	std::cout << std::endl<< " ✿-----Current status Jerry -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< jerry.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< jerry.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
	jerry.attack("spike");
	jerry.beRepaired(20);
	jerry.takeDamage(40);
	std::cout << std::endl<< " ✿-----Current status Jerry -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< jerry.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< jerry.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;

	std::cout << std::endl<< " ✿-----Current status Tuffy -----✿"<< std::endl<<"(Fresh)"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tuffy.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<LIGHT_GREEN<< tuffy.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
	tuffy = jerry;
	std::cout << std::endl<< " ✿-----Current status Tuffy -----✿"<< std::endl<<"(Surcharge d'opération '=' tuffy = jerry)"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tuffy.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< tuffy.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;


	tom.attack("spike");
	jerry.attack("spike");
	tuffy.attack("spike");

	jerry.guardGate();
	jerry.takeDamage(155); 
	//----dead test-----
	std::cout<<std::endl;
	jerry.guardGate();
	jerry.attack("Butch");
	jerry.beRepaired(10);
	jerry.takeDamage(55);
	std::cout<<std::endl;
	return (0);
}