// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 Template fonction sur container
//       ✩ chercher un nombre entier dans un container template.
//       ✩ pour l'exercice on doit gérer un container Template mais il va etre de type int
//         
//       ✩ première occurrence du second paramètre dans le premier paramètre
//       ✩ 'Templates must be defined in the header files'
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define BLUE            "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m"
#define MAGENTA		  	"\033[0;35m"
#define LILAC		   	"\033[0;94m"
#define LIGHT_BLUE		"\033[0;34m"
#define LIGHT_TURCOI    "\033[0;36m"
#define LIGHT_RED	  	"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE	    "\033[0;94m"
#define PEACH		    "\033[0;93m"
#define LIGHT_CYAN      "\033[0;36m"
#define BOLD		    "\033[1m"
#define ENDL            std::endl

template <typename T>
typename T::iterator easyfind(T &container, int toFind);

#include "easyfind.tpp"

#endif