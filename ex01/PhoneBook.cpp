#include	"PhoneBook.hpp"
#include	"Contact.hpp"
#include <string>
# include <iostream>

//--------- Constructor - Destructor ---------
Phonebook::Phonebook(void)
{
	std::cout << "Constructor Phonebook called"
			  << std::endl;
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

//--------- Getters ---------
int	Phonebook::getNbRegistred(void) const
{
	return (this->_nbRegistred);
}

//--------- Fonctions membres ---------


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

	this->InputPrompt(gnl, "Telephone number:", "But where's your number? so call me, maybe?");
	this->contact_tab[this->_entries % MAX_CONTACT].setPhoneNumber(gnl);
	gnl.clear();

	this->InputPrompt(gnl, "Your darkest secret:", "Pinkie promise, you can tell me. I won't tell anyone.");
	this->contact_tab[this->_entries % MAX_CONTACT].setDarkestSecret(gnl);
	gnl.clear();

	this->_entries++;
}

bool	Phonebook::searchContact(void)
{
	int promptIndex;
	if (this->getNbRegistred() == 0)
	{
		std::cout << "|___________________________________________|" << std::endl;
		std::cout	<< "There no entries in the phonebook."
					 << std::endl;
		std::cout << "|___________________________________________|" << std::endl;
		return (false);
	}
	this->printAllContact();

	// User choose an index
	std::cout	<< "Whose identifications do you need, enter their index number."
				 << std::endl;
	if (!(std::cin >> promptIndex)) // si pas d'entrée legit
	{
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout	<< "Wrong index, please try again."
					 << std::endl;
		return (false);
	}
	if (promptIndex >= 0 && promptIndex < this->getNbRegistred())
	{
		this->lookDataContact(promptIndex);
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (true);
	}
	std::cout	<< "No one know by this index number. Please try again."
				 << std::endl;
//	std::cin.clear();
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (false);
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
	int i = 0;  // Initialisation avant la boucle
	while (i < this->getNbRegistred())  // Condition de la boucle
	{
		std::cout << WORD_SEPA
				  << std::setw(MAX_LEN)
				  << (i % MAX_CONTACT)
				  << WORD_SEPA;
		std::cout << std::setw(MAX_LEN)
				  << this->PrintWord10(this->contact_tab[i % MAX_CONTACT].getFirstName())
				  << WORD_SEPA;
		std::cout << std::setw(MAX_LEN)
				  << this->PrintWord10(this->contact_tab[i % MAX_CONTACT].getLastName())
				  << WORD_SEPA;
		std::cout << std::setw(MAX_LEN)
				  << this->PrintWord10(this->contact_tab[i % MAX_CONTACT].getNickname())
				  << WORD_SEPA
				  << std::endl;
		std::cout << ROW_SEPA
				  << std::endl;

		i++;  // Incrémentation à la fin du corps de la boucle
	}
}
void	Phonebook::lookDataContact(int i)
{
	std::cout	<< "Here's the info you are looking for:"
				 << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout	<< "FULL NAME"
				 << std::endl
				 << TITLE
				 << std::endl
				 << this->contact_tab[i].getFirstName()
				 << " \""
				 << this->contact_tab[i].getNickname()
				 << "\" "
				 << this->contact_tab[i].getLastName()
				 << std::endl
				 << std::endl;
	std::cout	<< "TELEPHONE NUMBER"
				 << std::endl
				 << TITLE
				 << std::endl
				 << this->contact_tab[i].getPhoneNumber()
				 << std::endl
				 << std::endl;
	std::cout	<< "DARKEST SECRET"
				 << std::endl
				 << TITLE
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