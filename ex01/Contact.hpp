#ifndef	CONTACT_H
# define CONTACT_H


# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>


class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		//Constructor- destructor
		Contact(void);
		~Contact(void);

		// Getters - récupere
		// Const: ne modifie rien
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
		//Setters - init
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);


};

#endif