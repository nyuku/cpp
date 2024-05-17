/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:52:00 by angela            #+#    #+#             */
/*   Updated: 2024/05/17 15:38:06 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

void InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage, const std::string& color)
{
    if (!std::cin.eof())
        std::cout<< std::endl << color << promptAsk << RESET_COLOR << std::endl;
    while (input.empty() && !std::cin.eof())
	{
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cerr << LIGHT_RED << std::endl << "Error: You entered: [ CTRL + D ]" << RESET_COLOR << std::endl;
            std::cin.clear();
            exit(1);
        }
        if (input.empty() && !std::cin.eof())
		{
            std::cout << LIGHT_RED << errorMessage << RESET_COLOR << std::endl;
			std::cin.clear();//ajout
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
	InputPrompt(input, "Please enter level of complain: ", "Choose between: debug / info / warning / error", LILAC);//tourne jusuq'a avoir une rentré
	std::cout << std::endl<<CYAN<<" You entered: [" << input << "]"
			  <<RESET_COLOR<< std::endl;

	harl.complain(input);
	input.clear();
	return (0);
}
