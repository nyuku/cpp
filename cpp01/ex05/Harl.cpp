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
				 <<RESET_COLOR<< std::endl;
}
//------------- Fonction membre-------------//

void Harl::debug( void )
{
	std::cout <<CYAN<< "\U0001F60D I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" <<RESET_COLOR<< std::endl<< std::endl;
}

void Harl::info( void )
{
	std::cout <<LIGHT_LILAC<< "\U0001F616 I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<RESET_COLOR<< std::endl<< std::endl;
}

void Harl::warning( void )
{
	std::cout <<LIGHT_GREEN<< "\U0001F615 I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<RESET_COLOR<< std::endl<< std::endl;
}

void Harl::error( void )
{
	std::cout<<LIGHT_RED << "\U0001F621 This is unacceptable! I want to speak to the manager now." << RESET_COLOR<<std::endl<< std::endl;
}

void	Harl::complain(std::string str)
{
	void (Harl::*ptr_level[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string	lvl[4] = { "debug", "info", "warning", "error" };
	std::string	LVL[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	bool	check = false;
	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == str || LVL[i] == str)
		{
			(this->*ptr_level[i])();
			{
				check = true;
				break;
			}
		}
	}
	if (check == false)
		std::cerr <<LIGHT_RED<< "Error : Your complain-option is unavailable, only: debug / info / warning / error" <<RESET_COLOR<< std::endl;
}