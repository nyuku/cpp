#include "ScavTrap.hpp"
#include "FragTrap.hpp"



int main()
{
	
	
	std::cout <<  "......................................................................................................................."<< std::endl;
	std::cout <<  " \t\t\t\t\t\tCLAPTRAP & SCAVTRAP & FRAGTRAP \t\t"<< std::endl;
	std::cout <<  "......................................................................................................................."<< std::endl;
	
	std::cout<<LILAC<<"• This color is for Claptrap"<<std::endl;
	std::cout<<CYAN<<"• This color is for Scavtrap"<<std::endl;
	std::cout<<GREEN<<"• This color is for Fragtrap"<<std::endl<<std::endl;


	std::cout<<std::endl;
	ClapTrap tom("Tom");

	std::cout<<std::endl;
	ScavTrap jerry("Jerry");

	std::cout<<std::endl;
	FragTrap tuffy("Tuffy");

	std::cout << std::endl<< " ✿-----Current status"<< LILAC<<" Tom"<<RESET_COLOR<<" -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tom.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<LIGHT_GREEN<< tom.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
		tom.attack("spike");
		tom.beRepaired(10);
		tom.takeDamage(5);
	std::cout << " ✿-----Current status"<< LILAC<<" Tom"<<RESET_COLOR<<" -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tom.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<LIGHT_GREEN<< tom.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl<<std::endl;
	std::cout<<"......................................................................................................"<<std::endl;

	std::cout << std::endl<< " ✿-----Current status"<<CYAN<< " Jerry"<< RESET_COLOR<<" -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< jerry.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< jerry.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
		jerry.attack("spike");
		jerry.beRepaired(20);
		jerry.takeDamage(40);
		jerry.guardGate();
	std::cout << std::endl<< " ✿-----Current status"<<CYAN<< " Jerry"<< RESET_COLOR<<" -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< jerry.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< jerry.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
	std::cout<<"......................................................................................................"<<std::endl;

	std::cout << std::endl<< " ✿-----Current status"<<GREEN<<" Tuffy"<<RESET_COLOR<<" -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tuffy.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< tuffy.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;
		tuffy.attack("spike");
		tuffy.beRepaired(10);
		tuffy.takeDamage(60);
		tuffy.highFivesGuys();
	std::cout << std::endl<< " ✿-----Current status"<<GREEN<<" Tuffy"<<RESET_COLOR<<" -----✿"<< std::endl<<"Hp: \t\t"<<LIGHT_GREEN<< tuffy.getHitPoints()<<RESET_COLOR << std::endl<<"Energy point: \t"<<CYAN<< tuffy.getEnergyPoints()<<RESET_COLOR<< std::endl;
	std::cout<<std::endl;

	std::cout<<"........................................... DEATH ..........................................................."<<std::endl;
	tuffy.takeDamage(155); 
	//----dead test-----
	std::cout<<std::endl;
	tuffy.attack("Butch");
	tuffy.beRepaired(10);
	tuffy.takeDamage(55);
	std::cout<<std::endl;
	return (0);
}