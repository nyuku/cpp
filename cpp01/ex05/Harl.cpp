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
	std::cout<<std::endl<<LIGHT_RED << "\U0001F621 This is unacceptable! I want to speak to the manager now." << RESET_COLOR<<std::endl<< std::endl;
}

void Harl::complain(std::string str)
{
    // Tableau de pointeurs de fonctions membres
    void (Harl::*ptr_level[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // Niveaux de plainte
    std::string lvl[4] = { "debug", "info", "warning", "error" };
    std::string LVL[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    bool check = false;

    while (!check && !std::cin.eof())
    {
        // Vérifie si 'str' correspond à l'un des niveaux de plainte
        for (int i = 0; i < 4; ++i)
        {
            if (lvl[i] == str || LVL[i] == str)
            {
                // Appelle la fonction membre correspondante
                (this->*ptr_level[i])();
                check = true;
                break;
            }
        }

        // Si 'str' ne correspond à aucun niveau de plainte, demande une nouvelle entrée
        if (!check)
        {
            std::cerr << LIGHT_RED << "Error: Your complain-option is unavailable, only: debug / info / warning / error" << RESET_COLOR << std::endl;
            std::string input;
            InputPrompt(input, "Please enter level of complain: ", "Choose between: debug / info / warning / error", LILAC);
            if (std::cin.eof()) // Sortir de la boucle si EOF est rencontré
                break;
            str = input; // Met à jour 'str' avec la nouvelle entrée
            std::cout << std::endl << CYAN << "You entered: [" << str << "]" << RESET_COLOR << std::endl;
        }
    }
}

// void	Harl::complain(std::string str)
// {
// 	void (Harl::*ptr_level[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};// tableau de pointeurs 

// 	std::string	lvl[4] = { "debug", "info", "warning", "error" };
// 	std::string	LVL[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

// 	bool	check = false;
// 	std::string input = str;
// 	while (check == false && !std::cin.eof())
// 	{
// 		for (int i = 0; i < 4; i++)
// 		{
// 			// std::cout << std::endl<<CYAN<<"Yploop"<<RESET_COLOR<< std::endl;
// 			if (lvl[i] == input || LVL[i] == input)
// 			{
// 				(this->*ptr_level[i])();
// 				{
// 					check = true;
// 					break;
// 				}
// 			}
// 		}
// 		if (check == false)
// 		{
// 			std::cerr <<LIGHT_RED<< "Error : Your complain-option is unavailable, only: debug / info / warning / error" <<RESET_COLOR<< std::endl;
// 			InputPrompt(input, "Please enter level of complain: ", "Choose between: debug / info / warning / error", LILAC);
// 			std::cout << std::endl<<CYAN<<"You entered: [" << input << "]"<<RESET_COLOR<< std::endl;
// 			input = str;
// 		}

// 	}
// }

