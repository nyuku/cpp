// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ applique une fonction donnée sur chaque élément d’un tableau
//       ✩ Prend en paramètre: 
//          1. un tableau (via un pointeur ou une référence)
//          2. sa taille
//          3. une fonction, appliquée sur chaque élément du tableau
//              can be an instantiated function template
//       ✩  must work with any type of array
//       ✩ Templates must be defined in the header files
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

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

template <typename T, typename Function>
void iter(T *array, size_t sizeTab, Function func) {
    if (!array) return;

    for (size_t i = 0; i < sizeTab; i++) {
        func(array[i]); 
    }
}

#endif