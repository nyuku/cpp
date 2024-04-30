/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:58:56 by angela            #+#    #+#             */
/*   Updated: 2024/04/29 11:26:58 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include	<iostream>
# include "PhoneBook.hpp"


int	main(void)
{
	Phonebook	phonebook;
	std::string	prompt;
	int i ;

	std::cout << DIVIDER << std::endl;
	std::cout << "     *          Phonebook           *"<< std::endl;
	std::cout << DIVIDER << std::endl;

	while ((!std::cin.eof()))
	{
		std::cout << SOFT_GREEN<< "Commands available : ADD, SEARCH and EXIT "
		          << RESET_COLOR << std::endl;
		std::getline(std::cin, prompt);
		i = 0;
		while (i < (int)prompt.length())
		{
			prompt[i] = (char)toupper(prompt[i]);
			i++;
		}
		std::cout << std::endl <<"You entered: [" << prompt << "]"
					 << std::endl<< std::endl<< std::endl;

		if (prompt == "EXIT")
			break;
		if (prompt != "ADD" && prompt != "SEARCH")
		{
			std::cout	<<LIGHT_RED<<"[" << prompt << "] is an invalid command. Please try again."<< RESET_COLOR
						 << std::endl;
			continue;
		}
		if (prompt == "ADD")
			phonebook.addContact();

		if (prompt == "SEARCH")
			phonebook.searchContact();

		prompt.clear();
		std::cout << prompt << std::endl;
	}
	return (0);
}