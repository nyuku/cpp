/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:58:38 by angela            #+#    #+#             */
/*   Updated: 2024/05/19 11:58:39 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

std::string toupperStr(std::string str)
{
    for (size_t i = 0; i < str.length(); ++i)
        str[i] = std::toupper((str[i]));
	return (str);
}

void Harl::complain(std::string str)
{
    std::string LVL[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i;
	std::string input;
    while (!std::cin.eof())
	{
        str = toupperStr(str);
        for (i = 0; i < 4; ++i) 
		{
            if (LVL[i] == str)
            	break;
        }

        switch (i) 
		{
            case 0:
                this->debug();
                return;  
            case 1:
                this->info();
                return;  
            case 2:
                this->warning();
                return;  
            case 3:
                this->error();
                return;  
            default:
				{
					std::cerr << LIGHT_RED << "Error: Argument not valid. Only: DEBUG, INFO, WARNING, ERROR" << RESET_COLOR << std::endl;
					InputPrompt(input, "Please enter level of complain: ", "Choose between: DEBUG, INFO, WARNING, ERROR", LILAC);
					str = input;
					std::cout << std::endl << CYAN << "You entered: [" << str << "]" << RESET_COLOR << std::endl;
				}

        }
    }
}