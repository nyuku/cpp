// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Tableau dynamique
//       ✩ instanciable avec n’importe quel type T
//       ✩ Gestion de la mémoire dynamique (new[] et delete[]).obligatoirement
//       ✩ taille : vide (Array()) ou contenir n éléments (Array(n)).
//       ✩ Supporter la copie et l’affectation sans partager la même mémoire, independant
//       ✩ opérateur [] pour accéder aux éléments, avec une gestion des erreurs si l’indice est hors limite.
//       ✩ méthode size() qui retourne le nombre d’éléments

//      ✩ Standar Constructor : Creates an empty array
//      ✩ Try to compile int * a = new int(); then display *a.
//      ✩ Write exception handling for the [] operator
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef ARRAY_HPP
# define ARRAY_HPP

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

#include <iostream>

template <typename Type>
class Array
{
    private: 
    //	✩  ---------   Variables      --------- 
        Type            *_tab;
        unsigned int    _size;
    public:   
    //	✩  ---------   Constructor- destructor - arg constructor - copy constructor     --------- 
	    Array() ;//: _tab(nullptr), _size(0) {} //array est vide au départ AVEC un ptr null(aucune mémoire allouée)
        ~Array();

        Array(unsigned int element);
        Array(const Array &other);

    //	✩  ---------   Operator      ---------
        Array& operator=(const Array &other);
        const Type &operator[](unsigned int index) const;
        Type &operator[](unsigned int index); // retourne un element du tab
        
        unsigned int	size() const;
    //    ✩  ---------   Exception   perso  ---------
        class outOfBoundsException : public std::exception
		{
			public :
			virtual const char* what() const throw()
			{
				return ("Index out of bound.\n");
			}
		};
		
};

#include "Array.tpp"
#endif
