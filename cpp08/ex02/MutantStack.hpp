// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ MutantStack va herite de stack -> container protege en deque
//       ✩ On accede aux iterators en exposant Begin et End

//       ✩ Bonus:  remplacer MutantStack par std::list<int>

//       ✩Rappel :
//                  -avec constructor copie <-> operator
//                  -le type de le class est "MutantStack<T>"
//iterator:
//          - "container_type" est l’alias du type du container interne à std::stack. plus simple que d'appeler le type du container recherche
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <list>
# include <vector>
# include <iostream>
# include <string>


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

template<typename T>
class MutantStack :public std::stack<T> //herite de stack
{

    public:
    //    ✩  ---------   Constructor - Destructor -  Copy    --------- 
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack<T> &src)
        {
            *this = src; // appelle l'operator =
        }

    //    ✩  ---------   Opérator    ---------
        MutantStack<T>&operator=(const MutantStack<T> &rhs)
        {
            this->c = rhs.c;
            return *this;
        }
       
    //    ✩  ---------  Iterator   ---------   ✩
        typedef typename std::stack<T>::container_type::iterator iterator;
        //std::stack<T> la stack de template. ca peut etre int
        //std::stack<T>::container_type fait reference au type du container interne, qui par defaut et un deque
        //le 2e iterator et le nom donne
        //Dans cette classe MutantStack<T>, appelle iterator le même type que std::stack<T>::container_type::iterator.
        iterator begin() 
        { 
            return this->c.begin(); 
        }
        iterator end()   
        { 
            return this->c.end(); 
        }


};
#endif