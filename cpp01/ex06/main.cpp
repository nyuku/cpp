
#include "Harl.hpp"
#include <fstream>
#include <iostream>


#define RESET_COLOR "\033[0m"
#define SOFT_GREEN   "\033[0;92m"
#define LIGHT_GREEN	 "\033[1;32m"
#define LIGHTPURPLE		" \033[1;35m"
#define LIGHT_LILAC		" \033[1;34m"
#define LIGHT_MAGENTA   " \033[0;95m"
#define LIGHT_CYAN		" \033[1;36m"
#define MAGENTA			" \033[0;35m"
#define LILAC			" \033[0;94m"
#define BLUE			" \033[0;34m"
#define CYAN			" \033[0;36m"
#define LIGHT_RED       " \033[0;91m"
#define GREEN           " \033[0;32m"
#define DARK_BLUE       "\033[0;94m"

void	InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage)
{
	std::cout << LILAC <<promptAsk<< RESET_COLOR << std::endl;
	while (input.empty())
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout <<LIGHT_RED<< errorMessage <<RESET_COLOR<< std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1) {
		std::cerr << LIGHT_RED << "Error: Please execute without arguments" << RESET_COLOR
				  << std::endl;
		return (1);
	}

	std::string input;
	Harl harl;

	//--------PARSING---------//
	//get the files
	InputPrompt(input, "Please enter level of complain: ", "Choose between: debug / info / warning / error");
	std::cout << std::endl<<CYAN<<"You entered: [" << input << "]"
			  <<RESET_COLOR<< std::endl;
	int i = 0;
	while (i < (int)input.length())
	{
		input[i] = (char)toupper(input[i]);
		i++;
	}

	harl.complain(input);
	input.clear();
	return (0);
}
