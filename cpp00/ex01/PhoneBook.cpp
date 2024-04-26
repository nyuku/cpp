/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:59:10 by angela            #+#    #+#             */
/*   Updated: 2024/04/25 12:59:11 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"
#include	"Contact.hpp"


//--------- Constructor - Destructor ---------//
Phonebook::Phonebook(void)
{
//	std::cout << "Constructor Phonebook called"
//			  << std::endl;
	this->_nbRegistred = 0;
	this->_entries = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor Phonebook called"
			  << std::endl;
	return;
}

//--------- Getters ---------//
int	Phonebook::getNbRegistred(void) const
{
	return (this->_nbRegistred);
}

//--------- Fonctions membres ---------//


void	Phonebook::addContact(void)
{
	std::string gnl;

	if (this->getNbRegistred() < MAX_CONTACT)
		this->_nbRegistred++;

	std::cout << "Please enter the new contact's informations:" << std::endl;
	//Check prompt not empty for each info
	this->InputPrompt(gnl, "First name:", "Your first name, pretty please.");
	this->contact_tab[this->_entries % MAX_CONTACT].setFirstName(gnl);
	gnl.clear();

	this->InputPrompt(gnl, "Last name:", "Please give me your last name.");
	this->contact_tab[this->_entries % MAX_CONTACT].setLastName(gnl);
	gnl.clear();

	this->InputPrompt(gnl, "Nickname:", "I'm sure you have a nickname.");
	this->contact_tab[this->_entries % MAX_CONTACT].setNickname(gnl);
	gnl.clear();

	this->InputPrompt(gnl, "Phone number:", "But where's your number? so call me, maybe?");
	this->contact_tab[this->_entries % MAX_CONTACT].setPhoneNumber(gnl);
	gnl.clear();

	this->InputPrompt(gnl, "Your darkest secret:", "Pinkie promise, you can tell me. I won't tell anyone.");
	this->contact_tab[this->_entries % MAX_CONTACT].setDarkestSecret(gnl);
	gnl.clear();

	this->_entries++;
}

bool	Phonebook::searchContact(void)
{
	bool valid = false;
	std::string input;
	if (this->getNbRegistred() == 0)
	{
		std::cout << "___________________________________________" << std::endl;
		std::cout	<< "There no entries in the phonebook."
					 << std::endl;
		std::cout << "___________________________________________" << std::endl;
		return (false);
	}

	this->printAllContact();
	std::cout	<< "Whose identifications do you need? Enter their index number or exit:"
					 << std::endl;

	while (!valid) // Continue tant que l'index n'est pas valide
	{

		std::cin >> input;

		if (input == "exit")
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return false;
		}

		// Convertit la string input -> iss ->int
		std::istringstream iss(input);
		int promptIndex;
		if (!(iss >> promptIndex)) // Si la conversion échoue
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "ERROR: Wrong index" << std::endl;
		}
		promptIndex -=1;
		if (promptIndex >= 0 && promptIndex <= this->getNbRegistred()) // ! new decallage avec prompt
		{
			this->lookDataContact(promptIndex);//test
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			valid = true; // L'index est valide, on peut sortir de la boucle
		}
		else
		{
			std::cout << "Please try again." << std::endl;
		}
	}
	return true;
}

void	Phonebook::InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage)
{
	std::cout << LILAC <<promptAsk<< RESET_COLOR << std::endl;
	while (input.empty())
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << errorMessage << std::endl;
		}
	}
}

void	Phonebook::printAllContact(void)
{
	std::cout	<< ROW_SEPA
				 << std::endl;
	std::cout	<< ROW_TITLE
				 << std::endl;
	std::cout	<< ROW_SEPA
				 << std::endl;
	int i = 0;
	while (i < this->getNbRegistred())
	{
		std::cout << PIPE
				  << std::setw(MAX_LEN)
				  << (i % MAX_CONTACT) +1// test
				  << PIPE;
		std::cout << std::setw(MAX_LEN)
				  << this->PrintWord10(this->contact_tab[i % MAX_CONTACT].getFirstName())
				  << PIPE;
		std::cout << std::setw(MAX_LEN)
				  << this->PrintWord10(this->contact_tab[i % MAX_CONTACT].getLastName())
				  << PIPE;
		std::cout << std::setw(MAX_LEN)
				  << this->PrintWord10(this->contact_tab[i % MAX_CONTACT].getNickname())
				  << PIPE
				  << std::endl;
		std::cout << ROW_SEPA
				  << std::endl;

		i++;
	}
}
void	Phonebook::lookDataContact(int i)
{
	std::cout	<< std::endl << LIGHT_LILAC<< "Here's the info you are looking for:" << RESET_COLOR
				 << std::endl<< std::endl;
	std::cout << "§___________________________________________§" << std::endl;
	std::cout << LIGHT_CYAN << "FULL NAME" << RESET_COLOR
			  << std::endl
			  << DIVIDER
				 << std::endl
				 << this->contact_tab[i].getFirstName()
				 << " "
				 << this->contact_tab[i].getLastName()
				 << " \""
				 << this->contact_tab[i].getNickname()
				 << "\" "
				 << std::endl
				 << std::endl;
	std::cout << LIGHT_CYAN << "TELEPHONE NUMBER" << RESET_COLOR
			  << std::endl
			  << DIVIDER
				 << std::endl
				 << this->contact_tab[i].getPhoneNumber()
				 << std::endl
				 << std::endl;
	std::cout << LIGHT_CYAN << "DARKEST SECRET" << RESET_COLOR
			  << std::endl
			  << DIVIDER
				 << std::endl
				 << this->contact_tab[i].getDarkestSecret()
				 << std::endl
				 << std::endl;
}

std::string	Phonebook::PrintWord10(std::string word)
{
	if ((int)word.length() > MAX_LEN)
	{
		word.resize((unsigned)(MAX_LEN - 1));
		word.append(".");
	}
	return (word);
}