#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>

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
//					                        	Classe "Base"                                           |
//                                          							                                |
//.......................................................................................................
 
    class Base
    {

        public: 
            //    ✩  ---------   Destructor    --------- 
            virtual ~Base() = 0;
   
    };



//.......................................................................................................
//						                        Fonctions externes                                       |
//                                          							                                 |
//.......................................................................................................
 
    Base * generate(void);
    void identify(Base* p);
        bool isA(Base* p);
        bool isB(Base* p);
        bool isC(Base* p);
    void identify(Base& p);
        bool refToA(Base& p);
        bool refToB(Base& p);
        bool refToC(Base& p);

#endif