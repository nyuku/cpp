// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Span pouvant stocker un maxium de 'N' entiers
//       ✩ 'N' est le seul paramètre du constructeur
//       ✩ Fonction addNumber() qui ajoute un seul entier à Span
//          -> lance une exception si le nombre d'entiers dépasse 'N'
//       ✩ Fonctions member shortestSpan() et longestSpan()
//          -> calculent la différence entre les plus petits et plus grands entiers
//          -> lancent une exception si le nombre d'entiers est insuffisant ou aucune différence n'est trouvée
//       ✩  Testez votre Span avec au moins 10 000 nombres
//       ✩  Bonus: ajouter plusieurs nombres à la fois via une plage d'itérateurs (range of iterators)
//                 sans appeler explicitement addNumber() plusieurs fois
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

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

class Span
{
    private:
        unsigned int _n;
        std::vector<unsigned int> _container;
    public:

        //    ✩  ---------   Constructor - Destructor - Const with arg - Copy    --------- 
        Span();
        ~Span();
        Span(unsigned int n);
        Span(Span const & rhs);

        //    ✩  ---------   Opérator    ---------
        Span & operator=(Span const & rhs);

        //    ✩  ---------  Fonctions   ---------   ✩
        void            addNumber(unsigned int addNumber);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
        void            fillContainer(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        //    ✩  ---------  Exceptions   ---------   ✩
        class FullContainerException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class InsufficientDataException : public std::exception
        {
            public:
                const char* what() const throw();
        };

}