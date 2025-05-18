
// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩  division entière, pas décimale -> division 0
//       ✩ 
//       ✩ 
//         
// 		 ✩ 
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <cctype>
# include <stdexcept>
# include <sstream>
# include <cstring>  
# include <cstdlib> 



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

class RPN
{
    private:
        std::stack<int> _stack;
        // int             _result;
        //    ✩  ---------  Fonctions   ---------   ✩
        void addStack(int a);
        void calculus(char op);
        bool isOperator(const std::string& token) const;
        bool isNumber(const std::string& token) const;

    public:
    //    ✩  ---------   Constructor - Destructor -  Copy    --------- 
        RPN();
        ~RPN();
        RPN(const RPN &other);
    //    ✩  ---------   Opérator    ---------
        RPN& operator=(const RPN &other);

    //    ✩  ---------  Fonctions   ---------   ✩
        bool reversePolishNotation(const std::string &expression, int &result);


    //    ✩  ---------  Exceptions   ---------   ✩

    //    ✩  ---------  Print Container   ---------   ✩

    //    ✩  ---------  Getters - Setters   ---------   ✩


};
#endif