
# include	<iostream>
# include "PhoneBook.hpp"
# include "Contact.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	prompt;

	std::cout	<< TITLE
				 << std::endl;
	std::cout	<< "     *          Phonebook           *"
				 << std::endl;
	std::cout	<< TITLE
				 << std::endl;

	while (1)
	{
		std::cout	<< SOFT_GREEN<< "Commands available : ADD, SEARCH and EXIT "<< RESET_COLOR << std::endl;

		std::getline(std::cin, prompt);
		for (int i = 0; i < (int)prompt.length(); i++)
			prompt[i] = (char)toupper(prompt[i]);
		std::cout	<< std::endl <<"You entered: [" << prompt << "]"
					 << std::endl<< std::endl<< std::endl;

		if (prompt == "EXIT")
			break;

		if (prompt != "ADD" && prompt != "SEARCH")
		{
			std::cout	<<LIGHT_RED<<"[" << prompt << "] is an invalid command. Please try again."<< RESET_COLOR
						 << std::endl;
//			continue;
		}

		if (prompt == "ADD")
		{
			phonebook.addContact();
		}

		if (prompt == "SEARCH")
			phonebook.searchContact();

		prompt.clear();
		std::cout << prompt << std::endl;
	}
	return (0);
}