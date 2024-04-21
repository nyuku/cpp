#include			<iostream>
#define CYAN		"\033[0;36m"
#define LIGHTPURPLE	" \033[1;35m"
#define LIGHT_LILAC	"\033[1;34m"
#define RESET_COLOR "\033[0m"
#define PEACH		"\033[0;93m"
int main()
{
	//init string
	std::string bonjour_str = "HI THIS IS BRAIN";
	//pointeur sur la string, stocke addresse de str
	std::string *stringPTR = &bonjour_str;
	//référence sur la string, prend la valeur de str, copie
	std::string &stringREF = bonjour_str;


	std::cout << "Address of the string: " << LIGHT_LILAC << "\t\t"
			  << &bonjour_str << RESET_COLOR << std::endl;
	std::cout << "Address stock in stringPTR: " << LIGHT_LILAC << "\t"
			  << stringPTR << RESET_COLOR << std::endl;
	std::cout << "Address of stringREF: " << LIGHT_LILAC<<"\t\t"
			  << &stringREF << RESET_COLOR <<std::endl;

	std::cout <<PEACH << "      ---------------------------------"<< RESET_COLOR <<std::endl;

	std::cout << "The value of the string variable: "<< CYAN <<"\t"
			  << bonjour_str << RESET_COLOR<< std::endl;
	std::cout << "The value pointed to by stringPTR: "<< CYAN <<"\t"
			  << *stringPTR << RESET_COLOR<<std::endl;
	std::cout << "The value pointed to by stringREF: "<< CYAN <<"\t"
			  << stringREF << RESET_COLOR<<std::endl;
	return (0);
}