/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:59:14 by angela            #+#    #+#             */
/*   Updated: 2024/04/25 12:59:15 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>
#define MAX_CONTACT  8
#define MAX_LEN      10


#define ROW_SEPA     "±-------------------------------------------±"
#define ROW_TITLE    "|     INDEX|      NAME|   SURNAME|  NICKNAME|"
#define DIVIDER      "---------------------------------------------"
#define PIPE    "|"


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