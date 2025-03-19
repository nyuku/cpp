// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ non-instanciable-> constructor private
//       ✩ two static method serialize, deserialize
//          ✩uintptr_t serialize(Data* ptr);
//              It takes a pointer and converts it to the unsigned integer type uintptr_t
//          ✩Data* deserialize(uintptr_t raw);
//              It takes an unsigned integer parameter and converts it to a pointer to Data
//       ✩ uintptr_t: unsigned int
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

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

class Serializer
{
    private:
    //    ✩  ---------   Constructor- copy constructor- operator    --------- 
        Serializer();
        Serializer(Serializer const & src);
        Serializer & operator=(Serializer const & src);

    public: 
        //    ✩  ---------   Destructor    --------- 
        ~Serializer();
        //    ✩  ---------   Fonctions static     ---------
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);

};
#endif