#include "ClapTrap.hpp"


int main()
{
	
	
	std::cout <<  "......................................................................................................."<< std::endl;
	std::cout <<  " \t\t\t\t\tCLAPTRAP \t\t"<< std::endl;
	std::cout <<  "......................................................................................................."<< std::endl;
	
	ClapTrap frodo("frodo");
	ClapTrap sam("sam");

	std::cout << std::endl<< " ✿----- Current status Frodo -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< frodo.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< frodo.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
	frodo.attack("orc");
	frodo.beRepaired(10);
	frodo.takeDamage(5);
	std::cout << std::endl<< " ✿-----Current status Frodo -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< frodo.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< frodo.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl<<std::endl<<std::endl;



	std::cout << std::endl<< " ✿-----Current status Sam -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< sam.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< sam.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
	sam = frodo;
	std::cout << std::endl<< " ✿-----Current status Sam -----✿"<< std::endl<<"(Surcharge d'opération '=' Sam = Frodo)"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< sam.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< sam.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;

	
	frodo.attack("orc");
	frodo.beRepaired(10);
	frodo.takeDamage(55); 
	//----dead test-----
	std::cout<<std::endl;
	frodo.attack("Uruk-hai");
	frodo.beRepaired(10);
	frodo.attack("Balrog");
	frodo.beRepaired(10);
	frodo.takeDamage(55);
	std::cout<<std::endl;
	return (0);
}