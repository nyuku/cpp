/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:55:27 by angela            #+#    #+#             */
/*   Updated: 2024/05/04 00:55:28 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include				<iostream>

#define CYAN			"\033[0;36m"
#define LIGHTPURPLE		" \033[1;35m"
#define LIGHT_LILAC		"\033[1;34m"
#define RESET_COLOR 	"\033[0m"
#define PEACH			"\033[0;93m"
#define LIGHT_RED       "\033[0;91m"
#define BLUE			" \033[0;34m"

int main()
{
	//init string
	std::string bonjour_str = "HI THIS IS BRAIN";

	//pointeur sur la string, stocke addresse de str
	std::string *stringPTR = &bonjour_str;

	//référence sur la string, prend la valeur de str, copie
	std::string &stringREF = bonjour_str;

	std::cout << std::endl<<BLUE<< "------------------ \tRound 1 \t-----------------------" << std::endl << RESET_COLOR ;
	std::cout <<std::endl<< "1. Address of the string: " << LIGHT_LILAC << "\t\t"
			  << &bonjour_str << RESET_COLOR  << std::endl << std::endl;
	std::cout << "      --------\tExpected: same as 1. \t--------" <<  "\t"
			 << std::endl;		  
	std::cout << std::endl<< "2. Address stock in stringPTR: " << LIGHT_LILAC << "\t\t"
			  << stringPTR << RESET_COLOR << std::endl;
	std::cout << "3. Address of stringREF: " << LIGHT_LILAC<<"\t\t"
			  << &stringREF << RESET_COLOR <<std::endl;

	std::cout  << std::endl << std::endl<<BLUE << "------------------Round 2-----------------------" << std::endl<< RESET_COLOR <<std::endl;

	std::cout << "1. The value of the string variable: "<< CYAN <<"\t"
			  << bonjour_str << RESET_COLOR<< std::endl<< std::endl;
	std::cout << "      --------\tExpected: same as 1. \t--------" <<  "\t"
			 << std::endl<< std::endl;		  
	std::cout << "2. The value pointed to by stringPTR: "<< CYAN <<"\t"
			  << *stringPTR << RESET_COLOR<<std::endl;
	std::cout << "3. The value pointed to by stringREF: "<< CYAN <<"\t"
			  << stringREF << RESET_COLOR<< std::endl<<std::endl;
	return (0);
}