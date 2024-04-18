#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp" // Assurez-vous que ce fichier existe et est accessible
#include <string>      // Nécessaire pour std::string
#include <iostream>    // Nécessaire pour std::cout et std::cin

#define MAX_CONTACT  8
#define MAX_LEN      10
#define DIVIDER      "|"

#define ROW_SEPA     "*----------*----------*----------*----------*"
#define ROW_TITLE    "|     INDEX|      NAME|   SURNAME|  NICKNAME|"
#define TITLE        "*-------------------------------------------*"
#define WORD_SEPA    "|"

const std::string LILAC = "\033[0;94m";
const std::string RESET_COLOR = "\033[0m";

class Phonebook
{
	private:
		Contact contact_tab[MAX_CONTACT];
		int		_nbRegistred; // nombre enregirstré
		int		_entries;

	public:
		//Constructor- destructor
		Phonebook(void);
		~Phonebook(void);
		// Getters - récupere
		int				getNbRegistred(void) const;
		//Fonctions membres
		void			addContact(void);
		bool			searchContact(void);
		std::string		PrintWord10(std::string word);
		void			lookDataContact(int i);
		void			printAllContact(void);
		void			InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage);

};
#endif