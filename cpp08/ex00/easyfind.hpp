// ╔───────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────╗
// 		 Template fonction sur container d'entier
//
//       Données:
//       ✩ Créer une fonction template, chercher un nombre entier dans un container entier template 
//         -> found: retourne un itérateur pointant sur l'élément trouvé
//         -> not found: retourne un itérateur vers la fin du container (container.end()) si l'entier n'est pas trouvé
//                       Lancer une exception ou retourner une valeur erreur
//       Fonction:
//          -premier paramètre : un container d’entiers 
//          -second paramètre : un entier à rechercher
//          -template, utilisable avec différents types de containers 
//
//       More:
//       ✩ "template": s’adapter à différents types de containers d'entier
//              (comme std::vector<int>, std::list<int>, std::deque<int>, etc.)
//       ✩ std::find dans <algorithm>
//       ✩ "typename T::iterator" → Comme chaque container a son propre type d’itérateur 
//         
// ╚───────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────╝

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

//.......................................................................................................
//										    fonction      												|
//.......................................................................................................
    template <typename T>
    typename T::iterator easyfind(T &container, int toFind);


#include "easyfind.tpp"
#endif