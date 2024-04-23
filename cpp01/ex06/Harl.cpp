#include "Harl.hpp"

//--------- Constructor - Destructor ---------//

Harl::Harl()
{
	std::cout	<<LIGHT_CYAN<< "Oh?? An earthquake?! Oh no...He...is coming.."
				 <<RESET_COLOR<< std::endl;
}

Harl::~Harl()
{
	std::cout	<<LIGHT_CYAN<< "Phew....he's leaving.."
				 <<RESET_COLOR<< std::endl<< std::endl;
}
//------------- Fonction membre-------------//

void Harl::debug( void )
{
	std::cout <<CYAN<< "\U0001F60D [DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" <<RESET_COLOR<< std::endl<< std::endl;
}

void Harl::info( void )
{
	std::cout <<LIGHT_LILAC<< "\U0001F616 [INF0] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<RESET_COLOR<< std::endl<< std::endl;
}

void Harl::warning( void )
{
	std::cout <<LIGHT_GREEN<< " \U0001F615 [WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<RESET_COLOR<< std::endl<< std::endl;
}

void Harl::error( void )
{
	std::cout<<LIGHT_RED << "\U0001F621 [ERROR] This is unacceptable! I want to speak to the manager now." << RESET_COLOR<<std::endl<< std::endl;
}

void	Harl::complain(std::string str)
{
	//void (Harl::*ptr_level[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
//	std::string	lvl[4] = { "debug", "info", "warning", "error" };
	std::string	LVL[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (i = 0; i < 4; i++)
	{
		if (!(LVL[i]).compare(str))
			break;
	}
	if (i == 4)
	{
		std::cerr<< LIGHT_RED << "ERROR: Argument not valid" << RESET_COLOR<<std::endl;
		return;
	}
	while (i < 4)
	{
		switch(i)
		{
			case 0:
				this->Harl::debug();
				break;
			case 1:
				this->Harl::info();
				break;
			case 2:
				this->Harl::warning();
				break;
			case 3:
				this->Harl::error();
				break;
		}
		i++;
	}
}